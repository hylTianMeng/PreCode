#include<bits/stdc++.h>
using namespace std;
#define R int
#define int long long
#define AC 101000 
#define LL long long

int n, m, k, tot1, tot2, tot3, cnt;
LL s[AC];

const int mod=1e9+7;

struct node{
    int opt, id, x;LL v, w;//w为分母
}m1[AC], m2[AC], m3[AC], ans[AC],ques[AC];//不需要知道具体值……所以减1再比较也不影响结果，知道哪些是我要的操作就好了
int t;

inline bool cmp1(node a, node b){return (a.x != b.x) ? (a.x < b.x) : (a.v < b.v);}//给操作1去重
inline bool cmp2(node a, node b){return (a.x != b.x) ? (a.x < b.x) : (a.v > b.v);}//上面去重所以从小到大，这里贪心所以从大到小
inline bool cmp3(node a, node b){return a.opt < b.opt;}//先1再2再3,且取走的加法是一段前缀才能保证结果正确性
inline bool cmp4(node a, node b){return a.v * b.w > a.w * b.v;}//分数比较

inline int read()
{
    int x = 0;char c = getchar();
    while(c > '9' || c < '0') c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}

void pre()
{
    n = read(), m = read(), k = read();
    for(R i = 1; i <= n; i ++) s[i] = read();
    for(R i = 1; i <= m; i ++)
    {
        int a = read(), b = read(), c = read();
        if(a == 1 && c > s[b]) m1[++ tot1] = (node){1, i, b, c, 1};//如果改了反而不优就算了
        else if(a == 2) m2[++ tot2] = (node){2, i, b, c, 1};
        else if(a == 3) m3[++ tot3] = (node){3, i, b, c, 1};//默认分母为1
        ques[++t]=(node){a,i,b,c,1};
    }
}

void build()
{
    sort(m1 + 1, m1 + tot1 + 1, cmp1);	
    int tmp = 0;
    for(R i = 1; i <= tot1; i ++)
        if(m1[i].x != m1[i + 1].x) m1[++ tmp] = m1[i];//对于同一个数的赋值操作只保留最大的,否则影响贪心正确性
    tot1 = tmp;
    for(R i = 1; i <= tot1; i ++) 
        m1[i].v = m1[i].v - s[m1[i].x], m2[++ tot2] = m1[i];//把赋值变成加法后加入m2中
    sort(m2 + 1, m2 + tot2 + 1, cmp2);//因为要每个数单独看，所以还是要先按数排序，再按大小排序
    LL sum = 0;
    for(R i = 1; i <= tot2; i ++) 
    {
        if(m2[i].x != m2[i - 1].x) sum = s[m2[i].x];//对于新的一段就重置一下
        m2[i].w = sum, sum += m2[i].v;//v不用修改，因为统一-1了，所以分子要-sum
    }	
    for(R i = 1; i <= tot3; i ++) m3[i].v --;//统一-1不会影响比较结果
    for(R i = 1; i <= tot2; i ++) m3[++ tot3] = m2[i];
}

void work()
{
    sort(m3 + 1, m3 + tot3 + 1, cmp4);
    int tmp = min(tot3, k);
    for(R i = 1; i <= tmp; i ++) ans[++ cnt] = m3[i];	
    // printf("%d\n", cnt);
    sort(ans + 1, ans + cnt + 1, cmp3);
    for(R i = 1; i <= cnt; i ++) printf("%d ", ans[i].id);
    // printf("\n");
    // for(int i=1;i<=n;i++) printf("%d\n",s[i]);
    for(int i=1;i<=cnt;i++){
        int id=ans[i].id;
        if(ques[id].opt==1) s[ques[id].x]=ques[id].v;
        else if(ques[id].opt==2) (s[ques[id].x]+=ques[id].v)%=mod;
        else if(ques[id].opt==3) (s[ques[id].x]*=ques[id].v)%=mod;
    }
    // for(int i=1;i<=n;i++) printf("%d\n",s[i]);
    int Ans=1;
    for(int i=1;i<=n;i++) Ans=Ans*s[i]%mod;
    printf("%lld\n",Ans);
}

signed main()
{
    freopen("my.in", "r", stdin);
    freopen("gou.out","w",stdout);
    pre();
    build();
    work();
//	fclose(stdin);
    return 0;
}
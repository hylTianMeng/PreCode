#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 20020010
#define M 500010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Node{
    int ch[2],Size,End;
}p[N];

int tot,Root[N],rtt;

typedef pair<int,int> P;

struct Trie{
    inline Trie(){memset(p,0,sizeof(p));tot=0;}
    inline void Insert(int last,int x,int id){
        Root[++rtt]=++tot;
        int now=tot,q=last;
        for(int i=33;i>=0;i--){
            int w=(x>>i)&1;
            p[now]=p[q];
            p[now].ch[w]=++tot;
            p[now].Size=p[q].Size+1;
            now=p[now].ch[w];
            q=p[q].ch[w];
        }
        p[now].End=id;p[now].Size=p[q].Size+1;
    }
    inline P Query(int l,int r,int x){
        if(r<l) return make_pair(0,0);
        int res=0,q=Root[l-1],now=Root[r];
        for(int i=33;i>=0;i--){
            int w=(x>>i)&1;
            if(p[p[now].ch[w^1]].Size-p[p[q].ch[w^1]].Size>0){
                now=p[now].ch[w^1];q=p[q].ch[w^1];res|=(1ll<<i);
            }
            else now=p[now].ch[w],q=p[q].ch[w];
        }
        return make_pair(res,p[now].End);
    }
}tr;

int n,k,a[M],Ans;

struct node{
    int val,k,l,r,sum;
    inline node(){}
    inline node(int val,int k,int l,int r,int sum) : val(val),k(k),l(l),r(r),sum(sum) {}
    inline bool operator < (const node &b)const{return val<b.val;}
};
priority_queue<node> q;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(k);
    for(int i=2;i<=n+1;i++) read(a[i]);
    tr.Insert(0,0,1);
    for(int i=2;i<=n+1;i++){
        a[i]^=a[i-1];tr.Insert(Root[rtt],a[i],i);
    }
    for(int i=2;i<=n+1;i++){
        P val=tr.Query(1,i,a[i]);
        // printf("val.first=%lld\n",val.first);
        q.push(node(val.first,val.second,1,i,a[i]));
    }
    for(int i=1;i<=k;i++){
        node ans=q.top();q.pop();Ans+=ans.val;
        // printf("ans.val=%lld\n",ans.val);
        // printf("ans.sum=%lld\n",ans.sum);
        // printf("ans.k=%lld\n",ans.k);
        P Max1=tr.Query(ans.l,ans.k-1,ans.sum);
        P Max2=tr.Query(ans.k+1,ans.r,ans.sum);
        // printf("Max1.f=%lld Max1.se=%lld\n",Max1.first,Max1.second);
        // printf("Max2.f=%lld Max2.se=%lld\n",Max2.first,Max2.second);
        q.push(node(Max1.first,Max1.second,ans.l,ans.k-1,ans.sum));
        q.push(node(Max2.first,Max2.second,ans.k+1,ans.r,ans.sum));
    }
    printf("%lld\n",Ans);
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 2010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct edge{
    int from,to,w,op;
    inline bool operator < (const edge &b)const{
        return w<b.w;
    }
}li[N*N<<1];
int tail;

typedef pair<int,int> P;
P a[N];

int c[N],k[N],n;

int fa[N];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

vector<int> v;
typedef pair<int,int> P;
vector<P> e;


signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++){read(a[i].first);read(a[i].second);}
    for(int i=1;i<=n;i++) read(c[i]);
    for(int i=1;i<=n;i++) read(k[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j) continue;
            ++tail;li[++tail].from=i;li[tail].to=j;
            li[tail].w=(k[i]+k[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
            li[tail].op=2;
        }
    }
    int u=n+1;
    for(int i=1;i<=n;i++){
        ++tail;
        li[tail].from=u;li[tail].to=i;li[tail].w=c[i];
        li[tail].op=1;
    }
    sort(li+1,li+tail+1);
    int Ans=0;
    for(int i=1;i<=n+1;i++) fa[i]=i;
    for(int i=1;i<=tail;i++){
        int faa=Find(li[i].from),fab=Find(li[i].to);
        if(faa!=fab){
            Ans+=li[i].w;
            fa[faa]=fab;
            if(li[i].op==1) v.push_back(li[i].to);
            else e.push_back(make_pair(li[i].from,li[i].to));
        }
    }
    printf("%lld\n",Ans);
    printf("%lld\n",(int)v.size());
    for(int now:v) printf("%lld ",now);puts("");
    printf("%lld\n",(int)e.size());
    for(P now:e) printf("%lld %lld\n",now.first,now.second);
    return 0;
}
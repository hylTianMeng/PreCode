#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=r;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 200010
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

int n,a[N];
int fa[N],Size[N];
ll g[N],f[N];

vector<int> e[N],v[N];
bool vis[N],vi[N];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

inline void Calc(int x,int id){
    int i;
    for(i=1;i*i<x;i++){
        if(x%i) continue;
        v[i].push_back(id);
        g[i]++;
        v[x/i].push_back(id);
        g[x/i]++;
    }
    if(i*i==x){v[i].push_back(id);g[i]++;}
}

inline void Merge(int a,int b){
    int faa=Find(a),fab=Find(b);
    if(faa==fab) return;
    if(Size[faa]>Size[fab]) swap(faa,fab);
    fa[faa]=fab;Size[fab]+=Size[faa];
}

int Prime[N],tail,mu[N];
bool NotPrime[N];

inline void BinearSieve(){
    mu[1]=1;
    rep(i,2,200000){
        if(!NotPrime[i]){Prime[++tail]=i;mu[i]=-1;}
        for(int j=1;j<=tail&&1ll*Prime[j]*i<=200000;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0){mu[Prime[j]*i]=0;break;}
            else mu[Prime[j]*i]=-mu[i];
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    BinearSieve();
    read(n);rep(i,1,n)read(a[i]);
    rep(i,1,n){Calc(a[i],i);}
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    rep(i,1,n){
        fa[i]=i;Size[i]=1;
    }
    rep(i,1,n){fa[i]=i;Size[i]=1;}
    rep(i,1,200000){
        // printf("i=%d\n",i);
        for(int j:v[i]) vis[j]=1;
        for(int j:v[i]){
            for(int to:e[j]){
                if(!vis[to]) continue;
                Merge(to,j);
            }
        }
        for(int j:v[i]){
            int faj=Find(j);
            if(vi[faj]) continue;
            vi[faj]=1;int si=Size[faj];
            g[i]+=1ll*si*(si-1)/2;
            // printf("si=%d\n",si);
        }
        for(int j:v[i]){
            int faj=Find(j);vi[j]=0;
        }
        for(int j:v[i]){fa[j]=j;Size[j]=1;}
        for(int j:v[i]) vis[j]=0;
    }
    // rep(i,1,n){printf("mu[%d]=%d\n",i,mu[i]);}
    rep(i,1,200000){
        for(int j=i;j<=200000;j+=i){
            f[i]+=1ll*mu[j/i]*g[j];
            // printf("i=%d f[i]=%lld\n",i,f[i]);
        }
    }
    rep(i,1,200000){
        if(f[i]) printf("%lld %lld\n",i,f[i]);
    }
    return 0;
}
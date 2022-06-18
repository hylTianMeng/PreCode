#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 22
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,p,w[N],sum[1<<N],h[N][1<<N],f[N][1<<N],cn[1<<N],len,in[1<<N];
bool vis[1<<N];
P e[N*N];
int fa[N],siz[N],d[N];

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
inline void Merge(int a,int b){
    a=Find(a),b=Find(b);if(a==b) return;
    if(siz[a]<siz[b]) swap(a,b);
    fa[b]=a;siz[a]+=siz[b];
}
inline void Init(){rep(i,1,n) fa[i]=i,siz[i]=1,d[i]=0;}
inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}
inline int inv(int x){return ksm(x,mod-2,mod);}
inline void FWT(int *f,int len,int op){
    for(int mid=1;mid<=(len>>1);mid<<=1)
        for(int l=0;l<len;l+=(mid<<1))
            for(int i=l;i<=l+mid-1;i++){
                int a=f[i],b=f[i+mid];
                if(op==0) f[i+mid]=inc(f[i+mid],a);
                else f[i+mid]=sub(f[i+mid],a);
            }
}
int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);read(p);
    rep(i,1,m){read(e[i].fi);read(e[i].se);}
    rep(i,1,n){read(w[i]);}
    len=(1<<n);
    rep(i,0,len-1) cn[i]=cn[i>>1]+(i&1);
    rep(i,0,len-1){
        rep(j,0,n-1){
            if((i>>j)&1) sum[i]+=w[j+1];
        }
        sum[i]=ksm(sum[i],p,mod);
    }
    vis[0]=1;
    rep(i,1,len-1){
        Init();
        rep(j,1,m){
            if(((i>>(e[j].fi-1))&1)&&((i>>(e[j].se-1))&1)){
                d[e[j].fi]++,d[e[j].se]++,Merge(e[j].fi,e[j].se);
            }
        }
        // if(!i){vis[i]=1;continue;}
        int now=-1;rep(j,0,n-1) if((i>>j)&1){now=j;break;}
        int fan=Find(now+1);
        if(siz[fan]!=cn[i]){vis[i]=1;continue;}
        int cnt=0;
        rep(j,1,n){
            cnt+=(d[j]&1);
        }
        if(cnt){vis[i]=1;continue;}
        vis[i]=0;
    }
    rep(i,0,len-1) h[cn[i]][i]=sum[i]*vis[i];
    rep(i,0,len-1) in[i]=inv(sum[i]);
    rep(i,0,n) FWT(h[i],len,0);
    f[0][0]=1;FWT(f[0],len,0);
    rep(i,1,n){
        rep(j,0,i-1) rep(k,0,len-1) f[i][k]=inc(f[i][k],mul(f[j][k],h[i-j][k]));
        FWT(f[i],len,1);
        // rep(j,0,len-1) f[i][j]=mul(f[i][j],in[j]);
        // rep(j,0,len-1) if(cn[j]!=i) f[i][j]=0;
        rep(j,0,len-1) f[i][j]=(cn[j]==i)?mul(f[i][j],in[j]):0;
        if(i!=n) FWT(f[i],len,0);
    }
    printf("%d\n",f[n][len-1]);
    return 0;
}
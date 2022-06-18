#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) (1ll*(a)*(b)%mod)
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 53
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

int c[N][N],coef[N],per[N][N],n,root,dep[N],high[N],siz[N],ans,f[N][N];

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

inline bool Check(int k,int fa,int d){
    if(d==0) return k==root;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;if(to!=fa&&!Check(to,k,d-1)) return 0;
    }
    return 1;
}

inline void dfs(int k,int fa,int d){
    siz[k]=1;dep[k]=d;high[k]=0;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        dfs(to,k,d+1);siz[k]+=siz[to];
        cmax(high[k],high[to]+1);
    }
    // printf("spe %d\n",Check(3,1,dep[3]-1));
    // printf("k=%d fa=%d dep[k]=%d\n",k,fa,dep[k]);
    if(k==root||Check(fa,k,dep[k]-1)){
        f[0][0]=f[1][1]=1;siz[k]=1;
        for(int x=head[k];x;x=li[x].next){
            int to=li[x].to;if(to==fa) continue;
            dec(i,1,siz[k]){
                rep(j,1,siz[to])
                    f[i+j][1]=inc(f[i+j][1],1ll*inc(f[i][1],f[i][0])*per[siz[to]][j]%mod*c[i+j][j]%mod);
                if(k!=root&&dep[k]<=high[to]+1) f[i][1]=f[i][0]=0;
            }
            if(f[0][0]) rep(j,1,siz[to]) f[j][0]=inc(f[j][0],per[siz[to]][j]);
            if(k!=root&&dep[k]<=high[to]+1) f[0][0]=0;
            siz[k]+=siz[to];
        }
        // printf("k=%d\n",k);
        // printf("root=%d\n",root);
        rep(i,1,siz[k]){
            ans=inc(ans,mul(coef[i],f[i][1]));
            // printf("f[%d][1]=%d\n",i,f[i][1]);
        }
        // printf("nowans=%d\n",ans);
        rep(i,0,siz[k]) f[i][0]=f[i][1]=0;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,2,n){
        int fat;read(fat);fat++;Add(fat,i);Add(i,fat);
    }
    rep(i,0,n)rep(j,0,i)if(j==0||j==i)c[i][j]=1;else c[i][j]=inc(c[i-1][j],c[i-1][j-1]);
    rep(i,0,n){
        per[i][0]=1;rep(j,0,i-1) per[i][j+1]=mul(per[i][j],i-j);
    }
    coef[n]=n;coef[n-1]=sgn(1);
    dec(i,1,n-2) coef[i]=mul(coef[i+1],n-i);
    rep(i,1,n){
        root=i;dfs(i,0,0);
    }
    printf("%d\n",ans);
    return 0;
}
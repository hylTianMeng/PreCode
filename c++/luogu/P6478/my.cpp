#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 5010
#define M 5010
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}
template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,f[N][M],a[N],Size[N],Cnt[N][2],Jie[N],Invjie[N],g[N],h[N];
char s[N];

inline void Init(){
    read(n);m=n>>1;
    scanf("%s",s+1);
    for(int i=1;i<n;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    for(int i=1;i<=n;i++) a[i]=s[i]-'0';
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1){res=1ll*res*a%mod;}a=1ll*a*a%mod;b>>=1;}return res;}

inline void Merge(int *f,int s1,int *g,int s2){
    for(int i=Min(s1+s2,m);i>=0;i--){
        h[i]=0;
        for(int j=Min(s1,i);j>=Max(i-s2,0);j--){
            h[i]=(h[i]+1ll*f[j]*g[i-j]%mod)%mod;
        }
    }
    for(int i=Min(s1+s2,m);i>=0;i--) f[i]=h[i];
}

inline void Dfs(int k,int fa){
    Size[k]=1;f[k][0]=1;
    int i=0;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs(to,k);Merge(f[k],Min(Size[k]>>1,m),f[to],Min(Size[to]>>1,m));
        // printf("to=%d\n",to);
        Size[k]+=Size[to];
        Cnt[k][0]+=Cnt[to][0];Cnt[k][1]+=Cnt[to][1];i++;
        // printf("i:%d to:%d f[%d]=\n",i,to,k);
        // for(int i=0;i<=m;i++) printf("%d ",f[k][i]);puts("");
    }
    int now=a[k];
    if(Cnt[k][now^1]!=0){
        for(int i=Min(Size[k]>>1,m);i>=1;i--) f[k][i]=(f[k][i]+1ll*f[k][i-1]*(Cnt[k][now^1]-i+1)%mod);
    }
    Cnt[k][a[k]]++;
    // printf("f[%d]=\n",k);
    // for(int i=0;i<=m;i++) printf("%d ",f[k][i]);puts("");
}

inline int sgn(int k){return (k&1)?(mod-1):1;}

inline void PreWork(){
    Jie[0]=1;Invjie[0]=1;
    for(int i=1;i<=n;i++){Jie[i]=1ll*Jie[i-1]*i%mod;Invjie[i]=1ll*Invjie[i-1]*ksm(i,mod-2,mod)%mod;}
}

inline int C(int n,int m){
    if(n<m) return 0;return 1ll*Jie[n]*Invjie[m]%mod*Invjie[n-m]%mod;
}

inline void Solve(){
    for(int i=0;i<=m;i++) f[1][i]=1ll*f[1][i]*Jie[m-i]%mod;
    for(int i=0;i<=m;i++){
        for(int j=i;j<=m;j++){
            g[i]=(g[i]+1ll*C(j,i)*sgn(j-i)%mod*f[1][j]%mod)%mod;
        }
    }
}

inline void Print(){
    for(int i=0;i<=m;i++) printf("%d\n",g[i]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dfs(1,0);PreWork();Solve();Print();
    return 0;
}
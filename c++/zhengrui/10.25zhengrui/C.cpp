#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3010
#define M number
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

template<typename T> inline void Write(T x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) Write(x/10);
    putchar((x%10)^48);
}

vector<int> v[N];

int n,a[N],f[N],ans[N][N],fenmu[N],rat[N],len,inv[N],m,g[N];
ll RatSum[N];

inline void Dfs1(int k,int fa,int x){
    f[k]=1ll*a[k]*x%mod;
    for(int i=0;i<v[k].size();i++){
        int to=v[k][i];
        if(to==fa) continue;
        g[to]=f[k];
        Dfs1(to,k,x);
        f[k]=1ll*f[k]*(f[to]+1)%mod;
    }
}

inline void Dfs2(int k,int fa,int x){
    f[k]=1;
    for(int i=v[k].size()-1;i>=0;i--){
        int to=v[k][i];
        if(to==fa) continue;
        g[to]=1ll*g[to]*f[k]%mod;
        Dfs2(to,k,x);
        f[k]=1ll*f[k]*(f[to]+1)%mod;
    }
    f[k]=1ll*f[k]*a[k]%mod*x%mod;
}

inline void Calc(int k,int fa,int x){
    g[k]=1ll*g[k]*(g[fa]+1)%mod;
    ans[k][x]=1ll*(g[k]+1)*f[k]%mod;
    // printf("ans[%d][%d]=%d\n",k,x,ans[k][x]);
    for(int i=0;i<v[k].size();i++){
        int to=v[k][i];
        if(to==fa) continue;
        Calc(to,k,x);
    }
}

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        v[from].push_back(to);v[to].push_back(from);
    }
    inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    // for(int i=1;i<=n;i++){printf("inv[%d]=%d\n",i,inv[i]);}
}

inline void Dp(){
    for(int x=0;x<=n;x++){
        Dfs1(1,0,x);Dfs2(1,0,x);Calc(1,0,x);
    }
}

inline void Add(int a){
    len++;
    for(int i=len;i>=1;i--){
        rat[i]=(1ll*rat[i]*a+(ll)rat[i-1])%mod;
    }
    // assert(rat[0]);
}

inline void Del(int a){
    for(int i=1;i<=len;i++){
        rat[i]=1ll*((rat[i]-rat[i-1]))*(mod-inv[mod-a])%mod;
    }
    rat[len]=0;
    len--;
}

inline void Lagrange(){
    for(int i=0;i<=n;i++){
        fenmu[i]=1;
        for(int j=0;j<=n;j++){
            if(i==j) continue;
            fenmu[i]=1ll*fenmu[i]*((i-j)>0?inv[i-j]:(mod-inv[j-i]))%mod;
        }
    }
    rat[0]=1;
    Add(mod);rat[0]=0;
    for(int i=1;i<=n;i++) Add(mod-i);
    for(int j=m;j>=0;j--) RatSum[0]=RatSum[0]+rat[j];
    RatSum[0]%=mod;
    for(int i=1;i<=n;i++){
        Del(mod-i);
        for(int j=m;j>=0;j--) RatSum[i]=(RatSum[i]+rat[j]);
        RatSum[i]%=mod;
        Add(mod-i); 
    }
    for(int i=1;i<=n;i++){
        ll Ans=0;
        for(int j=0;j<=n;j++){
            Ans=(Ans+1ll*ans[i][j]*RatSum[j]%mod*fenmu[j]%mod);
        }
        Ans=(Ans%mod+mod)%mod;
        Write(Ans);putchar(' ');
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dp();Lagrange();
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

struct Matrix{
    int a[2][2];
    inline void Clear(){memset(a,0,sizeof(a));}
    inline Matrix operator * (const Matrix &b)const{
        Matrix c;c.Clear();
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++) c.a[i][j]=(c.a[i][j]+1ll*a[i][k]*b.a[k][j]%mod)%mod;
        return c;
    }
}ma[N],E;

inline int Frac(int a,int b){
    return 1ll*a*ksm(b,mod-2,mod)%mod;
}

int p[N],q[N],t[N],n,rd[N];
bool vis[N];

queue<int> qu;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        int a,b;read(a);read(b);
        p[i]=Frac(a,b);
    }
    for(int i=1;i<=n;i++){read(t[i]);rd[t[i]]++;}
    for(int i=1;i<=n;i++){
        int a,b;read(a);read(b);
        q[i]=Frac(a,b);
    }
}

inline void Bfs(){
    for(int i=1;i<=n;i++) if(!rd[i]) qu.push(i);
    while(qu.size()){
        int top=qu.front();qu.pop();
        vis[top]=1;
        rd[t[top]]--;if(!rd[t[top]]) qu.push(t[top]);
        p[t[top]]=(1-1ll*(1-1ll*p[t[top]])*(1-1ll*p[top]*q[top]%mod)%mod)%mod;
    }
}

inline Matrix Dfs(int k,Matrix val){
    if(vis[k]) return E;vis[k]=1;
    Matrix now=ma[k]*Dfs(t[k],val*ma[k]);
    p[k]=(now*val).a[1][0];return now;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    // cout<<(ll)1ll*11*ksm(16,mod-2,mod)%mod;
    Init();Bfs();
    for(int i=1;i<=n;i++){
        ma[i].a[0][0]=1ll*(1-(ll)p[t[i]])*q[i]%mod;
        ma[i].a[0][1]=0;ma[i].a[1][1]=1;
        ma[i].a[1][0]=p[t[i]];
    }E.a[0][0]=E.a[1][1]=1;
    for(int i=1;i<=n;i++) if(!vis[i]) Dfs(i,E);
    for(int i=1;i<=n;i++){
        printf("%lld ",(p[i]%mod+mod)%mod);
    } 
    return 0;
}
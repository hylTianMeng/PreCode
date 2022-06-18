#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20
#define M 2000
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

int tt,w[N],t,k,Pow[N];
int g[N][M],f[N][M];

ll L,R;

//num
inline int G(int p,int S,int lim,int pre){
    if(__builtin_popcountll(S)>k) return 0;
    if(p==0) return 1;
    if(!lim&&!pre&&g[p][S]!=-1) return g[p][S];
    int up=(lim==1)?w[p]:9,ans=0;
    for(int i=1;i<=up;i++){
        (ans+=G(p-1,S|(1<<i),lim&&(i==up),0))%=mod;
    }
    if(pre){(ans+=G(p-1,S,0,1))%=mod;}
    else{(ans+=G(p-1,S|1,lim&&(up==0),0))%=mod;}
    if(!lim&&!pre) g[p][S]=ans;
    return ans;
}

//sum
inline int F(int p,int S,int lim,int pre){
    if(__builtin_popcountll(S)>k) return 0;
    if(p==0) return 0;
    if(!lim&&!pre&&f[p][S]!=-1) return f[p][S];
    int up=(lim==1)?w[p]:9,ans=0;
    for(int i=1;i<=up;i++){
        (ans+=(1ll*i*Pow[p-1]%mod*G(p-1,S|(1<<i),lim&&(i==up),0)%mod+F(p-1,S|(1<<i),lim&&(i==up),0))%mod)%=mod;
    }
    // printf("ans=%lld\n",ans);
    if(pre){(ans+=F(p-1,S,0,1))%=mod;}
    else{(ans+=F(p-1,S|1,lim&&(up==0),0))%=mod;}
    if(!lim&&!pre) f[p][S]=ans;
    // printf("p=%lld S=%lld lim=%lld pre=%lld ans=%lld\n",p,S,lim,pre,ans);
    return ans;
}

inline int Work(ll k){
    t=0;
    while(k){
        w[++t]=k%10;k/=10;
    }
    return F(t,0,1,1);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    memset(f,-1,sizeof(f));memset(g,-1,sizeof(g));
    Pow[0]=1;for(int i=1;i<=18;i++) Pow[i]=1ll*Pow[i-1]*10%mod;
    read(L);read(R);read(k);
    // printf("%lld\n",Work(R));
    // printf("%lld\n",Work(L-1));
    printf("%d\n",((Work(R)-Work(L-1))%mod+mod)%mod);
    return 0;
}
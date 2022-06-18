#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int lowbit(int x){return x&(-x);}

int lg2[1<<N],Cnt[1<<N],Pre[N],Next[N],n,m,g[1<<N],f[1<<N],Pow[N*N];

inline int sgn(int a){if(a&1) return -1;return 1;}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    //点的编号是 0 到 n-1
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        from--;to--;
        Pre[to]|=(1<<from);Next[from]|=(1<<to);
    }
    lg2[0]=-1;Pow[0]=1;
    for(int i=1;i<1<<N;i++) lg2[i]=lg2[i>>1]+1;
    for(int j=1;j<1<<N;j++) Cnt[j]=Cnt[j>>1]+(j&1);
    for(int i=1;i<=m;i++) Pow[i]=1ll*Pow[i-1]*2%mod;
    f[0]=1;
    for(int S=1;S<1<<n;S++){
        // printf("S=%d\n",S);
        for(int R=S&(S-1);;R=S&(R-1)){
            int T=S-R,lb=lowbit(T);
            //我们这里枚举 R=S-T
            //从大到小枚举 R，就是从小到大枚举 T。
            g[T]=g[T-lb]-Cnt[Pre[lg2[lb]]&T]+Cnt[Next[lg2[lb]]&R];
            // printf("g[%d]=g[%d]-Cnt[Pre[%d]&%d]+Cnt[Next[%d]&%d]\n",T,T-lowbit(T),lg2[lowbit(T)]+1,T,lg2[lowbit(T)]+1,R);
            // printf("%d=%d-%d+%d\n",g[T],g[T-lowbit(T)],Cnt[Pre[lg2[lowbit(T)]]&T],Cnt[Next[lg2[lowbit(T)]]&R]);
            // printf("g[%d]=%d\n",T,g[T]);
            f[S]=(f[S]+1ll*sgn(Cnt[T]-1)*Pow[g[T]]*f[R]%mod)%mod;
            if(!R) break;
        }
        // printf("f[%d]=%d\n",S,f[S]);
    }
    printf("%lld\n",((Pow[m]-f[(1<<n)-1])%mod+mod)%mod);
    return 0;
}
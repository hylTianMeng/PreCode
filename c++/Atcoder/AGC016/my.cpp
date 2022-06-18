#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 23
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

int n,m;
int e[N][N],f[N][1<<N],g[1<<N],p[N*N];
int h[1<<N];

inline void PreWork(){
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            for(int k=0;k<n;k++){
                if(!((j>>k)&1)||!e[i][k]) continue;
                f[i][j]++;
            }
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if((((i>>j)&1)&&((i>>k)&1))&&e[j][k]) g[i]++;
    p[0]=1;
    for(int i=1;i<=400;i++) p[i]=1ll*p[i-1]*2%mod;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        from--;to--;
        e[from][to]=1;
    }
    PreWork();
    h[3]=1;
    for(int s=4;s<(1<<n);s++){

        if((s&3)!=3) continue;
        h[s]=1;
        // printf("S=%d\n",s);
        for(int t=s&(s-1);t;t=s&(t-1)){
            int st=s^t;
            if((t&3)!=3&&(st&3)!=3) continue;
            // printf("t=%d\n",t);
            // printf("st=%d\n",st);
            if((t&3)==3){
                int now=1;
                for(int i=0;i<n;i++) if((s>>i)&1){
                    if((t>>i)&1) now=1ll*now*(p[f[i][st]]-1)%mod;
                    else now=1ll*now*p[f[i][t]]%mod;
                }
                    
                // printf("now=%d\n",now);
                h[s]=(h[s]+1ll*h[t]*now%mod)%mod;
            }
            else{
                int now=1;
                for(int i=0;i<n;i++) if((s>>i)&1){
                    if((t>>i)&1) now=1ll*now*(p[f[i][st]]-1)%mod*(p[f[i][t]])%mod;
                    else now=1ll*now*p[f[i][t]]%mod;
                }

                h[s]=(h[s]+1ll*now)%mod;
            }
        }
        // printf("h[%d]=%d\n",s,h[s]);
    }
    // printf("%d\n",h[(1<<n)-1]);
    printf("%d\n",((p[m]-h[(1<<n)-1])%mod+mod)%mod);
    return 0;
}
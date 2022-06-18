#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
#define M 210
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

int F[N],G[N],n,k,p,h[N];

inline void PreWork(int n){
    int b=sqrt(n);
	F[0]=G[0]=1;
	for(int i=1,p;i<=b;i++){
		p=i*i;
		for(int tt=1;tt<=2;tt++)
		    for(int j=i;j+p<=n;j++)
                F[j]=(F[j]+F[j-i])%mod;
		for(int j=p;j<=n;j++)
            G[j]=(G[j]+F[j-p])%mod;
	}
}

namespace Subtask1{
    int f[2][M][M],g[2][M][M],Ans;
    inline void Solve(){
        for(int i=1;i<=n;i++){
            f[1][i][i]=1;
            g[1][i][i]=1;
            for(int j=i+1;j<=n;j++) g[1][i][j]=1;
        }
        Ans=g[1][n][n]*h[1%p];
        for(int i=2;i<=n;i++){
            for(int j=(1+(i-1)*k-k+1)*(i-2)/2;j<=n;j++)
                for(int q=(i-1)*k+1;q<=n;q++){
                    f[i&1][j][q]=g[i&1][j][q]=0;
                }
            for(int j=(1+i*k-k+1)*(i-1)/2;j<=n;j++){
                for(int q=i*k+1;q<=n;q++){
                    (f[i&1][j][q]+=g[(i-1)&1][j-q][q-k])%=mod;
                    (g[i&1][j][q]=g[i&1][j][q-1]+f[i&1][j][q])%=mod;
                    // printf("f[%d][%d][%d]=%d\n",i,j,q,f[i][j][q]);
                }
            }
            Ans=(Ans+g[i&1][n][n]*h[i%p])%mod;
        }
        printf("%d\n",Ans);
    }
}

namespace Subtask2{
    inline void Solve(){
        PreWork(n);
        int Ans=G[n]*h[1%p];
        printf("%d\n",Ans);
    }
}

namespace Subtask3{
    inline void Solve(){
        int Ans=1*h[1%p];
        for(int i=1;i<=n;i++){
            int a=i,b=n-i;
            if(b-a<k) break;
            (Ans+=h[2%p])%=mod;
        }
        printf("%d\n",Ans);
    }
}


int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);read(k);read(p);for(int i=0;i<=p-1;i++) read(h[i]);
    if(n<=200){Subtask1::Solve();return 0;}
    if(3*k>=n){Subtask3::Solve();return 0;}
    if(k==0&&p==1){Subtask2::Solve();return 0;}
    if(n<=5000){Subtask1::Solve();return 0;}
    return 0;
}
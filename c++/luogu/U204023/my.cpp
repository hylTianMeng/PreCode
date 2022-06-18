#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
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

int f[N][N],n,ans1,ans2;
char s[N][N];
bool v1[N][N],v2[N][N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i+=2)
        for(int j=1;j<=n;j+=2){
            if(s[i][j+1]=='.') v1[i/2+1][j/2+1]=1;
            if(s[i+1][j]=='.') v2[i/2+1][j/2+1]=1;
        }
    // printf("%d\n",v2[1][1]);
    f[0][1]=1;
    for(int j=1;j<=n/2+1;j++){
        for(int i=1;i<=n/2+1;i++){
            f[i][j]=(f[i][j-1]+f[i-1][j])%mod;
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
        int w=-1;
        for(int i=n/2;i>=1;i--){
            if(v1[i][j]){w=i;break;}
        }
        // printf("w=%d\n",w);
        if(w!=-1) for(int i=w;i>=1;i--)f[i][j]=0;
        w=-1;
        for(int i=1;i<=n/2;i++){
            if(v2[i][j]){w=i;break;}
        }
        // printf("w=%d\n",w);
        if(w!=-1) for(int i=w+1;i<=n/2+1;i++) f[i][j]=0;
    }
    ans1=f[n/2+1][n/2+1];
    // printf("%d\n",ans1);

    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    memset(f,0,sizeof(f));

    for(int i=1;i<=n;i+=2)
        for(int j=1;j<=n;j+=2){
            if(s[i][j]=='.'){
                v1[i/2+1][j/2+1]=1;
                // printf("Must %d %d\n",i/2+1,j/2+1);
            }
            if(s[i+1][j+1]=='.'){
                v2[i/2+1][j/2+1]=1;
                // printf("Ban %d %d\n",i/2+1,j/2+1);
            }
        }
    f[n/2+2][1]=1;
    for(int j=1;j<=n/2+1;j++){
        for(int i=n/2+1;i>=1;i--){
            f[i][j]=(f[i+1][j]+f[i][j-1])%mod;
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
        int w=-1;
        for(int i=n/2;i>=1;i--){
            if(v1[i][j]){w=i;break;}
        }
        // printf("w=%d\n",w);
        if(w!=-1) for(int i=w;i>=1;i--) f[i][j]=0;
        w=-1;
        for(int i=1;i<=n/2;i++){
            if(v2[i][j]){w=i;break;}
        }
        // printf("w=%d\n",w);
        if(w!=-1) for(int i=w+1;i<=n/2+1;i++) f[i][j]=0;
    }
    ans2=f[1][n/2+1];
    // printf("%d\n",ans2);

    printf("%d\n",1ll*ans1*ans2%mod);
    return 0;
}
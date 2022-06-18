#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 140
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

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int R,a[5],p[5],tot,invp2,len,Ans;
int vis[N][N],v[N][N];
int b[N][N][N],c[N],d[N][N],tail,ans[N];

inline void calc(int x,int y){
    // printf("x=%d y=%d\n",x,y);
    for(int i=1;i<=len+1;i++) c[i]=0;
    if(x-1>=0&&y+1<=2*R) for(int j=1;j<=len+1;j++) c[j]=(c[j]-1ll*b[x-1][y+1][j]*p[1]%mod)%mod;
    if(y+1<=2*R) for(int j=1;j<=len+1;j++) c[j]=(c[j]+1ll*b[x][y+1][j]%mod)%mod;
    if(y+2<=2*R) for(int j=1;j<=len+1;j++) c[j]=(c[j]-1ll*b[x][y+2][j]*p[4]%mod)%mod;
    if(x+1<=2*R&&y+1<=2*R) for(int j=1;j<=len+1;j++) c[j]=(c[j]-1ll*b[x+1][y+1][j]*p[3]%mod)%mod;
    c[len+1]--;
    for(int j=1;j<=len+1;j++) c[j]=1ll*c[j]*invp2%mod;
    for(int j=1;j<=len+1;j++) b[x][y][j]=c[j];
}

inline void calc2(int x,int y){
    tail++;
    for(int i=1;i<=len+1;i++) c[i]=b[x][y][i];
    if(x-1>=0) for(int j=1;j<=len+1;j++) c[j]=(c[j]-1ll*b[x-1][y][j]*p[1]%mod)%mod;
    if(y+1<=2*R) for(int j=1;j<=len+1;j++) c[j]=(c[j]-1ll*b[x][y+1][j]*p[4]%mod)%mod;
    if(x+1<=2*R) for(int j=1;j<=len+1;j++) c[j]=(c[j]-1ll*b[x+1][y][j]*p[3]%mod)%mod;
    c[len+1]--;
    for(int i=1;i<=len+1;i++) d[tail][i]=c[i];
}


inline void Guass(){

    // for(int i=1;i<=len;i++){
    //     for(int j=1;j<=len+1;j++) printf("%d ",d[i][j]);
    //     puts("");
    // }

    for(int i=1;i<=len;i++) d[i][len+1]*=-1;

    for(int i=1;i<=len;i++){
        for(int j=i+1;j<=len+1;j++){
            int now=1ll*d[j][i]*ksm(d[i][i],mod-2,mod)%mod;
            for(int k=1;k<=len+1;k++) (d[j][k]-=1ll*now*d[i][k]%mod)%=mod;
        }
    }

    // printf("Guass:\n");
    // for(int i=1;i<=len;i++){
    //     for(int j=1;j<=len+1;j++) printf("%d ",d[i][j]);
    //     puts("");
    // }

    for(int i=len;i>=1;i--){
        int now=d[i][len+1];
        for(int j=len;j>=i+1;j--){
            (now-=1ll*d[i][j]*ans[j]%mod)%=mod;
        }
        ans[i]=1ll*now*ksm(d[i][i],mod-2,mod)%mod;
    }
}

inline void PreWork(){
    read(R);for(int i=1;i<=4;i++) read(a[i]);
    int sum=0;for(int i=1;i<=4;i++) sum+=a[i];
    for(int i=1;i<=4;i++){
        p[i]=1ll*a[i]*ksm(sum,mod-2,mod)%mod;
    }
    len=2*R+1;
    for(int i=-R;i<=R;i++)
        for(int j=R;j>=-R;j--)
            if(j*j+i*i<=R*R){vis[i+R][j+R]=++tot;break;}
    invp2=ksm(p[2],mod-2,mod);
    for(int i=R;i>=-R;i--)
        for(int j=-R;j<=R;j++){
            if(i*i+j*j>R*R) continue;
            if(vis[j+R][i+R]) b[j+R][i+R][vis[j+R][i+R]]=1;
            else calc(j+R,i+R);
        }
    // for(int i=R;i>=-R;i--)
    //     for(int j=-R;j<=R;j++){
    //         printf("x=%d y=%d\n",j,i);
    //         for(int k=1;k<=len+1;k++) printf("%d ",b[j+R][i+R][k]);
    //         puts("");
    //     }
    for(int i=-R;i<=R;i++)
        for(int j=-R;j<=R;j++)
            if(i*i+j*j<=R*R){
                calc2(i+R,j+R);
                break;
            }
    Guass();
    
    // puts("");for(int i=1;i<=len;i++) printf("%d ",ans[i]);puts("");

    for(int i=1;i<=len;i++) Ans=(Ans+1ll*b[R][R][i]*ans[i]%mod)%mod;
    (Ans+=b[R][R][len+1])%=mod;
    printf("%d\n",(Ans%mod+mod)%mod);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();return 0;
}
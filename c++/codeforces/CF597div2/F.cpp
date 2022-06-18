#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 40
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N][2][2];
int w1[N],w2[N],p1,p2,p,t,a,b;

inline int dfs(int posi,int lim1,int lim2){
    if(posi==0) return 1;
    int up1=(lim1==1)?w1[posi]:1;
    int up2=(lim2==1)?w2[posi]:1;
    if(f[posi][lim1][lim2]!=-1) return f[posi][lim1][lim2];
    int ans=0;
    // printf("up1=%d up2=%d\n",up1,up2);
    for(int i=0;i<=up1;i++){
        for(int j=0;j<=up2;j++){
            if(i==1&&j==1) continue;
            ans=ans+dfs(posi-1,lim1&&(i==up1),lim2&&(j==up2));
        }
    }
    // printf("posi=%d lim1=%d lim2=%d ans=%lld\n",posi,lim1,lim2,ans);
    f[posi][lim1][lim2]=ans;
    return ans;
}

inline int Solve(int a,int b){
    if(a<0||b<0) return 0;
    for(int i=1;i<=p;i++) w1[i]=w2[i]=0;
    memset(f,-1,sizeof(f));
    p1=p2=p=0;
    while(a){w1[++p1]=a&1;a>>=1;}
    while(b){w2[++p2]=b&1;b>>=1;}
    p=max(p1,p2);
    return dfs(p,1,1);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    memset(f,-1,sizeof(f));
    read(t);
    while(t--){
        read(a);read(b);
        // printf("%lld\n",Solve(b,b));
        // printf("%lld\n",Solve(b,a-1));
        printf("%lld\n",Solve(b,b)-Solve(b,a-1)-Solve(a-1,b)+Solve(a-1,a-1));
    }
    return 0;
}
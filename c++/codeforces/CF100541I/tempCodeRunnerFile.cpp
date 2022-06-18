#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int t,n,m,f[N][N][4][2];
char s[N][N];

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
}

inline void Solve(){
    memset(f,0,sizeof(f));
    // for(int i=1;i<=n;i++)
        // for(int j=1;j<=m;j++){
            // if(s[i][j]=='0') continue;
            // for(int k=0;k<=3;k++) f[i][j][k][0]=f[i][j][k][1]=1;
        // }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i][j]=='0') continue;
            if(j+1<=m&&s[i][j+1]=='1') f[i][j][0][1]=f[i][j+1][1][0]+1;
            if(i-1>=1&&s[i-1][j]=='1') f[i][j][1][0]=f[i-1][j][0][1]+1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(s[i][j]=='0') continue;
            if(j+1<=m&&s[i][j+1]=='1') f[i][j][2][0]=f[i][j+1][1][1]+1;
            if(i+1<=n&&s[i+1][j]=='1') f[i][j][1][1]=f[i+1][j][2][0]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='0') continue;
            if(j-1>=1&&s[i][j-1]=='1') f[i][j][0][0]=f[i][j-1][3][1]+1;
            if(i-1>=1&&s[i-1][j]=='1') f[i][j][3][1]=f[i-1][j][0][0]+1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='0') continue;
            if(i+1<=n&&s[i+1][j]=='1') f[i][j][3][0]=f[i+1][j][2][1]+1;
            if(j-1>=1&&s[i][j-1]=='1') f[i][j][2][1]=f[i][j-1][3][0]+1;
        }
    }
    int ans=-INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='0') continue;
            int nowans=0;
            if(i-1>=1&&s[i-1][j]=='1') nowans+=f[i-1][j][0][1];
            if(i+1<=n&&s[i+1][j]=='1') nowans+=f[i+1][j][2][1];
            if(j-1>=1&&s[i][j-1]=='1') nowans+=f[i][j-1][3][1];
            if(j+1<=m&&s[i][j+1]=='1') nowans+=f[i][j+1][1][1];
            ans=Max(ans,nowans+5);
        }
    }
    printf("%d\n",ans);
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Solve();
    }
    return 0;
}
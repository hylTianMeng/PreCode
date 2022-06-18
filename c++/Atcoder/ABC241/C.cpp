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

char s[N][N],t[N];
int f[N][3],g[N][N][3],n;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[j][0]=f[j][1]=f[j][2]=0;
        int maxx=0;
        for(int j=1;j<=n;j++){
            if(s[i][j]=='#'){
                for(int k=0;k<=2;k++) f[j][k]=f[j-1][k]+1;
            }
            else{
                f[j][0]=0;
                for(int k=1;k<=2;k++) f[j][k]=max(0,f[j-1][k-1]+1);
            }
            maxx=max(max(maxx,f[j][0]),max(f[j][1],f[j][2]));
        }
        if(maxx>=6){puts("Yes");return 0;}
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[j][0]=f[j][1]=f[j][2]=0;
        int maxx=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='#'){
                for(int k=0;k<=2;k++) f[j][k]=f[j-1][k]+1;
            }
            else{
                f[j][0]=0;
                for(int k=1;k<=2;k++) f[j][k]=max(0,f[j-1][k-1]+1);
            }
            maxx=max(max(maxx,f[j][0]),max(f[j][1],f[j][2]));
        }
        if(maxx>=6){puts("Yes");return 0;}
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]=='#'){
                for(int k=0;k<=2;k++) g[i][j][k]=g[i-1][j-1][k]+1;
            }
            else{
                g[i][j][0]=0;
                for(int k=1;k<=2;k++) g[i][j][k]=max(0,g[i-1][j-1][k-1]+1);
            }
            for(int k=0;k<=2;k++) maxx=max(maxx,g[i][j][k]);
        }
    }
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++)
        for(int j=n;j>=1;j--){
            if(s[i][j]=='#'){
                for(int k=0;k<=2;k++) g[i][j][k]=g[i-1][j+1][k]+1;
            }
            else{
                g[i][j][0]=0;
                for(int k=1;k<=2;k++) g[i][j][k]=max(0,g[i-1][j+1][k-1]+1);
            }
            for(int k=0;k<=2;k++) maxx=max(maxx,g[i][j][k]);
        }
    if(maxx>=6){puts("Yes");}
    else puts("No");
    return 0;
}
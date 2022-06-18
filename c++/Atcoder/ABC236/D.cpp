#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 30
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

bool vis[N];
int n,Ans,a[N][N];

inline void dfs(int k,int sum){
    if(k==n+1){
        Ans=max(Ans,sum);return;
    }
    for(int i=1;i<=2*n;i++){
        if(vis[i]) continue;
        for(int j=i+1;j<=2*n;j++){
            if(vis[j]) continue;
            vis[i]=vis[j]=1;
            dfs(k+1,sum^a[i][j]);
            vis[i]=vis[j]=0;
        }
        break;
    }
}

int main(){
    read(n);
    for(int i=1;i<=2*n;i++){
        for(int j=i+1;j<=2*n;j++){
            read(a[i][j]);a[j][i]=a[i][j];
        }
    }
    dfs(1,0);
    printf("%d\n",Ans);
    return 0;
}
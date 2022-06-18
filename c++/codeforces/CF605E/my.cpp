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

int n;
ld p[N][N],p1[N],p2[N];

ld f[N];
int vis[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x;read(x);p[i][j]=1.0*x/100;
        }
    for(int i=1;i<=n;i++) p2[i]=1-p[i][n];
    for(int i=0;i<n;i++) f[i]=1;
    vis[n]=1;
    for(int i=1;i<=n;i++){
        int id=1;ld minn=INF;
        for(int j=1;j<=n;j++){
            if(vis[j]==1) continue;
            if(minn>f[j]/(1-p2[j])){
                minn=f[j]/(1-p2[j]);id=j;
            }
        }
        vis[id]=1;
        if(id==1){
            printf("%0.7Lf\n",f[1]/(1-p2[1]));return 0;
        }
        for(int j=1;j<=n;j++){
            f[j]+=f[id]/(1-p2[id])*p[j][id]*p2[j];
            p2[j]*=(1-p[j][id]);
        }
    }
    return 0;
}
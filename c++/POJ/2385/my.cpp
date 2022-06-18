#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
#define M 32
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;   char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int f[N][M][2],t,w,a,Ans;

inline void Init(){
    read(t);read(w);
}

inline void Update(int &a,int b){a=Max(a,b);}

inline void Solve(){
    memset(f,-1,sizeof(f));
    f[0][0][0]=0;
    for(int i=0;i<=t-1;i++){
        read(a);a--;
        for(int j=0;j<=w;j++){
            for(int k=0;k<=1;k++){
                if(f[i][j][k]==-1) continue;
                if(a==k){
                    Update(f[i+1][j][k],f[i][j][k]+1);
                    if(j!=w) Update(f[i+1][j+1][k^1],f[i][j][k]);
                }
                else{
                    Update(f[i+1][j][k],f[i][j][k]);
                    if(j!=w) Update(f[i+1][j+1][k^1],f[i][j][k]+1);
                }
            }
        }
    }
    for(int j=0;j<=w;j++)
        for(int k=0;k<=1;k++) Update(Ans,f[t][j][k]);
    printf("%d\n",Ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}
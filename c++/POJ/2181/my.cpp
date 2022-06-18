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
#define N 150100
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

int f[N][2],P,a[N];

inline void Init(){
    read(P);for(int i=1;i<=P;i++) read(a[i]);
}

inline void GMax(int &a,int b){a=Max(a,b);}

inline void Solve(){
    memset(f,-INF,sizeof(f));f[0][0]=0;
    for(int i=0;i<=P-1;i++){
        for(int j=0;j<=1;j++){
            if(f[i][j]==-1) continue;
            GMax(f[i+1][j],f[i][j]);
            if(j==0){
                GMax(f[i+1][j^1],f[i][j]+a[i+1]);
            }
            else{
                GMax(f[i+1][j^1],f[i][j]-a[i+1]);
            }
        }
    }
    // for(int i=0;i<=P;i++){
        // for(int j=0;j<=1;j++){
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        // }
    // }
    printf("%d\n",Max(f[P][0],f[P][1]));
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}
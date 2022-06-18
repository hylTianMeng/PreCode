// #include<bits/stdc++.h>
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
#define M 12010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

int f[N][M],n,m,a[N],b[N],Ans;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);read(b[i]);
    }
}

inline void Update(int &a,int b){a=Min(a,b);}

inline void Print(int a,int b,int c,int d,int op){
    printf("f[%d][%d]=%d <- f[%d][%d]=%d+%d\n",a,b-6000,f[a][b],c,d-6000,f[c][d],op);
}

inline void Solve(){
    memset(f,INF,sizeof(f));
    f[0][6000]=0;
    for(int i=0;i<=n-1;i++){
        // printf("i=%d\n",i);
        for(int j=-6*i+6000;j<=i*6+6000;j++){
            if(f[i][j]>n) continue;
            int cha=j-6000;
            Update(f[i+1][cha+a[i+1]-b[i+1]+6000],f[i][j]);
            // Print(i+1,cha+a[i+1]-b[i+1]+6000,i,j,0);
            Update(f[i+1][cha+b[i+1]-a[i+1]+6000],f[i][j]+1);
            // Print(i+1,cha+b[i+1]-a[i+1]+6000,i,j,1);
        }
    }
    for(int i=0;i<=6000;i++){
        if(f[n][i+6000]>n&&f[n][-i+6000]>n) continue;
        Ans=Min(f[n][i+6000],f[n][-i+6000]);
        // printf("i=%d\n",i);
        break;
    }
    printf("%d\n",Ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}
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
#define N 100010
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

int f[N],g[N],n,a[N];

inline void Init(){
    for(int i=1;i<=n;i++) read(a[i]);
}

inline void GMax(int &a,int b){a=Max(a,b);}

int Maxx=-INF,Ans=-INF;

inline void Solve(){
    f[1]=a[1];
    for(int i=2;i<=n;i++){
        f[i]=a[i];
        GMax(f[i],a[i]+f[i-1]);
    }
    g[n]=a[n];
    for(int i=n-1;i>=1;i--){
        g[i]=a[i];
        GMax(g[i],a[i]+g[i+1]);
    }
    Maxx=g[n];
    for(int i=n-1;i>=1;i--){
        Maxx=Max(Maxx,g[i+1]);
        GMax(Ans,Maxx+f[i]);
    }
    printf("%d\n",Ans);
} 

inline void Clear(){
    Maxx=-INF;Ans=-INF;
}

int main(){
    // freopen("my.in","r",stdin);
    while(scanf("%d",&n)!=EOF&&n){
        Init();Solve();Clear();
    }
    return 0;
}
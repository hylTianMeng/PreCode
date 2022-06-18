#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const dd eps=1e-5;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],b[N],g[N];
dd f[N];

inline bool Check(dd mid){
    f[0]=0;f[1]=(dd)a[1]-mid;
    for(int i=2;i<=n;i++) f[i]=max(f[i-1],f[i-2])+a[i]-mid;
    return max(f[n],f[n-1])>=0;
}

inline void Solve1(){
    dd l=1,r=1000000000;
    while(r-l>eps){
        dd mid=(l+r)/2;
        if(Check(mid)) l=mid;
        else r=mid;
    }
    printf("%0.4lf\n",l);return;
}

inline bool check(int mid){
    for(int i=1;i<=n;i++){
        if(a[i]<mid) b[i]=-1;else b[i]=1;
    }
    g[0]=0;g[1]=b[1];
    for(int i=2;i<=n;i++) g[i]=max(g[i-1],g[i-2])+b[i];
    return max(g[n],g[n-1])>0;
}

inline void Solve2(){
    int l=1,r=1000000000;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){l=mid;}
        else r=mid-1;
    }
    printf("%d\n",l);return;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    Solve1();Solve2();
    return 0;
}
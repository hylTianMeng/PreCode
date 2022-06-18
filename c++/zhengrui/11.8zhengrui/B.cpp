#include<bits/stdc++.h>
#include<iostream>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const dd eps=1e-4;
const dd eps2=1e-10;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int n,a[N],k;

struct BIT{
    int p[N];
    inline void Init(int n){
        for(int i=1;i<=n;i++) p[i]=-1;
    }
    inline int lowbit(int x){return x&(-x);}
    inline void Add(int w,int x){
        for(int i=w;i<=n;i+=lowbit(i)) p[i]=Max(x,p[i]);
    }
    inline int GetMax(int w){
        int res=-INF;
        for(int i=w;i;i-=lowbit(i)) res=Max(res,p[i]);return res;
    }
}bit;

inline void Init(){
    read(n);read(k);
    for(int i=1;i<=n;i++) read(a[i]);
}

int f[N],d[N];
dd b[N],c[N],rk[N];

inline bool Check(dd mid){
    bit.Init(n);
    // printf("mid=%lf\n",mid);
    for(int i=1;i<=n;i++) b[i]=1.0*a[i]-mid;
    // printf("b:");for(int i=1;i<=n;i++) printf("%lf ",b[i]);puts("");
    for(int i=1;i<=n;i++) b[i]+=b[i-1];   
    for(int i=1;i<=n;i++) c[i]=b[i];
    sort(c+1,c+n+1);int len=unique(c+1,c+n+1)-c-1;
    // printf("c:");for(int i=1;i<=n;i++) printf("%lf ",b[i]);puts("");
    for(int i=1;i<=n;i++){
        int Rank=lower_bound(c+1,c+len+1,b[i])-c;
        rk[Rank]=b[i];d[i]=Rank;
    }
    // printf("d:");for(int i=1;i<=n;i++) printf("%d ",d[i]);puts("");
    for(int i=1;i<=n;i++){
        if(b[i]>=0) f[i]=1;
        else{f[i]=-1;continue;}
        int Ans=bit.GetMax(d[i]);
        f[i]=Max(f[i],Ans+1);
        bit.Add(d[i],f[i]);
    }
    // printf("f:");for(int i=1;i<=n;i++) printf("%d ",f[i]);puts("");
    return f[n]>=k;
}

inline void Solve(){
    dd l=1,r=100;
    while(r-l>eps){
        // printf("%lf\n",l);
        dd mid=(l+r)/2;
        if(Check(mid)) l=mid;
        else r=mid;
    }
    printf("%0.3lf",l);
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();Solve();return 0;
}
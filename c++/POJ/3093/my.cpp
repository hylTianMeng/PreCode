#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 32
#define M 1010
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

int n,m,a[M],t,f[M],sum,now,Ans,g[M];

inline void Init(){
    read(n);read(m);sum=0;
    for(int i=1;i<=n;i++){
        read(a[i]);sum+=a[i];
    }
    fill(f,f+m+1,-INF);f[0]=1;Ans=0;
}

inline void Add(int k){
    for(int i=m-a[k];i>=0;i--){
        if(f[i]==-INF) continue;
        if(f[i+a[k]]<0) f[i+a[k]]=0;
        f[i+a[k]]+=f[i];
    }
}

inline void Solve(){
    sort(a+1,a+n+1);
    if(a[1]>m) return(void)(Ans=0);
    for(int i=n;i>=1;i--){
        sum-=a[i];now=m-sum;
        // printf("%lld\n",m-sum-a[i]+1);
        for(int j=Max(0ll,m-sum-a[i]+1);j<=now;j++){
            if(f[j]==-INF) continue;
            Ans+=f[j];
        }
        Add(i);
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    for(int i=1;i<=t;i++){
        Init();Solve();printf("%lld %lld",i,Ans);
        if(i!=t) puts("");
    }
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 5010
#define M number
using namespace std;

const int INF=1e8;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,n,a[N],sum[N],Ans[N],x;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(x);
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        fill(Ans,Ans+n+1,-INF);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                Ans[i-j+1]=max(Ans[i-j+1],sum[i]-sum[j-1]);
            }
        }
        for(int i=n-1;i>=0;i--) Ans[i]=max(Ans[i+1],Ans[i]);
        int ans=0;
        for(int i=0;i<=n;i++){
            ans=max(ans,Ans[i]+i*x);
            printf("%d ",ans);
        }
        puts("");
    }
}
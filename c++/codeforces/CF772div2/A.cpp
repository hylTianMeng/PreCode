#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 110
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

int t,n,a[N];
bool vis[40];

signed main(){
    read(t);
    while(t--){
        read(n);for(int i=1;i<=n;i++) read(a[i]);
        for(int j=0;j<=30;j++) vis[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=30;j>=0;j--){
                if((a[i]>>j)&1) vis[j]=1;
            }
        }
        int ans=0;
        for(int i=0;i<=30;i++) if(vis[i]) ans+=(1ll<<i);
        printf("%lld\n",ans);
    }
    return 0;
}
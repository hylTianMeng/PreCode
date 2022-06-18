#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int TwoPow(int x){return 1ll*x*x%mod;}

int n,T,a[N],b[N],c[N],d[N];
int li[N];
bool vis[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(T);
    for(int i=1;i<=n;i++){read(a[i]);c[i]=a[i];}
    for(int i=1;i<=n;i++){read(b[i]);d[i]=b[i];}
    sort(c+1,c+n+1);sort(d+1,d+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+TwoPow(c[i]-d[i]))%mod;
    }
    printf("%lld ",ans);
    if(T==0) exit(0);
    int len=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+len+1,a[i])-c;
    len=unique(d+1,d+n+1)-d-1;
    for(int i=1;i<=n;i++) b[i]=lower_bound(d+1,d+len+1,b[i])-d;
    for(int i=1;i<=n;i++){
        li[a[i]]=b[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        cnt++;int now=i;
        while(!vis[now]){
            vis[now]=1;now=li[now];
        }
    }
    printf("%d\n",n-cnt);
    return 0;
}
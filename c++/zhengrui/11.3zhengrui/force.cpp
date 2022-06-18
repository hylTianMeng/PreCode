#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 30
#define M 30
using namespace std;

const int INF=0x3f3f3f3f;
const int mod = 998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,x,ans,a[N],b[N],c[N];
bool vis[N];

void check(){
    int val=x;
    for(int i=n+m;i>=1;i--){
        if(c[i]>n) val=val%b[c[i]];
        if(c[i]<=n) val=val/a[c[i]];
    }
    if(val==0) ans++;
}
void dfs(int step){
    if(step==n+m+1){
        check();
        return;
    }
    for(int i=1;i<=n+m;i++){
        if(vis[i]) continue;
        c[step]=i;vis[i]=true;
        dfs(step+1);
        c[step]=0;vis[i]=false;
    }
}
signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(x);read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=n+1;i<=n+m;i++) read(b[i]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
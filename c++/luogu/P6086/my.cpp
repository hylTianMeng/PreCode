#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 5000100
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

int n,m,d[N];

namespace Subtask1{

    int k=INF,fa[N],p[N];

    inline void Solve(){
        for(int i=1;i<=n-1;i++){
            int x;read(x);
            d[x]++;d[i]++;fa[i]=x;
        }
        for(int i=1,j=1;i<=n-2;i++,j++){
            while(d[j]!=1) j++;p[i]=fa[j];d[j]--;d[fa[j]]--;
            while(i<=n-2&&d[p[i]]==1&&p[i]<j){p[i+1]=fa[p[i]];d[p[i]]--;d[fa[p[i]]]--;i++;}
        }
        int ans=0;
        for(int i=1;i<=n-2;i++) ans=(ans^(i*p[i]));
        printf("%lld\n",ans);
    }
}

namespace Subtask2{

    int fa[N],p[N],d[N];

    inline void Solve(){
        for(int i=1;i<=n-2;i++) read(p[i]),d[p[i]]++;
        p[n-1]=n;
        for(int i=1;i<=n;i++) d[i]++;
        for(int i=1,j=1;i<=n-1;i++,j++){
            while(d[j]!=1) j++;fa[j]=p[i];d[j]--;d[p[i]]--;
            while(i<=n-1&&d[p[i]]==1&&p[i]<j){fa[p[i]]=p[i+1];d[p[i]]--;d[fa[p[i]]]--;i++;}
        }
        int ans=0;
        for(int i=1;i<=n-1;i++) ans=(ans^(i*fa[i]));
        printf("%lld\n",ans);
    }
}

signed main(){
    read(n);read(m);
    if(m==1) Subtask1::Solve();else Subtask2::Solve();
    return 0;
} 
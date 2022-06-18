#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 150005
#define M number
using namespace std;

const ll INF=9223372036854775800;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

ll n,m,b[N],c[N],To[N],Mext[N];

void Check(){
    for(int i=1;i<=n;i++){c[i]=b[i],To[i]=Mext[i]=0;}
    sort(c+1,c+n+1);ll ans=0,lst=0;
    for(int i=1;i<=n;i++){
        if(c[i]<0) continue;
        if(c[i]>n) break;++To[c[i]];
    }
    ll tot0=0,nownxt=n;
    for(int i=n;i>=1;i--){
       if(To[i]) nownxt=i;
       Mext[i]=nownxt;
    }
    for(int i=1;i<=n;i++){
       if(To[i]==0)
          if(To[Mext[i]]>1) To[i]=1,--To[Mext[i]];
    }
    for(int i=1;i<=n;i++) if(To[i]==0) ++ans;
    printf("%lld\n",ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++) read(b[i]);
    for(int i=1;i<=m;i++){
        int x,k;
        read(x);read(k);
        if(x==0) for(int j=1;j<=n;j++) b[j]+=k;
        else b[x]=k;
        Check();
    }
    return 0;
}
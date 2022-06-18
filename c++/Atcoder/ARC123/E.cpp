#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 1000100
#define M number
using namespace std;

const int INF=1e18;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int Prime[N],tail,sum[N],n,a[N],f[N];
bool NotPrime[N];
int Len=1e6;

inline void LinearSieve(){
    for(int i=2;i<=Len;i++){
        if(!NotPrime[i]){Prime[++tail]=i;f[i]=i;}
        for(int j=1;j<=tail&&1ll*Prime[j]*i<=Len;j++){
            NotPrime[Prime[j]*i]=1;
            f[Prime[j]*i]=Prime[j];
            if(i%Prime[j]==0){
                break;
            }
        }
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    LinearSieve();
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        int l,r;
        if(i==1){l=1;r=n+1;}
        else if(i&1){
            l=max(0ll,i-f[i]+1);r=min(n+1,i+f[i]);
        }
        else{
            l=i;r=i+1;
        }
        // printf("i=%d\n",i);
        sum[l]+=a[i];sum[r]-=a[i];
        // printf("%d %d\n",l,r);
    }
    for(int i=1;i<=n+1;i++) sum[i]+=sum[i-1];
    int maxx=-INF;
    for(int i=0;i<=n+1;i++){
        // if(maxx==463){printf("i=%d\n",i);break;}
        maxx=max(maxx,sum[i]);
    }
    printf("%lld\n",maxx);
    return 0;
}
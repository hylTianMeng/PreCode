#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int Prime[N],tail;
bool NotPrime[N];

inline void GetPrime(){
    NotPrime[1]=1;
    for(int i=2;i<=1000000;i++){
        if(!NotPrime[i]) Prime[++tail]=i;
        for(int j=1;j<=tail&&1ll*Prime[j]*i<=1000000;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0) break;
        }
    }
}
int t;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);GetPrime();
    while(t--){
        int n;read(n);
        int val=1,now=1+n;
        for(int i=1;i<=2;i++){
            int Next=lower_bound(Prime+1,Prime+tail+1,now)-Prime;
            val*=Prime[Next];now=Prime[Next]+n;
        }
        printf("%lld\n",val);
    }
    return 0;
}
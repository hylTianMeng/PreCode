#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

int f[N],n,a[N];
typedef pair<int,int> P;
P Stack[N];int top,now,sg=1;

inline int sgn(int x){if(x&1) return -1;else return 1;}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    f[0]=1;
    for(int i=1;i<=n;i++){
        // printf("i=%d\n",i);
        int sum=0;
        while(top>0&&Stack[top].first>=a[i]){
            (now-=1ll*Stack[top].second*Stack[top].first%mod)%=mod;
            (sum+=Stack[top].second)%=mod;top--;
        }
        // printf("now=%d sum=%d\n",now,sum);
        Stack[++top]=make_pair(a[i],(sum+sg*f[i-1])%mod);
        (now+=1ll*Stack[top].first*Stack[top].second%mod)%=mod;
        // printf("now=%d\n",now);
        f[i]=1ll*now*sg%mod;sg*=(-1);
        // printf("f[%d]=%d\n",i,f[i]);
    }
    printf("%lld\n",(f[n]%mod+mod)%mod);
    return 0;
}
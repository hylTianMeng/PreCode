#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define sgn(a) (((a)&1)?(mod-1):1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 20
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

const ll INF=1e18;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

#define int long long

int t,n;
int jie[N];

inline int Cnt(int x){
    int w=0;while(x){w+=(x&1);x>>=1;}return w;
}

signed main(){
    jie[0]=1;rep(i,1,15) jie[i]=1ll*jie[i-1]*i;
    int nt=(1<<14)-1;
    read(t);
    while(t--){
        int n;read(n);
        int ans=INF;
        rep(i,0,nt){
            int sum=n;
            rep(j,0,13) if((i>>j)&1) sum-=jie[j+1];
            if(sum<0) continue;
            if((sum&1)&&(i&1)) continue;
            if(((i>>1)&1)&&((sum>>1)&1)) continue;
            ans=min(ans,Cnt(i)+Cnt(sum));
        }
        if(ans==INF) ans=-1;
        printf("%lld\n",ans);
    }
}
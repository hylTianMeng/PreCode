#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 100010
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

#define int long long

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,ans;
vector<P> v[N];



inline bool cmp(P a,P b){
    if(a.se!=b.se) return a.se<b.se;
    return a.fi<b.fi;
}

signed main(){
    read(n);read(m);
    rep(i,1,n)rep(j,1,m){
        int x;read(x);
        v[x].push_back(mp(i,j));
    }
    rep(i,1,100000) sort(v[i].begin(),v[i].end());
    rep(i,1,100000){
        int sum=0;
        for(int j=0;j<v[i].size();j++){
            if(j!=0){
                ans=ans+v[i][j].fi*j-sum;
            }
            sum+=v[i][j].fi;
        }
    }
    rep(i,1,100000) sort(v[i].begin(),v[i].end(),cmp);
        rep(i,1,100000){
        int sum=0;
        for(int j=0;j<v[i].size();j++){
            if(j!=0) ans=ans+v[i][j].se*j-sum;
            sum+=v[i][j].se;
        }
    }
    printf("%lld\n",ans);
    // return 0;
}
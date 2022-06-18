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
//#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int len,posi[N],n,m,a[N],ans[N],nowans,cnt[N];
vi v[N];

struct Ques{
    int l,r,id;
    inline bool operator < (const Ques &b)const{
        if(posi[l]==posi[b.l]) return r<b.r;
        else return l<b.l;
    }
}qu[N];

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

inline void Add(int x){
    x=a[x];
    int nc=cnt[x];if(nc==0) nowans++;
    nowans=inc(nowans,1ll*(x-1)*v[x][nc]%mod);
    cnt[x]++;
}

inline void Del(int x){
    x=a[x];
    int nc=cnt[x];nowans=sub(nowans,1ll*(x-1)*v[x][nc-1]%mod);cnt[x]--;
    if(nc==1) nowans--;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n) read(a[i]);len=sqrt(n)+1;
    rep(i,1,n){
        if(!v[a[i]].size()) v[a[i]].pb(1);
        int now=v[a[i]][(int)v[a[i]].size()-1];
        now=mul(now,a[i]);v[a[i]].pb(now);
    }
    rep(i,1,n) posi[i]=(i-1)/len+1;
    rep(i,1,m){
        read(qu[i].l);read(qu[i].r);qu[i].id=i;
    }
    sort(qu+1,qu+m+1);
    int l=1,r=0;
    rep(i,1,m){
        // printf("%d %d %d\n",qu[i].l,qu[i].r,qu[i].id);
        while(l>qu[i].l) Add(--l);
        while(r<qu[i].r) Add(++r);
        while(l<qu[i].l) Del(l++);
        while(r>qu[i].r) Del(r--);
        ans[qu[i].id]=nowans;
    }
    rep(i,1,m) printf("%d\n",ans[i]);
    return 0;
}
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
#define N 1000100
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

#define int long long

int n,a[N],q,ans[N],cnt[N],nowans;
int sq;

struct query 
{
    int l, r, id;
    inline bool operator<(const query &o) const
    {
        if (l / sq != o.l / sq) 
            return l < o.l;
        if (l / sq & 1)
            return r < o.r;
        return r > o.r;
    }
} Q[N];

inline void Add(int id){
    nowans-=cnt[a[id]]/2;
    cnt[a[id]]++;
    nowans+=cnt[a[id]]/2;
}

inline void Del(int id){
    nowans-=cnt[a[id]]/2;
    cnt[a[id]]--;
    nowans+=cnt[a[id]]/2;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);rep(i,1,n) read(a[i]);
    read(q);sq=sqrt(q)+1;
    rep(i,1,q){
        read(Q[i].l);read(Q[i].r);Q[i].id=i;
    }
    sort(Q+1,Q+q+1);
    int l=0,r=-1;
    rep(i,1,q){
        while(l>Q[i].l) Add(--l);
        while(r<Q[i].r) Add(++r);
        while(l<Q[i].l) Del(l++);
        while(r>Q[i].r) Del(r--);
        ans[Q[i].id]=nowans;
    }
    rep(i,1,q) printf("%lld\n",ans[i]);
    return 0;
}
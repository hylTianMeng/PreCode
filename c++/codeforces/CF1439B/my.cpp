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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int d[N],n,m,k,t;
vi e[N];

struct Node{
    int id,val;
    inline Node(){}
    inline Node(int id,int val):id(id),val(val) {}
    inline bool operator < (const Node &b)const{
        return val<b.val;
    }
};

bool vis[N];
vi v,ans,a;
queue<int> q;

inline bool Check(int id){
    v.clear();
    for(int to:e[id]){
        // if(vis[to]) continue;
        if(d[to]<k-1) continue;
        v.pb(to);
    }
    v.pb(id);
    if(v.size()<k) return 0;
    assert(v.size()==k);
    bool op=1;
    rep(i,0,k-1){
        rep(j,0,k-1){
            if(i==j) continue;
            auto it=lower_bound(e[v[i]].begin(),e[v[i]].end(),v[j]);
            if(it==e[v[i]].end()||(*it)!=v[j]){op=0;break;}
        }
        if(!op) break;
    }
    return op;
}

inline void Solve(){
    read(n);read(m);read(k);
    rep(i,1,m){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
        d[from]++;d[to]++;
    }
    rep(i,1,n) sort(e[i].begin(),e[i].end());
    rep(i,1,n){
        if(d[i]<k) q.push(i),vis[i]=1;
    }
    bool al=1;
    while(q.size()){
        int top=q.front();q.pop();
        if(d[top]==k-1){
            if(Check(top)&&al){
                ans=v;al=0;
            }
        }
        for(int to:e[top]){
            d[top]--;d[to]--;
            if(vis[to]) continue;
            if(d[to]<k) q.push(to),vis[to]=1;
        }
    }
    bool op=0;rep(i,1,n) if(!vis[i]) op=1;
    if(op){
        // rep(i,1,n){
            // printf("vis[%d]=%d\n",i,vis[i]);
        // }
        rep(i,1,n) if(!vis[i]) a.pb(i);
        printf("1 %d\n",(int)a.size());
        for(int now:a) printf("%d ",now);puts("");
    }
    else if(ans.size()){
        puts("2");
        for(int now:ans) printf("%d ",now);puts("");
    }
    else puts("-1");
}

inline void Clear(){
    rep(i,1,n) e[i].clear(),d[i]=0,vis[i]=0;
    v.clear();ans.clear();a.clear();
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Solve();Clear();
    }
    return 0;
}
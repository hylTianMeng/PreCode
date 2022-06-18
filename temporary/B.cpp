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
#define Next(k) for(int x=head[k];x;x=li[x].next)
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

int a[N],n,m,t;
struct Node{
    vi v;int siz,id;
    inline bool operator < (const Node &b)const{
        return siz>b.siz;
    }
    inline int& operator [] (int k){assert(k<=siz-1);return v[k];}
}b[N];

inline void Clear(){
    rep(i,1,n) a[i]=0,b[i].v.clear();
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);
        rep(i,1,n){
            read(b[i].siz);rep(j,1,b[i].siz){int x;read(x);b[i].v.pb(x);}b[i].id=i;
        }
        sort(b+1,b+n+1);
        bool pd=0;
        rep(i,1,n){
            if(b[i].siz==0) continue;
            // printf("%d\n",b[i].siz);
            int now=a[b[i][0]];
            int op=-1;rep(j,0,b[i].siz-1){if(now!=a[b[i][j]]){op=max(op,a[b[i][j]]);break;}}
            if(op==-1){
                rep(j,0,b[i].siz-1){
                    a[b[i][j]]=i;
                    // printf("%d ",b[i][j]);
                }
            }
            else{
                rep(j,0,b[i].siz-1) op=max(op,a[b[i][j]]);
                // printf("op=%d\n",op);
                puts("YES");printf("%d %d\n",b[i].id,b[op].id);pd=1;break;
            }
            // rep(i,1,n){printf("%d ",a[i]);}puts("");
        }
        Clear();
        if(pd) continue;
        puts("NO");
    }
}
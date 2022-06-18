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
#define N 400010
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

struct Point{
    int x,y,id;
    inline bool operator < (const Point &b)const{
        if(x!=b.x)return x>b.x;else return id<b.id;
    }
}p[N];
int n,m;
multiset<int> s;

int main(){
    read(n);read(m);
    rep(i,1,n) cin>>p[i].x;
    rep(i,1,n) {cin>>p[i].y;p[i].id=1;}
    rep(i,1,m) cin>>p[i+n].x;
    rep(i,1,m) {cin>>p[i+n].y;p[i+n].id=0;}
    sort(p+1,p+n+m+1);
    rep(i,1,n+m){
        // printf("p[%d].id=%d\n",i,p[i].id);
        if(p[i].id==0) s.insert(-p[i].y);
        else{
            auto it=s.upper_bound(-p[i].y);
            // printf("now=%d\n",-p[i].y);
            // printf("it=%d\n",*it);
            if(it==s.begin()){puts("No");return 0;}
            else s.erase((--it));
        }
    }
    puts("Yes");
    return 0;
}
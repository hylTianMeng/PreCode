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
#define N 500010
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
const int base=13331;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

ull h1[N],h2[N],Pow[N];
int t,a[N],n,sta[N];
char s[N];

inline void Pre(){
    h1[0]=0;h2[n+1]=0;
    rep(i,1,n) h1[i]=h1[i-1]*base+s[i];
    dec(i,1,n) h2[i]=h2[i+1]*base+s[i];
}

inline bool check(int l,int r){
    ull a=h1[r]-h1[l-1]*Pow[r-l+1];
    ull b=h2[l]-h2[r+1]*Pow[r+1-l];
    return a==b;
}

inline int v(char c){
    if(c=='(') return 1;
    if(c==')') return -1;
    return INF;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    Pow[0]=1;
    rep(i,1,500000) Pow[i]=Pow[i-1]*base;
    while(t--){
        read(n);
        scanf("%s",s+1);
        Pre();
        int cnt=0,l=0,sum=0;
        while(l<=n){
            bool op=1;
            int now=l+2;sum=v(s[l+1])+v(s[now]);
            if(v(s[l+1])<0) op=0;if(sum<0) op=0;
            while(now<=n&&(!check(l+1,now)&&(!(sum==0&&op)))){
                now++;sum+=v(s[now]);if(sum<0) op=0;
            }
            if(now>n) break;
            cnt++;l=now;
        }
        printf("%d %d\n",cnt,n-l);
    }
    return 0;
}
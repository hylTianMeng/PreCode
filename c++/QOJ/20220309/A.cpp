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
#define N 2010
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

struct Bignum{
    int a[N],n;
    inline void Clear(){mset(a,0);n=1;}
    inline void up(int id){
        if(a[id]<0) a[id]+=10,a[id+1]--;
        if(a[id]>=10) a[id+1]/=10,a[id]%=10;
    }
    inline Bignum operator - (const Bignum &b)const{
        Bignum c;c.Clear();c.n=a.n;
        rep(i,1,n){c.a[i]=a[i]-b.a[i];if(c.a[i]<0)c.a[i]+=10;c.a[i+1]--;}
        while(!c.a[c.n])c.n--;
        return c;
    }
    inline Bignum operator * (const int b)const{
        Bignum c;c.Clear();c.n=a.n;
        rep(i,1,n) c.a[i]=mul(a[i],b);
        rep(i,1,n) c.up(i);
        while(c.a[c.n+1]) c.n++,c.up(c.n);
    }
    inline Bignum operator / (const int b)const{
        Bignum c;c.Clear();c.n=a.n;
        int now=0,id=n;
        while(id>=1){
            while(now<b&&id>=1){now*=10;now+=a[id];id--;}
            if(id<=0) break;
            c.a[id]+=now/b;now%=b;
        }
        return c;
    }
    inline void ly(){
        (*this)=(*this)*2;
    }
}I;

char s[N],t[N];
int n;

int main(){
}
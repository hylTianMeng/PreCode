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
#define N 510
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
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

int n,m,cnt;
char s[N][N];

int main(){
    read(n);read(m);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,2,n+m){
        bool p1=0,p2=0;
        rep(j,max(1,i-m),min(i-1,n)) if(s[j][i-j]=='B'){p1=1;}else if(s[j][i-j]=='R'){p2=1;}
        if(p1&&p2){puts("0");return 0;}
        if(p1||p2){
            rep(j,max(1,i-m),min(i-1,n)) if(p1) s[j][i-j]='B';else s[j][i-j]='R';
        }
        else{cnt++;}
    }
    printf("%d\n",ksm(2,cnt,mod));
    return 0;
}
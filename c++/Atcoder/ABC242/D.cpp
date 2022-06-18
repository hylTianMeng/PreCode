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

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

#define int long long

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

char s[N];
int q,w[N],c;
int a[3][3];

inline char dfs(int t,int k){
    if(t==0) return s[k];
    if(k==0){
        int now=s[0]-'A';
        t+=now;t%=3;return t+'A';
    }
    char c=dfs(t-1,k>>1);
    int nowc=c-'A';
    int p=k&1;
    c=a[nowc][p]+'A';
    return c;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    scanf("%s",s);
    int n=strlen(s);
    read(q);
    a[0][0]=1;a[0][1]=2;
    a[1][0]=2;a[1][1]=0;
    a[2][0]=0;a[2][1]=1;
    rep(i,1,q){
        int t,k;read(t);read(k);
        k--;
        printf("%c\n",dfs(t,k));
    }
    return 0;
}
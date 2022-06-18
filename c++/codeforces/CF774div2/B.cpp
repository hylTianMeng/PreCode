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
#define N 200010
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

int t,n,a[N];

signed main(){
    read(t);
    while(t--){
        read(n);rep(i,1,n) read(a[i]);
        sort(a+1,a+n+1);
        int l=2,r=n;
        int sum1=a[1]+a[2],sum2=a[n];
        bool op=0;
        while(l<r){
            // printf("l=%d r=%d\n",l,r);
            // printf("sum1=%d sum2=%d\n",sum1,sum2);
            if(r<=l) break;
            if(sum1<sum2){op=1;break;}
            sum1+=a[++l];
            sum2+=a[--r];
        }
        if(op){puts("YES");}
        else puts("NO");
    }
}
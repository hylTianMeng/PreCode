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

#define int long long

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int w[N],sum[N],n,c,t;

signed main(){
    read(t);
    while(t--){
        bool op=1;
        read(n);read(c);
        rep(i,1,n){int x;read(x);w[x]++;}
        rep(i,1,c){sum[i]=sum[i-1]+w[i];}
        // if(!w[1]){puts("No");continue;}
        rep(i,1,c){
            if(!w[i]) continue;
            // printf("i=%d\n",i);
            for(int j=i;j<=c;j+=i){
                int l=j-1,r=min(j+i-1,c);
                int num=sum[r]-sum[l];
                if(!num) continue;
                if(!w[r/i]){op=0;break;}
            }
            if(!op) break;
        }
        if(!op){puts("No");}
        else puts("Yes");
        rep(i,0,c){w[i]=0;sum[i]=0;}
    }
}
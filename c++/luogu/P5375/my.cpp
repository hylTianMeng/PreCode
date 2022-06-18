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
#define N number
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

queue<int> q;
stack<int> s;
multiset<int> S,T;

bool a[4];

int main(){
    int n;
    mset(a,1);
    read(n);
    rep(i,1,n){
        int op,x;
        read(op);read(x);
        if(op==1){
            if(a[0]) q.push(x);
            if(a[1]) s.push(x);
            if(a[2]) S.insert(-x);
            if(a[3]) T.insert(x);
        }
        else{
            if(q.empty()) a[0]=0;
            if(s.empty()) a[1]=0;
            if(S.empty()) a[2]=0;
            if(T.empty()) a[3]=0;
            int now;
            if(a[0]){
                now=q.front();q.pop();
                if(now!=x) a[0]=0;
            }
            if(a[1]){
                now=s.top();s.pop();
                if(now!=x) a[1]=0;
            }
            if(a[2]){
                now=*S.begin();S.erase(S.begin());
                if(-now!=x) a[2]=0;
            }
            if(a[3]){
                now=*T.begin();T.erase(T.begin());
                if(now!=x) a[3]=0;
            }
        }
    }
    rep(i,0,3) if(a[i]) puts("Yes");else puts("No");
    return 0;
}
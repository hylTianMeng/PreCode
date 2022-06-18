#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N number
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,n,x,a,b,nown,nowe,cnt;
bool op=1;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(x);read(a);read(b);
        nown=n;nowe=0;op=1;cnt=0;
        while(nown>=x){
            int num=nown/x;
            nowe+=num;nown=nown%x;cnt+=num;
            nown+=(nowe/a)*b;nowe%=a;
            if(nown>=n){op=0;break;}
        }
        if(op){
            printf("%lld\n",cnt);continue;
        }
        puts("-1");
    }
    return 0;
}
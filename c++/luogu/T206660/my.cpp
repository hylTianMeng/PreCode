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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

ll n,k,sum;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(k);
    for(int i=1;i<=n;i++){
        int x;read(x);
        if(i&1) sum+=x;
        else sum-=x;
    }
    sum=abs(sum);
    if((k&1)==0){
        for(int i=1;i<=k;i++){
            int x;read(x);
            if(i&1){
                if(sum<=x) sum=0;
                else sum-=x;
            }
            else sum+=x;
        }
        printf("%lld\n",-sum);
    }
    else{
        for(int i=1;i<=k;i++){
            int x;read(x);
            if(i&1) sum+=x;
            else{
                if(sum<=x) sum=0;
                else sum-=x;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
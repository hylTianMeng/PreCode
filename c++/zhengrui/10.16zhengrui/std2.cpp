#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
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

const int mod=1e9+7;

int main(){
    freopen("duipi.out","w",stdout);
    int ans=1;
    for(int i=318801;i>=1;i--){
        ans=1ll*ans*i%mod;
        printf("nowans-j+i=%d\n",i);
        printf("%lld\n",ans);
    }
    printf("%d\n",ans);
}
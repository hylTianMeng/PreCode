#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 110
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

typedef pair<int,int> P;
P a[N];
int t,n,k;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(k);
        for(int i=1;i<=n;i++) {
            int x;read(x);a[i].first=x;
        }
        for(int i=1;i<=n;i++){
            int x;read(x);a[i].second=x;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(a[i].first<=k) k+=a[i].second;
            else break;
        }
        printf("%d\n",k);
    }
    return 0;
}
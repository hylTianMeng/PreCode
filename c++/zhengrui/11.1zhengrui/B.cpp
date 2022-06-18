#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

int t,n,a[N];

inline void Solve(){
    int mid=(1+n)>>1;
    int c=mid,d=mid+1;
    for(int i=1;i<=n-1;i++){
        printf("%d %d\n",a[c],a[d]);
        if(i&1) c--;
        else d++;
    }
}

inline void Change(){
    int last=a[1];
    for(int i=1;i<=n-1;i++) a[i]=a[i+1];
    a[n]=last;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    for(int i=1;i<=t;i++){
        read(n);
        printf("Case #%d: %d\n",i,n/2);
        for(int i=1;i<=n;i++) a[i]=i;
        for(int j=1;j<=n/2;j++){
            Solve();Change();
        }
    }
}
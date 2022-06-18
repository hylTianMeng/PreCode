#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 200010
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

int n,k,a[N];

int sum[N],b[N];
int tot;

signed main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    read(n);read(k);for(int i=0;i<=n-1;i++) read(a[i]);
    int X=0;
    int nowk=k;
    while(nowk){
        nowk--;
        printf("Xmodn=%d\n",X%n);
        X+=a[X%n];
        printf("X=%d\n",X);
    }
    printf("%d\n",X);
}
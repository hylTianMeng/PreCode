#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200
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

int n,a[N],b[N],t;

int main(){
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=1;i<=n;i++) if(a[i]<b[i]) swap(a[i],b[i]);
        int maxx1=-INF,maxx2=-INF;
        for(int i=1;i<=n;i++) maxx1=max(maxx1,a[i]);
        for(int i=1;i<=n;i++) maxx2=max(maxx2,b[i]);
        printf("%d\n",maxx1*maxx2);
    }
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
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

int n,a[N],t;

int main(){
    read(t);
    while(t--){
        read(n);for(int i=1;i<=n;i++) read(a[i]);
        int len=1;
        for(int i=n-1;i>=1;i--) if(a[i]==a[n]) len++;else break;
        int cnt=0;
        for(;;){
            bool op=1;
            for(int i=n-1;i>=1;i--) if(a[i]!=a[n]){op=0;break;}
            if(op) break;
            cnt++;len<<=1;
            for(int i=max(1,n-len+1);i<=n;i++) a[i]=a[n];
            len=1;
            for(int i=n-1;i>=1;i--) if(a[i]==a[n]) len++;else break;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
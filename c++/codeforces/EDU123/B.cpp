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

int t,n,a[51];

int main(){
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) a[i]=n-i+1;
        for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
        for(int i=n-1;i>=1;i--){
            swap(a[i],a[i+1]);
            for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
        }
    }
    return 0;
}
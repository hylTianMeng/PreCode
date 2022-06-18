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

int n,a[N],num;

int main(){
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=2;i<=n+1;i++){
        if(a[i]!=a[i-1]){
            if(a[i-1]<a[i]) continue;
            num=a[i-1];break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==num) continue;
        printf("%d ",a[i]);
    }puts("");
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10010
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

int f[N][2],n,m,a[N],b[N];

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=;i++){
        read(a[i]);read(b[i]);
    }
    sort(a+1,a+n+1);reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]+=a[n-i+1];
}



int main(){

}

#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

int T,n,a[N],b[N];

inline char Getchar(){
    char c;c=getchar();
    while(c!='0'&&c!='1') c=getchar();
    return c;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(T);read(n);
    for(int i=1;i<=n;i++){
        a[i]=Getchar()-'0';
    }
    for(int i=1;i<=T;i++){
        b[1]=a[2];b[n]=a[n-1];
        for(int j=2;j<=n-1;j++){
            b[j]=(a[j-1]+a[j+1])%2;
        }
        bool op=0;
        for(int j=1;j<=n;j++){
            if(a[j]!=b[j]) op=1;
        }
        if(!op) break;
        for(int j=1;j<=n;j++) a[j]=b[j];
    }
    for(int i=1;i<=n;i++) printf("%d",b[i]);
    return 0;
}
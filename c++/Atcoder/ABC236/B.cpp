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

int n,a[N<<2],cnt[N];

int main(){
    read(n);
    for(int i=1;i<=4*n-1;i++){
        int x;read(x);cnt[x]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]!=4){printf("%d\n",i);break;}
    }
    return 0;
}
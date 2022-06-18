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

int n,m,a[N];

map<int,int> Map;

int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]),Map[a[i]]++;
    for(int i=1;i<=m;i++){
        int x;read(x);if(Map[x]){Map[x]--;}
        else{puts("No");return 0;}
    }
    puts("Yes");
    return 0;
}
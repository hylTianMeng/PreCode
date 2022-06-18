#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
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

typedef pair<int,int> P;

multiset<P> S,T;

int main(){
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=1;i<=n;i++){
            S.insert(make_pair(a[i],a[n-i+1]));
        }
        for(int i=1;i<=n;i++){
            T.insert(make_pair(b[i],b[n-i+1]));
        }
        if(S==T) puts("yes");
        else puts("no");
        S.clear();T.clear();
    }
}
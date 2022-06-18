#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 4010
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

int val[N][N],n;
int f[N][N];

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        int p,w;val[i][p]=w;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
        }
    }
}

inline void Solve(){

}

signed main(){
    Init();Solve();return 0;
}
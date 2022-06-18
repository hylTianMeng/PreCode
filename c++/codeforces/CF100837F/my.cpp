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

typedef vector<int> V;
V Bsys[9];

inline void Dfs(V v){

}

inline void dfs(int k,int cnt,int now){
    if(k==17){
        Bsys[cnt].push_back(now);return;
    }
    now<<=1;
    if(k<=7) dfs(k+1,cnt+1,now|1);
    dfs(k+1,cnt,now);
}

int n,a[N][N],m;

int main(){
    dfs(1,0,0);
    read(n);read(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            read(a[i][j]);
        }
    V begin;for(int i=1;i<=n;i++) begin.push_back(i);
}
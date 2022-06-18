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

int n,m;

typedef pair<int,int> P;
vector<pair<P,int> > e;
vector<int> v[N];

int col[N];

inline bool dfs(int k,int c){
    col[k]=x;
    for(int to:v[k]){
        if(col[to]){
            if(col[to]==c) return 0;
            continue;
        }
        if(!dfs(to,3-c)) return 0;
    }
    return 1;
}

int main(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int op,from,to;read(op);read(from);read(to);
        e.push_back(make_pair(make_pair(op,from),to));
        v[from].push_back(to);v[to].push_back(from);
    }
    for(int i=1;i<=n;i++) if(!col[i]) if(!dfs(i,1)){puts("No");return 0;}

}
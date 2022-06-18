#include<bits/stdc++.h>
#include<unordered_map>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10
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

int n,m,k;
char s[N][N][N];

inline char GetChar(){
    char c=getchar();while(c!='.'&&c!='x') c=getchar();
    return c;
}

unordered_map<int,bool> Map;
bool vis[N][N][N];

inline void dfs(int x,int y,int z,int a,int b,int c,int d){
    if(vis[x][y][z]) return;
    vis[x][y][z]=1;
    if(Map.find(d)!=Map.end()){
        puts("No");exit(0);
    }
    Map[d]=1;
    if(s[x][y][z+1]=='x') dfs(x,y,z+1,a,b,d,-c);
    if(s[x][y][z-1]=='x') dfs(x,y,z-1,a,b,-d,c);
    if(s[x+1][y][z]=='x') dfs(x+1,y,z,d,b,c,-a);
    if(s[x-1][y][z]=='x') dfs(x-1,y,z,-d,b,c,a);
    if(s[x][y+1][z]=='x') dfs(x,y+1,z,a,d,c,-b);
    if(s[x][y-1][z]=='x') dfs(x,y-1,z,a,-d,c,b);
}

int main(){
    freopen("hypercube.in","r",stdin);
    freopen("hypercube.out","w",stdout);
    read(m);read(n);read(k);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++)
            for(int l=1;l<=m;l++) s[j][l][i]=GetChar();
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int l=1;l<=k;l++){
                if(s[i][j][l]=='x'){
                    dfs(i,j,l,1,2,3,4);
                    puts("Yes");
                    return 0;
                }
            }
    return 0;
}
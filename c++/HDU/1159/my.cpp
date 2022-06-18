#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1100
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

char s[N],t[N];
int f[N][N],n,m;

inline void Init(){
    n=strlen(s+1);m=strlen(t+1);
}

inline void Update(int &a,int b){a=Max(a,b);}

inline void Solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                Update(f[i][j],f[i-1][j-1]+1);
                Update(f[i][j],f[i-1][j]);
                Update(f[i][j],f[i][j-1]);
            }
            else{
                Update(f[i][j],f[i-1][j-1]);
                Update(f[i][j],f[i-1][j]);
                Update(f[i][j],f[i][j-1]);
            }
        }
    }
    printf("%d\n",f[n][m]);
}

inline void Clear(){
    memset(f,0,sizeof(f));
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    while(scanf("%s %s",s+1,t+1)!=EOF){
        Init();Solve();Clear();
    }
}
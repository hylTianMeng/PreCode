#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 5010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int g[N][N],n;
char s[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    scanf("%s",s+1);
    g[n+1][0]=1;
    for(int j=n+1;j>=2;j--){
        for(int k=0;k<=n;k++){
            if(!g[j][k]) continue;
            char c=s[j-1];
            if(c=='+') (g[j-1][k+1]+=g[j][k])%=mod;
            else if(c=='-') (g[j-1][max(0,k-1)]+=g[j][k])%=mod;
            else if(c=='0') (g[j-1][k]+=g[j][k])%=mod;
            else{
                (g[j-1][k+1]+=g[j][k])%=mod;
                (g[j-1][max(0,k-1)]+=g[j][k])%=mod;
                (g[j-1][k]+=g[j][k])%=mod;
            }
        }
    }
    for(int i=0;i<=n;i++)
        printf("%d\n",g[1][i]);
    return 0;
}
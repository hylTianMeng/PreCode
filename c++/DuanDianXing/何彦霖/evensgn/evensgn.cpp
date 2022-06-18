#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
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

int n,m,ans;
char s[N][N];
string ss[N];

int main(){
    freopen("evensgn.in","r",stdin);
    freopen("evensgn.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int j=1;j<=m;j++){
        bool op=0;
        for(int i=2;i<=n;i++){
            if(ss[i]==ss[i-1]&&s[i][j]<s[i-1][j]){op=1;break;}
        }
        if(op){ans++;continue;}
        for(int i=1;i<=n;i++) ss[i]+=s[i][j];
    }
    printf("%d\n",ans);
    return 0;
}
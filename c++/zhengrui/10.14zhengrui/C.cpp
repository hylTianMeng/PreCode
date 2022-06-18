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

bitset<N> bit1[N],bit2[N],Beat[N];
int f[N][N][2],n;
char s[N];

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=n;j++) if(s[j]=='1') Beat[i][j]=1;
    }   
}

inline void Dp(){
    for(int i=1;i<=n;i++){
        f[i][i][0]=f[i][i][1]=1;
        bit1[i][i]=bit2[i][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            int l=j,r=j+i-1;
            f[l][r][0]=(Beat[l]&bit1[l+1]&bit2[r]).any();
            f[l][r][1]=(Beat[r]&bit1[l]&bit2[r-1]).any();
            // printf("f[%d][%d][0]=%d f[%d][%d][1]=%d\n",l,r,f[l][r][0],l,r,f[l][r][1]);
        }
        for(int j=1;j<=n-i+1;j++){
            int l=j,r=j+i-1;
            if(f[l][r][0]) bit2[r][l]=1;
            if(f[l][r][1]) bit1[l][r]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(f[1][i][1]&&f[i][n][0]) printf("%d ",i);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dp();
    return 0;
}
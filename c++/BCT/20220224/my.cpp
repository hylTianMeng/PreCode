#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 3010
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

int f[N][3],a[N],n,m;

inline int Dp(int l,int r){
    memset(f,0,sizeof(f));
    for(int i=l;i<=r;i++){
        for(int j=0;j<=2;j++){
            if(i-j+1<=l-1) continue;
            int maxx=0;
            for(int k=0;k<=2;k++){
                if(i-j-1<l) continue;
                maxx=max(maxx,f[i-j-1][k]);
            }
            f[i][j]=maxx;
            for(int k=i;k>=i-j+1;k--) f[i][j]+=a[k];
            // printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        }
    }
    return max(f[r][0],max(f[r][1],f[r][2]));
}

signed main(){
    freopen("my.in","r",stdin);
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++){
        int op,l,r;
        read(op);read(l);read(r);
        if(op==1){printf("%lld\n",Dp(l,r));}
        else a[l]=r;
    }
    return 0;
}
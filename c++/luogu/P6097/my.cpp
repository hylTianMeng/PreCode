#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 21
#define M 1100000
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N][M],b[N][M],Cnt[M],c[N][M];

inline void FWT(int *f,int n,int op){
    for(int mid=1;mid<=(n>>1);mid<<=1)
        for(int l=0;l<n;l+=(mid<<1))
            for(int i=l;i<=l+mid-1;i++){
                if(op==0){(f[i+mid]+=f[i])%=mod;}
                else{(f[i+mid]-=f[i])%=mod;}
            }
}


signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=(1<<20);i++){
        Cnt[i]=__builtin_popcount(i);
    }
    for(int i=0;i<(1<<n);i++) read(a[Cnt[i]][i]);
    for(int i=0;i<(1<<n);i++) read(b[Cnt[i]][i]);
    n=1<<n;
    for(int i=0;i<=20;i++) FWT(a[i],n,0);
    // for(int i=0;i<n;i++) printf("%d ",a[0][i]);puts("");
    for(int i=0;i<=20;i++) FWT(b[i],n,0);
    // for(int i=0;i<n;i++) printf("%d ",b[0][i]);puts("");
    for(int i=0;i<=20;i++){
        for(int j=0;i+j<=20;j++){
            for(int k=0;k<n;k++) c[i+j][k]=(c[i+j][k]+1ll*a[i][k]*b[j][k]%mod)%mod;
        }
    }
    // for(int i=0;i<n;i++) printf("%d ",c[0][i]);puts("");
    for(int i=0;i<=20;i++) FWT(c[i],n,1);
    for(int i=0;i<n;i++) printf("%d ",(c[Cnt[i]][i]%mod+mod)%mod);
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1350000
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;
const int gg=3;
const int invg=332748118;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,tr[N<<1],f[N<<1],g[N<<1];

inline int ksm(int a,int b,int mod){
    int res=1;
    while(b){
        if(b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}

inline void NTT(int *f,bool op){
    for(int i=0;i<n;i++) if(i<tr[i]) swap(f[i],f[tr[i]]);
    for(int p=2;p<=n;p<<=1){
        int len=p>>1;
        int tg=ksm((op==1?gg:invg),(mod-1)/p,mod);
        for(int k=0;k<n;k+=p){
            int buf=1;
            for(int l=k;l<k+len;l++){
                int now=1ll*buf*f[l+len]%mod;
                f[l+len]=f[l]-now;
                if(f[l+len]<0) f[l+len]+=mod;
                f[l]=f[l]+now;
                if(f[l]>mod) f[l]%=mod;
                buf=1ll*buf*tg%mod;
            }
        }
    }
}

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);
    for(int i=0;i<n;i++) read(f[i]);
    for(m+=n,n=1;n<m;n<<=1);
	for(int i=0;i<n;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
    for(int i=0;i<n;i++) printf("%d ",tr[i]);puts("");
    NTT(f,1);for(int i=0;i<n;i++) printf("%d ",f[i]);puts("");
	return 0;
}
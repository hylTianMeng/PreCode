#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 400010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int g=3;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

struct Poly{
    int tr[N],c[N],d[N];
    inline void Gettr(int len){
        for(int i=0;i<len;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?(len>>1):0);
    }
    inline void NTT(int *f,int len,int flag){
        for(int i=0;i<len;i++) if(i<tr[i]) swap(f[i],f[tr[i]]);
        for(int i=2;i<=len;i<<=1){
            int tg=ksm(g,(mod-1)/i,mod),l=i>>1;
            if(flag==-1) tg=ksm(tg,mod-2,mod);
            for(int j=0;j<len;j+=i){
                int buf=1;
                for(int k=j;k<j+l;k++){
                    int tt=1ll*buf*f[k+l]%mod;
                    f[k+l]=((f[k]-tt)%mod+mod)%mod;
                    f[k]=(f[k]+tt)%mod;buf=1ll*buf*tg%mod;
                }
            }
        }
        if(flag==1) return;
        int inv=ksm(len,mod-2,mod);for(int i=0;i<len;i++) f[i]=1ll*f[i]*inv%mod;
    }
    inline void GetInv(int len,const int *a,int *b){
        if(len==1){b[0]=ksm(a[0],mod-2,mod);return;}
        GetInv((len+1)>>1,a,b);int m=1;while(m<(len<<1)) m<<=1;Gettr(m);
        for(int i=0;i<len;i++) c[i]=a[i];for(int i=len;i<m;i++) c[i]=0;
        NTT(c,m,1);NTT(b,m,1);
        for(int i=0;i<m;i++) b[i]=1ll*(2-1ll*c[i]*b[i]%mod+mod)%mod*b[i]%mod;
        NTT(b,m,-1);for(int i=len;i<m;i++) b[i]=0;
    }//c is not clear
    inline void GetSqrt(int len,const int *a,int *b){
        if(len==1){b[0]=a[0];return;}
        GetSqrt((len+1)>>1,a,b);int m=1;while(m<(len<<1)) m<<=1;
        for(int i=0;i<len;i++) b[i]<<=1;
        for(int i=0;i<m;i++) d[i]=0;GetInv(len,b,d);
        for(int i=0;i<len;i++) b[i]>>=1;Gettr(m);
        for(int i=0;i<len;i++) c[i]=a[i];for(int i=len;i<m;i++) c[i]=0;
        NTT(c,m,1);NTT(d,m,1);NTT(b,m,1);
        for(int i=0;i<m;i++) b[i]=1ll*(1ll*b[i]*b[i]%mod+c[i])%mod*d[i]%mod;
        NTT(b,m,-1);
        for(int i=len;i<m;i++) b[i]=0;
    }//c is not clear d is not clear
}pl;

int n,m,a[N],b[N],g[N],f[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);n++;m++;
    for(int i=0;i<n;i++) read(a[i]);
    for(int i=0;i<m;i++) read(b[i]);
    return 0;
}
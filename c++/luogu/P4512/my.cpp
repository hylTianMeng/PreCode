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
const int mod=1004535809;
const int g=3;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}

struct Poly{
    int tr[N],c[N],d[N],A[N],B[N];
    inline void Gettr(int len){for(int i=0;i<len;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?(len>>1):0);}
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
        NTT(c,m,1);NTT(c,m,1);NTT(b,m,1);
        for(int i=0;i<m;i++) b[i]=1ll*(1ll*b[i]*b[i]%mod+c[i])%mod*d[i]%mod;
        NTT(b,m,-1);
        for(int i=len;i<m;i++) b[i]=0;
    }//c,d is not clear
    inline void GetDivi(int lena,int lenb,const int *a,const int *b,int *f,int *h){
        int len=lena-lenb+1;int m=1;while(m<(len<<1)) m<<=1;
        for(int i=0;i<lena;i++) A[i]=a[i];for(int i=0;i<lenb;i++) B[i]=b[i];
        reverse(A,A+lena);reverse(B,B+lenb);
        for(int i=len;i<lena;i++) A[i]=0;for(int i=len;i<lenb;i++) B[i]=0;
        GetInv(len,B,d);Gettr(m);NTT(A,m,1);NTT(d,m,1);
        for(int i=0;i<m;i++) f[i]=1ll*A[i]*d[i]%mod;NTT(f,m,-1);
        for(int i=len;i<m;i++) f[i]=0;reverse(f,f+len);
        for(int i=0;i<lena;i++) A[i]=a[i];for(int i=0;i<lenb;i++) B[i]=b[i];
        m=1;while(m<(lenb+lena)) m<<=1;Gettr(m);
        NTT(A,m,1);NTT(B,m,1);for(int i=0;i<len;i++) c[i]=f[i];for(int i=len;i<m;i++) c[i]=0;
        NTT(c,m,1);for(int i=0;i<m;i++) h[i]=((A[i]-1ll*B[i]*c[i]%mod)%mod+mod)%mod;NTT(h,m,-1);
        for(int i=lenb;i<m;i++) h[i]=0;
    }//A,B,c,d is not clear
    inline void GetLn(int len,const int *a,int *b){
        for(int i=1;i<len;i++) A[i-1]=1ll*a[i]*i%mod;
        for(int i=0;i<len;i++) B[i]=a[i];GetInv(len,B,d);
        int m=1;while(m<(len<<1)) m<<=1;NTT(A,m,1);NTT(d,m,1);
        for(int i=0;i<m;i++) b[i]=1ll*A[i]*d[i]%mod;NTT(b,m,-1);
        for(int i=len-1;i<m;i++) b[i]=0;
        for(int i=len-1;i>=1;i--) b[i]=1ll*b[i-1]*ksm(i,mod-2,mod)%mod;
        b[0]=0;
    }
    inline void GetExp(int len,const int *a,int *b){
        if(len==1){b[0]=1;return;}
        GetExp((len+1)>>1,a,b);
    }
}pl;

int n,m,a[N],b[N];

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);for(int i=0;i<n;i++) read(a[i]);
    for(int i=0;i<n;i++) read(b[i]);
    int t=1;while(t<=(n<<1)) t<<=1;pl.Gettr(t);
    pl.NTT(a,t,1);pl.NTT(b,t,1);
    for(int i=0;i<t;i++) printf("%d ",a[i]);puts("");
    for(int i=0;i<t;i++) printf("%d ",b[i]);puts("");
    for(int i=0;i<t;i++) a[i]=1ll*a[i]*b[i]%mod;
    for(int i=0;i<t;i++) printf("%d ",a[i]);puts("");
    pl.NTT(a,t,-1);
    for(int i=0;i<t;i++) printf("%d ",a[i]);
    return 0;
}
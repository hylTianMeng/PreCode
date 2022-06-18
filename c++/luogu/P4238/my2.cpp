#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*a*res%mod;a=1ll*a*a%mod;b>>=1;}return res;}

struct Poly{
    int tr[N];
    inline void Gettr(int n){
        for(int i=0;i<n;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?(n>>1):0);
    }
    inline void NTT(int *f,int len,int flag){
        for(int i=0;i<len;i++) if(i<tr[i]) swap(f[i],f[tr[i]]);
        for(int p=2;p<=len;p<<=1){
            int md=ksm(g,(mod-1)/p,mod),l=p>>1;
            if(flag==-1) md=ksm(md,mod-2,mod);
            for(int i=0;i<len;i+=p){
                int buf=1;
                for(int j=i;j<i+l;j++){
                    int tt=1ll*f[j+l]*buf%mod;
                    f[j+l]=((f[j]-tt)%mod+mod)%mod;
                    f[j]=(f[j]+tt)%mod;buf=1ll*buf*md%mod;
                }
            }
        }
        if(flag==1) return;
        int inv=ksm(len,mod-2,mod);for(int i=0;i<len;i++) f[i]=1ll*f[i]*inv%mod;
    }
    inline void GetInv(int len,int *a,int *b){
        if(len==1){b[0]=ksm(a[0],mod-2,mod);return;}
        GetInv((len+1)>>1,a,b);m=1;while(m<(len<<1)) m<<=1;
        Gettr(m);for(int i=0;i<len;i++) c[i]=a[i];
        for(int i=len;i<m;i++) c[i]=0;
        NTT(c,m,1);NTT(b,m,1);
        for(int i=0;i<m;i++) b[i]=1ll*(2-1ll*b[i]*c[i]%mod+mod)%mod*b[i]%mod;
        NTT(b,m,-1);int inv=ksm(m,mod-2,mod);for(int i=0;i<m;i++) b[i]=1ll*b[i]*inv%mod;
        for(int i=len;i<m;i++) b[i]=0;
    }
    inline void GetSqrt(){
        
    }
}pl;
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;
const int inv2=499122177;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline void FWT1(int *f,int n,int op){
    for(int mid=1;mid<=(n>>1);mid<<=1)
        for(int l=0;l<n;l+=(mid<<1))
            for(int i=l;i<=l+mid-1;i++){
                if(op==0){(f[i+mid]+=f[i])%=mod;}
                else{(f[i+mid]-=f[i])%=mod;}
            }
}

inline void FWT2(int *f,int n,int op){
    for(int mid=1;mid<=(n>>1);mid<<=1)
        for(int l=0;l<n;l+=(mid<<1))
            for(int i=l;i<=l+mid-1;i++){
                if(op==0){(f[i]+=f[i+mid])%=mod;}
                else (f[i]-=f[i+mid])%=mod;
            }
}

inline void FWT3(int *f,int n,int op){
    for(int mid=1;mid<=(n>>1);mid<<=1)
        for(int l=0;l<n;l+=(mid<<1))
            for(int i=l;i<=l+mid-1;i++){
                int a=f[i],b=f[i+mid];
                if(op==0){f[i]=(a+b)%mod;f[i+mid]=(a-b)%mod;}
                else{f[i]=1ll*((a+b)%mod)%mod*inv2%mod;f[i+mid]=1ll*((a-b)%mod)*inv2%mod;}
            }
}

int a[N],n,b[N],c[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);n=1<<n;
    for(int i=0;i<n;i++) read(a[i]);
    for(int i=0;i<n;i++) read(b[i]);
    FWT1(a,n,0);
    FWT1(b,n,0);for(int i=0;i<n;i++) c[i]=1ll*a[i]*b[i]%mod;
    FWT1(a,n,1);FWT1(b,n,1);FWT1(c,n,1);
    for(int i=0;i<n;i++) printf("%d ",(c[i]%mod+mod)%mod);puts("");
    FWT2(a,n,0);FWT2(b,n,0);for(int i=0;i<n;i++) c[i]=1ll*a[i]*b[i]%mod;
    FWT2(a,n,1);FWT2(b,n,1);FWT2(c,n,1);
    for(int i=0;i<n;i++) printf("%d ",(c[i]%mod+mod)%mod);puts("");
    FWT3(a,n,0);FWT3(b,n,0);for(int i=0;i<n;i++) c[i]=1ll*a[i]*b[i]%mod;
    FWT3(a,n,1);FWT3(b,n,1);FWT3(c,n,1);
    for(int i=0;i<n;i++) printf("%d ",(c[i]%mod+mod)%mod);puts("");
    return 0;
}
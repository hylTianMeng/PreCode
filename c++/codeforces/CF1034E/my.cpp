#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 2100000
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

inline void FWT(ull *f,int n,int op){
    for(int mid=1;mid<=(n>>1);mid<<=1)
        for(int l=0;l<n;l+=(mid<<1))
            for(int k=l;k<=l+mid-1;k++){
                // printf("k+mid=%d k=%d\n",k+mid,k);
                if(op==0) f[k+mid]+=f[k];
                else f[k+mid]-=f[k];
            }
}

ull a[N],b[N],c[N];
int n;
char s[N],t[N];

signed main(){
    read(n);n=1<<n;
    scanf("%s%s",s,t);
    for(int i=0;i<n;i++) a[i]=((ull)(s[i]-'0'))<<(__builtin_popcountll(i)<<1);
    for(int i=0;i<n;i++) b[i]=((ull)(t[i]-'0'))<<(__builtin_popcountll(i)<<1);
    // for(int i=0;i<n;i++) printf("%d ",a[i]);puts("");
    // for(int i=0;i<n;i++) printf("%d ",b[i]);puts("");
    FWT(a,n,0);FWT(b,n,0);
    for(int i=0;i<n;i++){
        c[i]=a[i]*b[i];
        // printf("i=%d a=%d b=%d c=%d\n",i,a[i],b[i],c[i]);
    }
    FWT(c,n,1);
    for(int i=0;i<n;i++) c[i]=(c[i]/((ull)1<<(__builtin_popcountll(i)<<1)))&3;
    for(int i=0;i<n;i++) printf("%llu",c[i]);
    return 0;
}
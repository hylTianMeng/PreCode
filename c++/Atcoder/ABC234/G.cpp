#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N],f[N];
int m1[N],t1,m2[N],m3[N],t3,m4[N],maxx,minn;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    f[0]=1;
    for(int i=1;i<=n;i++){
        int sum1=0,sum2=0;
        while(t1>0&&m1[t1]<=a[i]){
            (maxx-=1ll*m1[t1]*m2[t1]%mod)%=mod;
            (sum1+=m2[t1])%=mod;t1--;
        }
        t1++;m1[t1]=a[i];m2[t1]=(sum1+f[i-1])%mod;
        (maxx+=1ll*m1[t1]*m2[t1]%mod)%=mod;
        while(t3>0&&m3[t3]>=a[i]){
            (minn-=1ll*m3[t3]*m4[t3]%mod)%=mod;
            (sum2+=m4[t3])%=mod;t3--;
        }
        t3++;m3[t3]=a[i];m4[t3]=(sum2+f[i-1])%mod;
        (minn+=1ll*m3[t3]*m4[t3]%mod)%=mod;
        // printf("%d %d\n",maxx,minn);
        f[i]=(maxx-minn)%mod;
    }
    printf("%d\n",(f[n]%mod+mod)%mod);
    return 0;
}
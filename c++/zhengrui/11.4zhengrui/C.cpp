#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10000100
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n;

inline int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

inline void Init(){
    
}

int Ans=0;

int Prime[N],tail,f[N];
bool NotPrime[N];

inline void GetPrime(int n){
    NotPrime[1]=1;
    for(int i=2;i<=n;i++){
        if(!NotPrime[i]) Prime[++tail]=i;
        for(int j=1;j<=tail&&1ll*Prime[j]*i<=n;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0) break;
        }
    }
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);
    if(n<=1000){
        for(int i=1;i<=n;i++){
            int res=1;
            for(int j=1;j<=i;j++) if(gcd(i,j)==1) res=1ll*res*j%i;
            Ans=(Ans+res)%mod;
            f[i]=res;
            // if(f[i]==1||f[i]==0) printf("f[%d]=%d\n",i,f[i]);
            // else printf("f[%d]=-1\n",i);
        }
        printf("%d\n",Ans);
    }
    else{
        GetPrime(10000000);
        f[1]=0;f[2]=-1;f[4]=-1;
        for(int i=2;i<=tail;i++){
            ll now=Prime[i];
            while(now<=n){
                f[now]=-1;
                if(2*now<=n) f[2*now]=-1;
                now=now*Prime[i];
            }
        }
        for(int i=2;i<=n;i++) if(!f[i]) f[i]=1;
        int Ans=0;
        for(int i=1;i<=n;i++){
            (Ans+=(f[i]%i+i)%i)%=mod;
            // printf("f[%d]=%d\n",i,f[i]);
        }
        printf("%d\n",Ans);
    }
}
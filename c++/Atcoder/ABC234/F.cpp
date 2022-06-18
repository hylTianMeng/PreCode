#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 5010
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

int ch[26],f[N],Jie[N],Jieinv[N],Inv[N],len,g[N],Ans;
char s[N];

inline int C(int n,int m){
    if(n<m) return 0;
    return 1ll*Jie[n]*Jieinv[m]%mod*Jieinv[n-m]%mod;
}

int main(){
    scanf("%s",s+1);len=strlen(s+1);
    for(int i=1;i<=len;i++){
        ch[s[i]-'a']++;
    }
    Jie[0]=1;for(int i=1;i<=5000;i++) Jie[i]=1ll*Jie[i-1]*i%mod;
    Inv[1]=1;for(int i=2;i<=5000;i++) Inv[i]=1ll*(mod-mod/i)*Inv[mod%i]%mod;
    Jieinv[0]=1;for(int i=1;i<=5000;i++) Jieinv[i]=1ll*Jieinv[i-1]*Inv[i]%mod;
    f[0]=1;
    for(int i=0;i<26;i++){
        for(int j=0;j<=len;j++){
            for(int k=1;k<=ch[i]&&k+j<=len;k++){
                g[k+j]=(g[k+j]+1ll*f[j]*C(j+k,k)%mod)%mod;
            }
        }
        for(int j=0;j<=len;j++) f[j]=(f[j]+g[j])%mod;
        for(int j=0;j<=len;j++) g[j]=0;
    }
    for(int i=1;i<=len;i++) Ans=(Ans+f[i])%mod;
    // for(int i=1;i<=len;i++) printf("%d ",f[i]);puts("");
    printf("%d\n",Ans);
    return 0;
}
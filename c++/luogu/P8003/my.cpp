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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,t,f[N],g[N],Jie[N],Inv[N],Jieinv[N],Ans;
const int lim=1000000;
char s[N];

inline int C(int n,int m){
    if(n<m) return 0;
    return 1ll*Jie[n]*Jieinv[m]%mod*Jieinv[n-m]%mod;
}

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1){res=1ll*res*a%mod;}a=1ll*a*a%mod;b>>=1;}return res;}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    Jie[0]=1;for(int i=1;i<=lim;i++) Jie[i]=1ll*Jie[i-1]*i%mod;
    Inv[1]=1;for(int i=2;i<=lim;i++) Inv[i]=1ll*(mod-mod/i)*Inv[mod%i]%mod;
    Jieinv[0]=1;for(int i=1;i<=lim;i++) Jieinv[i]=1ll*Jieinv[i-1]*Inv[i]%mod;
    while(t--){
        // printf("here\n");
        read(n);read(m);
        scanf("%s",s+1);
        if(n==2){
            printf("%d\n",1ll*ksm(2,m-n,mod)*m%mod*(m-1)%mod*ksm(2,mod-2,mod)%mod);continue;
        }
        int cnt1=0,cnt2=0;
        for(int i=n;i>=1;i--){
            if(s[i]=='(') cnt1++;
            if(s[i]==')'){
                if(cnt1){cnt1=cnt2=-INF;break;}
                cnt2++;
            }
            if(cnt1==cnt2) break;
        }
        // printf("%d %d\n",cnt1,cnt2);
        if(cnt1==-INF){
            for(int i=0;i<=m-n;i++) f[i]=1;
        }
        else{
            for(int i=0;i<=m-n;i++) f[i]=C(cnt1+i,i);
            for(int i=1;i<=m-n;i++) f[i]=(f[i]+f[i-1])%mod;
        }
        // for(int i=0;i<=m-n;i++) printf("%d ",f[i]);puts("");
        cnt1=cnt2=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='('){
                if(cnt2){cnt1=cnt2=-INF;break;}
                cnt1++;
            }
            if(s[i]==')') cnt2++;
            if(cnt1==cnt2) break;
        }
        // printf("%d %d\n",cnt1,cnt2);
        if(cnt2==-INF){
            for(int i=0;i<=m-n;i++) g[i]=1;
        }
        else{
            for(int i=0;i<=m-n;i++) g[i]=C(cnt2+i,i);
            for(int i=1;i<=m-n;i++) g[i]=(g[i-1]+g[i])%mod;
        }
        // for(int i=0;i<=m-n;i++) printf("%d ",g[i]);puts("");
        for(int i=0;i<=m-n;i++) Ans=(Ans+1ll*f[i]*g[m-n-i]%mod)%mod;
        printf("%d\n",Ans);Ans=0;
        for(int i=0;i<=m-n;i++) f[i]=g[i]=0;
    }
    return 0;
}
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

const int MAXN=5e3;
const int MOD=998244353;
char s[MAXN+5];
int n,c0[MAXN+5],c1[MAXN+5],dp[MAXN+5][MAXN+5];
int hd[MAXN+5],to[MAXN*2+10],nxt[MAXN*2+10],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int tmp[MAXN+5];
void dfs(int x,int f){
	dp[x][0]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;dfs(y,x);
		memset(tmp,0,sizeof(tmp));
		for(int u=0;u<=min(c0[x],c1[x]);u++)
			for(int v=0;v<=min(c0[y],c1[y]);v++){
				tmp[u+v]=(tmp[u+v]+1ll*dp[x][u]*dp[y][v])%MOD;
			}
		c0[x]+=c0[y];c1[x]+=c1[y];
		for(int u=0;u<=min(c0[x],c1[x]);u++) dp[x][u]=tmp[u];
	}
	if(s[x]=='0'){
		for(int u=min(c0[x],c1[x]);~u;u--){
			dp[x][u+1]=(dp[x][u+1]+1ll*dp[x][u]*(c1[x]-u))%MOD;
		} c0[x]++;
	} else {
		for(int u=min(c0[x],c1[x]);~u;u--){
			dp[x][u+1]=(dp[x][u+1]+1ll*dp[x][u]*(c0[x]-u))%MOD;
		} c1[x]++;
	}
//	for(int u=0;u<=min(c0[x],c1[x]);u++) printf("%d %d %d\n",x,u,dp[x][u]);
}
int fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int binom(int n,int k){return 1ll*fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;}
int f[MAXN+5],g[MAXN+5];
int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%s",&n,s+1);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);

    for(int i=0;i<=n;i++) printf("%d ",dp[1][i]);puts("");

    init_fac(n);
	for(int i=0;i<=n/2;i++) f[i]=1ll*fac[n/2-i]*dp[1][i]%MOD;
	for(int i=0;i<=n/2;i++){
		for(int j=i;j<=n/2;j++){
			if((j-i)&1) g[i]=(g[i]-1ll*binom(j,i)*f[j]%MOD+MOD)%MOD;
			else g[i]=(g[i]+1ll*binom(j,i)*f[j])%MOD;
		} printf("%d\n",g[i]);
	}
	return 0;
}
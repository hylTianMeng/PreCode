#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxl=105,mod=1e9+7;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}
int n,cnt;
int head[maxl],f[maxl][maxl][2],siz[maxl],F[maxl][2],res[maxl],jc[maxl],inv[maxl];
struct edge{int nxt,to;}e[maxl<<1];

void chksum(int x,int &y){y=(y+x)%mod;}
void add_edge(int u,int v){e[++cnt].to=v,e[cnt].nxt=head[u],head[u]=cnt;}
int C(int x,int y){return ((jc[x]*inv[y])%mod*inv[x-y])%mod;}
int quick_power(int x,int y){
	int res=1;
	for (;y;y=y>>1,x=(x*x)%mod){
		if (y&1)  res=(res*x)%mod;
	}
	return res;
}
void init(){
	jc[0]=1;
	for (int i=1;i<=n;i++)  jc[i]=(jc[i-1]*i)%mod;
	inv[n]=quick_power(jc[n],mod-2);
	for (int i=n-1;i>=0;i--)  inv[i]=(inv[i+1]*(i+1))%mod;
}
void dfs(int now,int fath){
	f[now][0][0]=f[now][0][1]=1,siz[now]=1;
	for (int i=head[now];i;i=e[i].nxt){
		int y=e[i].to;
		if (y==fath)  continue;
		dfs(y,now);
		for (int j=0;j<=siz[now];j++){
			for (int k=0;k<=min(n-j,siz[y]);k++){
				for (int u=0;u<=1;u++){
					for (int v=0;v<=1&&u+v<2;v++)  chksum(f[now][j][u]*f[y][k][v]%mod,F[j+k+1][u|v]);
				}
				for (int u=0;u<=1;u++)  chksum((f[now][j][u]*f[y][k][1])%mod,F[j+k][u]);
			}
		}
		siz[now]+=siz[y];
		for (int j=0;j<=siz[now];j++){
			for (int k=0;k<=1;k++){
				  f[now][j][k]=F[j][k],F[j][k]=0; 
				printf("f[%d][%d][%d]=%d\n",now,j,k,f[now][j][k]);
			}
		}
	}
}

signed main(){
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	n=read();init();
	for (int i=1;i<n;i++){
		int u=read(),v=read();
		add_edge(u,v),add_edge(v,u);
	}
	dfs(1,0),res[n-1]=1;
	for (int i=0;i<n-1;i++)  res[i]=(f[1][i][1]*quick_power(n,n-i-2))%mod;
	for(int i=0;i<n-1;i++){
		printf("g[%d]=%d\n",i,res[i]);
	}
	for (int i=0;i<n;i++){
		int val=0,cur;
		for (int j=i;j<=n;j++)  cur=(C(j,i)*res[j])%mod,chksum(((j-i)&1)?(mod-cur):(cur),val);
		printf("%lld ",val);
	}
	return 0;
}
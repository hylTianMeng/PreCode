#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5010;
int n,cnt,ans;
int head[maxn];
int f[maxn][maxn],g[maxn][maxn];
struct edge
{
	int to,nxt;
}e[maxn<<1];
inline int read()
{
	char c=getchar();int res=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res*f;
}
inline void add(int u,int v)
{
	e[++cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}
void dfs(int x,int fa)
{
	f[x][0]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(y==fa)continue;
		dfs(y,x);
		for(int j=0;j<n;j++)	
		{
			if(j)ans+=f[x][j-1]*g[y][j];
			ans+=g[x][j+1]*f[y][j];
		}
		for(int j=0;j<n;j++)
		{
			g[x][j+1]+=f[x][j+1]*f[y][j];
			if(j)g[x][j-1]+=g[y][j];
			f[x][j+1]+=f[y][j];
		}
	}
}
signed main()
{
    freopen("my.in","r",stdin);
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
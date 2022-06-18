#include<cstdio>
#include<vector>
using std::vector;
typedef long double ldb;
const int N=55;
int n;
vector<int> G[N];
int size[N];
ldb fact[N];
ldb dp[N][N],tmp[N],g[N];
inline ldb choose(int n,int m)
{
	return fact[n]/(fact[m]*fact[n-m]);
}
void dfs(int now,int father)
{
	register int i,j;
	dp[now][0]=1;size[now]=1;
	for(auto x:G[now])
	{
   
		if(x==father)
			continue;
		dfs(x,now);
     printf("to=%d\n",x);
		for(i=0;i<=size[x];i++)
		{
			g[i]=0;
			for(j=1;j<=size[x];j++)
				if(j<=i)
					g[i]+=0.5*dp[x][j-1];
				else
					g[i]+=dp[x][i];
            printf("g[%d]=%Lf\n",i,g[i]);
		}
		for(i=0;i<size[now]+size[x];i++)
			tmp[i]=0;
		for(i=0;i<size[now];i++)
			for(j=0;j<=size[x];j++)
				tmp[i+j]+=dp[now][i]*g[j]*choose(i+j,i)*choose(size[now]-1-i+size[x]-j,size[now]-1-i);
		for(i=0;i<size[now]+size[x];i++)
		{	dp[now][i]=tmp[i];printf("h[%d]=%Lf\n",i,tmp[i]);}
		size[now]+=size[x];
	}
	return;
}
signed main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	int x,y;
	register int i;
	scanf("%d",&n);
	fact[0]=1;
	for(i=1;i<=n-1;i++)
		fact[i]=fact[i-1]*i;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(i=2;i<=n;i++)
	{
		dfs(i,0);
		printf("%.9lf\n",(double)(dp[i][n-1]/fact[n-1]));
	}
	return 0;
}

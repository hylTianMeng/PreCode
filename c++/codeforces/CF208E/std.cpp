#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,q,i,j,x,y,z,l,r,cnt,an[19][MAXN],f[MAXN],dep[MAXN],in[MAXN],out[MAXN];
vector<int> G[MAXN],inn[MAXN];
inline void read(int &x)   //快读 
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
    	if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
inline void print(int x)   //快输 
{
    if (x<0)
        putchar('-'),x=-x;
    if (x>9)
        print(x/10);
    putchar(x%10+'0');
}
inline void dfs(int u)
{
	an[0][u]=f[u];
	dep[u]=dep[f[u]]+1;  //深度 
	in[u]=++cnt;         //dfs序 入序 
	inn[dep[u]].push_back(in[u]);  //将这个点的dfn放入本层的vector中(满足单调性)
	for (int i=0;i<G[u].size();i++)
		dfs(G[u][i]);
	out[u]=cnt;    //dfs序 出序 
}
signed main(void)
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	read(n);
	for (i=1;i<=n;i++)
	{
		read(f[i]);
		G[f[i]].push_back(i);
	}
	dep[0]=-1;  //我只是想让0号点深度为0而已 
	dfs(0);
	for (j=1;j<19;j++)  //倍增 
		for (i=1;i<=n;i++)
			an[j][i]=an[j-1][an[j-1][i]];
	read(q);
	while (q--)
	{
		read(x),read(y);
		z=dep[x];
		if (y>=z)  //由于数据的特异性,需要特判 
		{
			printf("0 ");
			continue;
		}
		for (j=18;j>=0;j--)  //找到k级祖先 
			if (an[j][x] && y>=(1<<j))
				x=an[j][x],y-=(1<<j);
		l=lower_bound(inn[z].begin(),inn[z].end(),in[x])-inn[z].begin()-1;
		r=upper_bound(inn[z].begin(),inn[z].end(),out[x])-inn[z].begin()-1;
		//二分求出k-son的最左边与最右边 
		print(r-l+1),putchar(' ');
	}
	return 0;
}
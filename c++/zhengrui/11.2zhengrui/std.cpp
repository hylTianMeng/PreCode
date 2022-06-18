#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
#include<set>
#define ll long long
using namespace std;
const int inf = 0x7fffffff;
int n,m;
#define maxn 800009
vector<int> son[maxn];
int tot=0;

int fa[maxn][88],dep[maxn];
void Init()
{

	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
}
//树上倍增的 dp，处理 fa 数组
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int l=dep[x]-dep[y],k=0;
	while(l)
	{
		if(l&1)x=fa[x][k];
		k++;
		l>>=1;
	}
	if(x==y)return x;
	for(int i=30;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];
		}
	}
	return fa[x][0];
}
//求两个点的lca
void dfs(int x,int f)
{
	fa[x][0]=f;
	for(int i=0;i<son[x].size();i++)
	{
		int to=son[x][i];
		if(to==f)continue;
		dep[to]=dep[x]+1;
		dfs(to,x);
	}
}
//这个 dfs 能够预处理 fa 数组以及每个点的深度。

map<int,int> num[maxn];
vector<int> val[maxn];
int fro[maxn],t[maxn];
signed main()
{
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(!num[x][y])
		{
			num[x][y]=num[y][x]=++tot;son[x].push_back(y);son[y].push_back(x);
			fro[tot]=x,t[tot]=y;
		}
		val[num[x][y]].push_back(z);
	}
	//这里是输入，貌似用了多种方式来存图，其中我们给每条边一个编号，然后我们存下这条边的两个端点，用 vector 代替邻接表
	//然后读入每条边的可能的权值。
	dfs(1,0);
	Init();
	//这里是树上倍增，直接预处理完了 fa 数组。
	int q;scanf("%d",&q);
	vector<int> road;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int l=LCA(x,y);
		printf("Lca=%d\n",l);
		road.clear();
		while(x!=l)road.push_back(x),x=fa[x][0];
		//我们暴力往上条父亲，这里复杂度之所以对，是因为数据时随机造的，所以树的深度接近于 log。
		//我们把从 x 到 lca 之前的所有点都存到 road 里面。
		stack<int> st;
		road.push_back(l);
		//开栈，并放入 lca 作为一条链。
		while(y!=l)st.push(y),y=fa[y][0];
		//这边同样处理，只不过把节点存在栈中（竟然不清空栈）
		while(!st.empty())road.push_back(st.top()),st.pop();
		//然后我们把整个路径剖开成这样。
		priority_queue<pair<int,int> > q[2];
		//竟然还开了一个堆吗。。。
		q[0].push(make_pair(0,0));
		//接下来应该是算法主题，我们已经处理出了这条链，存到 road 里面。
		//接下来就是类似于一个滚动堆的东西。
		//这个pair第一维是当前贡献，第二维是当前贡献地颜色。
		for(int i=1;i<road.size();i++)
		{
			while(!q[i&1].empty())q[i&1].pop();
			for(auto j:val[num[road[i]][road[i-1]]])//枚举这条边能用哪个权值 
			{
				pair<int,int> it=q[i&1^1].top();//上一个点来的最大答案 
				if(j!=it.second)//能继续走可以换边 
				{
					q[i&1].push(make_pair(it.first+1,j));
				}else//边权一样了就可以pop  
				{
					q[i&1^1].pop();
					if(!q[i&1^1].empty())q[i&1].push(make_pair(max(it.first,q[i&1^1].top().first+1),j));
					else q[i&1].push(make_pair(it.first,j));
					q[i&1^1].push(it);
				}
			}
		}
		printf("%d\n",max(0,-1+q[road.size()-1&1].top().first));
	}
	return 0;
}

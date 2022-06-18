// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// const ll N=1e6+10,M=2e6+10;
// const ll inf=1e17;
// ll n,m,k,t,head[N];
// struct node
// {
	// ll from,to,nxt,len;ll val;
	//from,to,next的概念明了，len的意义是边权。
	// bool mark;
// }e[M<<1],ec[M<<1];
// void add(ll x,ll y,ll z)
// {
// 	e[++k].to=y;e[k].nxt=head[x];head[x]=k;e[k].len=z;e[k].from=x;
// }
//邻接表插入边。
// struct data
// {
	// ll x;ll dis;
	// data(ll x=0,ll dis=0) :x(x),dis(dis){}
// };priority_queue<data>q;
//优先队列要用的结构体。
// bool operator < (data x,data y)
// {
// 	return x.dis>y.dis;
// }
// ll dis[N];
// ll fath[N],dep[N];
// bool vis[N];
// void dfs(ll u,ll lst)
// {
// 	vis[u]=1;fath[u]=lst;dep[u]=dep[lst]+1;
// 	for(ll i=head[u];i;i=e[i].nxt)
// 	{
// 		ll v=e[i].to;
// 		if(dis[v]!=dis[u]+e[i].len||vis[v]) continue;
// 		e[i].mark=1;
// //		printf("%d->%d\n",u,v);
// 		dfs(v,u);
// 	}
// }
//求解最短路树，把最短路数路径标记为1，然后预处理出最短路树上节点的父亲和深度。
// void dij()
// {
// 	for(ll i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
// 	q.push(data(t,0));dis[t]=0;
// 	while(!q.empty())
// 	{
// 		ll x=q.top().x;q.pop();
// 		if(vis[x]) continue;
// 		vis[x]=1;
// 		for(ll i=head[x];i;i=e[i].nxt)
// 		{
// 			ll v=e[i].to;
// 			if(dis[v]>dis[x]+e[i].len)
// 				dis[v]=dis[x]+e[i].len,q.push(data(v,dis[v]));
// 		}
// 	}
// }
//纯粹的迪杰斯特拉，复杂度 O(nlogn)
// bool cmp(node x,node y)
// {
// 	return x.val<y.val;
// }
// ll fa[N];
// ll val[N];
// ll find(ll x)
// {
// 	if(fa[x]==x) return x;
// 	return fa[x]=find(fa[x]);
// }
//并查集.
// void update(ll x,ll y,ll z)
// {
	//不要忘记x和y是一个路径。
	// if(!dep[x]||!dep[y]) return;
	//如果某个点的深度为 0（为根），就返回
	// x=find(x);y=find(y);
	//找到两个节点所在集合代表。
	// while(x!=y)
	// {
		// if(dep[x]<dep[y]) swap(x,y);
		//保证y在上x在下。
		// val[x]=z;fa[x]=fath[x];x=find(x);
	// }
// }
//这个函数可以完成这样一个操作，对于一个非树边，两端节点为 a,b, lca 为 k
//我们把 a,b 到 k 之间的树边的 val 值全部设为 dis[a]+dis[b]+w(a,b)。
//因为我们从小到大排序，所以满足这些树边上的 val 一定是最小的，并查集满足不重复覆盖。
ll dp[N];
void getans()
{
	for(ll i=1;i<=n;i++) dp[i]=inf,vis[i]=0;
	q.push(data(t,0));dp[t]=0;
	while(!q.empty())
	{
		ll x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(ll i=head[x];i;i=e[i].nxt)
		{
			ll v=e[i].to;
			if(dp[v]>max(val[v],dp[x]+e[i].len))
				dp[v]=max(val[v],dp[x]+e[i].len),q.push(data(v,dp[v]));
		}
	}
}

int main()
{
	// scanf("%lld%lld%lld",&n,&m,&t);
	// for(ll i=1,x,y,z;i<=m;i++)
	// 	scanf("%lld%lld%lld",&x,&y,&z),add(x,y,z),add(y,x,z);
	//输入基本信息。
	// dij();
//	for(ll i=1;i<=n;i++) printf("%d ",dis[i]);puts("");
	// for(ll i=1;i<=n;i++) vis[i]=0,val[i]=inf;
	//给val数组赋初值，求解val数组，vis数组清零。
	//猜测val数组含义与题解所说相同，val[i]表示堵住i与其父亲的连边后，最短路。
	// dfs(t,0);
	// int tm=0;
	// for(ll i=1;i<=k;i+=2) if(!e[i].mark&&!e[i+1].mark)
		// ec[++tm]=e[i],ec[tm].val=dis[e[i].to]+dis[e[i+1].to]+e[i].len;
	// sort(ec+1,ec+tm+1,cmp);
	//把所有非树边拿出来，按照val拍序，其中val等于其路径两端的 dis 值加上这条边的权值。
	//这么做的原因还不清楚
	// for(ll i=1;i<=n;i++) fa[i]=i;
	//预处理并查集。
	// for(ll i=1;i<=tm;i++) update(ec[i].from,ec[i].to,ec[i].val);
	// for(ll i=1;i<=n;i++) val[i]-=dis[i];
//	for(ll i=1;i<=n;i++) printf("%d ",val[i]);puts("");
	getans();
	for(ll i=1;i<=n;i++) printf("%lld ",dp[i]<(inf/10)?dp[i]:-1);
}
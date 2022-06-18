#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,maxk=1000100;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,el,head[maxn],to[maxn*2],w[maxn*2],nxt[maxn*2];
int rt,tot,sz[maxn],son[maxn],mine[maxk],ans=INT_MAX,dis1[maxn],dis2[maxn],dl;
bool vis[maxn];
inline void add(int u,int v,int w_){
	to[++el]=v;w[el]=w_;nxt[el]=head[u];head[u]=el;
}
void getrt(int u,int f){	//求重心
	sz[u]=1;son[u]=0;
	for(int i=head[u];i;i=nxt[i]){
    	//v=to[i]不是必需的，可以去掉
		if(to[i]==f || vis[to[i]]) continue;
		getrt(to[i],u);
		sz[u]+=sz[to[i]];son[u]=max(son[u],sz[to[i]]);
	}
	son[u]=max(son[u],tot-sz[u]);
	if(son[u]<son[rt]) rt=u;
}
void getdis(int u,int f,int d1,int d2){	//dfs将子树的信息记录下来（d1是权值和，d2是边数）
	if(d1>k) return;
	dis1[++dl]=d1;dis2[dl]=d2;
	for(int i=head[u];i;i=nxt[i]){
    	//同上
		if(to[i]==f || vis[to[i]]) continue;
		getdis(to[i],u,d1+w[i],d2+1);
	}
}
void getans(int u){	//计算经过u的路径的答案
	mine[0]=0;dl=0;	//mine[0]是0！因为一个端点是u的路径也要考虑，而且0不会被其它子树记录到
	for(int i=head[u];i;i=nxt[i]){
		if(vis[to[i]]) continue;
		int pdl=dl;	//前面的子树有多少元素
		getdis(to[i],u,w[i],1);	//注意调用时w[i]和1
		FOR(j,pdl+1,dl) ans=min(ans,mine[k-dis1[j]]+dis2[j]);
        //更新答案
		FOR(j,pdl+1,dl) mine[dis1[j]]=min(mine[dis1[j]],dis2[j]);
        //更新桶
	}
	FOR(i,1,dl) mine[dis1[i]]=1e9;
}
void getall(int u){	//点分治主过程
	vis[u]=true;
	getans(u);
	for(int i=head[u];i;i=nxt[i]){
		if(vis[to[i]]) continue;
		tot=sz[to[i]];rt=0;
		getrt(to[i],u);
		getall(rt);
	}
}
int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	n=read();k=read();
	FOR(i,1,n-1){
		int u=read()+1,v=read()+1,w=read();	//编号从0开始
		add(u,v,w);add(v,u,w);
	}
	son[0]=(tot=n)+1;	//son[0]设为INF
	getrt(1,0);
	MEM(mine,0x3f);
	getall(rt);
	printf("%d\n",ans>=n?-1:ans);	//最短长度超过n就是无解
}
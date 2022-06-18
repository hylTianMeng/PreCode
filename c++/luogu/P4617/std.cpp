#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,x,y,vis[N],head[N],cnt,ans[N],match[N];
struct edge{
	int to,nxt;
}e[N];
void add(int u,int v){
	e[++cnt].to=v,e[cnt].nxt=head[u],head[u]=cnt;
}
int dfs1(int u){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(vis[v])continue;
		vis[v]=1;
		if(!match[v]||dfs1(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}
void dfs2(int u){//跑增广路
	ans[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(vis[v])continue;
		vis[v]=1;
		dfs2(match[v]);
	}
}
int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		x=read(),y=read();
		add(x,y);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs1(i))continue;
        printf("here\n");
		memset(vis,0,sizeof(vis));
		dfs2(i);
	}
	for(int i=1;i<=n;i++)puts(!ans[i]?"Slavko":"Mirko");
	return 0;
}
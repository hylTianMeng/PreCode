#include<bits/stdc++.h>
using namespace std;
const int N=4e6+5;
int n,m,x,y,cnt=1,hd[N],to[N<<1],nxt[N<<1],in[N],num,ans[N];
bool vis[N];
void add(int x,int y){
	to[++cnt]=y,nxt[cnt]=hd[x],hd[x]=cnt,in[y]++; 
}
void dfs(int x){
    for(int &i=hd[x];i;i=nxt[i]){
        int y=to[i],j=i>>1; 
        if(vis[j]) continue;
        vis[j]=1,dfs(y),ans[j]=(++num)&1;
    }
}
signed main(){
	scanf("%d%d",&n,&m);
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)
		if(in[i]&1) add(i,0),add(0,i);
	for(int i=0;i<=n;i++){
		num=0,dfs(i);
		if((num&1)&&i) puts("-1"),exit(0);
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int N=2e5+5;
int n,m,k,lim=(1ll<<31)-1,x,y,Q,tot,rt[N],lc[N<<5],rc[N<<5],cnt[N<<5],sum[N<<5],f[N],ans[N];
bool vis[N];
vector<int>v[N];
multiset<int>s;
struct node{
	int a,b,id;
	inline bool operator < (const node &b)const{return a<b.a;}
}a[N]; 
struct query{
	int v,id; 
	vector<int>a;
	inline bool operator < (const query &b)const{return v<b.v;}
}q[N];
void pushup(int p){sum[p]=sum[lc[p]]+sum[rc[p]];} 
void modify(int &p,int l,int r,int pos,int v){
	if(!p) p=++tot;
	if(l==r){sum[p]=((cnt[p]+=v)%k==0);return ;}
	int mid=(l+r)/2;
	if(pos<=mid) modify(lc[p],l,mid,pos,v);
	else modify(rc[p],mid+1,r,pos,v);
	pushup(p); 
}
void merge(int &x,int y,int l,int r){
	if(!x||!y){x|=y;return ;} 
	if(l==r){sum[x]=((cnt[x]+=cnt[y])%k==0);return ;}
	int mid=(l+r)/2;
	merge(lc[x],lc[y],l,mid);
	merge(rc[x],rc[y],mid+1,r);
	pushup(x);
}
int find(int x){return x==f[x]?x:f[x]=find(f[x]);} 
signed main(){
	// freopen("my.in","r",stdin);
	// freopen("std.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].a),a[i].id=i;
	for(int i=1;i<=n;i++) scanf("%d",&a[i].b);
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&q[i].v,&x),q[i].id=i;
		while(x--) scanf("%d",&y),q[i].a.push_back(y);
	} 
	sort(q+1,q+1+Q);
	for(int i=1,j=1;i<=n+1;i++){
		// printf("i=%d\n",i);
		while(j<=Q&&(i>n||q[j].v<a[i].a)){
			for(int p:q[j].a)
				if(f[p]&&!vis[x=find(p)]) s.erase(s.find(-sum[rt[x]])),vis[x]=1;
			ans[q[j].id]=-*s.begin();
			// printf("ans[%d]=%d\n",q[j].id,ans[q[j].id]);
			for(int p:q[j].a)
				if(f[p]&&vis[x=find(p)]) s.insert(-sum[rt[x]]),vis[x]=0;
			j++;
		}
		if(i>n) break;
		x=a[i].id,f[x]=x,modify(rt[x],1,lim,a[i].b,1),s.insert(-sum[rt[x]]);
		// // printf("sum[%d]=%d\n",rt[x],sum[rt[x]]);
		for(int y:v[x]) if(f[y]){
			int u=find(x),v=find(y);
			if(u==v) continue;
			s.erase(s.find(-sum[rt[u]])),s.erase(s.find(-sum[rt[v]]));
			f[v]=u,merge(rt[u],rt[v],1,lim),s.insert(-sum[rt[u]]);
		}
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}
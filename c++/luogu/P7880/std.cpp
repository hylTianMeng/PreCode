#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e5+5;
int n,m;long long c[N];vector<long long> col;
struct Edge{int nxt,to,val;}e[N<<1];int fir[N];
void add(int u,int v,int w,int i){e[i]=(Edge){fir[u],v,w},fir[u]=i;}
struct Query{int l,r,id;}a[M];bool cmp(Query a,Query b){return a.r<b.r;}
vector<pair<int,int> > opt[N];set<int> bag[N];
int get_id(long long c){return lower_bound(col.begin(),col.end(),c)-col.begin()+1;}
void merge(int c,int u,int v){
	if(bag[u].size()<bag[v].size()) swap(bag[u],bag[v]);
	for(set<int>::iterator i=bag[v].begin(),j;i!=bag[v].end();++i){
		j=bag[u].upper_bound(*i);
		if(j!=bag[u].end()) opt[*j].push_back(make_pair(c,*i));
		j=bag[u].lower_bound(*i);
		if(j!=bag[u].begin()) j--,opt[*i].push_back(make_pair(c,*j));
	}
	while(!bag[v].empty()){
		bag[u].insert(*bag[v].begin());
		bag[v].erase(bag[v].begin());
	}
}
void dfs1(int u,int fa){
	for(int i=fir[u];i;i=e[i].nxt){
		int v=e[i].to;if(v==fa) continue;
		c[v]=c[u]+e[i].val,dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	for(int i=fir[u];i;i=e[i].nxt){
		int v=e[i].to;if(v!=fa) dfs2(v,u);
	}
	bag[u].insert(u);int tmp=get_id(c[u]);
	opt[u].push_back(make_pair(tmp,u));
	for(int i=fir[u];i;i=e[i].nxt){
		int v=e[i].to;if(v!=fa) merge(tmp,u,v);
	}
}
struct Tree_Array{
	int tr[N];
	int lowbit(int k){return k&(-k);}
	void add(int k,int x){for(;k<=n;k+=lowbit(k))tr[k]+=x;}
	int sum(int k){int res=0;for(;k;k-=lowbit(k))res+=tr[k];return res;}
}t;
int pos[N],res[M];
int main(){
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add(u,v,w,i<<1),add(v,u,w,i<<1|1);
	}
	for(int i=1;i<=m;++i) scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	sort(a+1,a+1+m,cmp),dfs1(1,0);
	for(int i=1;i<=n;++i) col.push_back(c[i]);
	sort(col.begin(),col.end());
	col.erase(unique(col.begin(),col.end()),col.end());
	dfs2(1,0);int R=0;
	for(int i=1;i<=m;++i){
		while(R<a[i].r){
			++R;
			for(int j=0;j<(int)opt[R].size();++j){
				pair<int,int> tmp=opt[R][j];
				if(pos[tmp.first]) t.add(pos[tmp.first],-1);
				pos[tmp.first]=max(pos[tmp.first],tmp.second);
				t.add(pos[tmp.first],1);
			}
		}
		res[a[i].id]=t.sum(a[i].r)-t.sum(a[i].l-1);
	}
	for(int i=1;i<=m;++i) printf("%d\n",res[i]);
	return 0;
}
/*
这是什么毒瘤题。
原本想从 O(1) lca 的角度去思考，但是发现边权可以是负的。
等一下，如果存在两个点 dep 相同但是点不相同，能否意味着还存在一个 lca ？
好像不太行，因为可能两个点的 lca 的深度是和他们相同的。
--------------------------------------------------------------
或者是我们考虑每一个 lca 的贡献。
但是由于是编号上的询问，我们根本不好搞。
根据不同的深度建虚树？这样会丢失掉点标号的信息。
-------------------------------------------------------------
偷偷看了下题解第一段，意识到自己题目转化错了，是求区间虚树的颜色数。我们再来尝试做
做看。
既然是区间的虚树数颜色，首先每一个点自己会产生贡献。然后他会与区间中的点组合然后再
lca 处做贡献。
首先感觉会有莫队的思路，但是发现我们动态虚树维护是带一个log，所以我们不考虑。
然后数颜色还有一种线段树的搞法，我们考虑这里可不可以实现。
考虑线段树上记录的是当前右端点每一个颜色最后出现的位置。
然后考虑右端点向右移动一位的话，实际上可能会增加很多的位置，这是并不合算的。
我们从单独的 lca 出发，该点的颜色最后一个的位置应该就是倒数第二个的子树。
------------------------------------------------------------------------
思路方向有点对了，但是不知道怎么处理。
实际上每一个点只需要找到其在其祖先中的前驱即可。
我们考虑这个东西的复杂度是什么？实际上我们容易想到树上启发式合并。
然后我们实际上寻找这个前驱的过程可以在启发式合并的过程中搞？
每个点在插入的时候找到前驱后继，更新即可。
NB啊，这是什么神仙题。
*/

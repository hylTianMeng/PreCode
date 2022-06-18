#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m,a[3][N];
ll pre[3][N],f[N],g[N],dp[N];
struct node
{
	ll v1,v2,v3;
	friend node operator + (node a,node b)
	{
		return (node){max(a.v1,b.v1),max(a.v2,b.v2),max(max(a.v3,b.v3),a.v1+b.v2)};
	}
};
struct SegmentTree
{
	node t[N<<2];
	void pushup(int p){t[p]=t[p<<1]+t[p<<1|1];}
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			t[p].v1=pre[0][l]-pre[1][l-1];
			t[p].v2=pre[1][l]-pre[2][l-1]+pre[2][n];
			t[p].v3=pre[0][l]+a[1][l]-pre[2][l-1]+pre[2][n];
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void upd(int p,int l,int r,int x,ll v)
	{
		if(l==r){t[p].v1=max(t[p].v1,v),t[p].v3=max(t[p].v3,t[p].v1+t[p].v2);return;}
		int mid=(l+r)>>1;
		if(x<=mid)upd(p<<1,l,mid,x,v);
		else upd(p<<1|1,mid+1,r,x,v);
		pushup(p);
	}
	node query(int p,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return t[p];
		int mid=(l+r)>>1;
		if(R<=mid)return query(p<<1,l,mid,L,R);
		if(L>mid)return query(p<<1|1,mid+1,r,L,R);
		return query(p<<1,l,mid,L,R)+query(p<<1|1,mid+1,r,L,R);
	}
}segt;
vector<pair<int,int> >q[N];
int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]),pre[i][j]=pre[i][j-1]+a[i][j];
	for(int i=1,l,r,k;i<=m;i++)
		scanf("%d%d%d",&l,&r,&k),q[r].push_back(make_pair(l,k));
	segt.build(1,1,n);
	ll ans=-9e18;
    printf("spe=%d\n",segt.t[1].v3);
	for(int i=1;i<=n;i++)
		for(auto p:q[i])
		{
			int l=p.first,k=p.second;
            printf("l=%d r=%d\n",l,i);
			node res=segt.query(1,1,n,l,i);
            printf("nowans=%lld\n",res.v3);
			ans=max(ans,res.v3-k);
			if(i<n)segt.upd(1,1,n,i+1,res.v1-k);
		}
	printf("%lld",ans);
	return 0;
}

							 	     			  		 					 			
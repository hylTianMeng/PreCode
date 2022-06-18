#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<vector>
#include<queue>
#define ll long long
#define ld long double

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

const ll inf=1e18;
const ll maxn=4e5+10;
ll n;
ll a[maxn],b[maxn],used[maxn];
ll s[62];
std::vector<ll> e[maxn];
std::vector<ll> sta1[maxn],sta2[maxn];

inline void dfs(ll x,ll f)
{
	sta1[x].push_back(x);
	sta2[x].push_back(x);
	for(auto v : sta1[f]) sta1[x].push_back(v);
	for(auto v : e[x])
	{
		if(v==f) continue;
		dfs(v,x);
		for(auto i : sta2[v]) sta2[x].push_back(i);
	}
}

inline void insert(ll x)
{
	for(int i=61;i>=0;i--)
	{
		if(!(x>>i)) continue;
		else
		{
			if(!s[i])
			{
				s[i]=x;
				break;
			}
			x^=s[i];
		}
	}
}

inline ll query()
{
	ll ans=0;
	for(int i=61;i>=0;i--)
	{
		if((ans^s[i])>ans) ans^=s[i];
	}
	return ans;
}

int main(void)
{
//	freopen("julian3.in","r",stdin);
//	freopen("ex_c3.ans","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<n;i++)
	{
		ll u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		memset(s,0,sizeof(s));
		for(auto v : sta1[i]) used[v]=1;
		for(auto v : sta2[i]) used[v]=1;
		for(int j=1;j<=n;j++)
		{
			if(!used[j]) insert(b[j]);
		}
		printf("%lld\n",query());
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
#define R(i,a,b) for(int i=(a),i##E=(b);i<=i##E;i++)
#define L(i,a,b) for(int i=(b),i##E=(a);i>=i##E;i--)
using namespace std;
int n,m;
int a[1111111],d[1111111],ans[1111111];
int tag1,tag2;
set<int>st;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int l=0,r=m;
	R(i,1,n-2)
	{
		cin>>a[i];
		int ll,rr,t;
		if(tag1&1) ll=tag2,rr=tag2-a[i];
		else ll=-tag2,rr=a[i]-tag2;
		t=rr;
		if(ll>rr) swap(ll,rr);
		l=max(l,ll),r=min(r,rr);
		while(st.size()&&(*st.begin())<ll) st.erase(st.begin());
		while(st.size()&&(*st.rbegin())>rr) st.erase(*st.rbegin());
		if(!st.size()&&l>r) 
		{
			cout<<"NO\n";
			return 0;
		}
		if(st.count(t)||(l<=t&&t<=r))
		{
			l=0,r=ans[i]=a[i];
			st.clear();
			tag1=tag2=0;
			continue;
		}
		if(l<=r)
		{
			if(tag1) ans[i]=tag2-l;
			else ans[i]=tag2+l;
		}
		else
		{
			int tt=*st.begin();
			if(tag1) ans[i]=tag2-tt;
			else ans[i]=tag2+tt;
		}
		tag1^=1;tag2=a[i]-tag2;
		if(tag1&1) t=tag2-a[i];
		else t=a[i]-tag2;
		st.emplace(t);
	}

	if(l<=r)
	{
		if(tag1) d[n-1]=tag2-l;
		else d[n-1]=tag2+l;
	}
	else
	{
		int tt=*st.begin();
		if(tag1) d[n-1]=tag2-tt;
		else d[n-1]=tag2+tt;
	}
	L(i,1,n-2)
	{
		if(ans[i]==a[i]) 
		{
			d[i]=a[i];
		}
		else if(d[i+1]==a[i]) d[i]=ans[i];
		else d[i]=a[i]-d[i+1];
	}
	int ret=1;
	L(i,1,n-2) 
	{
		if(abs(d[i])+abs(d[i+1])!=a[i]) ret*=-1;
		d[i]=ret*d[i];
	}
	ret=0;
	R(i,1,n-1) d[i]+=d[i-1],ret=min(ret,d[i]);
	cout<<"YES\n";
	R(i,1,n) cout<<d[i-1]-ret<<" ";
	cout<<endl;
}
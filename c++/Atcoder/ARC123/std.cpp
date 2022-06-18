#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	int n;
	cin>>n;
	
	vector<int> pre(n+1),pri;
	for (int i=2;i<=n;++i){
		if (!pre[i]) pre[i]=i,pri.push_back(i);
		for (auto p:pri){
			if (i*p>n) break;
			pre[i*p]=p;
			if (i%p==0) break;
		}
	}
	
	vector<int> f(n+3),a(n+1);
	for (int i=1;i<=n;++i){
		int x;
		cin>>a[i];
		if (i%2==0) continue;
		x=a[i];
		int l,r;
		if (i==1) l=0,r=n+1;
		 else l=i-pre[i]+1,r=min(n+1,i+pre[i]);
		f[l]+=x;
		f[r]-=x;
		printf("i=%d\n",i);
		printf("%d %d\n",l,r);
	}
	
	int ans=0;
	for (int i=1;i<=n;++i){
		f[i]+=f[i-1];
		ans=max(ans,f[i]);
		if (i%2==0) ans=max(ans,f[i]+a[i]);
	}
	cout<<ans;
	return 0;
}


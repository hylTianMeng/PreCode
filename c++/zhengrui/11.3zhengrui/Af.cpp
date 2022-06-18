#include<bits/stdc++.h>
using namespace std;
#define N 9000
#define ll long long
ll f[N][N],n;
int fir[10000005],sec[10000005];
int a[N],tail;
bool vis[N][N];
pair<int,int> ve[10000005];
pair<pair<int,int>,ll> vem[10000005];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	fir[++tail]=a[1],sec[tail]=a[1];
	f[a[1]][a[1]]=1;
	vis[a[1]][a[1]]=1;
	int o=0;
	for(int i=2;i<=n;i++)
	{
		int vetop=0,vemtop=0;
		for(int j=1;j<=tail;j++)
		{
			vem[++vemtop]=make_pair(make_pair(fir[j]^a[i],sec[j]&a[i]),f[fir[j]][sec[j]]);
			if(!vis[fir[j]^a[i]][sec[j]&a[i]])
			{
				vis[fir[j]^a[i]][sec[j]&a[i]]=1;
				ve[++vetop]=make_pair(fir[j]^a[i],sec[j]&a[i]);
			}
		}
		for(int j=1;j<=vemtop;j++)
			f[vem[j].first.first][vem[j].first.second]+=vem[j].second;
		if(!vis[a[i]][a[i]])
		{
			vis[a[i]][a[i]]=1;
			fir[++tail]=a[i],sec[tail]=a[i];
		}
		f[a[i]][a[i]]++;
		for(int j=1;j<=vetop;j++)
			fir[++tail]=ve[j].first,sec[tail]=ve[j].second;
	}
	ll ans=0;
	for(int i=0;i<=(1<<13)-1;i++)
		ans+=1ll*f[i][i];
	printf("%lld\n",ans);
	return 0;
}
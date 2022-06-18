#include<iostream>
#include<cstdio>
#define ll long long
#define N 1000100
#define M number
using namespace std;

const int mod=1e9+7;

int f[N][3],n,ans=1,inv2=500000004,d[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int from,to;scanf("%d%d",&from,&to);d[from]++;d[to]++;
		ans=1ll*ans*inv2%mod;
	}
	f[0][0]=1;f[0][1]=1;f[0][2]=2;
	for(int i=1;i<=n;i++){
		f[i][0]=(f[i-1][1]+1ll*2*(i-1)*f[i-2][2]%mod)%mod;
		f[i][1]=(f[i][0]+1ll*f[i-1][1]*2*i%mod)%mod;
		f[i][2]=((f[i][1]+f[i][0])%mod+1ll*f[i-1][2]*2*i%mod)%mod;
	}
	for(int i=1;i<=n;i++) ans=1ll*ans*f[d[i]][0]%mod;
	printf("%d",ans);
	return 0;
} 
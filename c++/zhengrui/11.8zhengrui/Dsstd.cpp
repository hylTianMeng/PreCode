#include<bits/stdc++.h>

using namespace std;

#define int long long
//#define i64 long long

template<typename _T>
inline void read(_T &x)
{
	x=0;char s=getchar();int f=1;
	while(s<'0'||s>'9') {f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
const int INF = 1e18;
const int np = 505;
int f[np][np],P[np],W[np];
int n,m;
int Sum[np][np],Sum2[np];
int a[np][np];
long long au = 0;
void E(long long &x, long long y) { x ^= y; x ^= x >> 12; x ^= x << 25; x ^= x >> 27; }
signed  main()
{
//	memset(f,-1,sizeof(f));
	read(n);//,read(m);
	for(int i=1;i <= n;i ++){
		read(P[i]);
		read(W[i]);
		a[i][P[i]] = W[i];
	}
	Sum[0][0]=0;
	for(int i=1;i <= n;i ++)
	{
		for(int j=1;j <= n;j ++)
		{
			Sum2[j] = Sum2[j-1] + a[i][j];
			Sum[i][j] = Sum[i-1][j] + Sum2[j];
		}
	}
	
	f[0][0] = 0;
	for(int i=1;i <= n;i ++)
	{
		for(int j=1;j <= n;j ++)
		{
			int Now=-INF;
			for(int a=1;a < i;a ++)
				for(int b=1;b<j;b ++)
			{
				Now = max(Now,f[a][b]+Sum[a][b]-Sum[a][j]-Sum[i][b]);
			}
			Now = max(Now,0ll);
			Now += Sum[i][j];
			f[i][j]=Now;
//			printf("dp[%lld][%lld]=%lld\n",i,j,Now);
			E(au,Now);
		}
	}
	printf("%lld",au);
 }



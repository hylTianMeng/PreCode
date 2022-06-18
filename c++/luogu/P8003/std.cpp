// Problem: T207070 Hard Brackets Inserting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T207070?contestId=59086
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[1000003];
int fac[1000003],ifac[1000003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int A(int x,int y,int z)
{
	int res=0;
	if(x!=z) return 1;
	for(int i=0; i<=y; ++i)
		res=(res+C(x+i,i))%p; 
	return res;
}
int F[1000003],G[1000003];
signed main()
{
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	const int N=1000000;
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p;
	ifac[N]=qp(fac[N],p-2);
	for(int i=N-1; i>=1; --i) ifac[i]=ifac[i+1]*(i+1)%p;
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		scanf("%s",s+1);
		if(n==2) printf("%lld\n",(m*(m-1)/2)%p*qp(2,m-n)%p);
		else
		{
			m-=n;
			int fir=1,lst=n,fc=0,lc=0,ffc=0,llc=0;
			while(s[fir]=='(') ++ffc,++fir;
			while(s[lst]==')') ++llc,--lst;
			while(s[fir]==')') ++fc,++fir;
			while(s[lst]=='(') ++lc,--lst;
			int ans=0;
			F[0]=G[0]=1;
			for(int i=1; i<=m; ++i) 
			{
				F[i]=F[i-1];
				if(fc==ffc) F[i]=(F[i]+C(fc+i,i))%p;
			}
			for(int i=1; i<=m; ++i) 
			{
				G[i]=G[i-1];
				if(lc==llc) G[i]=(G[i]+C(lc+i,i))%p;
			}
			for(int i=0; i<=m; ++i) ans=(ans+F[i]*G[m-i])%p;
			// for(int i=0;i<=m;i++) printf("%lld ",F[i]);puts("");
			// for(int i=0;i<=m;i++) printf("%lld ",G[i]);puts("");
			printf("%lld\n",ans);
		}
	}
	return 0;
}
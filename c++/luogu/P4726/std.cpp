#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const ll MOD=998244353,inv2=499122177;
int limit,l,r[400005];
ll ni[400005];
void calc_ni(int n)
{
	ni[1]=1;
	for(int i=2;i<=n;i++)
	  ni[i]=MOD-(MOD/i)*ni[MOD%i]%MOD;
}
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
void NTT(ll*A,int type)
{
	for(int i=0;i<limit;i++)
	  if(i<r[i])swap(A[i],A[r[i]]);
	for(int mid=1;mid<limit;mid<<=1)
	{
		ll Wn=type==1?quick_pow(3,(MOD-1)/(mid<<1)):quick_pow(3,MOD-1-(MOD-1)/(mid<<1));
		for(int R=mid<<1,j=0;j<limit;j+=R)
		{
			ll w=1;
			for(int k=0;k<mid;k++,w=w*Wn%MOD)
			{
				ll x=A[j+k],y=w*A[j+mid+k]%MOD;
				A[j+k]=(x+y)%MOD;
				A[j+mid+k]=(x-y+MOD)%MOD;
			}
		}
	}
	if(type==-1)
	{
		ll inv=quick_pow(limit,MOD-2);
		for(int i=0;i<limit;i++)A[i]=A[i]*inv%MOD;
	}
}
ll A[400005];
void Inv(ll*a,ll*b,int n)
{
	if(n==1)
	{
		b[0]=quick_pow(a[0],MOD-2);
		return;
	}
	Inv(a,b,(n+1)>>1);
	limit=1,l=0;
	while(limit<(n<<1))limit<<=1,l++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<limit;i++)A[i]=i<n?a[i]:0;
	NTT(A,1);
	NTT(b,1);
	for(int i=0;i<limit;i++)
	  b[i]=b[i]*(2+MOD-A[i]*b[i]%MOD)%MOD;
	NTT(b,-1);
	for(int i=n;i<limit;i++)b[i]=0;
}
ll a2[400005];
void Ln(ll*a,ll*b,int n)
{
	for(int i=0;i<(n<<2);i++)b[i]=0;
	Inv(a,b,n);
	limit=1,l=0;
	while(limit<(n<<1))limit<<=1,l++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<n-1;i++)a2[i]=a[i+1]*(i+1)%MOD;
	for(int i=n-1;i<limit;i++)a2[i]=0;
	NTT(a2,1);
	NTT(b,1);
	for(int i=0;i<limit;i++)
	  b[i]=b[i]*a2[i]%MOD;
	NTT(b,-1);
	for(int i=n-1;i>0;i--)
	  b[i]=b[i-1]*ni[i]%MOD;
	for(int i=n;i<limit;i++)b[i]=0;
	b[0]=0;
}
ll lnb[400005];
void Exp(ll*a,ll*b,int n)
{
	if(n==1)
	{
		b[0]=1;
		return;
	}
	Exp(a,b,(n+1)>>1);
    printf("len=%d\n",n);
    for(int i=0;i<n;i++) printf("%lld ",b[i]);puts("");
	Ln(b,lnb,n);
	limit=1,l=0;
	while(limit<(n<<1))limit<<=1,l++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    printf("lnb:");for(int i=0;i<limit;i++) printf("%lld ",lnb[i]);puts("");
	for(int i=0;i<n;i++)lnb[i]=a[i]>=lnb[i]?a[i]-lnb[i]:a[i]-lnb[i]+MOD;
	for(int i=n;i<limit;i++)lnb[i]=b[i]=0;
	lnb[0]++;
    printf("lnb:");for(int i=0;i<limit;i++) printf("%lld ",lnb[i]);puts("");
	NTT(lnb,1);
	NTT(b,1);
	for(int i=0;i<limit;i++)b[i]=b[i]*lnb[i]%MOD;
	NTT(b,-1);
	for(int i=n;i<limit;i++)b[i]=0;
    for(int i=0;i<n;i++) printf("%lld ",b[i]);puts("");
}
int n;
ll f[400005],g[400005];
int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&f[i]);
	calc_ni(n);
	Exp(f,g,n);
	for(int i=0;i<n;i++)printf("%lld ",g[i]);
	printf("\n");
	return 0;
}
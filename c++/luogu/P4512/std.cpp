#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const ll mod=998244353;
#define G 3
#define MAXN 400040
#define invG 332748118
#define ck(x) ((x)>=mod?(x)-mod:(x))
inline ll read()
{
	ll q=0;char ch=' ';
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')q=(q<<3)+(q<<1)+ch-'0',ch=getchar();
	return q;
}

ll n,tr[MAXN],f[MAXN],g[MAXN],w[MAXN];
ll ff[MAXN],_f[MAXN],_g[MAXN],h[MAXN];
inline ll Quickly_Power(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}

//快速数论变换
void NTT(ll *f,ll flag,ll n)
{
	for(ll i=0;i<n;i++)
		if(i<tr[i])swap(f[i],f[tr[i]]);
	for(ll p=2;p<=n;p<<=1)
	{
		ll len=(p>>1);
		ll wn=Quickly_Power(flag?G:invG,(mod-1)/p);
		for(ll k=0;k<n;k+=p)
		{
			ll buf=1;
			for(ll i=k;i<k+len;i++)
			{
				ll tmp=buf*f[i+len]%mod;
				f[i+len]=ck(f[i]-tmp+mod);
				f[i]=ck(f[i]+tmp);
				buf=buf*wn%mod;
			}
		}
	}
}

//多项式求逆
void Inv(ll *f,ll *g,ll m)
{
	if(m==1)
	{
		g[0]=Quickly_Power(f[0],mod-2);
		return;
	}
	Inv(f,g,(m+1)>>1);
	ll n=1;
	while(n<(m<<1))n<<=1;
	ll invn=Quickly_Power(n,mod-2);
	for(ll i=0;i<n;i++)
		tr[i]=((tr[i>>1]>>1)|((i&1)?n>>1:0)),w[i]=f[i];
	for(ll i=m;i<n;i++)w[i]=0;
	NTT(w,1,n),NTT(g,1,n);
	for(ll i=0;i<n;i++)
		g[i]=(2-w[i]*g[i]%mod+mod)*g[i]%mod;
	NTT(g,0,n);
	for(ll i=0;i<m;i++)
		g[i]=invn*g[i]%mod;
	for(ll i=m;i<n;i++)g[i]=0;
}

//多项式乘法
void Mul(ll *f,ll *g,ll *p,ll n,ll m)
{
	m+=n,n=1;
	while(n<m)n<<=1;
	for(ll i=0;i<n;i++)
		tr[i]=((tr[i>>1]>>1)|((i&1)?n>>1:0));
	ll invn=Quickly_Power(n,mod-2);
	NTT(f,1,n),NTT(g,1,n);
	for(ll i=0;i<n;i++)
		p[i]=f[i]*g[i]%mod;
	NTT(p,0,n);
	for(ll i=0;i<n;i++)
		p[i]=p[i]*invn%mod;
}

//求导、积分
void Differential(ll *f,ll *g,ll n)
{
	for(ll i=1;i<n;i++)
		g[i-1]=i*f[i]%mod;
	g[n-1]=0;
}
void Integral(ll *f,ll *g,ll n)
{
	for(ll i=1;i<n;i++)
		g[i]=f[i-1]*Quickly_Power(i,mod-2)%mod;
	g[0]=0;
}

//求多项式对数函数（ln）
void Ln(ll *f,ll *g,ll n)
{
	Differential(f,ff,n);
	Inv(f,_f,n);
    for(int i=0;i<n;i++) printf("%lld ",_f[i]);puts("");
	Mul(ff,_f,_g,n,n);
	Integral(_g,g,n);
}
int main()
{
    freopen("my.in","r",stdin);
	n=read();
	for(ll i=0;i<n;i++)f[i]=read();
	Ln(f,g,n);
	for(ll i=0;i<n;i++)
		printf("%lld ",g[i]);
	return 0;
}
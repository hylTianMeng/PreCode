//P5325
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
inline ll read() {
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(ll x) {
	if(!x)putchar('0');if(x<0)x=-x,putchar('-');
	static int sta[20];register int tot=0;
	while(x)sta[tot++]=x%10,x/=10;
	while(tot)putchar(sta[--tot]+48);
}
const int MAXN=1e6+5;
const int MOD=1e9+7,INV6=166666668;
ll n,sqrtn,prm[MAXN],sump[MAXN],sum2p[MAXN],cnt,g1[MAXN],g2[MAXN];
bool v[MAXN];
void sieve(int n) {
	cnt=0;
	for(int i=2;i<=n;++i) {
		if(!v[i]) {
			prm[++cnt]=i;
			sump[cnt]=(sump[cnt-1]+i)%MOD;
			sum2p[cnt]=(sum2p[cnt-1]+(ll)i*i%MOD)%MOD;
		}
		for(int j=1;j<=cnt && prm[j]*i<=n;++j) {
			v[prm[j]*i]=1;
			if(i%prm[j]==0) break;
		}
	}
}
ll val[MAXN];
int id1[MAXN],id2[MAXN];
inline int get_id(ll x){return ((x<=sqrtn)?id1[x]:id2[n/x]);}
ll getS(ll x,ll y) {
	if(x<prm[y] || x<=1) return 0;
	int k=get_id(x);
	ll res=((g2[k]-g1[k]+MOD)%MOD-(sum2p[y-1]-sump[y-1]+MOD)%MOD+MOD)%MOD;
	for(int i=y;i<=cnt && prm[i]*prm[i]<=x;++i) {
		ll t1=prm[i],t2=prm[i]*prm[i];
		for(int j=1;t2<=x;++j,t1=t2,t2*=prm[i]) {
			ll tt1=t1%MOD,tt2=t2%MOD;
			res=(res+getS(x/t1,i+1)*tt1%MOD*(tt1-1)%MOD+tt2*(tt2-1)%MOD)%MOD;
		}
	}
	return res%MOD;
}
int main() {
	ios::sync_with_stdio(0);/*syn加速*/
	n=read();
	sieve(sqrtn=sqrt(n));
	int tot=0;/*O(sqrt(n))级别*/
	for(ll i=1,j;i<=n;i=j+1) {
		j=n/(n/i);
		ll w=n/i;
		val[++tot]=w;
		if(w<=sqrtn) id1[w]=tot;
		else id2[n/w]=tot;
		
		w%=MOD;
		g1[tot]=w*(w+1)/2%MOD;
		g2[tot]=w*(w+1)%MOD*(2LL*w+1)%MOD*INV6%MOD;
		
		g1[tot]=(g1[tot]-1+MOD)%MOD;
		g2[tot]=(g2[tot]-1+MOD)%MOD;
	}
	for(int j=1;j<=cnt;++j) {
		for(int i=1;i<=tot && prm[j]*prm[j]<=val[i];++i) {
			int k=get_id(val[i]/prm[j]);
			g1[i]=(g1[i]-prm[j]*(g1[k]-sump[j-1]+MOD)%MOD+MOD)%MOD;
			g2[i]=(g2[i]-prm[j]*prm[j]%MOD*(g2[k]-sum2p[j-1]+MOD)%MOD+MOD)%MOD;
		}
	}
	//for(int i=1;i<=tot;++i)cout<<val[i]<<" "<<g1[i]<<" "<<g2[i]<<endl;
	write((getS(n,1)+1)%MOD);puts("");
	return 0;
}

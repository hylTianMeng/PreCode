#include<bits/stdc++.h>
using namespace std;
#define int register int
typedef long long ll;
#define int long long
const int maxn=5e5+10;
int g,m,n,r;
ll len[maxn],lst,tag[maxn];
map<int,int>p;
inline void modify(int l,int r,int v){
	if(l==r)return;
	auto il=p.lower_bound(l),ir=p.upper_bound(r);
	int tmp=prev(ir,1)->second;
	p.erase(il,ir);
	p[l]=v,p[r]=tmp;
	//这里更新map，注意 map 的表示：若 map[k]=a,map[h]=b，则表示，[k,b) 的时间内，会被 a 拦截，剩下时间会被 b 拦截。
}
inline int query(int k){
	k%=r;
	auto it=prev(p.upper_bound(k),1);
	return it->second;
}
inline ll calc(ll x,int y){
	return y==n+1?(len[n+1]-x):(((len[y]-x+r-1)/r)*r+tag[y]);
}
//如果等于 n+1 就说明没有被红绿灯拦住，直接跑就可以。否则，会在 y 这个红绿灯处被截停，tag[y] 是过了这个红绿灯后所需要的时间。
//x 是已经走的路程。
signed main(){
	// freopen("my.in","r",stdin);
	// freopen("std.out","w",stdout);
	scanf("%lld%lld%lld",&n,&g,&r);
	r+=g;
	for(int i=1;i<=n+1;++i)scanf("%lld",len+i),len[i]+=len[i-1];
	// 常规输入，并求前缀和。
	p[0]=n+1;
	//再开始我们假定如果从一开始出发，就会被 n+1 拦截。其实是一定能被 n+1 拦截。
	for(int i=n;i;--i){
		int ql=(g-len[i]%r+r)%r,qr=r-len[i]%r,pos=query(qr);
		//求完之后，[ql,qr)这段区间中的时间，如果不考虑前面的红绿灯，会被第 i 个红绿灯拦住。
		//pos 求完之后代表了 map 里面小于等于 qr 的第一个数。
		tag[i]=calc(len[i],pos);
		if(ql<qr)modify(ql,qr,i);
		else modify(0,qr,i),modify(ql,r,i);
	}
	scanf("%lld",&m);
	while(m--){
		int tim;
		scanf("%lld",&tim);
		tim^=(lst%INT_MAX);
		int pos=query(tim);
		// pos 求完之后代表了 map 里面小于等于 tim 的第一个数。
		printf("%lld\n",lst=calc(-tim,pos));
	}
	//lst里面放的是答案。
	return 0;
}
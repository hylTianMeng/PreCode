#include<bits/stdc++.h>
using namespace std;
#define N 3005
#define mod 998244353
#define ll long long
vector<int>v[N];
int n,m,x,y,inv[N],Inv[N],a[N],f[N],g[N],G[N],S[N],ans[N][N];
int qpow(int n,int m){
	int s=n,ans=1;
	while (m){
		if (m&1)ans=(ll)ans*s%mod;
		s=(ll)s*s%mod;
		m>>=1;
	}
	return ans;
}
void dfs1(int k,int fa){
	f[k]=(ll)x*a[k]%mod;
	for(int i=0;i<v[k].size();i++)
		if (v[k][i]!=fa){
			g[v[k][i]]=f[k];
			dfs1(v[k][i],k);
			f[k]=(ll)f[k]*(f[v[k][i]]+1)%mod;
		}
}
//如果没有中间那个 g 的话，这个就是一个很不同的根据 x 来计算值得转移方程，g的赋值在里面显得很突兀。
void dfs2(int k,int fa){
	f[k]=1;
	for(int i=(int)v[k].size()-1;i>=0;i--)
		if (v[k][i]!=fa){
			g[v[k][i]]=(ll)g[v[k][i]]*f[k]%mod;
			dfs2(v[k][i],k);
			f[k]=(ll)f[k]*(f[v[k][i]]+1)%mod;
		}
	f[k]=(ll)x*a[k]%mod*f[k]%mod;
}
//注意到枚举方式，发现 dfs1和dfs2 可能处理的一个是前缀，另一个是后缀
//暂不清楚 f 和 g 分别表示的意义是什么。
//我似乎明白一点了，这得益于这个思想和我考试时没有实现出来的想法很相像。
//用vector来存图可以比邻接表更方便的处理前缀后缀，f[k]在这里就是用来辅助的，真正想要预处理的是 g[k]
//g[k] 表示：设 k 的父亲为 fa,则其表示为当 fa 换根到 k 的时候以 g[k] 为根时候的答案。
//但是这仅局限于在 fa 这个子树中的答案。
void calc(int k,int fa){
	g[k]=(ll)g[k]*(g[fa]+1)%mod;
	ans[k][x]=(ll)(g[k]+1)*f[k]%mod;
	printf("ans[%d][%d]=%d\n",k,x,ans[k][x]);
	for(int i=0;i<v[k].size();i++)
		if (v[k][i]!=fa)calc(v[k][i],k);
}
int main(){
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	inv[0]=inv[1]=Inv[0]=1;
	for(int i=2;i<N;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<N;i++)Inv[i]=(ll)Inv[i-1]*inv[i]%mod;
    //inv里面存的是阶乘。
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
    //vector 当邻接表
	for(x=0;x<=n;x++){
		memset(g,0,sizeof(g));
		dfs1(1,0),dfs2(1,0),calc(1,0);
	}
    //终于看见一个比较靠谱的拉插了，这里的 x 应该是枚举的 拉插带进去的数。
    //完成dp部分，接下来进行拉格朗日插值，其中 ans[k][x] 表示以 k 为根的时候代入的数为 x 的时候的答案是多少。
	memset(g,0,sizeof(g));
	g[0]=1;
	for(int i=0;i<=n;i++){
		for(int j=n+1;j;j--)g[j]=(g[j-1]-(ll)g[j]*i%mod+mod)%mod;
		g[0]=(mod-(ll)g[0]*i%mod)%mod;
	}
	for(int i=0;i<=n;i++){
		if (!i){
			for(int j=0;j<=m;j++)S[i]=(S[i]+g[j+1])%mod;
		}
		else{
			memcpy(G,g,sizeof(g));
			for(int j=0;j<=m;j++){
				int k=(mod-(ll)G[j]*inv[i]%mod)%mod;
				S[i]=(S[i]+k)%mod,G[j+1]=(G[j+1]-k+mod)%mod;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int Ans=0;
		for(int j=0;j<=n;j++){
			int s=(ll)ans[i][j]*Inv[j]%mod*Inv[n-j]%mod*S[j]%mod;
			if ((n-j)&1)Ans=(Ans-s+mod)%mod;
			else Ans=(Ans+s)%mod;
		}
		printf("%d",Ans);
		if (i<n)printf(" ");
		else printf("\n");
	}
	return 0;
}
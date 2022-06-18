#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
int n,m,k,f[N],ans;
char a[N],b[N];
//上面都是基本信息，f[i]的信息不明。大概是dp数组？
vector<int>pos[N];
int calc(int s1,int t1,int s2,int t2){
	int la=t1-s1+1,lb=t2-s2+1;
	fill(f+1,f+1+lb,0),f[0]=1;
	for(int i=0;i<26;i++) vector<int>().swap(pos[i]);
	for(int i=lb;i>=1;i--) pos[b[s2+i-1]-'a'].push_back(i);
    //这里 pos 里面存放了左右字母的出现次数。
	for(int i=1;i<=la;i++)
		for(int j:pos[a[s1+i-1]-'a']) f[j]=(f[j]+f[j-1])%mod;
	return f[lb];
}
//这个东西不是分治，推测用的是第四种方法乱搞过地。
signed main(){
	scanf("%d%d%d%s%s",&n,&m,&k,a+1,b+1);
    ans=calc(1,n,1,m);
    //考虑简单的补集转化，这个 ans 目前存的是全部的答案。
	if(m>k) printf("%d\n",ans),exit(0);
    //如果 m>k 的话，那么在第一个字符串中前后坐标差至少为 m。
	ans=(ans-calc(n-k+2,n,1,m)+mod)%mod;
	for(int i=1;i<=n-k+1;i++)
		if(a[i]==b[1]) ans=(ans-calc(i+1,i+k-1,2,m)+mod)%mod;
    //对于那些满足上面条件的 i,才有可能作为开始节点。
	printf("%d\n",ans);
	return 0;
}
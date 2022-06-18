#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,u,v,e[20],re[20],pw[310],f[(1<<18)+10],num[(1<<18)+10],lb[(1<<18)+10],cnt[(1<<18)+10];
int main(){
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d%d",&n,&m),pw[0]=1;
	for(int i=1;i<=m;++i)(pw[i]=pw[i-1]<<1)>=mod?pw[i]-=mod:0;
	for(int i=1;i<(1<<n);++i)cnt[i]=cnt[i>>1]+(i&1),lb[i]=(i&1?1:lb[i>>1]+1);
	for(int i=1;i<=m;++i)scanf("%d%d",&u,&v),e[u]|=(1<<v-1),re[v]|=(1<<u-1);
	f[0]=1;
	for(int i=1;i<(1<<n);++i){
		printf("S=%d\n",i);
		for(int t=(i-1&i),j=i-t;;t=(t-1&i),j=i-t){
			num[j]=num[j-(j&-j)]-cnt[re[lb[j]]&j]+cnt[e[lb[j]]&i-j];
			printf("g[%d]=g[%d]-Cnt[Pre[%d]&%d]+Cnt[Next[%d]&%d]\n",j,j-(j&-j),lb[j],j,lb[j],i-j);
			printf("%d=%d-%d+%d\n",num[j],num[j-(j&-j)],cnt[re[lb[j]]&j],cnt[e[lb[j]]&i-j]);
			printf("g[%d]=%d\n",j,num[j]);
			f[i]=(f[i]+((cnt[j]&1?1ll:mod-1ll)*pw[num[j]])%mod*f[i-j])%mod;
			if(!t)break;
		}
		printf("f[%d]=%d\n",i,f[i]);
	}
	printf("%d",(pw[m]-f[(1<<n)-1]+mod)%mod);
	return 0;
}

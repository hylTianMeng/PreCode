#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MOD 998244353
void add(int &x,int y){x+=y;if(x>=MOD)x-=MOD;}
char g[200][200];
int n,m,inv[1500],sum,pw,nw,ans,S;
int f[2][1<<6][1200];
int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%d",&n,&m);S=1<<n;sum=2*n*m-n-m;
	for(int i=1;i<=n;++i)scanf("%s",g[i]+1);
	inv[0]=inv[1]=1;for(int i=2;i<1500;++i)inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	f[0][0][0]=MOD-1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
		{
			pw=nw;nw^=1;memset(f[nw],0,sizeof(f[nw]));
			for(int T=0;T<S;++T)
				for(int k=0;k<=sum;++k)
					if(f[pw][T][k])
					{
						int nT=T&((S-1)^(1<<(j-1)));
						add(f[nw][nT][k],f[pw][T][k]);
						if(g[j][i]=='*')
						{
							nT|=1<<(j-1);int pls=0;
							if(j>1&&!(T&(1<<(j-2))))++pls;
							if(i>1&&!(T&(1<<(j-1))))++pls;
							if(i<m)++pls;if(j<n)++pls;
							add(f[nw][nT][k+pls],MOD-f[pw][T][k]);
						}
					}
		}
	for(int T=0;T<S;++T)
		for(int i=1;i<=sum;++i){
			add(ans,1ll*f[nw][T][i]*inv[i]%MOD);
            printf("f[%d][%d][%d]=%d\n",nw,T,i,f[nw][T][i]);
        }
	ans=1ll*ans*sum%MOD;printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define mod 1000000007
int t,n,ans,a[N],f[N][16];
char g[8],s[N];
int get(int p1,int p2,int p3){
	return g[p1+(p2<<1)+(p3<<2)]-'0';
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%s%s",g,s+1);
		n=strlen(s+1),ans=0;
		memset(f,0,sizeof(f));
		f[0][9]=1;
		for(int i=2;i<n;i++)
			for(a[i-1]=0;a[i-1]<2;a[i-1]++)
				for(a[i]=0;a[i]<2;a[i]++){
					if ((s[i-1]!='?')&&(s[i-1]!=a[i-1]+'0'))continue;
					if ((s[i]!='?')&&(s[i]!=a[i]+'0'))continue;
					for(int S=0;S<16;S++){
						if (!f[i-2][S])continue;
						int SS=0;
						for(int p1=0;p1<2;p1++)
							for(int p2=0;p2<2;p2++){
								int p=((S&(1<<(get(a[i-1],a[i],p1)<<1)+p2))>0);
								if (get(0,a[i],p1)==p2)p|=((S&(1<<(a[i-1]<<1)))>0);
								if (get(1,a[i],p1)==p2)p|=((S&(1<<(a[i-1]<<1)+1))>0);
								if (p)SS|=(1<<(p1<<1)+p2);
							}
						f[i][SS]=(f[i][SS]+f[i-2][S])%mod;
					}
				}
		for(a[n]=0;a[n]<2;a[n]++){
			if ((s[n]!='?')&&(s[n]!=a[n]+'0'))continue;
			for(int S=0;S<16;S++)
				if (S&(1<<(a[n]<<1)+1))ans=(ans+f[n-1][S])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
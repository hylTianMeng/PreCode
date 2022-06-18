#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int Mod=1000000007;
int f[410][410];
int F(int n,int k)
{
	if(!k)return 1;
	if(n==1){
		return k==1;
	}
	if(f[n][k]!=-1)return f[n][k];
	f[n][k]=0;
	for(int i=0;i<=k;i++)
		f[n][k]=(f[n][k]+1ll*F(n-1,i)*F(n-1,k-i))%Mod;
	for(int i=0;i<k;i++)
		f[n][k]=(f[n][k]+1ll*F(n-1,i)*F(n-1,k-i-1))%Mod;
	for(int i=0;i<=k;i++)
		f[n][k]=(f[n][k]+1ll*F(n-1,i)*F(n-1,k-i)%Mod*k*2)%Mod;
	for(int i=0;i<=k+1;i++)
		f[n][k]=(f[n][k]+1ll*F(n-1,i)*F(n-1,k+1-i)%Mod*(k+1)*k)%Mod;
    printf("f[%d][%d]=%d\n",n,k,f[n][k]);
	return f[n][k];
}
int main()
{
    freopen("std.out","w",stdout);
	int n;scanf("%d",&n);
	memset(f,-1,sizeof(f));
	printf("%d\n",F(n,1));
	return 0;
}
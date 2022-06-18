#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};  
ll n,res2,res1;//res1 数      res2  约数个数
 
void dfs(int now,int last,ll ans,ll y_ans)//now  当前prime数组的下标，
{                                         //last （now-1）质因子的个数
	int i;                                //ans   当前的数
	if(now==15) return ;                  //y_ans  当前数的约数的个数
	if(y_ans>res2 || (y_ans==res2&&ans<res1)) res1=ans,res2=y_ans;
	for(i=1,ans*=prime[now];i<=last&&ans<=n;i++,ans*=prime[now])
		dfs(now+1,i,ans,y_ans*(i+1));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		res1=res2=1;
		scanf("%lld",&n);
		dfs(0,32,1,1);
		printf("%lld %lld\n",res1,res2);
	}
}


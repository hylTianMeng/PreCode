#include <cstdio>
using namespace std;
long long n;
int sum[10]={0,1,3,6,10,15,21,28,36,45};

int get(int n)
{
	if(n<0)return 0;
	return n;
}

long long get_ans(long long n)
{
	long long res=0,a=1,b=0;	
	while(n>0)
	{
		res=res+a*(45*(n/10)+sum[get(n%10-1)])+(n%10)*(b+1);
		b=b+(n%10)*a;a*=10;
		n/=10;
	}
	return res;	
}

int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%lld",&n);
	printf("%lld\n",get_ans(n));
	return 0;
}
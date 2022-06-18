#include <cstdio>
using namespace std;

void chkmin(int& a,int b) { if(a>b) a=b; }

int fi[800005];
int li[800005];
int ni[800005];
int vi[800005];

int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",fi+i);

	for(int i=1; i<=n; ++i) ni[i] = n;

	for(int i=1; i<=n; ++i)
	{
		if(!li[i])
		{
			int ln = 1;
			for(int j=fi[i]; j!=i; j=fi[j]) ++ln;
			li[i] = ln;
			for(int j=fi[i]; j!=i; j=fi[j]) li[j] = ln;
			chkmin(ni[ln],i);
		}
	}

	for(int i=1; i<=n; ++i)
	{
		for(int j=2; j*i<=n; ++j)
		{
			chkmin(ni[j*i],ni[i]);
		}
	}

	for(int i=1; i<=n; ++i)
	{
		if(!vi[i])
		{
			vi[i] = ni[li[i]];
			int curx = vi[i];
			for(int j=fi[i]; j!=i; j=fi[j])
			{
				curx = fi[curx];
				vi[j] = curx;
			}
		}
	}

	for(int i=1; i<=n; ++i)
	{
		printf("%d ",vi[i]);
	}
}
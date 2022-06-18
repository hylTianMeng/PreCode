#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define int long long 
using namespace std;
const int N = 2e5 + 9;
const int M = 2e5 + 9;
struct node{
	int last;
	int to;
}e[N<<1];
int head[N],cnt;
int n,m,T,a[N];
int ans,val,siz[N];
int f[N],Dir[N];
bool unMove[N];
int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^'0');s=getchar();}
	return f*x;
}
int find(int x)
{
	if(x == f[x]) return x;
	else return f[x] = find(f[x]);
}
void add(int from,int to)
{
	e[++cnt].last = head[from];
	e[cnt].to = to;
	head[from] = cnt;
}
void dfs(int u,int fa)
{
	Dir[u] ^= 1;
	for(int i = head[u]; i ; i = e[i].last)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v , u);
	}
}
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
signed main()
{
	freopen("my.in","r",stdin);
	freopen("std.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 1; i <= n; i ++)
		f[i] = i;
	for(int i = 1; i <= n; i ++)
		siz[i] = 1;
	while(m --)
	{
		int opt = read();
		if(opt == 1)
		{
			int x = read();
			int c = read();
			a[x] = c;
		}
		if(opt == 2)//合并起来 
		{
			int x = read();
			int y = read();
			int fu = find(x);
			int fv = find(y);
			if(x == y) continue;
			//cout<<"x = "<<x<<" fu = "<<fu<<" y = "<<y<<" fv = "<<fv<<endl;
			//cout<<"siz[fu] = "<<siz[fu]<<" siz[fv] = "<<siz[fv]<<endl;
			if(siz[fu] > siz[fv])
			{
				swap(x , y);
				swap(fu , fv);
			}
			if(fu == fv)//可能会拼接成一个环结构
			{
				if(Dir[x] == Dir[y])
					unMove[fv] = true;	
			}
			else//如果不在一个，找小的那个去跑一遍修改 
			{
				siz[fv] += siz[fu];
				f[fu] = fv;
				if(Dir[x] != Dir[y])
				{
					add(x , y);
					add(y , x);
				}
				else//如果方向相同 
				{
					dfs(x , 0);
					add(x , y);
					add(y , x);	
				}
				if(unMove[fu])
					unMove[fv] = true;
			}
		}
		if(opt == 3)
		{
			int x = read();
			int y = read();
			int V = read();
			int fu = find(x);
			int fv = find(y);
			if(fu != fv)
			{
				printf("0\n");
				continue;
			} 
			if(unMove[fu] == true)
			{
				printf("0\n");
				continue;
			}
			else
			{
				int Fir = V * a[x];
				int Sec = a[y];
				int cut = gcd(Fir , Sec);
				Fir /= cut;
				Sec /= cut;
				if(Dir[x] != Dir[y])
					Fir = -Fir;
				printf("%lld/%lld\n",Fir,Sec); 
			}
		}
	}
	return 0;
}
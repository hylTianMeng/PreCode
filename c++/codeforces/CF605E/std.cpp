#include <bits/stdc++.h>
using namespace std;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

const int N=1005;

template<typename T> void read(T &x){
   x=0;int f=1;
   char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
   for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
    x*=f;
}

int n;
double g[N][N];
double E[N],prod[N];
bool vis[N];

int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	read(n);
	Rep(i,1,n)
		Rep(j,1,n){
			int x;
			read(x);
			g[i][j]=1.*x/100;
		}
	if(n==1)return puts("0"),0;
	vis[n]=true;
	for(int i=1;i<n;i++){
		E[i]=1;
		prod[i]=1-g[i][n];	
	}
	Rep(i,1,n){
		double low=1e18;
		int pos=0;
		Rep(j,1,n)
			if(!vis[j]&&E[j]/(1-prod[j])<low)
				low=E[j]/(1-prod[j]),pos=j;
		if(pos==1)return printf("%.10lf\n",E[1]/(1-prod[1])),0;
		vis[pos]=true;
		Rep(j,1,n){
            E[j]+=E[pos]/(1-prod[pos])*g[j][pos]*prod[j],prod[j]*=(1-g[j][pos]);
            printf("E[%d]=%lf\n",j,E[j]);
        }
	}
	return 0;
}
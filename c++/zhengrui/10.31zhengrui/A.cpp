#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 31
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
	x=0; int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

ld f[N][N][N][N][5];
bool vis[N][N][N][N],Rb[N][N];

int n,m,k;

inline void Solve(int xl,int xr,int yl,int yr){
	if(vis[xl][xr][yl][yr]) return;
	vis[xl][xr][yl][yr]=1;
	ld *g=f[xl][xr][yl][yr];int cnt=0;
	for(int i=xl+1;i<xr;i++)
		for(int j=yl+1;j<yr;j++) if(Rb[i][j]){
			Solve(xl,i,yl,j);Solve(xl,i,j,yr);Solve(i,xr,yl,j);Solve(i,xr,j,yr);
			ld *g1=f[xl][i][yl][j],*g2=f[xl][i][j][yr],*g3=f[i][xr][yl][j],*g4=f[i][xr][j][yr];
			g[1]+=g1[1]+g1[4]+g3[1]+g2[4];g[2]+=g2[2]+g2[1]+g4[1]+g1[2];
			g[3]+=g2[3]+g4[3]+g4[2]+g3[2];g[4]+=g3[4]+g3[3]+g4[4]+g1[3];
			g[0]+=g1[0]+g2[0]+g3[0]+g4[0]+(g1[4]+g2[4]+g3[1]+g4[1])*(i-xl)+(g1[2]+g2[1]+g3[2]+g4[1])*(yr-j)
				 +(g1[3]+g2[3]+g3[2]+g4[2])*(xr-i)+(g1[3]+g2[4]+g3[3]+g4[4])*(j-yl);
			cnt++;
		}
	if(!cnt) return;
	g[0]=g[0]/(1.0*cnt)+2*(xr-xl+yr-yl);
	for(int i=1;i<=4;i++) g[i]=g[i]/(1.0*cnt)+1;
	// printf("f[%d][%d][%d][%d][0]=%Lf\n",xl,xr,yl,yr,f[xl][xr][yl][yr][0]);
}

signed main(){
	// freopen("my.in","r",stdin);
	// freopen("my.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=k;i++){
		int x,y;read(x);read(y);
		Rb[x][y]=1;
	}
	Solve(0,n,0,m);
	printf("%0.8Lf\n",f[0][n][0][m][0]);
	return 0;
}
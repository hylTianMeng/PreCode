#include<bits/stdc++.h>
using namespace std;
int n,m,k;long double f[35][35][35][35][5];bool v[35][35],vst[35][35][35][35];
void F(int l,int r,int d,int u){
	if(vst[l][r][d][u])return;
	vst[l][r][d][u]=1;int cnt=0;long double *g=f[l][r][d][u];
	for(int i=l+1;i<r;i++)
		for(int j=d+1;j<u;j++)if(v[i][j]){
			cnt++,F(l,i,d,j),F(i,r,d,j),F(l,i,j,u),F(i,r,j,u);
			long double *g1=f[l][i][d][j],*g2=f[i][r][d][j],*g3=f[l][i][j][u],*g4=f[i][r][j][u];
			g[0]+=g1[0]+g1[3]+g2[0]+g3[3],g[1]+=g3[1]+g3[0]+g4[0]+g1[1],
			g[2]+=g4[2]+g4[1]+g3[2]+g2[1],g[3]+=g2[3]+g2[2]+g4[3]+g1[2];
			swap(g2,g3);
			g[4]+=g1[4]+g2[4]+g3[4]+g4[4]+(g1[1]+g2[0]+g3[1]+g4[0])*(u-j)+(g1[3]+g2[3]+g3[0]+g4[0])*(i-l)
							  			 +(g1[2]+g2[2]+g3[1]+g4[1])*(r-i)+(g1[2]+g2[3]+g3[2]+g4[3])*(j-d);
		}
	if(cnt==0)return;
	g[0]/=cnt,g[1]/=cnt,g[2]/=cnt,g[3]/=cnt,g[4]/=cnt,g[0]++,g[1]++,g[2]++,g[3]++,g[4]+=(u-d+r-l<<1);
    printf("f[%d][%d][%d][%d][0]=%Lf\n",l,r,d,u,g[4]);
}
int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y;i<=k;i++)scanf("%d%d",&x,&y),v[x][y]=1;
	F(0,n,0,m);
	printf("%.12lf",(double)f[0][n][0][m][4]);
	return 0;
}
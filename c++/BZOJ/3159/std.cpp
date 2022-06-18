#include<iostream>
#include<cstdio>
#define N 50005
#define ll long long
using namespace std;
int n,m,x,y,z;
int Fa[N],C[N][2],Sz[N];ll Val[N],Pls[N],Rev[N],Mx[N],Mn[N],Sm[N];//这是一颗记录值的splay
int fa[N],c[N][2],size[N],Rt[N],rev[N];//这是一颗记录父子关系的LCT
 
//----------------splay------------------
void Rever(int x){Rev[x]^=1;swap(C[x][0],C[x][1]);}
void Add(int x,int y){Val[x]+=y;Pls[x]+=y;Mx[x]+=y;Mn[x]+=y;Sm[x]+=Sz[x]*y;}
void Up(int x)
{
	int l=C[x][0],r=C[x][1];
	Sz[x]=1;Sm[x]=Mx[x]=Mn[x]=Val[x];
	if (l) Sz[x]+=Sz[l],Sm[x]+=Sm[l],Mx[x]=max(Mx[x],Mx[l]),Mn[x]=min(Mn[x],Mn[l]);
	if (r) Sz[x]+=Sz[r],Sm[x]+=Sm[r],Mx[x]=max(Mx[x],Mx[r]),Mn[x]=min(Mn[x],Mn[r]);
}
void Down(int x)
{
	int l=C[x][0],r=C[x][1];
	if (Rev[x]) Rever(l),Rever(r),Rev[x]=0;
	if (Pls[x]) Add(l,Pls[x]),Add(r,Pls[x]),Pls[x]=0;
}
void Pd(int x){if (Fa[x]) Pd(Fa[x]);Down(x);}
void Ro(int x)
{
	int y=Fa[x],z=Fa[y],l=C[y][0]!=x,r=l^1;
	if(z)C[z][C[z][1]==y]=x;
	Fa[x]=z;Fa[y]=x;Fa[C[x][r]]=y;
	C[y][l]=C[x][r];C[x][r]=y;Up(y);Up(x);
}
void Splay(int x,int k,int y=0)
{
	for (Pd(x);Fa[x]!=k;Ro(x))
		if (Fa[y=Fa[x]]!=k) Ro(C[y][0]==x^C[Fa[y]][0]==y?x:y);
}
int Rank(int x,int k)
{
	Down(x);
	if (k==Sz[C[x][0]]+1) return x;
	if (k<=Sz[C[x][0]]) return Rank(C[x][0],k);
	return Rank(C[x][1],k-Sz[C[x][0]]-1);
}
void split(int &x,int &y,int k)
{
	int t=Rank(x,k);
	Splay(t,0);x=t;y=C[t][1];
	Fa[y]=C[t][1]=0;Up(x);
}
int merge(int x,int y)
{
	int t=Rank(x,Sz[x]);
	Splay(t,0);C[t][1]=y;Fa[y]=t;Up(t);
	return t;
}
//-----------------LCT-------------------
bool IR(int x){return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;}
void down(int x)
{
	if (rev[x])
	{
		swap(c[x][0],c[x][1]);
		rev[x]=0,rev[c[x][0]]^=1,rev[c[x][1]]^=1;
	}
}
void pd(int x){if (!IR(x))pd(fa[x]);down(x);}
void up(int x){size[x]=size[c[x][0]]+size[c[x][1]]+1;}
void rotate(int x)
{
	int y=fa[x],z=fa[y],l=c[y][0]!=x,r=l^1;
	if(!IR(y))c[z][c[z][1]==y]=x;
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;up(y);up(x);
}
void splay(int x,int y=0)
{
	for (pd(x),y=x;!IR(y);y=fa[y]);swap(Rt[x],Rt[y]);
	for (;!IR(x);rotate(x))
		if (!IR(y=fa[x])) rotate(c[y][0]==x^c[fa[y]][0]==y?x:y);
}
void acc(int x)
{
	for(int t=0;x;t=x,x=fa[x])
	{
		splay(x);
		if (c[x][1]) split(Rt[x],Rt[c[x][1]],size[c[x][0]]+1);
		if (t) Rt[x]=merge(Rt[x],Rt[t]),Rt[t]=0;
		c[x][1]=t;fa[t]=x;up(x);
	}
}
void MRt(int x){acc(x);splay(x);rev[x]^=1;Rever(Rt[x]);}
void link(int x,int y){MRt(x);fa[x]=y;}
void inv(int x,int y){MRt(x);acc(y);splay(y);Rever(Rt[y]);}
void add(int x,int y,int z){MRt(x);acc(y);splay(y);Add(Rt[y],z);}
ll Qsum(int x,int y){MRt(x);acc(y);splay(y);return Sm[Rt[y]];}
ll Qmax(int x,int y){MRt(x);acc(y);splay(y);return Mx[Rt[y]];}
ll Qmin(int x,int y){MRt(x);acc(y);splay(y);return Mn[Rt[y]];}
int main()
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%d%*d",&n,&m);
	for (int i=1;i<=n;i++) Rt[i]=i,Sz[i]=size[i]=1;
	for (int i=1;i<n;i++)
		scanf("%d%d",&x,&y),link(x,y);
	for(char p[10];m--;)
	{
		scanf("%s%d%d",p,&x,&y);
		if (p[0]=='S') printf("%lld\n",Qsum(x,y));
		else if (p[1]=='a')printf("%lld\n",Qmax(x,y));
		else if (p[1]=='i')printf("%lld\n",Qmin(x,y));
		else if (p[2]=='v')inv(x,y);
		else scanf("%d",&z),add(x,y,z);
	}
	//system("pause");
}
 


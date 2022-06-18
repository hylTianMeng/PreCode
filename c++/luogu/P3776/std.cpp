#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

int r=0,c=0,m=0,Q=0;

struct point
{
	int x,y;point(int xx=0,int yy=0):x(xx),y(yy){}
};bool operator<(point a,point b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;}
bool operator==(point a,point b){return a.x==b.x&&a.y==b.y;}

vector<point> q[4];
void add_point(int x,int y)
{
	for(int i=0;i<4;i++)q[i].push_back(point(x,y));
	if(x<r){q[1].push_back(point(x+1,y)),q[3].push_back(point(x+1,y));}
	if(y<c){q[2].push_back(point(x,y+1)),q[3].push_back(point(x,y+1));}
	if(x<r&&y<c){q[3].push_back(point(x+1,y+1));}
}

struct PresidentTree
{
	struct nd
	{
		int lc,rc,sum;
	}t[7000000];int used;
	void build(int l,int r,int &k)
	{
		if(!k)k=++used;t[k].sum=0;if(l==r)return;
		int mid=(l+r)>>1;build(l,mid,t[k].lc),build(mid+1,r,t[k].rc);
	}
	int add(int pos,int val,int l,int r,int k)
	{
		int p=++used;t[p]=t[k];
		if(l==r){t[p].sum+=val;return p;}
		int mid=(l+r)>>1;if(pos<=mid){t[p].lc=add(pos,val,l,mid,t[k].lc);}else t[p].rc=add(pos,val,mid+1,r,t[k].rc);
		t[p].sum=t[t[p].lc].sum+t[t[p].rc].sum;return p;
	}
	int sum(int x,int y,int l,int r,int k)
	{
		if(l>y||r<x)return 0;
		if(x<=l&&r<=y)return t[k].sum;
		int mid=(l+r)>>1;return sum(x,y,l,mid,t[k].lc)+sum(x,y,mid+1,r,t[k].rc);
	}
}T[4];int rt[4][500000];

char S[500000];

int sum(int i,int ar,int ac,int br,int bc)
{
	if(ar>br||ac>bc)return 0;
	return T[i].sum(ac,bc,1,c,rt[i][br])-T[i].sum(ac,bc,1,c,rt[i][ar-1]);
}

int main()
{
	scanf("%d%d%d%d",&r,&c,&m,&Q);
	int sr=0,sc=0;scanf("%d%d",&sr,&sc);add_point(sr,sc);
	if(m)scanf("%s",S+1);
	int minr=sr,maxr=sr,minc=sc,maxc=sc;
	for(int i=1;i<=m;i++)
	{
		if(S[i]=='N')sr--;if(S[i]=='S')sr++;if(S[i]=='W')sc--;if(S[i]=='E')sc++;
		minr=min(minr,sr),maxr=max(maxr,sr),minc=min(minc,sc),maxc=max(maxc,sc);
		add_point(sr,sc);
	}
	//puts("");
	for(int i=0;i<4;i++)
	{
		sort(q[i].begin(),q[i].end());
		
		vector<point>::iterator new_end=unique(q[i].begin(),q[i].end());
		q[i].erase(new_end,q[i].end());
		//for(int j=0;j<q[i].size();j++)printf("%d %d\n",q[i][j].x,q[i][j].y);
		T[i].build(1,c,rt[i][0]);
		for(int j=1,p=-1;j<=r;j++)
		{
			rt[i][j]=rt[i][j-1];
			while(p+1<q[i].size()&&q[i][p+1].x==j)
			{
				p++;
				rt[i][j]=T[i].add(q[i][p].y,1,1,c,rt[i][j]);
			}
		}
		//puts("");
	}
	
	while(Q--)
	{
		int ar=0,ac=0,br=0,bc=0;scanf("%d%d%d%d",&ar,&ac,&br,&bc);long long R=br-ar+1,C=bc-ac+1;
		long long ans1=R*C-sum(0,ar,ac,br,bc);
		long long ans2=(R-1)*C-sum(1,ar+1,ac,br,bc);
		long long ans3=R*(C-1)-sum(2,ar,ac+1,br,bc);
		long long ans4=(R-1)*(C-1)-sum(3,ar+1,ac+1,br,bc);
		if(ar<minr&&br>maxr&&ac<minc&&bc>maxc)ans4++;
		//printf("%lld %lld %lld %lld\n",ans1,ans2,ans3,ans4);
		printf("%lld\n",ans1-ans2-ans3+ans4);
	}
	return 0;
}
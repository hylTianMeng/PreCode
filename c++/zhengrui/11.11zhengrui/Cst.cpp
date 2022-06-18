#include<bits/stdc++.h>
#define ci const int&
#define Cr(l,r) (nex[l-1]<=r)
using namespace std;
const int N=5e5+10;
struct keys{
	int c,nxt;
}a[N];
int n,m,tn,Q,c[N],las[22][N],lg[N],nex[N],tmp,be[N],cnt,ap[N],fl,li[N],ri[N],qs,qt;
void add(ci x,ci y){
	a[++cnt]=(keys){y,be[x]},be[x]=cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i)scanf("%d",&c[i]),m=max(m,c[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&tn);
		for(int j=1;j<=tn;++j)scanf("%d",&tmp),add(i,tmp),ap[tmp]=i,m=max(m,tmp);
		las[0][i]=ap[c[i]];
	}
	for(int i=0;i<=m;++i)ap[i]=n+1;
	for(int i=n;i>=1;--i){
		for(int j=be[i];j;j=a[j].nxt)ap[a[j].c]=i;
		nex[i-1]=ap[c[i-1]];
	}
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	lg[0]=-1;
	for(int i=1;i<=lg[n-1];++i)for(int j=1;j+(1<<i)-1<n;++j)las[i][j]=min(las[i-1][j],las[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;++i){
		li[i]=ri[i]=i;
		do{
			fl=0;
			if(nex[li[i]-1]<=ri[i])li[i]=li[li[i]-1],fl=1;
			for(int j=lg[n-ri[i]];j>=0;--j)if(las[j][ri[i]]>=li[i])ri[i]+=(1<<j),fl=1;
		}while(fl);
	}
}
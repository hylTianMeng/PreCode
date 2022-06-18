#include<bits/stdc++.h>
#define pi pair<int,long long>
using namespace std;
const int N=2e5+10;
struct squ{
	int l,r;
	long long second;
	bool operator<(const squ&y)const{
		return r<y.r;
	}
}t;
int n,m,a[N],b[N],posi=1;
long long c[N],A[N],l,r,mid,Limit,B[N],Cov,cha;
vector<pi>S[N];
priority_queue<squ>q;
bool Check(long long mid,long long Cnt){
    //x是答案，tn是翻转区间个数，
	for(int i=1;i<=n;++i)B[i]=0;
	for(int i=1;i<=m;++i)B[a[i]]+=c[i],B[b[i]]-=c[i];
	Cov=0;while(q.size())q.pop();
	for(int i=1;i<=posi;++i){
		for(int j=0;j<S[i].size();++j){
			if(S[i][j].first>=posi)q.push((squ){i,S[i][j].first,S[i][j].second});
		}
		Limit=(i==posi?Cnt:max(0ll,(A[i]+Cnt-mid+1)>>1));
		while(q.size()&&Limit>Cov){
			t=q.top(),q.pop();
			if(Cov+t.second>Limit)cha=Limit-Cov,q.push((squ){t.l,t.r,t.second-cha});
			else cha=t.second;
			B[1]+=cha,B[t.l]-=(cha<<1),B[t.r]+=(cha<<1),Cov+=cha;
		}
		if(Cov<Limit)return 0;
	}
	for(int i=1;i<=n;++i){
		B[i]+=B[i-1];
		if(B[i]>mid)return 0;
	}
	return 1;
}
int main(){
	freopen("my.in","r",stdin);
	scanf("%d%d",&n,&m);
	if(!m)return putchar('0'),0;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&a[i],&b[i],&c[i]),a[i]>b[i]?swap(a[i],b[i]),0:0;
		A[a[i]]+=c[i],A[b[i]]-=c[i],S[a[i]].push_back(make_pair(b[i],c[i])); 
	}
	for(int i=1;i<=n;++i){
		A[i]+=A[i-1];
		if(A[i]>r)r=A[i],posi=i;
	}
	l=1;
	printf("l=%d r=%d\n",l,r);
	printf("posi=%d\n",posi);
	while(l<r)mid=l+r>>1,Check(mid,A[posi]-mid+1)||Check(mid,A[posi]-mid)?r=mid:l=mid+1;
	printf("%lld",l);
	return 0;
}
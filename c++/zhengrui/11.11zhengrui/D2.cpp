#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct squ{
    int l,r;ll second;
    inline squ(){}
    inline squ(int l,int r,ll second) : l(l),r(r),second(second) {}
    inline bool operator < (const squ &b)const{return r<b.r;}
}t;

int a[N],b[N],c[N],n,m,l,r,posi,ans,mid,Limit;
ll A[N],B[N],Cov,cha;
typedef pair<int,int> P;
vector<P> S[N];

inline void Init(){
    read(n);read(m);
    if(!m){return(void)putchar('0');}
    for(int i=1;i<=m;++i){
        read(a[i]);read(b[i]);read(c[i]);
        if(a[i]>b[i]) swap(a[i],b[i]);
        S[a[i]].push_back(make_pair(b[i],c[i]));
        A[a[i]]+=c[i];A[b[i]]-=c[i];
    }
    l=1;
    for(int i=1;i<=n;++i){
        A[i]+=A[i-1];if(A[i]>r){r=A[i];posi=i;}
    }ans=r;
    // printf("l=%d r=%d\n",l,r);
    // printf("posi=%d\n",posi);
}

priority_queue<squ> q;

bool Check(long long mid,long long Cnt){
    //x是答案，tn是翻转区间个数，
	for(int i=1;i<=n;++i)B[i]=0;
	for(int i=1;i<=m;++i)B[a[i]]+=c[i],B[b[i]]-=c[i];
	Cov=0;while(q.size())q.pop();
	for(int i=1;i<=posi;++i){
		for(int j=0;j<S[i].size();++j){
			if(S[i][j].first>=posi)q.push(squ(i,S[i][j].first,S[i][j].second));
		}
		Limit=(i==posi?Cnt:max(0ll,(A[i]+Cnt-mid+1)>>1));
		while(q.size()&&Limit>Cov){
			t=q.top(),q.pop();
			if(Cov+t.second>Limit)cha=Limit-Cov,q.push(squ(t.l,t.r,t.second-cha));
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

inline void Solve(){
    while(l<=r){
        // printf("l=%d r=%d\n",l,r);
        mid=(l+r)>>1;if(Check(mid,A[posi]-mid)||Check(mid,A[posi]-mid+1)){ans=mid;r=mid-1;}else l=mid+1;
    }
    printf("%lld\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}
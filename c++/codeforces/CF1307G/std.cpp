#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<deque>
#include<cstdlib>
#include<ctime>
#define dd double
#define ld long double
#define ll long long
#define ull unsigned long long
#define N 100100
#define M 500100
using namespace std;

const ll INF=0x3f3f3f3f;

inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

inline ll Min(ll a,ll b){
	return a>b?b:a;
}

struct edge{
	ll f,to,next,w;
	inline void intt(ll f_,ll to_,ll ne_,ll w_){
		f=f_;to=to_;next=ne_;w=w_;
	}
};
edge li[M*2];
ll head[N],tail=1;

inline void add(ll from,ll to,ll w,ll c){
	li[++tail].intt(c,to,head[from],w);
	head[from]=tail;
	li[++tail].intt(0,from,head[to],-w);
	head[to]=tail;
}

ll n,m,s,t,ans1,ans2;

ll fl[N],prep[N],pree[N],d[N];
bool vis[N];
queue<ll> q;

inline bool EK(){
//	printf("here\n");
	memset(d,INF,sizeof(d));
	memset(fl,INF,sizeof(fl));
	memset(vis,0,sizeof(vis));
	while(q.size()) q.pop();
	memset(prep,0,sizeof(prep));
	memset(pree,0,sizeof(pree));
	q.push(s);vis[s]=1;d[s]=0;
	while(q.size()){
		ll top=q.front();q.pop();vis[top]=0;
		for(int x=head[top];x;x=li[x].next){
			ll to=li[x].to,rest=li[x].f,w=li[x].w;
			if(rest==0||d[to]<=d[top]+w) continue;
//			printf("x:%d rest:%d to:%d\n",x,rest,to);
			d[to]=d[top]+w;
			fl[to]=Min(fl[top],rest);
			prep[to]=top;pree[to]=x;
			if(!vis[to]) q.push(to),vis[to]=1;
		}
	}
//	printf("d[t]:%lld fl[t]:%lld INF:%lld\n",d[t],fl[t],INF);cin.get();
	if(d[t]<INF&&fl[t]<INF) return 1;
	else return 0;
}

inline void update(){
//	printf("here\n");
	ll now=t,nowe;
	while(prep[now]){
		nowe=pree[now];
		now=prep[now];
//		printf("now:%d nowe:%d\n",now,nowe);
		li[nowe].f-=fl[t];
		li[nowe^1].f+=fl[t];
		ans2+=fl[t]*li[nowe].w;
	}
	ans1+=fl[t];
}

int main(){
//	freopen("P3381_8.in","r",stdin);
//	freopen("P3381_8.out","w",stdout);
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++){
		ll from=read(),to=read(),c=read(),w=read();
		add(from,to,w,c);
	}
	while(EK()) update();
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}

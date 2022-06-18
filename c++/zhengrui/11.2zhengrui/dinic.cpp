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
#define N 30000
#define M 300000
using namespace std;

const int INF=0x3f3f3f3f;

inline int Min(int a,int b){
	return a>b?b:a;
}

inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct edge{
	int to,next,f;
	inline void intt(int to_,int ne_,int f_){
		to=to_;next=ne_;f=f_;
	}
};
edge li[M];
int head[N],tail=1,now[N];

inline void add(int from,int to,int f){
	li[++tail].intt(to,head[from],f);
	head[from]=tail;
}

int s,t,n,m,e,ans;

queue<int> q;
int d[N];
inline bool bfs(){
	memset(d,0,sizeof(d));
	while(q.size()) q.pop();
	q.push(s);d[s]=1;now[s]=head[s];
	while(q.size()){
		int top=q.front();q.pop();
		for(int x=head[top];x;x=li[x].next){
			int to=li[x].to,rest=li[x].f;
			if(!rest||d[to]) continue;
			q.push(to);
			now[to]=head[to];
			d[to]=d[top]+1;
			if(to==t) return 1;
		}
	}
	if(!d[t]) return 0;
	return 1;
}

inline int dicnic(int k,int flow){
	if(k==t) return flow;
	int rest=flow,x;
	for(x=now[k];x&&rest;x=li[x].next){
		int to=li[x].to,re=li[x].f;
		if(!re||d[to]!=d[k]+1) continue;
		int val=dicnic(to,Min(rest,re));
		if(!val) d[to]=0;
		li[x].f-=val;
		li[x^1].f+=val;
		rest-=val;
	}
	now[k]=x;
	return flow-rest;
}

int main(){
	n=read();m=read();e=read();
	for(int i=1;i<=e;i++){
		int from=read(),to=read();
		add(from,to+n,1);
		add(to+n,from,0);
	}
	for(int i=1;i<=n;i++){
		add(n+m+1,i,1);
		add(i,n+m+1,0);
	}
	for(int i=n+1;i<=n+m;i++){
		add(i,n+m+2,1);
		add(n+m+2,i,0);
	}
	s=n+m+1;t=n+m+2;
	int flow=0;
	while(bfs())
		while(flow=dicnic(s,INF)) ans+=flow;
	printf("%lld",ans);
	return 0;
}

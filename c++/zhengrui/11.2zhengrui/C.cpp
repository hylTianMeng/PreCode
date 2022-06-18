#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

int n,m,tot;
map<int,int> Map[N];
vector<int> v[N],col[N];
int From[N],To[N],Fa[N][32],Dep[N];

inline void Dfs(int k,int f){
	Dep[k]=Dep[f]+1;Fa[k][0]=f;
	for(int i=1;i<=30;i++) Fa[k][i]=Fa[Fa[k][i-1]][i-1];
	for(int to:v[k]){if(to==f) continue;Dfs(to,k);}
}

inline int GetLca(int a,int b){
	if(Dep[a]<Dep[b]) swap(a,b);
	for(int i=30;i>=0;i--) if(Dep[Fa[a][i]]>=Dep[b]) a=Fa[a][i];
	if(a==b) return a;
	for(int i=30;i>=0;i--) if(Fa[a][i]!=Fa[b][i]){a=Fa[a][i];b=Fa[b][i];}return Fa[a][0];
}

inline void Init(){
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int from,to,w;read(from);read(to);read(w);
		if(!Map[from][to]){
			Map[from][to]=++tot;Map[to][from]=tot;
			v[from].push_back(to);v[to].push_back(from);
			From[tot]=from;To[tot]=to;
			col[tot].push_back(w);
		}
		else col[Map[from][to]].push_back(w);
	}
	Dfs(1,0);
}

inline void Solve(int a,int b){
	int Lca=GetLca(a,b);
	// printf("Lca=%d\n",Lca);
	vector<int> Road,c;Road.clear();
	int k=a;while(k!=Lca){Road.push_back(k);k=Fa[k][0];}
	Road.push_back(Lca);c.clear();
	k=b;while(k!=Lca){c.push_back(k);k=Fa[k][0];}
	for(int i=c.size()-1;i>=0;i--) Road.push_back(c[i]);
	priority_queue<pair<int,int> > q[2];
	q[0].push(make_pair(0,0));int o=0;
	// for(int i=0;i<Road.size();i++) printf("%d ",Road[i]);
	// puts("");
	for(int i=0;i<Road.size()-1;i++){
		// printf("i=%d\n",i);
		o^=1;int now=Map[Road[i]][Road[i+1]];
		while(q[o].size()) q[o].pop();
		for(int co:col[now]){
			pair<int,int> Top=q[o^1].top();
			if(co!=Top.second){q[o].push(make_pair(Top.first+1,co));}
			else{
				q[o^1].pop();
				if(q[o^1].size()){
					q[o].push(make_pair(Max(Top.first,q[o^1].top().first+1),co));
				}
				else q[o].push(make_pair(Top.first,co));
				q[o^1].push(Top);
			}
		}
	}
	printf("%d\n",Max(0,q[o].top().first-1));
}

int q;

int main(){
	// freopen("my.in","r",stdin);
	// freopen("my.out","w",stdout);
	Init();
	read(q);
	while(q--){
		int a,b;read(a);read(b);
		Solve(a,b);
	}
	return 0;
}
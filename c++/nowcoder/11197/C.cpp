#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
	x=0; int f=1;
	char c=getchar();
	for(; !isdigit(c); c=getchar()) if(c == '-') f=-f;
	for(; isdigit(c); c=getchar()) x=x*10+c-'0';
	x*=f;
}

struct edge {
	int to,next;
	inline void Init(int to_,int ne_) { to=to_; next=ne_; }
} li[N<<1];
int head[N],tail;

inline void Add(int from,int to) {
	li[++tail].Init(to,head[from]);
	head[from]=tail;
}

int n,m,a[N],v[N];
int itot,id[N],rk[N],fa[N],top[N],Dep[N],Size[N],Son[N];

inline void dfs(int k,int fat) {
	fa[k]=fat; Size[k]=1; Dep[k]=Dep[fat]+1; 
    for(int x=head[k]; x; x=li[x].next) {
		int to=li[x].to;
		if(to==fat) continue;
		dfs(to,k);
		Size[k]+=Size[to];
		if(Size[Son[k]]<Size[to]) Son[k]=to;
	}
}

inline void dfs2(int k,int t) {
	top[k]=t; itot++; id[k]=itot; rk[itot]=k;
	if(Son[k]) { dfs2(Son[k],t); }
	for(int x=head[k]; x; x=li[x].next) {
		int to=li[x].to;
		if(to==fa[k]||to==Son[k]) continue;
		dfs2(to,to);
	}
}

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree {
	int sum[N<<2][2],tag[N<<2][2],len[N<<2];
	inline void PushUp(int k) {
		for(int i=0; i<=1; i++) sum[k][i]=sum[ls(k)][i]+sum[rs(k)][i];
	}
	inline void Build(int k,int l,int r) {
		len[k]=r-l+1;
		if(l==r) return;
		int mid=(l+r)>>1;
		Build(ls(k),l,mid);
		Build(rs(k),mid+1,r);
	}
	inline void A(int k,int op,int x) {
		sum[k][op]+=len[k]*x;
		tag[k][op]+=x;
	}
	inline void PushDown(int k) {
		for(int i=0; i<=1; i++) {
			if(tag[k][i]) {
				A(ls(k),i,tag[k][i]);
				A(rs(k),i,tag[k][i]);
				tag[k][i]=0;
			}
		}
	}
	inline void Update(int k,int l,int r,int z,int y,int x,int op) {
		if(l==z&&r==y) {
			A(k,op,x);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(k);
		if(y<=mid) Update(ls(k),l,mid,z,y,x,op);
		else if(z>mid) Update(rs(k),mid+1,r,z,y,x,op);
		else {
			Update(ls(k),l,mid,z,mid,x,op);
			Update(rs(k),mid+1,r,mid+1,y,x,op);
		}
		PushUp(k);
	}
	inline int Ask(int k,int l,int r,int w) {
		if(l==r) return sum[k][0]*a[fa[rk[l]]]+sum[k][1]*a[Son[rk[l]]];
		int mid=(l+r)>>1;
		PushDown(k);
		if(w<=mid) return Ask(ls(k),l,mid,w);
		else return Ask(rs(k),mid+1,r,w);
		assert(0);
	}
} tr;

inline void PreWork() {
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n - 1; i++) {
		int from,to;
		read(from); read(to);
		Add(from,to); Add(to,from);
	}
	dfs(1,0); dfs2(1,1); tr.Build(1,1,n);
}

inline void Lca(int x,int y,int op) {
	if(x==y) return;
	while(top[x]!=top[y]) {
		// if(Dep[top[x]] > Dep[top[y]]) { // 起点跳
		// 	if(id[top[x]] <= id[x] - 1) tr.Update(1, 1, n, id[top[x]], id[x] - 1, 1, 1);
		// 	x = top[x];
		// 	v[fa[x]] += a[x];
		// 	x = fa[x];
		// } else { // 终点跳
		// 	if(id[top[y]] + 1 <= id[y]) tr.Update(1, 1, n, id[top[y]] + 1, id[y], 1, 0);
		// 	y = top[y];
		// 	v[y] += a[fa[y]];
		// 	y = fa[y];
		// }
       if(Dep[top[x]]<Dep[top[y]]){swap(x,y);op^=1;}

       if(op==0){
           if(id[top[x]]+1<=id[x]) tr.Update(1,1,n,id[top[x]]+1,id[x],1,op);
           v[top[x]]+=a[fa[top[x]]];
       }
       else{
           if(id[top[x]]<=id[x]-1) tr.Update(1,1,n,id[top[x]],id[x]-1,1,op);
           v[fa[top[x]]]+=a[top[x]];
       }

       x=fa[top[x]];
	}
    // printf("x=%d y=%d op=%d\n",x,y,op);

//     op^=1;
//    if(Dep[x]>Dep[y]){swap(x,y);}
//    if(x==y) return;
//    if(op==0){
//     //    printf("2: %d %d %d %d\n",id[x]+1,id[y],1,0);
//        tr.Update(1,1,n,id[x]+1,id[y],1,op);
//    }
//    else{
//     //    printf("1: %d %d %d %d\n",id[x],id[y]-1,1,1);
//        tr.Update(1,1,n,id[x],id[y]-1,1,op);
//    }

    if(op==0){swap(x,y);}
    if(x==y) return;
	if(Dep[x] > Dep[y]) {
        // printf("1: %d %d %d %d\n",id[y],id[x]-1,1,1);
		tr.Update(1, 1, n, id[y], id[x] - 1, 1, 1);
	} else if(Dep[x] < Dep[y]) {
        // printf("2: %d %d %d %d\n",id[x]+1,id[y],1,0);
		tr.Update(1, 1, n, id[x] + 1, id[y], 1, 0);
	}
}

signed main() {
    // freopen("my.in","r",stdin);
    // freopen("my2.out","w",stdout);
	PreWork();
	for(int i=1; i<=m; i++) {
		int op,l,r;
		read(op); read(l);
		if(op==1) {
			read(r); Lca(l,r,1);
		} else {
			printf("%lld\n",tr.Ask(1,1,n,id[l])+v[l]);
		}
	}
	return 0;
}
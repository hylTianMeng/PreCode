#pragma warning (disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define RG register
#define mid ((x+y)>>1)
#define lson (pst<<1)
#define rson (pst<<1|1)
using namespace std;
const int maxn = 3e5 + 5, maxm = maxn << 1, inf = 0x7fffffff;
int x[maxn], y[maxn], z[maxn], p[maxn];//x,y,z为每条边的数据，p[x]为x代表边的权值
int head[maxm], nxt[maxm], v[maxm], cnt;//前向星
int son[maxn], dad[maxn], sz[maxn], depth[maxn], root;//树剖dfs1
int id[maxn], top[maxn], rak[maxn], num;//树剖dfs2
int c[maxn], d[maxn], srt[maxn];//记录区间并排序的数组
int ma, mb, mc;//最大路径的记录
int n, m;

struct Binary_Indexed_Tree//求和树状数组
{
	int a[maxn];

	inline int lowbit(int k) { return k & (-k); }
	inline void update(int x, int k) { for (int i = x; i <= n; i += lowbit(i))	a[i] += k; }
	inline int query(int x) { int i = x, ans = 0; for (i = x; i >= 1; i -= lowbit(i))	ans += a[i]; return ans; }
	inline void build(int x) { for (int i = 1; i <= n; i++)	update(i, p[rak[i]]); }
	inline int sum(int l, int r) { return query(r) - query(l - 1); }
}BIT;

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }

struct Segment_Tree//最大值线段树
{
	int mx[maxn << 2], tag[maxn << 2];

	inline void pushdown(int pst)
	{
		if (!tag[pst])	return;
		int k = tag[pst];
		mx[lson] = max(mx[lson], k), mx[rson] = max(mx[rson], k);
		tag[lson] = max(tag[lson], k), tag[rson] = max(tag[rson], k);
		tag[pst] = 0; return;
	}

	inline void pushup(int pst) { mx[pst] = max(mx[lson], mx[rson]); }

	inline void update(int x, int y, int pst, int l, int r, int k)
	{
		if (x > y || y<l || x>r)	return;
		if (l <= x && y <= r) { mx[pst] = max(mx[pst], k), tag[pst] = max(tag[pst], k); return; }
		pushdown(pst);
		update(x, mid, lson, l, r, k), update(mid + 1, y, rson, l, r, k);
		pushup(pst); return;
	}

	inline int query(int x, int y, int pst, int p)
	{
		if (x == y)	return mx[pst];
		pushdown(pst);
		if (p <= mid)	return query(x, mid, lson, p);
		else return query(mid + 1, y, rson, p);
	}
}ST;

inline void addline(int x, int y) { v[cnt] = y, nxt[cnt] = head[x], head[x] = cnt++; }

inline int read()
{
	RG char c = getchar(); RG int x = 0;
	while (c<'0' || c>'9')	c = getchar();
	while (c >= '0'&&c <= '9')	x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x;
}

inline void dfs1(int x, int f, int d)//树剖
{
	dad[x] = f, depth[x] = d, sz[x] = 1;
	for (RG int i = head[x]; ~i; i = nxt[i])
	{
		if (v[i] == f)	continue;
		dfs1(v[i], x, d + 1);
		sz[x] += sz[v[i]];
		if (sz[v[i]] > sz[son[x]])	son[x] = v[i];
	}
	return;
}

inline void dfs2(int x, int t)//树剖
{
	top[x] = t, id[x] = ++num, rak[id[x]] = x;
	if (!son[x])	return;
	dfs2(son[x], t);
	for (RG int i = head[x]; ~i; i = nxt[i])
		if (v[i] != dad[x] && v[i] != son[x])	dfs2(v[i], v[i]);
	return;
}

inline int sum(int x, int y)//求某条路径的权值
{
	RG int tx = top[x], ty = top[y], ans = 0;
	while (tx != ty)
	{
		if (depth[tx] >= depth[ty])	ans += BIT.sum(id[tx], id[x]), x = dad[tx], tx = top[x];
		else ans += BIT.sum(id[ty], id[y]), y = dad[ty], ty = top[y];
	}
	if (id[x] <= id[y])	ans += BIT.sum(id[x] + 1, id[y]);
	else ans += BIT.sum(id[y] + 1, id[x]);
	return ans;
}

inline bool cmp(int x, int y) { return c[x] < c[y]; }

inline void update(int x, int y, int z)//更新mx数组（其实是更新最大值线段树）
{
	RG int tx = top[x], ty = top[y], t = 0;
	while (tx != ty)
	{
		if (depth[tx] >= depth[ty]) c[++t] = id[tx], d[t] = id[x], x = dad[tx], tx = top[x];
		else c[++t] = id[ty], d[t] = id[y], y = dad[ty], ty = top[y];
	}
	if (id[x] <= id[y])	c[++t] = id[x] + 1, d[t] = id[y];
	else c[++t] = id[y] + 1, d[t] = id[x];
	for (int i = 1; i <= t; i++)	srt[i] = i;
	sort(srt + 1, srt + t + 1, cmp);
	if (c[srt[1]] > 1)	ST.update(1, n, 1, 1, c[srt[1]] - 1, z);
	if (d[srt[t]] < n)	ST.update(1, n, 1, d[srt[t]] + 1, n, z);
	for (int i = 1; i < t; i++)	ST.update(1, n, 1, d[srt[i]] + 1, c[srt[i + 1]] - 1, z);
	return;
}

inline int find_ans(int x, int y)//在最大路径上遍历并清零边求答案
{
	RG int ans = inf;
	if (x == y)	return 0;
	if (depth[x] < depth[y])	swap(x, y);
	while (depth[x] != depth[y])	ans = min(ans, max(mc - p[x], ST.query(1, n, 1, id[x]))), x = dad[x];
	while (x != y)
	{
		if (depth[x] > depth[y])	ans = min(ans, max(mc - p[x], ST.query(1, n, 1, id[x]))), x = dad[x];
		else ans = min(ans, max(mc - p[y], ST.query(1, n, 1, id[y]))), y = dad[y];
	}
	return ans;
}

int main(void)
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	memset(head, -1, sizeof(head));
	n = read(), m = read();
	for (int i = 1; i < n; i++)	x[i] = read(), y[i] = read(), z[i] = read();
	for (int i = 1; i < n; i++)	addline(x[i], y[i]), addline(y[i], x[i]);
	root = rand() % n + 1, dfs1(root, 0, 1), dfs2(root, root);//树剖
	for (int i = 1; i < n; i++)
	{
		if (depth[x[i]] > depth[y[i]])	p[x[i]] = z[i];//把深度大的点作为一条边的代表
		else p[y[i]] = z[i];
	}
	BIT.build(n);
	for (int i = 1; i <= m; i++)
	{
		RG int a = read(), b = read(), temp;
		temp = sum(a, b), update(a, b, temp);
		if (temp >= mc)	ma = a, mb = b, mc = temp;//求最大路径
	}
	printf("%d\n", find_ans(ma, mb));
	return 0;
}
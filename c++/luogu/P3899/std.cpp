#include <cstdio>

typedef long long ll;
inline ll max(ll a, ll b) { return a > b ? a : b; }
inline ll min(ll a, ll b) { return a < b ? a : b; }

const int MAXN = 300005;

int N, T; ll ans[MAXN];
struct node { int v, next; } E[MAXN << 1]; int head[MAXN], Elen;
struct query { int u, k; } q[MAXN];
struct vec { int v, next, id; } Q[MAXN]; int headQ[MAXN], Qlen;
void add(int u, int v) { ++Elen, E[Elen].v = v, E[Elen].next = head[u], head[u] = Elen; }
void addQ(int u, int v, int id) { ++Qlen, Q[Qlen].v = v, Q[Qlen].next = headQ[u], Q[Qlen].id = id, headQ[u] = Qlen; }

int fa[MAXN], dep[MAXN], siz[MAXN], maxdep[MAXN], wson[MAXN], top[MAXN];
void dfs1(int u, int ff) {
    fa[u] = ff, dep[u] = dep[ff] + 1, siz[u] = 1;
    for (int i = head[u]; i; i = E[i].next) if (E[i].v != ff) {
        dfs1(E[i].v, u), siz[u] += siz[E[i].v];
        if (maxdep[E[i].v] > maxdep[wson[u]]) wson[u] = E[i].v;
    } maxdep[u] = maxdep[wson[u]] + 1;
}
void dfs2(int u, int ff, int tp) {
    top[u] = tp; if (wson[u]) dfs2(wson[u], u, tp);
    for (int i = head[u]; i; i = E[i].next) if (E[i].v != ff && E[i].v != wson[u]) dfs2(E[i].v, u, E[i].v);
}
ll *dp[MAXN], tag[MAXN], buc[MAXN << 2], *id = buc;
void dfs(int u, int ff) {
    if (wson[u]) {
        dp[wson[u]] = dp[u] + 1, dfs(wson[u], u);
        dp[u][0] = 0, tag[u] = tag[wson[u]] + siz[wson[u]] - 1;
    }
    for (int i = head[u]; i; i = E[i].next) if (E[i].v != ff && E[i].v != wson[u]) {
        dp[E[i].v] = id, id += maxdep[E[i].v], dfs(E[i].v, u), tag[u] += tag[E[i].v] + siz[E[i].v] - 1;
        for (int j = 1; j <= maxdep[E[i].v]; ++j) dp[u][j] += dp[E[i].v][j - 1];
    } dp[u][0] = -tag[u];
    for (int i = headQ[u]; i; i = Q[i].next) ans[Q[i].id] = dp[u][min(q[Q[i].id].k, maxdep[u] - 1)] + tag[u];
}

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d%d", &N, &T); int i, u, v;
    for (i = 1; i < N; ++i) scanf("%d%d", &u, &v), add(u, v), add(v, u);
    for (i = 1; i <= T; ++i) scanf("%d%d", &q[i].u, &q[i].k), addQ(q[i].u, q[i].k, i);
    dfs1(1, 0), dfs2(1, 0, 1);
    dp[1] = id, id += maxdep[1], dfs(1, 0);
    for (i = 1; i <= T; ++i) printf("%lld\n", ans[i] + (ll)min(dep[q[i].u] - 1, q[i].k) * (siz[q[i].u] - 1));
    return 0;
}
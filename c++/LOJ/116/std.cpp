#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 30000 + 10;
const int INF = 0x3fffffff;

int n, m, s, t;
int eu[MAXN], ev[MAXN], el[MAXN], er[MAXN];
int pre[MAXN], to[MAXN], f[MAXN], head[MAXN], wcnt = 1;
int deg[MAXN];

int ans[MAXN];

int dep[MAXN];

inline void addedge(int u, int v, int w) {
    wcnt++;
    pre[wcnt] = head[u];
    head[u] = wcnt;
    to[wcnt] = v;
    f[wcnt] = w;
}
inline void add1edge(int u, int v, int w) {
    addedge(u, v, w);
    addedge(v, u, 0);
}

bool bfs(int s, int t) {
    static int q[MAXN], ql, qr;
    int i, u;

    memset(dep, 0, sizeof(dep));
    ql = qr = 1;
    q[1] = s;
    dep[s] = 1;

    while (ql <= qr) {
        u = q[ql];
        ql++;

        for (i = head[u]; i; i = pre[i]) {
            if (f[i] and !dep[to[i]]) {
                dep[to[i]] = dep[u] + 1;
                qr++;
                q[qr] = to[i];
            }
        }
    }

    return dep[t];
}
int maxflow(int u, int t, int lim) {
    int i, tot = 0, flow;

    if (u == t)
        return lim;

    for (i = head[u]; lim - tot and i; i = pre[i]) {
        if (f[i] and dep[u] + 1 == dep[to[i]]) {
            flow = maxflow(to[i], t, std::min(lim - tot, f[i]));
            f[i] -= flow;
            f[i ^ 1] += flow;
            tot += flow;
        }
    }

    if (!tot)
        dep[u] = -1;

    return tot;
}
int dinic(int s, int t) {
    int tot = 0;

    while (bfs(s, t))
        tot += maxflow(s, t, INF);

    return tot;
}

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    int i;
    int u, v, l, r, tot = 0;

    scanf("%d %d %d %d", &n, &m, &s, &t);

    for (i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &eu[i], &ev[i], &el[i], &er[i]);
        deg[eu[i]] -= el[i];
        deg[ev[i]] += el[i];
        add1edge(eu[i], ev[i], er[i] - el[i]);
    }

    for (i = 1; i <= n; i++)
        if (deg[i] < 0)
            add1edge(i, n + 2, -deg[i]);
        else {
            tot += deg[i];
            add1edge(n + 1, i, deg[i]);
        }

    add1edge(t, s, INF);

    if (tot ^ dinic(n + 1, n + 2)) {
        printf("please go home to sleep\n");
        return 0;
    }

    tot = 0;

    for (i = 1; i <= m; i++)
        if (eu[i] == s)
            tot += el[i];

    for (i = head[s]; i; i = pre[i])
        if (~i & 1 and to[i] <= n)
            tot += f[i ^ 1];

    memset(head, 0, sizeof(head));
    wcnt = 1;

    for (i = 1; i <= m; i++)
        add1edge(eu[i], ev[i], er[i] - el[i] - f[i << 1 ^ 1]);

    printf("LastAns=%d\n",tot);
    tot += dinic(s, t);
    printf("%d\n", tot);
    return 0;
}
#define LOCAL
#include <bits/stdc++.h>
#define ll long long
#define plli pair <long long, int>
#define mp(a, b) make_pair(a, b)
#define mset(l, x) memset(l, x, sizeof(l))
using namespace std;

const int N = 2000010;
const double eps = 1e-7;
const int INF = 0x3fffffff;

template <typename T> inline void read(T &x) {
    x = 0; int f = 1; char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    x *= f;
}

struct Edge {int u, v, nxt; ll w;} e[N];

int n, m, I, C, T; ll wsum;
int ecnt(1), head[N], vis[N], pre[N]; ll d[N];
ll Cd[N], Id[N]; int Cpre[N], rd[N], rcnt;

inline void add_edge(int u, int v, ll w) {
    e[ecnt].u = u, e[ecnt].v = v, e[ecnt].w = w;
    e[ecnt].nxt = head[u], head[u] = ecnt ++;
}

priority_queue <plli > q;

void dijkstra(int s) {
    mset(d, 0x3f); mset(vis, 0); mset(pre, 0);
    d[s] = 0; q.push(mp(0, s)); 
    while (q.size()) {
        int now = q.top().second; q.pop();
        if (vis[now]) continue; vis[now] = 1;
        for (int i = head[now]; i; i = e[i].nxt)
          if (d[e[i].v] > d[now] + e[i].w) {
              d[e[i].v] = d[now] + e[i].w;
              pre[e[i].v] = i;
              q.push(mp(-d[e[i].v], e[i].v));
          }
    }
}

inline void get_road() {
    int now = T;
    do {
        rd[++ rcnt] = now;
        now = e[Cpre[now]].u;
    } while (now);
}

inline bool check(double x) {
    for (int i = 1; i <= rcnt; ++ i)
      if (1.0 * Cd[rd[i]] >= 1.0 * Id[rd[i]] * x)
        return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("my.in", "r", stdin);
    freopen("std.out", "w", stdout);
#endif
    read(n), read(m);
    for (int i = 1; i <= m; ++ i) {
        int u, v, w; read(u), read(v), read(w);
        add_edge(u, v, w); add_edge(v, u, w);
        wsum += w;
    }
    read(C), read(I), read(T);
    dijkstra(C);
    for (int i = 1; i <= n; ++ i) Cd[i] = d[i], Cpre[i] = pre[i];
    dijkstra(I); get_road();
    for (int i = 1; i <= n; ++ i) Id[i] = d[i];
    double l = 0, r = 1.0 * wsum, res = 1.0 * INF;
    // for (int i = 1; i <= rcnt; ++ i) printf("%d ", rd[i]); puts("");
    // for (int i = 1; i <= n; ++ i)
    //   printf("%d : %d %d %d\n", i, Cd[i], Cpre[i], Id[i]);
    if (Cd[T] > wsum) {puts("-1"); return 0;}
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (check(mid)) 
            res = mid, r = mid;
        else l = mid;
    }
    if (res > wsum) puts("-1");
    else printf("%0.5lf", res);
    return 0;
}
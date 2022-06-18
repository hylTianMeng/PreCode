#define maxn 150005

bool cons[maxn], vis[2][maxn * 2];

vector<vector<int>> graph, g, gr;

void dfs(int p, vector<vector<int>>& graph, int id) {
    vis[id][p] = true;
    for (auto i : graph[p])
        if (!vis[id][i]) dfs(i, graph, id);
    return;
}

void solve(void) {
    int n = read<int>() + 2, m = read<int>();
    graph.clear(), g.clear(), gr.clear(), graph.resize(n + 1), g.resize(2 * n + 1), gr.resize(2 * n + 1);
    for (int i = 1; i <= n; i++) cons[i] = false, vis[0][i] = vis[1][i] = vis[0][n + i] = vis[1][n + i] = false;
    for (int i = 3; i < n; i++) graph[1].push_back(i), graph[i - 1].push_back(n);
    cons[1] = cons[n - 1] = true;
    for (int i = 1; i <= m; i++) {
        int x = read<int>() + 1, y = read<int>() + 1;
        if (x + 1 == y)
            cons[x] = true;
        else
            graph[x].push_back(y);
    }
    int p = 0, l = 0, r = 0;
    for (int i = 1; i < n; i++)
        if (!cons[i]) {
            if (!p) p = l = i;
            r = i;
        }
    if (p == 0) return write(1LL * (n - 2) * (n - 3) / 2), putch('\n');
    for (int i = n, r = n; i > 1; i--) {
        if (!cons[i]) r = i;
        for (auto j : graph[i - 1])
            if (j <= r + 1)
                g[i - 1].push_back(n + j), g[n + i].push_back(j - 1), gr[n + j].push_back(i - 1), gr[j - 1].push_back(n + i);
    }
    dfs(p, g, 0), dfs(p, gr, 0), dfs(n + p + 1, g, 1), dfs(n + p + 1, gr, 1);
    long long ans = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= l; i++) cnt1 += vis[0][i];
    for (int i = r; i < n; i++) cnt2 += vis[0][i];
    ans += cnt1 * cnt2, cnt1 = cnt2 = 0;
    for (int i = 1; i <= l; i++) cnt1 += vis[1][i];
    for (int i = r; i < n; i++) cnt2 += vis[1][i];
    ans += cnt1 * cnt2, cnt1 = cnt2 = 0;
    for (int i = 1; i <= l; i++) cnt1 += (vis[0][i] & vis[1][i]);
    for (int i = r; i < n; i++) cnt2 += (vis[0][i] & vis[1][i]);
    ans -= cnt1 * cnt2;
    return write(ans - (l == r)), putch('\n');
}
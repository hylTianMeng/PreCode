  #include <bits/stdc++.h>

  using namespace std;

  const int maxn = 510;
  const int INF = 0x3f3f3f3f;
  typedef pair<int, int> P;
  int n, m, k;

  struct edge {
    int to, next, w;
    inline edge(){}
    inline edge(int to,int ne,int w) : to(to),next(ne),w(w) {}
  } e[maxn << 1];

  int head[maxn << 1], tree[maxn << 1], tot;
  int dp[maxn][5000], vis[maxn];
  int key[maxn];
  priority_queue<P, vector<P>, greater<P> > q;

  void add(int u, int v, int w) {
    e[++tot] = edge(v, head[u], w);
    head[u] = tot;
  }
//堆，建边以及邻接表。
  void dijkstra(int s) {  // 求解最短路
  //注意这里的 s 并不是起点，而是一个二进制状态。
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
      P item = q.top();
      q.pop();
      if (vis[item.second]) continue;
      vis[item.second] = 1;
      for (int i = head[item.second]; i; i = e[i].next) {
        int to=e[i].to;
        if (dp[to][s] > dp[item.second][s] + e[i].w) {
          dp[to][s] = dp[item.second][s] + e[i].w;
          q.push(P(dp[to][s], to));
        }
      }
    }
  }

  int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    memset(dp, INF, sizeof(dp));
    scanf("%d %d %d", &n, &m, &k);
    int u, v, w;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d %d", &u, &v, &w);
      add(u, v, w);
      tree[tot] = v;
      add(v, u, w);
      tree[tot] = u;
    }
	//输入，其中 tree[k] 表示第 k 条边的终点节点
    for (int i = 1; i <= k; i++) {
      scanf("%d", &key[i]);
      dp[key[i]][1 << (i - 1)] = 0;
    }
	//初始化
    for (int s = 1; s < (1 << k); s++) {//枚举第二维
      for (int i = 1; i <= n; i++) {//枚举第一维
        for (int subs = s & (s - 1); subs;//s&(s-1) 表示的是去掉最后一个1，这里的 subs 是枚举去掉 s
        // 的每一个1，很妙的二进制用法。这里是枚举 s 的所有子集。
             subs = s & (subs - 1))  // 状压 dp 可以看下题解里写的比较详细
          dp[i][s] = min(dp[i][s], dp[i][subs] + dp[i][s ^ subs]);//首先，都是以 i 为根，所以直接相加就可以。
        if (dp[i][s] != INF) q.push(P(dp[i][s], i));//
        // printf("before:f[%d][%d]=%d\n",i,s,dp[i][s]);
      }
      dijkstra(s);
      // for(int i=1;i<=n;i++){
      //   printf("f[%d][%d]=%d\n",i,s,dp[i][s]);
      // }
    }
	//状压dp。
    printf("%d\n", dp[key[1]][(1 << k) - 1]);
	//最后一定以某个关键点为根。
    return 0;
  }
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 51000, M = 8e5;
const LL INF = 1e18;
struct hh {
    int to, nex;
    LL quan;
} qwq[M];
int tot = 1, head[N];
void add(int x, int y, LL z) {
    //  cout<<x<<"->"<<y<<" "<<z<<endl;
    qwq[++tot].to = y;
    qwq[tot].quan = z;
    qwq[tot].nex = head[x];
    head[x] = tot;
}
int dep[N], cut[N], s, t;
LL low[M];
queue<int> q;
LL dfs(int u, LL in) {
    if (u == t)
        return in;

    LL num = 0;

    for (int i = cut[u]; i; i = qwq[i].nex) {
        int j = qwq[i].to;
        cut[u] = i;

        if (dep[j] != dep[u] + 1 || !qwq[i].quan)
            continue;

        LL out = dfs(j, min(qwq[i].quan, in));

        if (out == 0) {
            dep[j] = 0;    //.
            continue;
        }

        qwq[i].quan -= out;
        qwq[i ^ 1].quan += out;
        in -= out;
        num += out;
    }

    return num;
}
bool bfs() {
    memset(dep, 0, sizeof(dep));
    q.push(s);
    dep[s] = 1;

    while (!q.empty()) {
        //  cout<<111111<<endl;
        int u = q.front();
        q.pop();
        cut[u] = head[u];

        for (int i = head[u]; i; i = qwq[i].nex) {
            int j = qwq[i].to;

            if (dep[j] || !qwq[i].quan)
                continue;

            dep[j] = dep[u] + 1;
            q.push(j);
        }
    }

    return dep[t];
}
LL rd[N], cd[N], ans, flow, upp;
int n, m, s1, t1, a;
int main() {
    //  freopen("1.in","r",stdin);
    scanf("%d%d%d%d", &n, &m, &s1, &t1);

    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d%lld%lld", &x, &y, &low[i], &upp);
        add(x, y, upp - low[i]);
        add(y, x, 0); // 差网络
        cd[x] += low[i];
        rd[y] += low[i]; // 下界网络
    }

    add(t1, s1, INF);
    add(s1, t1, 0);
    a = tot;
    s = 0;
    t = 50005;

    for (int i = 1; i <= n; i++) {
        LL x = rd[i] - cd[i];

        if (x > 0)
            add(s, i, x), add(i, s, 0);

        if (x < 0)
            add(i, t, -x), add(t, i, 0);
    }

    while (bfs())
        ans += dfs(s, INF);

    for (int i = head[s]; i; i = qwq[i].nex)
        if (qwq[i].quan) {
            printf("please go home to sleep");
            return 0;
        }

    /*  for(int i=head[t];i;i=qwq[i].nex){
            int j=qwq[i].to;
            if(j==s){
                flow=qwq[i^1].quan;
                qwq[i].quan=qwq[i^1].quan=0;
            }
        }*/
    flow = qwq[a].quan;
    qwq[a].quan = qwq[a ^ 1].quan = 0;
    s = t1;
    t = s1;
    ans = 0;

    while (bfs())
        ans += dfs(s, INF);

    printf("%lld", flow - ans);
    /*  printf("YES\n");
        for(int i=1;i<=m;i++)
            printf("%d\n",qwq[a[i]].quan+low[i]);*/
    return 0;
}
/*

*/
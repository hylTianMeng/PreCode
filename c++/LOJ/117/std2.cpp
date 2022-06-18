#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 101000, M = 1e6 + 10;
const LL INF = 1e18;
struct hh {
    int to, nex;
    LL quan;
} qwq[M * 2];
int tot = 1, head[N];
void add(int x, int y, LL z) {
    //  cout<<x<<"->"<<y<<" "<<z<<endl;
    qwq[++tot].to = y;
    qwq[tot].quan = z;
    qwq[tot].nex = head[x];
    head[x] = tot;
}
LL dep[N], cut[N], s, t;
LL low;
queue<LL> q;
LL dfs(int u, LL in) {
    //  cout<<u<<endl;
    if (u == t)
        return in;

    LL num = 0;

    for (LL i = cut[u]; i && in; i = qwq[i].nex) { // && in
        LL j = qwq[i].to;
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

LL n;
bool bfs() {
    for (LL i = 1; i <= n + 2; i++)
        dep[i] = 0;

    dep[t] = 0;
    //  memset(dep,0,sizeof(dep));
    q.push(s);
    dep[s] = 1;

    while (!q.empty()) {
        //  cout<<111111<<endl;
        LL u = q.front();
        q.pop();
        cut[u] = head[u];

        for (LL i = head[u]; i; i = qwq[i].nex) {
            LL j = qwq[i].to;

            if (dep[j] || !qwq[i].quan)
                continue;

            dep[j] = dep[u] + 1;
            q.push(j);
        }
    }

    return dep[t];
}
LL rd[N], cd[N], ans, flow, upp;
LL m, s1, t1, a;
int main() {
    //  freopen("7.in","r",stdin);
    scanf("%d%d%d%d", &n, &m, &s1, &t1);

    for (LL i = 1, x, y; i <= m; i++) {
        scanf("%d%d%lld%lld", &x, &y, &low, &upp);
        add(x, y, upp - low);
        add(y, x, 0); // 差网络
        cd[x] += low;
        rd[y] += low; // 下界网络
    }

    add(t1, s1, INF);
    add(s1, t1, 0);
    a = tot;
    s = n + 1;
    t = n + 2;

    for (LL i = 1; i <= n; i++) {
        LL x = rd[i] - cd[i];

        if (x > 0)
            add(s, i, x), add(i, s, 0);

        if (x < 0)
            add(i, t, -x), add(t, i, 0);
    }

    //  cout<<11111111<<endl;
    LL num = 0;

    while (bfs())
        num++,
            ans += dfs(s, INF);

    //  cout<<num<<endl;
    for (LL i = head[s]; i; i = qwq[i].nex)
        if (qwq[i].quan) {
            printf("please go home to sleep");
            return 0;
        }

    /*  for(LL i=head[t];i;i=qwq[i].nex){
            LL j=qwq[i].to;
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
        for(LL i=1;i<=m;i++)
            printf("%d\n",qwq[a[i]].quan+low[i]);*/
    return 0;
}
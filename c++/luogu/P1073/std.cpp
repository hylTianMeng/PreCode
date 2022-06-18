#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m, d[maxn*3], inq[maxn*3];
vector<pair<int, int>> G[maxn*3];

#define t(x,i) (x+i*n)  // t(x,i) 表示第i层的x
// 建立x->y边的函数, 不用加 make_pair是 C++11特性
#define add(x, y) G[t(x,0)].push_back({t(y,0), 0}), G[t(x,1)].push_back({t(y,1),0}), G[t(x,2)].push_back({t(y,2),0})

void spfa(int s) {
    for(int i = 1;i <= n*3;i++) d[i] = INT_MIN; // 这里n*3别漏了, INT_MIN 是C++内置最小值常量
    d[s] = 0; 
    queue<int> Q; inq[s] = true; Q.push(s);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop(); inq[x] = false;
        for(auto [v, len] : G[x])  // C++17 特性, 等价于 int v = G[x][i].first, len = G[x][i].second;
            if(d[v] < d[x] + len) {
                d[v] = d[x] + len;
                if(!inq[v]) { Q.push(v); inq[v] = true; }
            } 
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); // 加速cin, cout
    cin >> n >> m;
    for(int i = 1, v;i <= n; ++i) {
        cin >> v;
        G[t(i,0)].push_back({t(i,1), -v});
        G[t(i,1)].push_back({t(i,2), v});
    }
    for(int i = 1,x,y,z;i <= m; ++i) {
        cin >> x >> y >> z; add(x, y);
        if(z == 2) add(y, x);
    }
    spfa(t(1,0));
    cout << d[t(n,2)] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, mod = 998244353;

int n, m, tot, last, rt[N], sz[N], sum, f[N<<1], g[N];

bool vis[N<<1];

struct Node {
	int fa, len;
	map <int, int> tr;
} t[N<<1];

void ins_(int k, int rt) {
	int x = ++tot, p = last;
	t[x].len = t[p].len + 1;
	
	while (p && !t[p].tr.count(k)) {
		t[p].tr[k] = x;
		p = t[p].fa;
	}
	
	if (!p) {
		t[x].fa = rt;
	} else {
		int q = t[p].tr[k];
		
		if (t[p].len + 1 == t[q].len) {
			t[x].fa = q;
		} else {
			t[++tot] = t[q], t[tot].len = t[p].len + 1;
			t[x].fa = t[q].fa = tot;
			
			while (p && t[p].tr[k] == q) {
				t[p].tr[k] = tot;
				p = t[p].fa;
			}
		}
	}
	
	last = x;
}
//后缀自动机插入一个字符。

void dfs_(int x) {
	if (vis[x]) {
		return;
	}
	
	vis[x] = 1;
	f[x] = 1 + sum;
	
	for (auto y : t[x].tr) {
        //y.first 为转移边上的字符，y.second 为转移到的节点编号。
		dfs_(y.second);
		f[x] = (f[x] + f[y.second])%mod;
		f[x] = (f[x] - g[y.first])%mod;
	}
}
//遍历整个后缀自动机。
//我们知道，后缀自动机上的每一个节点都代表着 endpos 相同的字符串，然后通过一条转移边转移到的，是某个节点第某些串在后面添加字符得到。
//也就是说，设从 u 转移到 v，那么有 u 是 v 中一些字符串的前缀。

void solve_(int k) {
	int x = rt[k];
	
	dfs_(x);
	
	for (auto y : t[x].tr) {
		int u = y.first, v = f[y.second];
		sum = (sum - g[u])%mod;
		g[u] = v;
		sum = (sum + g[u])%mod;
	}
}

int main() {
	//freopen("splice.in", "r", stdin);
	//freopen("splice.out", "w", stdout);
		
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		rt[i] = last = ++tot;
		scanf("%d", &sz[i]);
		
		for (int j = 1, x; j <= sz[i]; j++) {
			scanf("%d", &x);
			ins_(x, rt[i]);
		}
	}
    //给每个字符串都建立一个后缀自动机，其中第 i 个后缀自动机的初始结点存放在 rt[i] 里面。

	for (int i = n; i; i--) {
		solve_(i);
	}
    //对每个后缀自动机都做一遍。
	
	printf("%d\n", (sum%mod + mod)%mod);
} 

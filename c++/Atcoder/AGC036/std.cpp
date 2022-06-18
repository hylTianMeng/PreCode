#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

int n, mod, dp[505][505];
pair <int, int> p[505];

inline void Prefix() {
	for (int i = 0;i < n;i++) {
		p[i + 1].first = ceil(sqrt(n * n - i * i)) - 1;
		p[i + 1].second = floor(sqrt(4 * n * n - i * i));
		if (p[i + 1].second > 2 * n - 1) p[i + 1].second = 2 * n - 1;
	}
	for (int i = n;i < 2 * n;i++) {
		p[i + 1].first = floor(sqrt(4 * n * n - i * i));
		if (p[i + 1].first > 2 * n - 1) p[i + 1].first = 2 * n - 1;
		p[i + 1].second = 0;
	}
	sort(p + 1, p + 2 * n + 1);
    for(int i=1;i<=2*n+1;i++){
        printf("p[i]= %d %d\n",p[i].first,p[i].second);
    }
}

inline int Calc(int k) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int limcnt = 0, cntr = 0;
	for (int i = 1;i <= 2 * n;i++) {
		if (p[i].second == 0) {
			for (int j = 0;j <= limcnt;j++) dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j] * (p[i].first - cntr - j + 1) % mod) % mod;
			cntr++;
		} else {
			for (int j = 0;j <= limcnt;j++) {
				dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j] * (p[i].second + 1 - n - k - limcnt + j) % mod) % mod;
				dp[i][j + 1] = (dp[i][j + 1] + 1ll * dp[i - 1][j] * (p[i].first - cntr - j + 1) % mod) % mod;
			}
			limcnt++;
		}
        for(int j=1;j<=k;j++){
            printf("f[%d][%d]=%d\n",i,j,dp[i][j]);
        }
	}
	return dp[2 * n][k];
}

inline void Solve() {
	long long ans = 0;
	for (int i = 0;i <= n;i++) {
        printf("i=%d\n",i);
        printf("Ans=%d\n",ans);
		if (i & 1) ans = (ans - Calc(i) + mod) % mod;
		else ans = (ans + Calc(i)) % mod;
		//printf("%d\n", Calc(i));
	}
	printf("%lld", ans);
}

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	n = qread(); mod = qread();
	Prefix();
	Solve();
	return 0;
}
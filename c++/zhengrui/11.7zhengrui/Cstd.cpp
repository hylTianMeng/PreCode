#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010, w[] = {1, 2, 4, 20, INT_MAX};
int T, n, b, x[maxn], y[maxn];
long long a[4], sum[4];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %lld %lld %lld %d %lld", &n, &a[0], &a[1], &a[2], &b, &a[3]);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i < 4; i++) {
			a[i] = 1LL * a[i] * w[i] + (i ? a[i - 1] : 0), sum[i] = 0;
			for (int j = 1; j <= n; j++) sum[i] += x[j] % w[i + 1];
		}
		bool ans = 0;
		int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
		for (int i = 1; i <= n; i++) if (x[i] >= 10) {
			bool foo = x[i] % 4 < 2, bar = x[i] % 20 < 10;
			if (foo && bar) c00++;
			else if (foo) c01++;
			else if (bar) c10++;
			else c11++;
		}
		for (int t1 = 0; t1 <= min(1, c00); t1++) {
			for (int t4 = max(0, min(b, c11) - 1); t4 <= min(b, c11); t4++) {
				for (int diff = -c10; diff <= c01; diff++) {
					int t2, t3;
					if (diff < 0) t2 = 0, t3 = -diff;
					else t2 = diff, t3 = 0;
					if (t1 + t2 + t3 + t4 > b) continue;
					bool flag = a[0] >= sum[0];
					flag &= a[1] >= sum[1] + 2 * (t1 + t2 - t3 - t4);
					flag &= a[2] >= sum[2] + 10 * (t1 + t3 - t2 - t4);
					flag &= a[3] + 10LL * (b - (b - t1 - t2 - t3 - t4) % 2) >= sum[3];
					ans |= flag;
				}
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 15;

int N, M, A[MN][MN];
int w[MN * MN];
int c[1 << MN][MN], f[1 << MN];

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%d", &N, &M), w[0] = 1;
	for (int i = 1; i <= M; ++i) w[i] = 2 * w[i - 1] % Mod;
	for (int i = 1, x, y; i <= M; ++i) scanf("%d%d", &x, &y), A[--x][--y] = 1;
	for (int S = 1; S < 1 << N; ++S) {
		int j = 0;
		while (~S >> j & 1) ++j;
		for (int u = 0; u < N; ++u)
			c[S][u] = c[S ^ 1 << j][u] + A[u][j];
	}
	for (int S = 0; S < 1 << N; ++S) if ((S & 3) == 3) {
		f[S] = 1;
        printf("S=%d\n",S);
		for (int T = S & (S - 1); T; --T &= S) if ((T & 1) == (T >> 1 & 1)) {
			if (T & 1) {
				int Coef = 1;
				for (int i = 0; i < N; ++i) if (S >> i & 1) {
					if (T >> i & 1) Coef = (LL)Coef * (w[c[S ^ T][i]] - 1) % Mod;
					else Coef = (LL)Coef * w[c[T][i]] % Mod;
				}
				f[S] = (f[S] + (LL)Coef * f[T]) % Mod;
			} else {
				int Coef = 1;
				for (int i = 0; i < N; ++i) if (S >> i & 1) {
					if (T >> i & 1) Coef = (LL)Coef * (w[c[S ^ T][i]] - 1) % Mod * w[c[T][i]] % Mod;
					else Coef = (LL)Coef * w[c[T][i]] % Mod;
				}
				f[S] = (f[S] + Coef) % Mod;
			}
		}
        printf("h[%d]=%d\n",S,f[S]);
	}
	printf("%d\n", (w[M] - f[(1 << N) - 1] + Mod) % Mod);
	return 0;
}

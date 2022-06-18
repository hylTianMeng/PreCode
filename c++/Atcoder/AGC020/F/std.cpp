#include <bits/stdc++.h>
using namespace std;
int read();
int n, c, l[51];
double f[502][102], res, cnt;
int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    n = read(), c = read();
    for (int i = 0; i < n; ++i) l[i] = read();
    sort(l, l + n);
    while (1) {
        for (int i = 0; i <= c * n; ++i)
            for (int s = 0; s < (1 << n - 1); ++s) f[i][s] = 0;
        f[l[n - 1] * n][0] = 1;
        for (int i = 1, p; i <= c * n; ++i) {
            if ((p = i % n - 1) < 0) continue;
            for (int j = i; j <= c * n; ++j)
                for (int s = 0; s < (1 << n - 1); ++s)
                    if (~s >> p & 1){
                        // printf("f[%d][%d]=%d\n",j,s,(int)f[j][s]);
                        f[min(c * n, max(j, i + l[p] * n))][s | (1 << p)] +=
                            f[j][s];
                        // printf("now f[%d][%d]=%d\n",min(c * n, max(j, i + l[p] * n)),s | (1 << p),(int)f[min(c * n, max(j, i + l[p] * n))][s | (1 << p)]);
                    }
                        
        }
        res += f[c * n][(1 << n - 1) - 1], ++cnt;
        if (!next_permutation(l, l + n - 1)) break;
    }
    printf("res=%lf\n",res);
    printf("%.13lf\n", (double)res / cnt / pow(c, n - 1));
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll pm = 1000000007;
const int N = 15;
int out[N], in[N], fun[1 << N], pw[N * N + 5], cnt[1 << N], cross[1 << N];
ll dp[1 << N], all[1 << N], p[1 << N];
int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    int n, m, tn, i, a, b, S, T, rem, t, tmp;
    cin >> n >> m; tn = (1 << n) - 1;
    for (i = 1; i <= m; ++i) {
        cin >> a >> b; --a; --b;
        out[a] |= 1 << b; in[b] |= 1 << a;
    }
    for (i = 0; i < n; ++i) fun[1 << i] = i;
    for (pw[0] = i = 1; i <= n * n; ++i) pw[i] = pw[i - 1] * 2 % pm;
    for (S = 1; S <= tn; ++S) cnt[S] = cnt[S >> 1] + (S & 1);
    dp[0] = all[0] = 1; p[0] = pm - 1;
    for (S = 1; S <= tn; ++S) {
        if (cnt[S] == 1) {dp[S] = p[S] = all[S] = 1; continue;}
        for (i = tmp = 0; i < n; ++i) if (S & (1 << i)) tmp += cnt[S & out[i]];
        all[S] = dp[S] = pw[tmp];
        printf("tmp=%d\n",tmp);
        rem = S - (S & -S);
        for (T = rem; ; T = (T - 1) & rem) {
            t = T | (S & -S);
            if (t < S) (p[S] += pm - dp[t] * p[S - t] % pm) %= pm;
            if (!T) break;
        }
        for (T = S; T; T = (T - 1) & S) {
            if (T == S) cross[T] = 0;
            else {
                t = fun[(S - T) & (T - S)];
                printf("t=%d\n",t);
                cross[T] = cross[T + (1 << t)] + cnt[in[t] & T] - cnt[out[t] & (S - T - (1 << t))];
                printf("%d %d %d\n",cross[T+(1<<t)],cnt[in[t]&T],cnt[out[t]&(S-T-(1<<t))]);
                printf("t=%d in[t]=%d cnt=%d\n",t,in[t],cnt[in[t]&T]);
            }
            (dp[S] += pm - p[T] * all[S - T] % pm * pw[cross[T]] % pm) %= pm;
            printf("p[%d]=%d all[%d]=%d cross[%d]=%d\n",T,p[T],S-T,all[S-T],T,cross[T]);
            printf("dp[%d]=%d\n",S,dp[S]);
        }
        (p[S] += dp[S]) %= pm;
        printf("S=%d dp[s]=%d all[s]=%d p[s]=%d\n",S,dp[S],all[S],p[S]);
    }
    cout << dp[tn] << endl;
    return 0;
}
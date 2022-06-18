#include <bits/stdc++.h>
#define ll long long
using namespace std;
int tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;

const int N = 100010;
const int INF = 0x3fffffff;

template <typename T> inline void read(T &x) {
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    x = 0; int f = 1; char c = getchar();
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    x *= f;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
}

int t, n, one_tot, pos[2][N], cnt; char s[N];

void MAIN() {
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    one_tot = 0; cnt = 0;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    read(n); scanf("%s", s + 1);
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    for (int i = 1; i <= n; ++ i)
      if (s[i] - '0') ++ one_tot;
      tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
      tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    int l = 1, r = n;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    while (l <= r) {
        while (l <= n && !(s[l] - '0')) ++ l;
        while (r >= 1 && s[r] - '0') -- r;
        if (l < r) pos[0][++ cnt] = l, pos[1][cnt] = r;
        ++ l, -- r;
    }
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    if (cnt) printf("1\n");
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    printf("%d ", cnt * 2);
    for (int i = 1; i <= cnt; ++ i)
      printf("%d ", pos[0][i]);
       tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
        tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
         tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
          tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
           tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
            tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    for (int i = cnt; i >= 1; -- i)
      printf("%d ", pos[1][i]);
    puts("");
}

int main() {
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    read(t); while (t --) MAIN(); return 0;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
    tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt=123;
}
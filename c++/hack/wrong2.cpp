#include <bits/stdc++.h>
const int N = 1e5+5;
int n, m1, m2;
struct data {
    int a;
    int b;
    bool operator < (const data & other) const {
        return a < other.a;
    }
} a1[N], a2[N];
int mp1[N<<1], mp2[N<<1];
int tot1, tot2;
int leaf1[N<<1], leaf2[N<<1];
int l, r;
int ans;
// int id;
int ask(int x) {
    int res = 0;
    int num1 = x, num2 = n - x;
    int pos1 = 0, pos2 = 0;
    memset(leaf1, 0, sizeof(leaf1));
    memset(leaf2, 0, sizeof(leaf2));
    for (int i = 1; i <= m1; i++) {
        while (pos1 < a1[i].a)
            num1 += leaf1[++pos1];
        if (num1) {
            num1--;
            res++;
            leaf1[a1[i].b + 1]++;
        }
    }
    for (int i = 1; i <= m2; i++) {
        while (pos2 < a2[i].a)
            num2 += leaf2[++pos2];
        if (num2) {
            num2--;
            res++;
            leaf2[a2[i].b + 1]++;
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #define fin std::cin
    #define fout std::cout
    fin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        fin >> a1[i].a >> a1[i].b;
        mp1[++tot1] = a1[i].a;
        mp1[++tot1] = a1[i].b;
    }
    for (int i = 1; i <= m2; i++) {
        fin >> a2[i].a >> a2[i].b;
        mp2[++tot2] = a2[i].a;
        mp2[++tot2] = a2[i].b;
    }
    std::sort(mp1 + 1, mp1 + tot1 + 1);
    std::sort(mp2 + 1, mp2 + tot2 + 1);
    tot1 = std::unique(mp1 + 1, mp1 + tot1 + 1) - mp1 - 1;
    tot2 = std::unique(mp2 + 1, mp2 + tot2 + 1) - mp2 - 1;
    for (int i = 1; i <= m1; i++) {
        a1[i].a = std::lower_bound(mp1 + 1, mp1 + tot1 + 1, a1[i].a) - mp1;
        a1[i].b = std::lower_bound(mp1 + 1, mp1 + tot1 + 1, a1[i].b) - mp1;
    }
    for (int i = 1; i <= m2; i++) {
        a2[i].a = std::lower_bound(mp2 + 1, mp2 + tot2 + 1, a2[i].a) - mp2;
        a2[i].b = std::lower_bound(mp2 + 1, mp2 + tot2 + 1, a2[i].b) - mp2;
    }
    std::sort(a1 + 1, a1 + m1 + 1);
    std::sort(a2 + 1, a2 + m2 + 1);
    l = 0, r = n;
    while (l < r - 2000) {
        int sublen = (r - l) / 3;
        int ml = l + sublen;
        int mr = r - sublen;
        int resl = ask(ml), resr = ask(mr);
        if (resl < resr) {
            // std::cerr << 'a';
            l = ml;
        } else if (resl == resr) {
            // std::cerr << 'b';
            l = ml;
            r = mr;
        } else {
            // std::cerr << 'c';
            r = mr;
        }
    }
    // std::cerr << l << ' ' << r << std::endl;
    for (int i = l; i <= r; i++) {
        // if (ask(i) > ans) id = i;
        ans = std::max(ans, ask(i));
    }
    // std::cerr << id << '\n';
    fout << ans << std::endl;
}
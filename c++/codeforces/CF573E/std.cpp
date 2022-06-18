#include <bits/stdc++.h>
#define int long long
namespace mystd {// 快读 & 快输
    inline int read() {
        int w = 1, q = 0;
        char ch = ' ';
        while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
        if (ch == '-') w = -1, ch = getchar();
        while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
        return w * q;
    }
    inline void write(int x) {
        if (x < 0) {
            x = ~(x - 1);
            putchar('-');
        }
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
}
using namespace std;
using namespace mystd;

const int maxn = 1e5 + 100;
int n, s[maxn];
struct fhq_treap {// 用 fhq-treap 来维护区间操作
    int rt, tot;
    fhq_treap() { rt = 1; }
    int sz[maxn], ch[maxn][2], rd[maxn], lz1[maxn], lz2[maxn], val[maxn];
    #define ls(x) ch[x][0]
    #define rs(x) ch[x][1]
    void pushup(int x) { sz[x] = sz[ls(x)] + sz[rs(x)] + 1; }
    void down(int x, int l1, int l2) { if (x) lz1[x] += l1, lz2[x] += l2, val[x] += l1 * (sz[ls(x)] + 1) + l2; }
    void pushdown(int x) { if (lz1[x] || lz2[x]) down(ls(x), lz1[x], lz2[x]), down(rs(x), lz1[x], lz2[x] + lz1[x] * (sz[ls(x)] + 1)), lz1[x] = lz2[x] = 0; }
    void make(int v) {
        sz[++tot] = 1;
        val[tot] = v;
        rd[tot] = rand();
    }
    int merge(int x, int y) {// 合并
        if (!x || !y) return x + y;
        else {
            pushdown(x);
            pushdown(y);
            if (rd[x] >= rd[y]) {
                ls(y) = merge(x, ls(y));
                pushup(y);
                return y;
            } else {
                rs(x) = merge(rs(x), y);
                pushup(x);
                return x;
            }
        }
    }
    void split(int p, int k, int &x, int &y) {// 分裂
        if (!p) x = y = 0;
        else {
            pushdown(p);
            if (k > sz[ls(p)]) x = p, split(rs(p), k - sz[ls(p)] - 1, rs(x), y), pushup(x);
            else y = p, split(ls(p), k, x, ls(y)), pushup(y);
        }
    }
    }
}tr;
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 500500
using namespace std;

int n, p[N], a[N], mi[N];
int stk[N], top;

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);

    p[n + 1] = n + 1, p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i - 1] != i - 1 && p[i] != i && p[i + 1] != i + 1)
            return puts("No"), 0;
        a[i] = i == p[i];
    }

    printf("here\n");    
    for (int i = 1, j; i <= n; i = j + 1) {
        for (j = i; j < n && a[j] != a[j + 1]; ++j);
        top = 0;
        for (int k = i; k <= j; ++k) {
            if (p[k] < i || j < p[k]){
                printf("dfjas\n");
                return puts("No"), 0;
            }
            if (!a[k]) stk[++top] = p[k];
        }
        mi[top] = stk[top];
        for (int k = top - 1; k >= 1; --k)
            mi[k] = min(mi[k + 1], stk[k]);
        int mx = stk[1];
        for (int k = 2; k < top; ++k) {
            mx = max(mx, stk[k]);
            if (mi[k] < stk[k] && stk[k] < mx){
                printf("fdajfadl\n");
                printf("k=%d stk[k]=%d\n",k,stk[k]);
                return puts("No"), 0;
            }
        }
    }

    return puts("Yes"), 0;
}

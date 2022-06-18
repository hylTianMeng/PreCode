#include <iostream>
#include<cstdio>
using namespace std;
int main(int argc, char** argv) {
 
    int n, a[30], m, s, i;
    while (scanf("%de%d", &n, &m), (n || m)) {
        while (m--)
            n *= 10;
        s = 0;
        while (n)
            a[s++] = n % 2, n /= 2;
        for (i = s - 2, n = 0; i >= 0; i--)
            n += a[i]*(1 << (i+1));
        printf("%d\n", n+1);
    }
    return 0;
}


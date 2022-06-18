#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int  MAXN = 1001, mod = 1e9 + 7;
char S[16], SS[] = {"ACGT"};
int a[16], f[MAXN][(1 << 15) + 2], trans[(1 << 15) + 2][5], N, Len, limit, ans[111];
int tmp[2][16];
int solve(int sta, int ch) {
    int ret = 0;
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < N; i++) tmp[0][i + 1] = tmp[0][i] + ((sta >> i) & 1 );    
    for(int i = 1; i <= N; i++) {
        int mx = 0;
        if(a[i] == ch) mx = tmp[0][i - 1] + 1;
        mx = max( max(mx, tmp[0][i]), tmp[1][i-1]);
        tmp[1][i] = mx;
    }
    for(int i = 0; i < N; i++) ret += (1 << i) * (tmp[1][i + 1] - tmp[1][i]);
    return ret;
}
int main() {
    #ifdef WIN32
    freopen("a.in", "r", stdin);
    #endif
    int QWQ;scanf("%d", &QWQ);
    //输入
    while(QWQ--) { 
        memset(f, 0, sizeof(f));memset(ans, 0, sizeof(ans));
        //把数组全部清掉。
        scanf("%s", S + 1);
        N = strlen(S + 1); limit = (1 << N) - 1;    
        //这里的意思是我们第二维好像只需要压 limit 位，
        for(int i = 1; i <= N; i++)
            for(int j = 0; j < 4; j++)
                if(S[i] == SS[j]){a[i] = j + 1;break;}
        scanf("%d", &Len);
        f[0][0] = 1;
        for(int sta = 0; sta <= limit; sta++)
            for(int j = 1; j <= 4; j++)
                trans[sta][j] = solve(sta, j);    
        for(int i = 1; i <= Len; i++)
            for(int sta = 0; sta <= limit; sta++)
                for(int k = 1; k <= 4; k++)
                    f[i][ trans[sta][k] ] = (f[i][ trans[sta][k] ] + f[i - 1][sta]) % mod; 
        for(int sta = 0; sta <= limit; sta++)
            ans[__builtin_popcount(sta)] = (ans[__builtin_popcount(sta)] + f[Len][sta]) % mod;
            //这个函数是算出sta中1的个数 
        for(int i = 0; i <= N; i++)
            printf("%d\n", ans[i] % mod);
    }
    return 0;
}
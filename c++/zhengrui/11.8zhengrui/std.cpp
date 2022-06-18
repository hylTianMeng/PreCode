#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#define int unsigned long long 
using namespace std;
const int N = 2e4 + 9;
const int M = 2e4 + 9;
const int mod = 998244353;
int n,m;
int ans;
char s[N];
int A[N] , B[N];//记录每一个点 X , Y 在 64 轮的状态
int read()
{
 int s = 0, f = 0;
 char ch = getchar();
 while (!isdigit(ch)) f |= ch == '-', ch = getchar();
 while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
 return f ? -s : s;
}
signed main() 
{
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    n = read(); m = read();
    for(int i = 1; i <= m; i ++)
    {
        scanf("%s" , s + 1); 
  int T = (1ull << (i - 1)); 
        for(int j = 1 ; j <= n; j ++)
        {
            if(s[j] == '0') continue;
            if(s[j] == '1') A[j] |= T;
            if(s[j] == '2') B[j] |= T;
            if(s[j] == '3') A[j] |= T, B[j] |= T;
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++)
        {
            int Fir = A[i] & B[j];
            int Sec = B[i] & A[j];//记录两种情况
            int Thr = Fir & Sec;//多出来的情况 
            int cnt = __builtin_popcountll(Fir) + 
                      __builtin_popcountll(Sec) - 
                      __builtin_popcountll(Thr);
            ans += (cnt & 1);
        }
    printf("%lld\n" , ans);
    return 0;
}
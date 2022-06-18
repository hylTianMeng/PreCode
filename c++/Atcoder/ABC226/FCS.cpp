#include <stdio.h>
 
#define  MYDATA long long
const MYDATA MOD = 1000000007;
#define MAXNUM 100005            //最高次数  
 
//递归法求解整数划分
unsigned long GetPartitionCount(int n, int max)
{
    if (n == 1 || max == 1)return 1;
    if (n < max)return (GetPartitionCount(n, n)) % MOD;
    if (n == max)return (1 + GetPartitionCount(n, n - 1)) % MOD;
    else return (GetPartitionCount(n - max, max) + GetPartitionCount(n, max - 1)) % MOD;
}
 
 
int main(int argc, char **argv)
{
    int n;
    int m;
    unsigned long count;
    while (1)
    {
        scanf("%d", &n);
        if (n <= 0)
            return 0;
        m = n;
        count = GetPartitionCount(n, m);
        printf("%ld\n", count);
    }
    return 0;
}
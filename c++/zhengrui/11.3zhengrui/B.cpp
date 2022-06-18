#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

const int N = 20;
const int M = 400;
const int mod = 998244353;
struct node{
    int u;
    int v;
}e[M<<1];
int n,m,ans;
int f[N],siz[N];
int Cun[N],top;
bool vis[N];
bool vis2[N];
int read()
{
	int s = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}
int find(int x)
{
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);    
}
void calc(int s)
{
    memset(f , 0 , sizeof(f));
    memset(vis, false, sizeof(vis));
    memset(vis2, false, sizeof(vis));
    memset(Cun , 0 , sizeof(Cun));
    top = 0;
    for(int i = 1; i <= n; i ++)
        f[i] = i;
    for(int i = 1; i <= n; i ++)
        siz[i] = 1;
    for(int i = 1; i <= m; i ++)
    {
        if(!(s & (1 << (i - 1))))
            continue;
        int u = e[i].u;
        int v = e[i].v;
        vis[u] = true; vis[v] = true;
        int fu = find(u);
        int fv = find(v); 
        if(fu == fv) continue;
        f[fu] = fv;
        siz[fv] += siz[fu];
    }
    for(int i = 1; i <= n; i ++)
    {
        if(!vis[i]) continue;
        int fa = find(i);
        if(!vis2[fa])
        {
            Cun[++ top] = siz[fa];
            vis2[fa] = true;
        }
    }
    int res = n - __builtin_popcount(s);
    if(top - 1 <= res)
    {
        int val = 1;
        for(int i = 1; i <= top; i ++)
            val = val * Cun[i] % mod;
        ans = (ans + val) % mod;
    }
    else return;
}
signed main() 
{
    n = read();
    m = read();
    for(int i = 1; i <= m ; i ++)
    {
        int u = read();
        int v = read();
        e[i].u = u;
        e[i].v = v;    
    }
    for(int s = 0 ; s < (1 << m) ; s ++)
        calc(s);
    printf("%lld\n", ans);
    return 0;
}
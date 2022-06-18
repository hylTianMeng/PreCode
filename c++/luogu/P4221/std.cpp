#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
void fwt(ll *a, int len, int opt){//板子
	for(int i = 2; i <= len; i <<= 1)
		for(int p = i >> 1, j = 0; j + i <= len; j += i)
			for(int k = j; k < j + p; k ++)
				a[p + k] =(a[p + k] + opt * a[k] + mod) % mod;
}
ll qpow(ll x, int y){
	ll ret = 1;
	for(;y; y >>= 1, x = x * x % mod) if(y & 1) ret = ret * x % mod;
	return ret;
}
int fa[25];
int get(int x){
	return fa[x] == x? x:(fa[x] = get(fa[x]));
}
void merge(int x , int y){
	x = get(x), y = get(y);
	fa[x] = y;
}
int n, m, q, a[25][25], w[25], he[1 << 23], ok[1 << 23], du[25], U[1000005], V[1000005], bitcount[1 << 23];
ll f[23][1 << 22], g[23][1 << 22], inv[1 << 22];
int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	int len = 1 << n;
	for(int i = 1; i <= m; i ++) scanf("%d%d", &U[i], &V[i]);
	for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	for(int S = 0; S < len; S ++){
		
		int bb = 0;
		for(int i = 1; i <= n; i ++){
			if((1 << (i - 1)) & S) he[S] += w[i], bb ++;
			du[i] = 0, fa[i] = i;
		}
		bitcount[S] = bb;//bitcount(S)表示S中1的个数
		
		for(int i = 1; i <= m; i ++){
			if(((1 << (U[i] - 1)) & S) && ((1 << (V[i] - 1)) & S)){
				if(get(U[i]) != get(V[i])) merge(U[i], V[i]), bb --;
				du[U[i]] ++;
				du[V[i]] ++;
			}
		}
		
		if(bb != 1){
            if(S==21) printf("h1ere\n");
            ok[S] = 1;
        }
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			cnt += (du[i] & 1);if(S==21) printf("d[%d]=%d\n",i,du[i]);
            
        }
		if(cnt){
            ok[S] = 1;
            if(S==21) printf("here1\n");
        }
		
		if(ok[S]) g[bitcount[S]][S] = qpow(he[S], q);//g是用来转移的，表示S划分成一组的满意度（分子）
		inv[S] = qpow(qpow(he[S], mod - 2), q);//分母 —— 逆元
	}
    for(int i=0;i<=len-1;i++){
        printf("i=%d vis=%d sum=%d\n",i,ok[i],qpow(he[i],q));
    }
	for(int i = 0; i <= n; i ++) fwt(g[i], 1 << n, 1);
	f[0][0] = 1; fwt(f[0], 1 << n, 1);//FWT
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= i - 1; j ++)
			for(int k = 0; k < len; k ++)
				f[i][k] += f[j][k] * g[i - j][k] % mod, f[i][k] %= mod;//卷起来
		fwt(f[i], 1 << n, -1);//IFWT
		
		for(int j = 0; j < len; j ++) f[i][j] = bitcount[j] == i? f[i][j] * inv[j] % mod:0;//求满意度
		if(i != n) fwt(f[i], 1 << n, 1);
	}
	printf("%lld", f[n][len - 1]);
	return 0;
}

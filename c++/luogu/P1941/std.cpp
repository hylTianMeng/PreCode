#include<bits/stdc++.h>
#include<ctime>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1; char c = getchar();
    while(!isdigit(c)){if(c == '-') fl = -1; c = getchar();}
    while(isdigit(c)){res = (res << 3) + (res << 1) + c - '0'; c = getchar();}
    return res * fl;
}
const int maxn = 10010, maxm = 1010;
int n, m, k, l[maxn], r[maxn], f[maxn][maxm], x[maxn], y[maxn], p, ans, fn, pss, ps[maxn];
void Min(int &A, int B){
	if(B < A) A = B;
} 
int main(){
	freopen("P1941_4.in", "r", stdin);
	
	n = rd(), m = rd(), k = rd();
	for(int i(0); i < n; ++i) x[i] = rd(), y[i] = rd();
	for(int i(0); i <= n; ++i) l[i] = 1, r[i] = m;
	l[0] = 0;
	for(int i(1); i <= k; ++i){
		p = rd(), l[p] = rd() + 1, r[p] = rd() - 1;
		ps[p]++;
	}
	memset(f, 0x3f, sizeof(f));
	for(int i(1); i <= m; ++i) f[0][i] = 0;
	for(int i(0); i < n; ++i){
		fn = inf;
		for(int j(l[i]); j <= r[i]; ++j){
			
			Min(f[i][j], f[i][j - x[i - 1]] + 1);
			
			fn = min(fn, f[i][j]);
			if((j - y[i] >= l[i + 1]) && (j - y[i] <= r[i + 1])){
				Min(f[i + 1][j - y[i]], f[i][j]);
			}
			int k = max((l[i + 1] - j) / x[i], 1);
			if(j + x[i] * k < l[i + 1]) k++;
			int endpos = (r[i + 1] - j) / x[i] + 1;
			
			endpos = k; 
			for(; k <= endpos; k++){
				if(j + x[i] * k >= l[i + 1] && j + x[i] * k <= r[i + 1])
					Min(f[i + 1][min(j + x[i] * k, m)], f[i][j] + k);
			}
			if(!ps[i + 1] && j + x[i] * k >= m) Min(f[i + 1][m], f[i][j] + k);
			k--;
			if(!ps[i + 1] && j + x[i] * k >= m) Min(f[i + 1][m], f[i][j] + k);
		}
		if(fn ^ inf) pss += ps[i];
		else break;
	}
	ans = inf;
	for(int i(max(1,l[n])); i <= r[n]; ++i) Min(ans, f[n][i]);
	if(ans != inf) printf("1\n%d\n", ans);
	else printf("0\n%d\n", pss);
	return 0;
}

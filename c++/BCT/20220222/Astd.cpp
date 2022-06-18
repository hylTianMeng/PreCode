#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1; char c = getchar();
    while(!isdigit(c)){if(c == '-') fl = -1; c = getchar();}
    while(isdigit(c)){res = (res << 3) + (res << 1) + c - '0'; c = getchar();}
    return res * fl;
}
const int maxn = 10000010;
int n, k, a[11];
ll MOD, Ans, Inv, Fac2, Fac3, cnt, val[maxn], valsum, Invi[maxn], f[6][maxn];
ll ksm(ll a, ll p){
	ll res(1);
	for(; p; p >>= 1){
//		printf("p=%lld a=%lld res=%lld\n", p, a, res);
		if(p & 1) (res *= a) %= MOD;
		(a *= a) %= MOD; 
	}
	return res;
}
ll SumF(int num){
	return 1ll * num * (num + 1) * (num * 2 + 1) / 6;
}
ll Sum(int num){
	return 1ll * (1 + num) * num / 2;
}
int main(){
	n = rd(); k = rd(); MOD = rd();
	Inv = 1; Invi[1] = 1;
	for(int i(2); i <= n; ++i) {
		(Inv *= i) %= MOD;
		Invi[i] = ksm(i, MOD - 2);
	}
	Inv = ksm(Inv, MOD - 2);
//	printf("inv = %lld\n", Inv);
	if(n <= 10){
		for(int i(1); i <= n; ++i) a[i] = i;
		do{
			cnt = 0; 
			for(int i(2); i < n; ++i){
				if(a[i] < a[i - 1] && a[i] < a[i + 1]) cnt++;
			}
			
			(Ans += ksm(cnt, k)) %= MOD;
		}while(next_permutation(a + 1, a + 1 + n));
		(Ans *= Inv) %= MOD;
		printf("%lld\n", Ans);
		return 0;
	}
	return 0;
}
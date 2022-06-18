#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;
const int N = 2e5 + 9;
int prime[N], p[N], cnt, mp[N], ans[N];

void Init()
{ //素数筛
	int len = sqrt(1e5);
	for (int i = 2; i <= len; i++)
	{
		if (!prime[i])
		{
			p[++cnt] = i;
			mp[i] = cnt;
			for (ll j = 2 * i; j <= len; j += i)
				prime[j] = 1;
		}
	}
}

ll quick_pow(ll a, ll b)
{ //快速幂
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	int n;
	Init();
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int pre;
		cin >> pre;
		for (int j = 1; j <= cnt && pre >= p[j]; j++)
		{
			int cur = 0;
			if (pre % p[j] == 0)
			{
				while (pre % p[j] == 0)
				{
					++cur;
					pre /= p[j];
				}
			}
			ans[j] = max(ans[j], cur);
		}
		if (pre > 1)
		{
			int j = 0;
			if (!mp[pre])
			{
				p[++cnt] = pre;
				mp[pre] = cnt;
				j = cnt;
			}
			else
				j = mp[pre];
			ans[j] = max(1, ans[j]);
		}
	}
	ll res = 1;
	for (int i = 1; i <= cnt; i++)
	{
		res *= quick_pow(p[i], ans[i]);
		res %= mod;
	}
	cout << res << endl;
	return 0;
}


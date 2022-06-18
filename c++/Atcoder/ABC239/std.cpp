#include <iostream>
#include <unordered_map>
using namespace std;
const int mod=1000000007;

inline int ksm(int a,int b,int mod){int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;} return res;}

int inv;

int solve(int N, int x) {
    if(x==0) return 0;
  static unordered_map<int, int> memo;
  if (memo.count(x)) return memo[x];
  int res = 0;
  for (int R = x, L, q; R; R = L) {
    q = x / R, L = x / (q + 1);
    if(x==39239) printf("%d %d %d\n",x,L+1,R);
    if (q != x) (res += 1ll*solve(N, q) * (min(N, R) - min(N, L))%mod)%=mod;
  }
    // for(int i=2,j;i<=x;i=j+1){
    //     j=x/(x/i);
    //     (res += 1ll*solve(N, x/i) * (min(N, i) - min(N, j))%mod)%=mod;
    // }
    // for(int i=2;i<=x+2;i++) (res += 1ll*solve(N, x/i))%=mod;
  return memo[x] = 1ll* ((N + res)%mod) *inv%mod;
}

int main() {
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
  int N, M;
  cin >> N >> M;
   inv=ksm(N-1,mod-2,mod);
  cout << (solve(N, M)%mod+mod)%mod << "\n";
}


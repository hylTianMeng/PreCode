#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

vector<int> v[N];
int jie[N],n;

inline int dfs(int k,int fa){
    int ans=1;
    if(k==1){
        ans=1ll*ans*jie[(int)v[k].size()]%mod;
    }
    else ans=1ll*ans*jie[(int)v[k].size()-1]%mod;
    bool op=0;
    for(int to:v[k]){
        if(to==fa) continue;
        op=1;
        ans=1ll*ans*dfs(to,k)%mod;
    }
    if(fa!=0&&op){ans=1ll*ans*2%mod;}
    return 1ll*ans%mod;
}

signed main(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);v[from].push_back(to);v[to].push_back(from);
    }
    jie[0]=1;for(int i=1;i<=n;i++) jie[i]=1ll*jie[i-1]*i%mod;
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=1ll*ans*jie[v[i].size()]%mod;
    }
    printf("%d\n",1ll*n*ans%mod);
    return 0;
}
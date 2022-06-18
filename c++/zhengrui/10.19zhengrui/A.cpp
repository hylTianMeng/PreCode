#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,q[N],jie[N],inv[N],invjie[N],ans;
set<int> S;

inline void PreWork(int n){
    jie[0]=jie[1]=1;invjie[0]=invjie[1]=1;inv[1]=1;
    for(int i=2;i<=n;i++){
        jie[i]=1ll*jie[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        invjie[i]=1ll*invjie[i-1]*inv[i]%mod;
    }
}

inline bool LessThan(int a,int b){return a<b;}

inline void Delete(int k){
    ans=1ll*ans*(n-k)%mod;
    auto it=S.lower_bound(k);
    auto Pre=*(--it);
    it++;it++;auto Next=*it;
    ans=1ll*ans*jie[k-Pre-1]%mod;
    ans=1ll*ans*jie[Next-k-1]%mod;
    ans=1ll*ans*invjie[Next-Pre-1]%mod;
    S.erase(k);
}

inline void Add(int k){
    ans=1ll*ans*inv[n-k]%mod;
    auto it=S.lower_bound(k);
    auto Next=*(it);auto Pre=*(--it);
    ans=1ll*ans*invjie[k-Pre-1]%mod;
    ans=1ll*ans*invjie[Next-k-1]%mod;
    ans=1ll*ans*jie[Next-Pre-1]%mod;
    S.insert(k);
}

inline void Change(int k,int val){
    bool l=LessThan(q[k-1],q[k]);
    bool r=LessThan(q[k],q[k+1]);
    bool nowl=LessThan(q[k-1],val);
    bool nowr=LessThan(val,q[k+1]);
    if(l!=nowl){
        if(l) Delete(k-1);
        else Add(k-1);
    }
    if(r!=nowr){
        if(r) Delete(k);
        else Add(k);
    }
    q[k]=val;
    //注意相邻
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork(300000);
    read(n);read(m);
    S.insert(0);S.insert(n);
    ans=jie[n-1];int last=0;
    for(int i=1;i<=n;i++){
        read(q[i]);
        if(q[i-1]<q[i]&&i>1){
            S.insert(i-1);
            ans=1ll*ans*inv[n-(i-1)]%mod*invjie[i-1-last-1]%mod;
            last=i-1;
        }
    }
    ans=1ll*ans*invjie[n-last-1]%mod;
    printf("%d\n",ans);
    q[0]=0;q[n+1]=INF;
    for(int i=1;i<=m;i++){
        int a,b;read(a);read(b);
        int qa=q[a],qb=q[b];
        Change(a,qb);Change(b,qa);
        printf("%d\n",ans);
    }
    return 0;
}
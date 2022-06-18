#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 21
#define M 60000
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N][M],tt,a,b,Pow[N];
int t,w[N];
vector<int> v;
bool vis[M];

inline void dfs(int k,int sum){
    if(k==-1){vis[sum]=1;return;}
    if(k&1){
        dfs(k-1,sum*3+2);dfs(k-1,sum*3);
    }
    else{
        dfs(k-1,sum*3+1);dfs(k-1,sum*3);
    }
}

inline int Solve(int p,int S,int lim,int pre){
    // printf("p=%lld S=%lld lim=%lld pre=%lld\n",p,S,lim,pre);
    if(p==0){
        if(vis[S]) return 1;return 0;
    }
    if(!lim&&!pre&&f[p][S]!=-1) return f[p][S];
    int up=(lim==1)?w[p]:9,ans=0;
    for(int i=1;i<=up;i++){
        int now=(S/Pow[i])%3;
        int T=S-now*Pow[i];
        if(now==0) now=1;
        else now=3-now;
        T+=now*Pow[i];
        ans+=Solve(p-1,T,lim&&(i==up),0);
    }
    if(pre) ans+=Solve(p-1,S,0,1);
    else{
        int now=S%3;int T=S-now;
        if(now==0) now=1;else now=3-now;
        T+=now;
        ans+=Solve(p-1,T,lim&&(up==0),0);
    }
    if(!lim&&!pre) f[p][S]=ans;
    return ans;
}

inline int Work(int k){
    t=0;
    while(k){
        w[++t]=k%10;k/=10;
    }
    return Solve(t,0,1,1);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    dfs(9,0);read(tt);memset(f,-1,sizeof(f));
    Pow[0]=1;for(int i=1;i<=11;i++) Pow[i]=Pow[i-1]*3;
    while(tt--){
        read(a);read(b);
        printf("%lld\n",Work(b)-Work(a-1));
    }
    return 0;
}
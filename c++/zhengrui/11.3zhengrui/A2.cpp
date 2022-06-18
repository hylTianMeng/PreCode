#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 8200
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

int f[2][N][N],n;
typedef pair<int,int> P;
vector<P> States;
int a[N];
bool vis[N][N];

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    States.push_back(make_pair(a[1],a[1]));
    f[0][a[1]][a[1]]=1;vis[a[1]][a[1]]=1;
}

inline void Solve(){
    int o=0;
    for(int i=2;i<=n;i++){
        // printf("i=%lld\n",i);
        o^=1;
        for(P now:States) f[o][now.first][now.second]=f[o^1][now.first][now.second];
        for(int j=0;j<States.size();j++){
            P now=States[j];
            // printf("now= %lld %lld\n",now.first,now.second);
            int val1=now.first^a[i],val2=now.second&a[i];
            f[o][val1][val2]+=f[o^1][now.first][now.second];
            // printf("trans:%lld\n",f[o^1][now.first][now.second]);
            // printf("f[%lld][%lld]=%lld\n",val1,val2,f[o][val1][val2]);
            if(!vis[val1][val2]){
                vis[val1][val2]=1;
                States.push_back(make_pair(val1,val2));
            }
        }
        f[o][a[i]][a[i]]++;
        if(!vis[a[i]][a[i]]){
            vis[a[i]][a[i]]=1;States.push_back(make_pair(a[i],a[i]));
        }
    }
    ll ans=0;
    for(int i=0;i<=(1<<13)-1;i++){
        ans+=1ll*f[o][i][i];
    }
    printf("%lld\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();
    return 0;
}
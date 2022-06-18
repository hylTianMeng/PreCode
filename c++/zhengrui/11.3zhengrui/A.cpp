#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
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

ll f[N][N],n;
int fir[N*N],sec[N*N];
int a[N],tail;
bool vis[N][N];
pair<pair<int,int>,ll> vem[N*N];

inline void Add(int x,int y){
    ++tail;fir[tail]=x;sec[tail]=y;
}

inline void Init(){
    scanf("%lld",&n);
    for(int i(1);i<=n;++i) scanf("%d",&a[i]);
    Add(a[1],a[1]);
    f[a[1]][a[1]]=1;vis[a[1]][a[1]]=1;
}

inline void Solve(){
    int o(0);
    for(int i(2);i<=n;++i){
        // printf("tail=%d\n",tail);
        int vemtop(0);
        // for(int j(1);j<=tail;++j) f[fir[j]][sec[j]][o]=f[fir[j]][sec[j]][o^1];
        for(int j(1);j<=tail;++j){
            int val1(fir[j]^a[i]),val2(sec[j]&a[i]);
            // f[val1][val2][o]+=f[fir[j]][sec[j]][o^1];
            vem[++vemtop]=make_pair(make_pair(val1,val2),f[fir[j]][sec[j]]);
            if(!vis[val1][val2]){
                vis[val1][val2]=1;
                Add(val1,val2);
            }
        }
        for(int j(1);j<=vemtop;j++){
            f[vem[j].first.first][vem[j].first.second]+=vem[j].second;
        }
        f[a[i]][a[i]]++;
        if(!vis[a[i]][a[i]]){
            vis[a[i]][a[i]]=1;Add(a[i],a[i]);
        }
    }
    ll ans(0);
    for(int i(0);i<=(1<<13)-1;++i){
        ans+=f[i][i];
    }
    printf("%lld\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=r;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 110
#define M number
using namespace std;

const ld INF=1e18;
const dd eps=1e-7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,H,d[N],D[N];
vector<int> v[N];
ld f[N][N];

inline void Clear(){
    rep(i,1,n)rep(j,1,H) f[i][j]=INF;
}

inline void PreWork(){
    read(n);read(m);read(H);
    rep(i,1,m){
        int from,to;read(from);read(to);
        v[from].push_back(to);
    }
    rep(i,1,n)read(d[i]);
}

inline bool Check(ld mid){
    Clear();
    rep(i,1,H) f[n][i]=0;
    dec(i,1,n-1){
        if((int)v[i].size()==0){
            rep(j,1,H) f[i][j]=mid+H-j;
            // rep(j,1,H) printf("f[%d][%d]=%Lf\n",i,j,f[i][j]);
            continue;
        }
        rep(j,1,H){
            ld sum=0;
            for(int to:v[i]){
                ld now;
                if(j-d[to]<=0){now=INF;}
                else now=f[to][j-d[to]];
                sum+=now/(int)v[i].size();
            }
            if(i!=1) f[i][j]=min(mid+H-j,sum+1);
            else f[i][j]=sum+1;
        }
        // rep(j,1,H) printf("f[%d][%d]=%Lf\n",i,j,f[i][j]);
    }
    return f[1][H]>=mid;
}

inline void Binary(){
    // printf("%d\n",Check(7));
    ld l=0,r=1e6+3;
    while(r-l>eps){
        ld mid=(l+r)/2;
        // printf("mid=%Lf\n",mid);
        if(Check(mid)) l=mid;
        else r=mid;
    }
    if(l>1e6){puts("-1");}
    else printf("%0.7Lf\n",l);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();
    Binary();
    return 0;
}
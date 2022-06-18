#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int base=1000000;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int sum[N<<1],n,m;
ll ans;
typedef pair<int,int> P;
P a[N];
bool vis[N<<1];

//id=0 是上面，id=1 是下面。
inline P GetPoint(int x,int y,int id){
    int R=x-y;
    if(R<0){
        if(id==0) return make_pair(1,1-R);
        else if(id==1) return make_pair(n+R,n);
    }
    else{
        if(id==0) return make_pair(R+1,1);
        else if(id==1) return make_pair(n,n-R);
    }
    assert(0);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        // printf("i=%lld\n",i);
        int x,y;read(x);read(y);
        if(!sum[x+y]){
            sum[x+y]=1;
            if(x+y>n+1) ans+=(2*(n+1)-x-y-1);
            else ans+=x+y-1;
        }
        a[i]=make_pair(x,y);
        // printf("ans=%lld\n",ans);
    }
    // printf("ans=%lld\n",ans);
    for(int i=2;i<=(n<<1);i++){
        sum[i]+=sum[i-2];
    }
    for(int i=1;i<=m;i++){
        if(vis[a[i].first-a[i].second+base]) continue;
        vis[a[i].first-a[i].second+base]=1;
        P up=GetPoint(a[i].first,a[i].second,0);
        P down=GetPoint(a[i].first,a[i].second,1);
        int l=up.first+up.second,r=down.first+down.second;
        ans-=sum[r]-sum[l-2];
        ans+=down.first-up.first+1;
    }
    printf("%lld",1ll*n*n-ans);
    return 0;
}
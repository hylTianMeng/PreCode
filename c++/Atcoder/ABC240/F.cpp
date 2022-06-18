#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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

int t,n,m,b[N],suma[N],sumb[N],sums[N];

typedef pair<int,int> P;
P a[N];
vector<int> v;

inline void Init(){
    read(n);read(m);
    int now1=1;
    for(int i=1;i<=n;i++){
        read(a[i].first);read(a[i].second);
        int l=now1,r=now1+a[i].second-1;
        b[i]=a[i].first*(l+r)*(r-l+1)/2;now1+=a[i].second;
    }
    int sum=a[1].second*a[1].first;
    int now=a[1].second+1;
    if(sum==0) v.push_back(a[1].second);
    for(int i=2;i<=n;i++){
        int nowsum=sum+a[i].second*a[i].first;
        if(sum>0&&nowsum<=0){
            int Up=sum/abs(a[i].first);
            v.push_back(now+Up-1);
        }
        sum=nowsum;
        now+=a[i].second;
    }
    for(int i=1;i<=n;i++){
        suma[i]=suma[i-1]+a[i].second*a[i].first;
        sumb[i]=sumb[i-1]+b[i];
        sums[i]=sums[i-1]+a[i].second;
    }
}

inline void Solve(){
    int ans=a[1].first;
    for(int w:v){
        int nowans=0;
        int nowid=lower_bound(sums+1,sums+n+1,w);
        nowans=w*suma[nowid-1]+suma[nowid-1];
        nowans-=sumb[nowid-1];
        int l=sums[nowid-1]+1;
        int r=w;
        nowans+=w*a[nowid].first*(r-l+1)+a[nowid].first*(r-l+1);
        nowans-=a[nowid].first*(l+r)*(r-l+1)/2;
        ans=max(ans,nowans);
    }
    printf("%lld\n",ans);
}

inline void Clear(){
    v.clear();
    for(int i=0;i<=n;i++) b[i]=0;
    for(int i=0;i<=n;i++) suma[i]=0;
    for(int i=0;i<=n;i++) sumb[i]=0;
}

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();
        Solve();Clear();
    }
}
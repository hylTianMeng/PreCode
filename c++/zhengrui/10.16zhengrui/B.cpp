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

map<int,int> Map;

struct Node{
    int l,r,x;
    inline Node(){}
    inline Node(int l,int r,int x) : l(l),r(r),x(x) {}
    inline bool operator < (const Node &b)const{return x>b.x;}
}a[N];
int tail;

int T,n,m;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        int l,r;read(l);read(r);
        if(r==l+1) continue;
        Map[l+1]++;Map[r]--;
    }
}

inline int Solve(){
    int now=0,last=-1;
    for(auto it=Map.begin();it!=Map.end();it++){
        auto p=(*it);
        if(now==0){
            now=p.second;last=p.first;
            continue;
        }
        a[++tail]=Node(last,p.first-1,now);
        last=p.first;now+=p.second;
    }
    sort(a+1,a+tail+1);
    int ans=0;
    for(int i=1;i<=tail;i++){
        int len=a[i].r-a[i].l+1;
        if(len>m){
            ans+=m*a[i].x;
            break;
        }
        else{
            ans+=len*a[i].x;
            m-=len;
        }
    }
    return ans+n;
}

inline void Clear(){
    Map.clear();tail=0;
}

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(T);
    for(int i=1;i<=T;i++){
        Init();printf("Case #%lld: %lld\n",i,Solve());
        Clear();
    }
    return 0;
}
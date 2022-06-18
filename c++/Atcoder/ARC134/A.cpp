#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 100010
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

typedef pair<int,int> P;
set<P> S;

int n,a[N],L,W,ans;

inline void Insert(int x){
    // printf("enter\n");
    int r=x+W;
    while(1){
        // printf("here\n");
        auto it=S.lower_bound(make_pair(x,r));
        if(it==S.end()) break;
        if((*it).first<=r){
            r=max(r,(*it).second);
            S.erase(it);
        }
        else break;
    }
    auto it=S.lower_bound(make_pair(x,r));
    if(it!=S.begin()){
        it--;
        if((*it).second>=x){
            x=(*it).first;
            S.erase(it);
        }
    }
    S.insert(make_pair(x,r));
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(L);read(W);
    for(int i=1;i<=n;i++){
        read(a[i]);
        Insert(a[i]);
    }
    int maxr=0;
    for(auto it=S.begin();it!=S.end();it++){
        // printf("%d %d\n",(*it).first,(*it).second);
        if(it==S.begin()){
            ans+=((*it).first+W-1)/W;
            maxr=(*it).second;
            continue;
        }
        auto itt=it;itt--;
        int len=(*it).first-(*itt).second;
        maxr=max(maxr,(*it).second);
        ans+=(len+W-1)/W;
    }
    // printf("end\n");
    ans+=(L-maxr+W-1)/W;
    printf("%lld\n",ans);
    return 0;
}
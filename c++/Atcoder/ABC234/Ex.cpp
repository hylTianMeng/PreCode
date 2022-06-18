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
const int len=2000000000;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,k,b[N];
typedef pair<int,int> P;
P a[N];
map<int,vector<int> > Map;
const int fv[]={0,-len-1,-len,-len+1,-1,0,1,len-1,len,len+1};
vector<P> Ans;

inline int sq(int x){return x*x;}

inline bool Check(int i,int j){
    return sq(a[i].first-a[j].first)+sq(a[i].second-a[j].second)<=sq(k);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(k);
    for(int i=1;i<=n;i++){
        read(a[i].first);read(a[i].second);
        int ai=a[i].first/k,bi=a[i].second/k;
        int val=ai*len+bi;
        Map[val].push_back(i);b[i]=val;
        // printf("i:%lld val:%lld\n",i,val);
    }
    for(int i=1;i<=n;i++){
        int now=b[i];
        for(int j=1;j<=9;j++){
            int x=now+fv[j];
            for(int id:Map[x]){
                if(id<=i) continue;
                if(Check(i,id)){Ans.push_back(make_pair(i,id));}
            }
        }
    }
    sort(Ans.begin(),Ans.end());
    printf("%lu\n",Ans.size());
    for(P p:Ans){
        printf("%lld %lld\n",p.first,p.second);
    }
    return 0;
}
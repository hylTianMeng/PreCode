#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=2147483647;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

map<int,int> Map;

int n,G,R,len[N],Time[N],A,q;

inline void Insert(int l,int r,int id){
    if(l==r) return;
    auto lit=Map.lower_bound(l),rit=Map.upper_bound(r);
    int Last=prev(rit,1)->second;
    Map.erase(lit,rit);Map[l]=id;Map[r]=Last;
}

inline int Find(int posi){
    posi%=A;
    auto it=Map.upper_bound(posi);
    int now=prev(it,1)->second;
    return now;
}

inline int Calc(int x,int y){
    if(y==n+1) return len[y]-x;
    return ((len[y]-x+A-1)/A)*A+Time[y];
}

inline void Init(){
    read(n);read(G);read(R);A=G+R;
    for(int i=1;i<=n+1;i++) read(len[i]);
    for(int i=2;i<=n+1;i++){
        len[i]+=len[i-1];
    }
    Map[0]=n+1;
    for(int i=n;i>=1;i--){
        int l=(G-len[i]%A+A)%A,r=A-len[i]%A;
        int posi=Find(r);
        Time[i]=Calc(len[i],posi);
        if(l<r) Insert(l,r,i);
        else{Insert(0,l,i);Insert(r,A,i);}
    }
}

int ans;

inline void Solve(){
    read(q);
    for(int i=1;i<=q;i++){
        int x;read(x);
        x^=(ans%mod);
        int posi=Find(x);
        printf("%lld\n",(ans=Calc(-x,posi)));
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    // for(int i=n;i>=1;i--){
    //     printf("%lld ",Time[i]);
    // }
    Solve();
}
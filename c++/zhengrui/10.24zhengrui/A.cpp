#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct Point{
    int x,y,a,b,id;
    inline Point(){}
    inline Point(int x,int y) : x(x),y(y) {}
}p[N];

int n,ans[N],rk[N],b[N];

struct BIT{
    int p[N];
    inline int lowbit(int x){return x&(-x);}
    inline void PreAdd(int w,int x){
        for(int i=w;i<=n;i+=lowbit(i)) (p[i]+=x)%=mod;
    }
    inline void SufAdd(int w,int x){
        for(int i=w;i;i-=lowbit(i)) (p[i]+=x)%=mod;
    } 
    inline int AskPre(int w){
        int res=0;for(int i=w;i;i-=lowbit(i)) (res+=p[i])%=mod;return res;
    }
    inline int AskSuf(int w){
        int res=0;for(int i=w;i<=n;i+=lowbit(i)) (res+=p[i])%=mod;return res;
    }
    inline void Clear(){fill(p,p+n+1,0);}
}bit1,bit2,bit3;

namespace Cmp{
    inline bool cmp1(Point a,Point b){if(a.x!=b.x) return a.x<b.x;return a.y>b.y;}
    inline bool cmp2(Point a,Point b){if(a.y!=b.y) return a.y>b.y;return a.x>b.x;}
    inline bool cmp3(Point a,Point b){if(a.y!=b.y) return a.y<b.y;return a.x<b.x;}
    inline bool cmp4(Point a,Point b){if(a.x!=b.x) return a.x>b.x;return a.y<b.y;}
}

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(p[i].x);read(p[i].y);
        p[i].a=(p[i].x+p[i].y)%mod;p[i].b=(p[i].x-p[i].y)%mod;p[i].id=i;
        b[i*2-1]=p[i].x;b[i]=p[i].y;
    }
    sort(b+1,b+2*n+1);
    int len=unique(b+1,b+2*n+1)-b-1;
    for(int i=1;i<=n;i++){
        int Rank;
        (Rank=lower_bound(b+1,b+len+1,p[i].x)-b);
        (Rank=lower_bound(b+1,b+len+1,p[i].y)-b);
    }
}

inline void Clear(){
    bit1.Clear();bit2.Clear();bit3.Clear();
}

inline void Print(){
    for(int i=1;i<=n;i++) printf("%d\n",(ans[i]%mod+mod)%mod);
    // puts("");
}


namespace Solve{
    inline void Solve1(){
        Clear();
        sort(p+1,p+n+1,Cmp::cmp1);
        for(int i=1;i<=n;i++){
            int id=p[i].id;
            (ans[id]+=1ll*bit1.AskPre(p[i].y)*p[i].a%mod*p[i].a%mod)%=mod;
            (ans[id]-=1ll*bit2.AskPre(p[i].y)*2%mod*p[i].a%mod)%=mod;
            (ans[id]+=bit3.AskPre(p[i].y))%=mod;
            bit1.PreAdd(p[i].y,1);bit2.PreAdd(p[i].y,p[i].a);
            bit3.PreAdd(p[i].y,1ll*p[i].a*p[i].a%mod);
        }
        // Print();
    }
    inline void Solve2(){
        Clear();
        sort(p+1,p+n+1,Cmp::cmp2);
        for(int i=1;i<=n;i++){
            int id=p[i].id;
            (ans[id]+=1ll*bit1.AskPre(p[i].x)*p[i].b%mod*p[i].b%mod)%=mod;
            (ans[id]-=1ll*bit2.AskPre(p[i].x)*2%mod*p[i].b%mod)%=mod;
            (ans[id]+=bit3.AskPre(p[i].x))%=mod;
            bit1.PreAdd(p[i].x,1);bit2.PreAdd(p[i].x,p[i].b);
            bit3.PreAdd(p[i].x,1ll*p[i].b*p[i].b%mod);
        }
        // Print();
    }
    inline void Solve3(){
        Clear();
        sort(p+1,p+n+1,Cmp::cmp3);
        for(int i=1;i<=n;i++){
            int id=p[i].id;
            (ans[id]+=1ll*bit1.AskSuf(p[i].x)*p[i].b%mod*p[i].b%mod)%=mod;
            (ans[id]-=1ll*bit2.AskSuf(p[i].x)*2%mod*p[i].b%mod)%=mod;
            (ans[id]+=bit3.AskSuf(p[i].x))%=mod;
            bit1.SufAdd(p[i].x,1);bit2.SufAdd(p[i].x,p[i].b);
            bit3.SufAdd(p[i].x,1ll*p[i].b*p[i].b%mod);
        }
        // Print();
    }
    inline void Solve4(){
        Clear();
        sort(p+1,p+n+1,Cmp::cmp4);
        for(int i=1;i<=n;i++){
            int id=p[i].id;
            (ans[id]+=1ll*bit1.AskSuf(p[i].y)*p[i].a%mod*p[i].a%mod)%=mod;
            (ans[id]-=1ll*bit2.AskSuf(p[i].y)*2%mod*p[i].a%mod)%=mod;
            (ans[id]+=bit3.AskSuf(p[i].y))%=mod;
            bit1.SufAdd(p[i].y,1);bit2.SufAdd(p[i].y,p[i].a);
            bit3.SufAdd(p[i].y,1ll*p[i].a*p[i].a%mod);
        }
        // Print();
    }
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();
    Solve::Solve1();Solve::Solve2();Solve::Solve3();Solve::Solve4();
    // return 0;
    Print();
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
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

struct Point{
    int x,y;
    inline Point(){}
    inline Point(int x,int y) : x(x),y(y) {}
    inline Point operator - (const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    inline bool operator < (const Point &b)const{
        return (x==b.x)?(y<b.y):(x<b.x);
    }
}a[N];

int n;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i].x);read(a[i].y);
    }
}

set<Point> S;
int Ans;

inline int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

inline void Solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            Point now=a[i]-a[j];
            int g=gcd(now.x,now.y);now.x/=abs(g);now.y/=abs(g);
            if(S.find(now)!=S.end()) continue;
            S.insert(now);Ans++;
        }
    }
    printf("%d\n",Ans);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();return 0;
}
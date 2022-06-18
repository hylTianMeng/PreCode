#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 2510
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

inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

struct Vector{
    int x,y,z;
    inline Vector(){}
    inline Vector(int x,int y,int z) : x(x),y(y),z(z) {}
    inline Vector operator ^ (const Vector &b)const{
        return Vector(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
    inline void Standardization(){
        int g=gcd(gcd(abs(x),abs(y)),abs(z));
        if(!g) return;
        if((*this)<Vector(0,0,0)){g*=-1;}
        x/=g;y/=g;z/=g;
    }
    inline bool operator < (const Vector &b)const{
        if(x!=b.x) return x<b.x;
        else if(y!=b.y) return y<b.y;
        return z<b.z;
    }
    inline bool operator == (const Vector &b)const{
        return x==b.x&&y==b.y&&z==b.z;
    }
}v[N];

vector<Vector> now;
int n,ans;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        int a,b,c;read(a);read(b);read(c);
        v[i]=Vector(a,b,c);
    }
}

inline void Solve(){
    ans=n*(n-1)*(n-2)/6;
    for(int i=1;i<=n;i++){
        now.clear();
        for(int j=i+1;j<=n;j++){
            Vector Now=v[i]^v[j];Now.Standardization();
            now.push_back(Now);
        }
        sort(now.begin(),now.end());
        for(int j=0,Last=0;j<now.size();Last=j){
            while(j<now.size()&&now[j]==now[Last]) j++;
            int len=j-Last;
            ans-=len*(len-1)/2;
            if(now[Last]==Vector(0,0,0)) ans-=len*(n-i-len);
        }
    }
}

inline void Print(){
    printf("%lld\n",ans);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    Solve();Print();
}
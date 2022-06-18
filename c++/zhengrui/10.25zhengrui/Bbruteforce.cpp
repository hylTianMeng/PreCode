#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

struct Vector{
    int x,y,z;
    inline Vector(){}
    inline Vector(int x,int y,int z) : x(x),y(y),z(z) {}
    inline void Print(){printf("%lld %lld %lld\n",x,y,z);}
}V[2501];

int n,num,ans;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        int a,b,c;read(a);read(b);read(c);
        V[i]=Vector(a,b,c);
    }
}

inline bool Check(Vector a,Vector b,Vector c){
    return c.z*(a.x*b.y-b.x*a.y)+c.y*(a.z*b.x-a.x*b.z)+c.x*(a.y*b.z-a.z*b.y);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(Check(V[i],V[j],V[k])){
                    ans++;
                }
            }
        }
    printf("%lld\n",ans);
    return 0;
}
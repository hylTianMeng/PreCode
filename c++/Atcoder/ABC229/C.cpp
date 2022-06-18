#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
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

struct Node{
    int x,y;
    inline bool operator < (const Node &b)const{return x>b.x;}
}a[N];

int n,m;
ll ans;

int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i].x);read(a[i].y);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(m>a[i].y){
            ans+=1ll*a[i].y*a[i].x;m-=a[i].y;
        }
        else{
            ans+=1ll*m*a[i].x;
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
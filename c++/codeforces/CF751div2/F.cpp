#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Node{
    int s,a;
    inline Node(){}
    inline Node(int s,int a) : s(s),a(a) {}
    inline bool operator < (const Node &b)const{
        if(Max(s,a)!=Max(b.s,b.a)) return Max(s,a)<Max(b.s,b.a);
        else if(s!=b.s) return s<b.s;
        return a<b.a;
    }
}a[N];

int n,d;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(d);
    for(int i=1;i<=n;i++){
        read(a[i].s);read(a[i].a);
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].s>=d){
            ans++;d=Max(d,a[i].a);
        }
    }
    printf("%d\n",ans);
    return 0;
}
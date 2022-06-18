#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long 
#define uint unsigned int
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

struct Operation{
    int a,b,op;
    //op=0 做加法 op=1 做异或
    inline Operation(){}
    inline Operation(int a,int b,int op) : a(a),b(b),op(op) {}
}o[N];
int tail;

inline void Add(int a,int b,int op){o[++tail]=Operation(a,b,op);}

int x;

inline int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;return a;
    }
    int g=exgcd(b,a%b,x,y);int tmp=x;x=y;y=tmp-a/b*y;return g;
}

inline int lowbit(int x){return x&(-x);}

inline void Solve(int a,int b){
    int w=log2(b),now=a;
    for(int i=1;i<=w;i++){
        Add(now,now,0);
        now<<=1;
    }
    int nowval=lowbit(b);
    for(int j=b-lowbit(b);j;j-=lowbit(j)){
        int low=lowbit(j);
        Add(nowval*a,low*a,0);
        nowval+=low;
    }
}

inline void Print(){
    printf("%lld\n",tail);
    for(int i=1;i<=tail;i++){
        if(o[i].op==0) printf("%lld + %lld\n",o[i].a,o[i].b);
        else if(o[i].op==1) printf("%lld ^ %lld\n",o[i].a,o[i].b);
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(x);int w=log2(x);
    int now=x;
    for(int i=1;i<=w;i++){
        Add(now,now,0);
        now<<=1;
        if((now&x)==(1ll<<w)) break;
    }
    Add(now,x,1);now^=x;
    int a,b;int g=exgcd(now,x,a,b);
    if(a<0){
        swap(a,b);swap(now,x);
    }
    if((a&1)==0){
        a+=x;b-=now;
    }
    // printf("a=%lld now=%lld a*now=%lld x=%lld b=%lld x*b=%lld\n",a,now,a*now,x,b,x*b);
    assert(a&1);assert(a*now+b*x==1);
    Solve(now,a);Solve(x,abs(b));
    Add(now*a,x*abs(b),1);assert(((now*a)^(x*abs(b)))==1);
    Print();
    return 0;
}
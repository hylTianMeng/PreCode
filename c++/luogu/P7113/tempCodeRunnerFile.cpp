#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define lll __int128
#define uint unsigned int
#define ull unsigned long long
#define N 500100
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

template<typename T> inline void write(T x){
    if(x<9) putchar(x+'0');
    else if(x>=10){write(x/10);putchar(x%10+'0');}
}

template<typename T> inline void writeln(T x){
    write(x);putchar(' ');
}

int n,m;

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N];
int head[N],tail;

lll gcd(lll a,lll b){return b==0?a:gcd(b,a%b);}

struct Frac{
    lll A,B;
    inline Frac(){A=B=0;}
    inline Frac(int A,int B) : A(A),B(B) {}
    inline Frac operator + (const Frac &b)const{
        Frac c;c.A=A*b.B+b.A*B;c.B=b.B*B;
        lll g=gcd(c.A,c.B);c.A/=g;c.B/=g;return c;
    }
    inline Frac operator / (const int &b)const{
        Frac c;c.A=A;c.B=B*b;
        lll g=gcd(c.A,c.B);c.A/=g;c.B/=g;return c;
    }
    inline void Print(){
        writeln(A);writeln(B);puts("");
    }
}f[N];

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int rd[N],cd[N],d[N];

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=m;i++) Add(n+1,i),rd[i]++,cd[n+1]++;
    for(int i=1;i<=n;i++){
        int d;read(d);for(int j=1;j<=d;j++){int x;read(x);Add(i,x);rd[x]++;cd[i]++;}
    }
    for(int i=1;i<=n;i++) d[i]=rd[i];
    f[n+1]=Frac(m,1);
}

queue<int> q;

inline void Solve(){
    q.push(n+1);
    while(q.size()){
        int top=q.front();q.pop();
        printf("top=%d\n",top);
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to;rd[to]--;
            if(!rd[to]) q.push(to);
            printf("cd[%d]=%d\n",top,cd[top]);
            f[to]=f[to]+(f[top]/cd[top]);
        }
    }
}

inline void Print(){
    for(int i=1;i<=n;i++) if(!d[i]) f[i].Print();
}

int main(){
    freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    // write(431278);
    Init();
    Solve();
    // Print();return 0;
}
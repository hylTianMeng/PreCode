#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 300100
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

ll n,m,T,len;
char s[N],t[N];
bool op;

inline ll lowbit(ll x){return x&(-x);}

inline ll Digit(ll x){
    int cnt=0;while(x){x-=lowbit(x);cnt++;}return cnt;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);read(T);
    scanf("%s %s",s+1,t+1);
    len=n+m;
    while(T--){
        ll x;read(x);
        int num=x/len,yushu=x%len;
        if(yushu) num++;
        else yushu=len;
        ll all=Digit(num-1);
        if(all&1) op=0;
        else op=1;
        if(op){
            if(yushu<=n) putchar(s[yushu]);
            else putchar(t[yushu-n]);
        }
        else{
            if(yushu<=m) putchar(t[yushu]);
            else putchar(s[yushu-m]);
        }
        puts("");
    }
    return 0;
}
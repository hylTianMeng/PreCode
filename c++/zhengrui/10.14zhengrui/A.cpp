#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 26
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

bitset<25> bit[N];

int n,m,f[1<<N],cnt[N*N+100];

inline int Lowbit(int x){return x&(-x);}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    // dd d1=clock();
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        from--;to--;
        bit[from][to]=1;bit[to][from]=1;
    }
    int maxx=(1<<n)-1;
    for(int s=1;s<=(1<<n)-1;s++){
        int now=Lowbit(s);
        int t=s-now;
        int w=log2(now);
        bitset<25> nowt(t);
        nowt&=bit[w];
        f[s]=f[t]+nowt.count();
        assert(f[s]<=m);
        cnt[f[s]]++;
    }
    cnt[f[0]]++;
    for(int i=0;i<=m;i++) printf("%d ",cnt[i]);puts("");
    // dd d2=clock();
    // printf("%lf\n",d2-d1);
    return 0;
}
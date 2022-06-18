#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 5010
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

int t,n,D,fa[N],now,d[N],a[N],at,b[N],bt,bh,lg[N],Dep[N];

inline void dfs(int k){
    if((k<<1)<=n) dfs(k<<1);
    else b[++bt]=k;
    if((k<<1|1)<=n) dfs(k<<1|1);
}

inline void Change(int k){
    int nowdep=Dep[fa[k]];
    int nowfa=a[nowdep+1];
    d[fa[k]]--;d[nowfa]++;
    if(d[fa[k]]==1){
        b[++bt]=fa[k];
    }
    fa[k]=nowfa;Dep[k]++;
    if(d[nowfa]==2){
        a[++at]=k;bh++;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    lg[0]=-1;for(int i=1;i<=5000;i++) lg[i]=lg[i>>1]+1;
    while(t--){
        read(n);read(D);
        bh=bt=0;at=0;now=0;
        Dep[1]=1;
        for(int i=1;i<=n;i++) d[i]=0;
        int up=(1+n-1)*(n-1)/2;
        if(D>up){puts("NO");continue;}
        for(int i=2;i<=n;i++){
            Dep[i]=Dep[i>>1]+1;
            fa[i]=i>>1;now+=lg[i];
            d[i]++;d[i>>1]++;
        }
        if(now>D){puts("NO");continue;}
        for(int i=1;i<=n;i<<=1) a[++at]=i;
        dfs(1);bh=2;
        for(int i=now+1;i<=D;i++){
            Change(b[bh]);
            // printf("b[%d]=%d\n",bh,b[bh]);
            // for(int i=2;i<=n;i++) printf("%d ",fa[i]);
            // puts("");
        }
        puts("YES");
        for(int i=2;i<=n;i++) printf("%d ",fa[i]);
        puts("");
    }
}
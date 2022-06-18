#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int posi[N],a[N],b[N],n,m,c[N<<1],tail,t,Pre[N],Suf[N];

struct BIT{
    int p[N<<1];
    inline int lowbit(int x){return x&(-x);}
    inline void PreAdd(int w,int x){
        for(int i=w;i<=tail;i+=lowbit(i)) p[i]+=x;
    }
    inline int PreAsk(int w){
        int res=0;for(int i=w;i>=1;i-=lowbit(i)) res+=p[i];return res;
    }
    inline void SufAdd(int w,int x){
        for(int i=w;i>=1;i-=lowbit(i)) p[i]+=x;
    }
    inline int AskSuf(int w){
        int res=0;for(int i=w;i<=tail;i+=lowbit(i)) res+=p[i];return res;
    }
    inline void Clear(int n){
        for(int i=1;i<=n;i++) p[i]=0;
    }
}bit;

inline void Init(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++) read(b[i]);
    for(int i=1;i<=n;i++) c[++tail]=a[i];
    for(int i=1;i<=m;i++) c[++tail]=b[i];
    sort(c+1,c+tail+1);int len=unique(c+1,c+tail+1)-c-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+len+1,a[i])-c;
    for(int i=1;i<=m;i++) b[i]=lower_bound(c+1,c+len+1,b[i])-c;
    sort(b+1,b+m+1);a[n+1]=INF;
}

inline void Solve(int l,int r,int Rl,int Rr){
    if(r<l) return;
    int mid=(l+r)>>1;
    Pre[Rl]=0;
    for(int i=Rl+1;i<=Rr;i++){
        Pre[i]=Pre[i-1];
        if(a[i-1]>b[mid]) Pre[i]++;
    }
    Suf[Rr]=0;
    for(int i=Rr-1;i>=Rl;i--){
        Suf[i]=Suf[i+1];
        if(b[mid]>a[i]) Suf[i]++;
    }
    int minn=INF,minp=-1;
    for(int i=Rl;i<=Rr;i++){
        if(minn>Pre[i]+Suf[i]){
            minn=Pre[i]+Suf[i];
            minp=i;
        }
    }
    posi[mid]=minp;
    Solve(l,mid-1,Rl,minp);
    Solve(mid+1,r,minp,Rr);
}

inline int GetAns(){
    // for(int i=1;i<=m;i++) printf("%d ",posi[i]);puts("");
    int now=0,ans=0;
    for(int i=1;i<=m;i++){
        while(now<posi[i]-1){
            now++;
            bit.SufAdd(a[now],1);
        }
        ans+=bit.AskSuf(b[i]+1);
    }
    // printf("ans=%d\n",ans);
    bit.Clear(tail);
    now=n+1;
    for(int i=m;i>=1;i--){
        while(now>posi[i]){
            now--;
            bit.PreAdd(a[now],1);
        }
        ans+=bit.PreAsk(b[i]-1);
    }
    // printf("ans=%d\n",ans);
    bit.Clear(tail);
    for(int i=n;i>=1;i--){
        ans+=bit.PreAsk(a[i]-1);
        bit.PreAdd(a[i],1);
    }
    // printf("ans=%d\n",ans);
    bit.Clear(tail);
    tail=0;
    return ans;
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Solve(1,m,1,n+1);
        printf("%lld\n",GetAns());
    }
    return 0;
}
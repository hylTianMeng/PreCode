#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define Next(k) for(int x=head[k];x;x=li[x].next)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 600
#define M 70010
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int len=265;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct blo{
    int L,R,size,cn[M],su[N],a[N];
    inline int& operator [] (const int k){assert(k<=size);return a[k];}
}b[N];
int tot,posi[M],t1[N],now,lv,rv,t2[M],ans,nv,n,m,a[N];

inline void pre(){rep(i,1,70001) posi[i]=(i-1)/len+1;}
inline void ga(int l,int r,int k){
    int li=1,ri=1;
    while(l>b[li].size) l-=b[li].size,li=b[li].R;while(r>b[ri].size) r-=b[ri].size,ri=b[ri].R;
    if(li==ri){
        rep(i,l,r) t1[posi[b[li][i]]]++,t2[b[li][i]]++;
        now=1;while(k>t1[now]) k-=t1[now],now++;
        lv=(now-1)*len+1;rv=now*len;
        rep(i,lv,rv) if(k>t2[i]) k-=t2[i];else{ans=i;break;}
        rep(i,l,r) t1[posi[b[li][i]]]--,t2[b[li][i]]--;
    }
    else{
        rep(i,l,b[li].size) t1[posi[b[li][i]]]++,t2[b[li][i]]++;
        rep(i,1,r) t1[posi[b[ri][i]]]++,t2[b[ri][i]]++;
        now=1;while(k>(nv=t1[now]+b[ri].su[now]-b[li].su[now])) k-=nv;
        lv=(now-1)*len+1;rv=now*len;
        rep(i,lv,rv) if(k>(nv=t2[i]+b[ri].cn[i]-b[li-1].cn[i])) k-=nv;
        rep(i,l,b[li].size) t1[posi[b[li][i]]]--,t2[b[li][i]]--;
        rep(i,1,r) t1[posi[b[ri][i]]]--,t2[b[ri][i]]--;
    }
};
inline void build(){
    rep(i,1,posi[n]){
        int lv=(i-1)*len+1,rv=min(i*len,n);
        rep(j,lv,rv) b[i][j-lv+1]=a[j];
        rep(j,1,70000) b[i].cn[j]+=b[i-1].cn[j];rep(j,1,300) b[i].su[j]+=b[i-1].su[j];
        b[i].L=i-1;b[i].R=i+1;b[i].size=rv-lv+1;
    }
    b[posi[n]].R=INF;
    tot=posi[n];
}
inline void Change(int x,int w){
    now=1;while(x>b[now].size) w-=b[now].size,now=b[now].R;
    int lv=b[now][x];b[now][x]=w;
    while(now!=INF){
        b[now].su[posi[lv]]--;b[now].su[posi[w]]++;
        b[now].cn[lv]--;b[now].cn[w]++;now=b[now].R;
    }
}
inline void Insert(int x,int w){
    now=1;while(x>b[now].size) x-=b[now].size,now=b[now].R;
    dec(i,x,b[now].size) b[now][i+1]=b[now][i];
    b[now][x]=w;b[now].size++;int rnow=now;
    while(rnow!=INF){
        b[rnow].su[posi[w]]++;b[rnow].cn[w]++;rnow=b[rnow].R;
    }
    if(b[now].size>=len*2){
        tot++;b[tot].L=now;b[tot].R=b[now].R;b[now].R=tot;
        rep(i,len+1,b[now].size) b[tot][i-len]=b[now][i];
        rep(i,1,70000) b[tot].cn[i]=b[now].cn[i];
        rep(i,1,300) b[tot].su[i]=b[now].su[i];
        rep(i,len+1,b[now].size){
            int v=b[now][i];b[now].cn[v]--;b[now].su[posi[v]]--;b[now][i]=0;
        }
        b[tot].size=b[now].size-len;b[now].size=len;
    }
}

int main(){
    assert(freopen("my.in","r",stdi))
    read(n);read(m);rep(i,1,n) read(a[i]);build();
    rep(i,1,m){
        char s[2];int x,y,k;
        scanf("%s",s);read(x);read(y);
        x^=ans;y^=ans;
        if(s[0]=='Q'){
            read(k);
            k^=ans;
            ga(x,y,k);printf("%d\n",ans);
        }
        else if(s[0]=='M'){
            Change(x,y);
        }
        else if(s[0]=='I'){
            Insert(x,y);
        }
    }
    return 0;
}
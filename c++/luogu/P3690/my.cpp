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
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 100010
#define M number
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int tag[N],val[N],ch[N][2],fa[N],n,m,a[N];

inline void Print(){
    rep(i,1,n){
        printf("k=%d tag=%d val=%d ch[0]=%d ch[1]=%d fa=%d\n",i,tag[i],val[i],ch[i][0],ch[i][1],fa[i]);
    }
}

#define ls(k) ch[k][0]
#define rs(k) ch[k][1]
struct LCT{
    inline int Get(int k){return rs(fa[k])==k;}
    inline void PushUp(int k){
        val[k]=a[k]^val[ls(k)]^val[rs(k)];
    }
    inline void C(int k){
        swap(ls(k),rs(k));tag[k]^=1;
    }
    inline void PushDown(int k){
        if(tag[k]){
            C(ls(k));C(rs(k));tag[k]^=1;;
        }
    }
    inline bool Root(int k){
        int fat=fa[k];
        return ls(fat)!=k&&rs(fat)!=k;
    }
    inline void rotate(int k){
        int y=fa[k];int z=fa[y],x=Get(k);
        if(!Root(y)) ch[z][Get(y)]=k;
        ch[y][x]=ch[k][x^1];fa[ch[k][x^1]]=y;
        ch[k][x^1]=y;fa[y]=k;fa[k]=z;
        PushUp(y);PushUp(k);
    }
    inline void Update(int k){
        if(!Root(k)) Update(fa[k]);
        PushDown(k);
    }
    inline void Splay(int k){
        Update(k);
        for(int f=fa[k];!Root(k);rotate(k),f=fa[k]){
            if(!Root(f)) rotate(Get(k)==Get(f)?f:k);
        }
    }
    inline int Access(int k){
        int p;
        for(p=0;k;p=k,k=fa[k]){
            Splay(k);rs(k)=p;PushUp(k);
        }
        return p;
    }
    inline void MakeRoot(int k){
        k=Access(k);C(k);
    }
    inline void Split(int x,int y){
        MakeRoot(x);Access(y);Splay(y);
    }
    inline int Find(int k){
        Access(k);Splay(k);PushDown(k);
        while(ls(k)) k=ls(k),PushDown(k);
        Splay(k);return k;
    }
    inline void Cut(int a,int b){
        MakeRoot(a);
        if(Find(b)==a&&rs(a)==b&&ls(b)==0){
            rs(a)=fa[b]=0;PushUp(a);
        }
    }
    inline void Link(int a,int b){
        MakeRoot(a);if(Find(b)==a) return;Splay(a);fa[a]=b;
    }
    inline void Change(int k,int x){
        MakeRoot(k);a[k]=x;PushUp(k);
    }
    inline int Ask(int a,int b){
        Split(a,b);return val[b];
    }
}lct;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    rep(i,1,n){
        read(val[i]);a[i]=val[i];
    }
    rep(i,1,m){
        int op,x,y;read(op);read(x);read(y);
        if(op==0){
            printf("%d\n",lct.Ask(x,y));
        }
        else if(op==1){
            lct.Link(x,y);
        }
        else if(op==2){
            lct.Cut(x,y);
        }
        else if(op==3){
            lct.Change(x,y);
        }
    }
    return 0;
}
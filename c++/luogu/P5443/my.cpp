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

int n,m,len,q,posi[N],fa[N],siz[N],ans[N];
struct edge{
    int u,v,w;
    inline bool operator < (const edge &b)const{return w>b.w;}
}e[N],b[N];
struct Ques{
    int op,a,b,id;
    inline bool operator < (const Ques &c)const{return b>c.b;}
}qu[N];
vector<Ques> v;
vector<P> te;
bool vis[N];

P sta[N];int top;
inline int Find(int x){return x==fa[x]?x:Find(fa[x]);}
inline void Merge(int x,int y){
    int fax=Find(x),fay=Find(y);if(fax==fay) return;
    if(siz[fax]<siz[fay]) swap(fax,fay);
    sta[++top]=mp(fay,siz[fax]);siz[fax]+=siz[fay];fa[fay]=fax;
}
inline void Rollonce(){
    P now=sta[top--];siz[fa[now.fi]]=now.se;fa[now.fi]=now.fi;
}
inline void Roll(int val){
    rep(i,1,val){assert(top);Rollonce();}
}

int main(){
    // assert(freopen("my.in","r",stdin));
    // assert(freopen("my.out","w",stdout));
    read(n);read(m);
    len=sqrt(m*log2(m))+1;
    rep(i,1,m){
        read(e[i].u);read(e[i].v);read(e[i].w);
    }
    read(q);
    rep(i,1,q){
        read(qu[i].op);read(qu[i].a);read(qu[i].b);qu[i].id=i;
    }
    rep(i,1,q) posi[i]=(i-1)/len+1;rep(i,1,n) fa[i]=i,siz[i]=1;
    rep(i,1,posi[q]){
        int l=(i-1)*len+1,r=min(i*len,q);
        rep(j,l,r) if(qu[j].op==1) vis[qu[j].a]=1;
        int t=0;
        rep(j,1,m) if(!vis[j]) b[++t]=e[j];else te.pb(mp(j,e[j].w));
        sort(b+1,b+t+1);
        rep(j,l,r) if(qu[j].op==2) v.pb(qu[j]);
        sort(v.begin(),v.end());
        int cnt;int id=0;
        for(Ques now:v){
            while(b[id+1].w>=now.b&&id+1<=t) id++,Merge(b[id].u,b[id].v)/*,printf("%d %d\n",b[id].u,b[id].v)*/;
            cnt=top;
            rep(j,l,now.id) if(qu[j].op==1) e[qu[j].a].w=qu[j].b;
            for(P j:te) if(e[j.fi].w>=now.b) Merge(e[j.fi].u,e[j.fi].v);
            for(P j:te) e[j.fi].w=j.se;
            int f=Find(now.a);ans[now.id]=siz[f];
            Roll(top-cnt);assert(top==cnt);
        }
        v.clear();te.clear();
        rep(j,l,r) if(qu[j].op==1) vis[qu[j].a]=0;
        rep(j,l,r) if(qu[j].op==1) e[qu[j].a].w=qu[j].b;
        rep(j,l,r) if(qu[j].op==1) vis[qu[j].a]=0;
        Roll(top);
    }
    rep(i,1,q){
        if(qu[i].op==2) printf("%d\n",ans[i]);
    }
    return 0;
}
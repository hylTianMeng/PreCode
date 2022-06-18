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
#define N 200010
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
#define int long long
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

int n,m,siz[N],top[N],fa[N],dep[N],son[N],id[N],rk[N],tot,r;
vi e[N];
vector<P> s1,s2,v;

inline int random(int n){return 1ll*rand()*rand()%n+1;}

struct Node{
    int val,siz,ls,rs,sum,stag,ctag,maxx,minn,key;
    inline Node(){}
    inline Node(int val,int siz,int ls,int rs,int sum,int stag,int ctag,int maxx,int minn,int key)
        :val(val),siz(siz),ls(ls),rs(rs),sum(sum),stag(stag),ctag(ctag),maxx(maxx),minn(minn),key(key) {} 
    inline void Print(){
        printf("val=%d siz=%d ls=%d rs=%d sum=%d stag=%d ctag=%d maxx=%d minn=%d key=%d\n"\
            ,val,siz,ls,rs,sum,stag,ctag,maxx,minn,key);
    }
}p[N];

int wh;

struct Squ{
    int l,r,y,x,id,op;
    inline void Print(){
        printf("l=%d r=%d y=%d x=%d id=%d op=%d\n",l,r,y,x,id,op);
    }
}s[N];

inline bool cmp(Squ a,Squ b){
    if(wh==1) return a.l<b.l;
    else return a.id<b.id;
}

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct FHQ_Treap{
    int root,tot;
    inline FHQ_Treap(){
        p[0]=Node(0,0,0,0,0,0,0,-INF,INF,0);
    }
    inline int NewNode(int val){
        tot++;p[tot]=Node(val,1,0,0,0,0,0,val,val,random(INF));return tot;
    }
    inline void PushUp(int k){
        p[k].sum=p[ls(k)].sum+p[rs(k)].sum+p[k].val;
        p[k].siz=p[ls(k)].siz+p[rs(k)].siz+1;
        p[k].maxx=max(p[ls(k)].maxx,max(p[rs(k)].maxx,p[k].val));
        p[k].minn=min(p[ls(k)].minn,min(p[rs(k)].minn,p[k].val));
    }
    inline void A(int k,int x){
        if(!k) return;
        p[k].val+=x;p[k].sum+=x*p[k].siz;p[k].stag+=x;
        p[k].maxx+=x;p[k].minn+=x;
    }
    inline void C(int k){
        if(!k) return;
        swap(ls(k),rs(k));p[k].ctag^=1;
    }
    inline void PushDown(int k){
        if(p[k].stag){
            A(ls(k),p[k].stag);A(rs(k),p[k].stag);p[k].stag=0;
        }
        if(p[k].ctag){
            C(ls(k));C(rs(k));p[k].ctag=0;
        }
    }
    inline void Split(int k,int &x,int &y,int siz){
        if(!k){x=y=0;return;}
        PushDown(k);
        if(p[ls(k)].siz+1<=siz){
            x=k;Split(rs(k),rs(x),y,siz-p[ls(k)].siz-1);PushUp(k);
        }
        else{
            y=k;Split(ls(k),x,ls(y),siz);PushUp(k);
        }
    }
    inline int Merge(int a,int b){
        if(!a||!b) return a+b;
        PushDown(a);PushDown(b);
        if(p[a].key<p[b].key){
            ls(b)=Merge(a,ls(b));PushUp(b);return b;
        }
        else{
            rs(a)=Merge(rs(a),b);PushUp(a);return a;
        }
    }
    inline void Insert(int siz){
        int x,y;Split(root,x,y,siz);root=Merge(Merge(x,NewNode(0)),y);
    }
    inline void Add(int a,int b,int w){
        // printf("a=%d b=%d x=%d\n",a,b,w);
        // printf("root=%d\n",root);
        int x,y,z;Split(root,x,z,b);Split(x,x,y,a-1);
        A(y,w);root=Merge(Merge(x,y),z);
    }
    inline int AskSum(int a,int b){
        int x,y,z;Split(root,x,z,b);Split(x,x,y,a-1);
        
        int ans=p[y].sum;root=Merge(Merge(x,y),z);return ans;
    }
    inline int AskMax(int a,int b){
        int x,y,z;Split(root,x,z,b);Split(x,x,y,a-1);
        // puts("spe");Print();puts("");
        int ans=p[y].maxx;root=Merge(Merge(x,y),z);return ans;
    }
    inline int AskMin(int a,int b){
        int x,y,z;Split(root,x,z,b);Split(x,x,y,a-1);
        int ans=p[y].minn;root=Merge(Merge(x,y),z);return ans;
    }
    inline void ReVec(vector<P> s1,vector<P> s2){
        int len=0;
        for(auto now:s1){len++;s[len].l=now.fi;s[len].r=now.se;s[len].id=len;s[len].op=1;s[len].x=0;s[len].y=0;}
        for(auto now:s2){len++;s[len].l=now.fi;s[len].r=now.se;s[len].id=len;s[len].op=0;s[len].x=0;s[len].y=0;}
        // rep(i,1,len){
            // s[i].Print();
        // }
        wh=1;sort(s+1,s+len+1,cmp);
        for(int i=len;i>=1;i--){
            int x,y,z;Split(root,y,z,s[i].r);Split(y,x,y,s[i].l-1);root=x;
            s[i].y=y;s[i].x=z;
        }
        // printf("Have Splited!!\n");
        rep(i,1,len) if(s[i].op==1) C(s[i].y);
        // Print();
        // printf("Enter Merge\n");
        wh=2;sort(s+1,s+len+1,cmp);
        // rep(i,1,len) s[i].Print();
        int nr=0;
        rep(i,1,len){
            // printf("nr=%d s[i].y=%d\n",nr,s[i].y);
            nr=Merge(nr,s[i].y);
        }
        // printf("nr=%d\n",nr);
        C(nr);
        // printf("Merge First Complitely!!\n");
        // Print();
        // printf("Enter Merge Second\n");
        rep(i,1,len){
            int x,y;Split(nr,x,y,s[i].r-s[i].l+1);
            nr=y;s[i].y=x;
        }
        // rep(i,1,len) s[i].Print();
        rep(i,1,len) if(s[i].op==1) C(s[i].y);
        // Print();
        wh=1;sort(s+1,s+len+1,cmp);
        rep(i,1,len){root=Merge(root,Merge(s[i].y,s[i].x));}
    }
    inline void Print(){
        printf("root=%d\n",root);
        rep(i,1,tot){
            printf("i=%d\n",i);
            p[i].Print();
        }
    }
}tr;

inline void dfs(int k,int fat){
    dep[k]=dep[fat]+1;siz[k]=1;fa[k]=fat;
    for(int to:e[k]){
        if(to==fat) continue;
        dfs(to,k);siz[k]+=siz[to];if(siz[son[k]]<siz[to]) son[k]=to;
    }
}

inline void dfs2(int k,int t){
    id[k]=++tot;rk[tot]=k;top[k]=t;
    // printf("id[%d]=%d\n",k,id[k]);
    if(son[k]) dfs2(son[k],t);
    for(int to:e[k]){
        if(to==fa[k]||to==son[k]) continue;
        dfs2(to,to);
    }
}

inline int ge(int a,int b,int op,int w){
    // printf("a=%d b=%d op=%d x=%d\n",a,b,op,w);
    int sum=0,maxx=-INF,minn=INF;
    if(dep[a]<dep[b]) swap(a,b);
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        if(op==1) tr.Add(id[top[a]],id[a],w);
        else if(op==2) sum+=tr.AskSum(id[top[a]],id[a]);
        else if(op==3) maxx=max(maxx,tr.AskMax(id[top[a]],id[a]));
        else if(op==4) minn=min(minn,tr.AskMin(id[top[a]],id[a]));
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) swap(a,b);
    if(op==1) tr.Add(id[b],id[a],w);
    else if(op==2) sum+=tr.AskSum(id[b],id[a]);
    else if(op==3) maxx=max(maxx,tr.AskMax(id[b],id[a]));
    else if(op==4) minn=min(minn,tr.AskMin(id[b],id[a]));
    if(op==1) return -1;else if(op==2) return sum;else if(op==3) return maxx;else return minn;
}

inline void re(int a,int b){
    s1.clear();s2.clear();v.clear();
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]){
            s2.pb(mp(id[top[b]],id[b]));
            b=fa[top[b]];
        }
        else{
            s1.pb(mp(id[top[a]],id[a]));
            a=fa[top[a]];
        }
    }
    if(dep[a]<dep[b]){
        s2.pb(mp(id[a],id[b]));
    }
    else{
        s1.pb(mp(id[b],id[a]));
    }
    for(int i=(int)s2.size()-1;i>=0;i--) v.pb(s2[i]);
    tr.ReVec(s1,v);
}

inline void PreWork(){
    read(n);read(m);read(r);
    rep(i,1,n-1){
        int from,to;read(from);read(to);
        e[from].pb(to);e[to].pb(from);
    }
    dfs(1,0);dfs2(1,1);
    rep(i,1,n){
        tr.Insert(i);
        // tr.Print();
        // puts("");
    }
}

inline void Solve(){
    rep(i,1,m){
        string s;cin>>s;
        int op=-1;
        if(s=="Increase") op=1;
        else if(s=="Sum") op=2;
        else if(s=="Major") op=3;
        else if(s=="Minor") op=4;
        else if(s=="Invert") op=5;
        else assert(0);
        int a,b,x=-1;
        read(a);read(b);if(op==1) read(x);
        if(op<=4){
            int ans=ge(a,b,op,x);
            if(op!=1) printf("%lld\n",ans);
        }
        else re(a,b);
        // tr.Print();puts("");
    }
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();Solve();return 0;
}
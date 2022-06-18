#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 4000010
#define M 20
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=2908361;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Min(T a,T b){return a<b?a:b;}

// int table[9][10]={
//     {0,0,0,0,0,0,0,0,0,0},
//     {0,2,7,6,9,5,1,4,3,8},
//     {0,2,9,4,7,5,3,6,1,8},
//     {0,4,3,8,9,5,1,2,7,6},
//     {0,4,9,2,3,5,7,8,1,6},
//     {0,6,1,8,7,5,3,2,9,4},
//     {0,6,7,2,1,5,9,8,3,4},
//     {0,8,1,6,3,5,7,4,9,2},
//     {0,8,3,4,1,5,9,6,7,2}
// };

int t[9]={0,276951438,294753618,438951276,492357816,618753294,672159834,816357492,834159672};
int ta[9];

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N*10];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

struct Hash{
    int head[N],li[N],tot,val[N];
    inline void Insert(int v){
        int ha=v%mod;
        for(int x=head[ha];x;x=li[x]);
        val[++tot]=v;li[tot]=head[ha];head[ha]=tot;
        // printf("v=%d tot=%d\n",v,tot);
    }
    inline int Find(int v){
        int now=v%mod;
        for(int x=head[now];x;x=li[x]){
            // printf("x=%d\n",x);
            if(val[x]==v) return x;
        }
        return -1;
    }
}h;

int a[M],b[N],bt,TenPow[N],T;

inline void PreWork(){
    for(int i=1;i<=9;i++) a[i]=i;
    for(int i=1;i<=362880-1;i++){
        int val=0;
        for(int j=1;j<=9;j++){val*=10;val+=a[j];}
        h.Insert(val);b[++bt]=val;
        next_permutation(a+1,a+9+1);
    }
    int val=0;
    for(int j=1;j<=9;j++){val*=10;val+=a[j];}
    h.Insert(val);b[++bt]=val;
    TenPow[0]=1;
    for(int i=1;i<=9;i++) TenPow[i]=TenPow[i-1]*10;
    for(int i=1;i<=8;i++) ta[i]=h.Find(t[i]);
    // for(int i=1;i<=8;i++){
    //     printf("i=%d ta[i]=%d\n",i,ta[i]);
    // }
}

inline int Get(int x,int i,int j){
    if(i<j) swap(i,j);
    int p1=x/TenPow[i];
    int p2=(x%TenPow[i])/TenPow[i-1];
    int p3=(x%TenPow[i-1])/TenPow[j];
    int p4=(x%TenPow[j])/TenPow[j-1];
    int p5=x%TenPow[j-1];
    // printf("%d %d %d %d %d\n",p1,p2,p3,p4,p5);
    swap(p2,p4);
    return p1*TenPow[i]+p2*TenPow[i-1]+p3*TenPow[j]+p4*TenPow[j-1]+p5;
}

inline void Build(){
    for(int i=1;i<=bt;i++){
        // assert(h.Find(b[i])!=-1);
        // if(h.Find(Get(b[i],9,8))==-1){
        //     printf("b[i]=%d get=%d\n",b[i],Get(b[i],9,8));
        // }
        // assert(h.Find(Get(b[i],9,8))!=-1);
        Add(h.Find(b[i]),h.Find(Get(b[i],9,8)));
        Add(h.Find(b[i]),h.Find(Get(b[i],9,6)));
        Add(h.Find(b[i]),h.Find(Get(b[i],8,5)));
        Add(h.Find(b[i]),h.Find(Get(b[i],8,7)));
        Add(h.Find(b[i]),h.Find(Get(b[i],6,3)));
        Add(h.Find(b[i]),h.Find(Get(b[i],6,5)));
        Add(h.Find(b[i]),h.Find(Get(b[i],5,2)));
        Add(h.Find(b[i]),h.Find(Get(b[i],5,4)));
        Add(h.Find(b[i]),h.Find(Get(b[i],7,4)));
        Add(h.Find(b[i]),h.Find(Get(b[i],4,1)));
        Add(h.Find(b[i]),h.Find(Get(b[i],3,2)));
        Add(h.Find(b[i]),h.Find(Get(b[i],2,1)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],8,9)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],6,9)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],5,8)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],7,8)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],3,6)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],5,6)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],2,5)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],4,5)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],4,7)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],1,4)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],2,3)));
        // Add(h.Find(b[i]),h.Find(Get(b[i],1,2)));
    }
}

int d[N];
queue<int> q;
bool vis[N];
inline int bfs(int s){
    for(int i=1;i<=400000;i++) vis[i]=0;
    while(q.size()) q.pop();
    d[s]=0;q.push(s);vis[s]=1;
    while(q.size()){
        int top=q.front();q.pop();
        // printf("val=%d\n",h.val[top]);
        for(int i=1;i<=8;i++) if(top==ta[i]){
            // printf("top=%d\n",top);
            return d[top];
        }
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to;
            // printf("id=%d to=%d\n",to,h.val[to]);
            if(vis[to]) continue;
            vis[to]=1;q.push(to);
            d[to]=d[top]+1;
        }
    }
    return -1;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork();
    // printf("here\n");
    Build();
    // printf("here\n");
    read(T);
    while(T--){
        int val=0;
        for(int i=1;i<=9;i++){
            read(a[i]);val*=10;val+=a[i];
        }
        // printf("here\n");
        int id=h.Find(val);
        // printf("val=%d\n",val);
        // printf("id=%d\n",id);
        printf("%d\n",bfs(id));
    }
    return 0;
}
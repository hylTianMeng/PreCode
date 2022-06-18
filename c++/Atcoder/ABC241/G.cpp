#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 55
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

struct edge{
    int to,next,f;
    inline void Init(int to_,int ne_,int f_){
        to=to_;next=ne_;f=f_;
    }
}li[200010<<1];
int head[200010],tail=1,now[200010];

int n,m,a[N][N],b[N][N];
int w[N],l[N],w2[N],s,t;
vector<int> Now;
queue<int> q;
int d[200010];

inline void Add(int from,int to,int w){
    li[++tail].Init(to,head[from],w);
    head[from]=tail;
}

inline bool bfs(int s){
//    printf("ENTER\n");
    while(q.size()) q.pop();
    memset(d,0,sizeof(d));
    d[s]=1;now[s]=head[s];q.push(s);
    while(q.size()){
        int top=q.front();q.pop();
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to,f=li[x].f;
            if(!f||d[to]) continue;
            d[to]=d[top]+1;now[to]=head[to];
            q.push(to);
            if(to==t) return 1;
        }
    }
    if(!d[t]) return 0;
    return 1;
}

inline int dicnic(int k,int flow){
    if(k==t) return flow;
    int rest=flow,x;
    for(x=now[k];x&&rest;x=li[x].next){
        int to=li[x].to,re=li[x].f;
        if(!re||d[to]!=d[k]+1) continue;
        int val=dicnic(to,min(rest,re));
        if(!val) d[to]=0;
        li[x].f-=val;
        li[x^1].f+=val;
        rest-=val;
    }
    now[k]=x;
    return flow-rest;
}

inline void Clear(int id){
    for(int i=1;i<=n;i++){
        b[i][id]=a[i][id];
        b[id][i]=a[id][i];
    }
}

inline void Build(int id){
    tail=1;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++){
        if(i==id) continue;
        Add(i,i+n,w2[id]-w2[i]-1);
        Add(i+n,i,0);
    }
    int tot=2*n;
    vector<int>().swap(Now);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(b[i][j]) continue;
            tot++;Now.push_back(tot);
            Add(tot,i,1);Add(i,tot,0);
            Add(tot,j,1);Add(j,tot,0);
        }
    s=++tot;t=++tot;
    for(int k:Now){
        Add(s,k,1);Add(k,s,0);
    }
    for(int i=1;i<=n;i++){
        if(i==id) continue;
        Add(i+n,t,INF);Add(t,i+n,0);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        a[from][to]=1;a[to][from]=1;
        b[from][to]=1;b[to][from]=1;
        w[from]++;
    } 
    for(int i=1;i<=n;i++){
        // printf("i=%d\n",i);
        for(int j=1;j<=n;j++) w2[j]=w[j];
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(a[i][j]) continue;
            w2[i]++;b[i][j]=1;b[j][i]=1;
        }
        bool op=0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            if(w2[j]>=w2[i]){op=1;break;}
        }
        if(op) continue;
        Build(i);
        int flow,ans=0;
        while(bfs(s)){
            while((flow=dicnic(s,INF))) ans+=flow;
        }
        if(ans==Now.size()){printf("%d ",i);}
        Clear(i);
    }
    return 0;
}
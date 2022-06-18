#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
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
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,rd[N],xulie[N],tt;

struct cmp{
    inline bool operator () (int a,int b){return a>b;}
};
priority_queue<int,vector<int>,cmp> q;

inline void bfs(){
    while(q.size()){
        int top=q.top();q.pop();
        xulie[++tt]=top;
        for(int x=head[top];x;x=li[x].next){
            int to=li[x].to;rd[to]--;
            if(!rd[to]) q.push(to);
        }
    }
}

int main(){
    read(n);read(m);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(from,to);rd[to]++;
    }
    for(int i=1;i<=n;i++) if(!rd[i]) q.push(i);
    bfs();
    if(tt!=n) return puts("-1"),0;
    for(int i=1;i<=n;i++) printf("%d ",xulie[i]);
    return 0;
}
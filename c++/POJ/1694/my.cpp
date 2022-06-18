#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,m,t,a,b,c,f[N];

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a);read(b);
        for(int j=1;j<=b;j++){read(c);Add(c,a);Add(a,c);}
    }
}

inline void Dfs(int k,int fa){
    vector<int> v;v.clear();
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(to==fa) continue;
        Dfs(to,k);v.push_back(f[to]);
    }
    if(v.empty()){f[k]=1;return;}
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=(int)v.size()-1;i>=0;i--){
        f[k]=Max(f[k],v[i]+cnt);cnt++;
    }
}

inline void Print(){printf("%d\n",f[1]);}

inline void Clear(){
    fill(head+1,head+n+1,0);
    fill(f+1,f+n+1,0);tail=0;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Dfs(1,0);Print();Clear();
    }
    return 0;
}


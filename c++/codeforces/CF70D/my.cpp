#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

template<typename T> inline T Min(T a,T b){return a<b?a:b;}
template<typename T> inline T Max(T a,T b){return a<b?b:a;}
 
struct Node{
    ld x,y;
    ld horn;
    inline Node(){}
    inline Node(ld x,ld y,ld horn) : x(x),y(y),horn(horn) {}
    inline bool operator < (const Node &b)const{
        return horn<b.horn;
    }
    inline ld operator ^ (const Node &b)const{return x*b.y-y*b.x;}
    inline Node operator - (const Node &b)const{return Node(x-b.x,y-b.y,0);}
    inline void Print(){printf("%Lf %Lf\n",this->x,this->y);}
}p[4],O;
 
set<Node> S;
 
inline set<Node>::iterator Pre(set<Node>::iterator it){
    return it==S.begin()?--S.end():--it;
}
 
inline set<Node>::iterator Next(set<Node>::iterator it){
    return it==--S.end()?S.begin():++it;
}
 
int n;
 
inline void Insert(ld x,ld y){
    ld ho=atan2(y-O.y,x-O.x);
    Node now=Node(x,y,ho);
    auto it=S.lower_bound(now);
    if(it==S.end()) it=S.begin();
    auto it2=Pre(it);
    if((((*it)-now)^((*it2)-now))<=0) return;
    S.insert(now);it=S.find(now);
    auto it1=Pre(it);it2=Pre(it1);
    while((((*it1)-(*it2))^(now-(*it2)))<=0){S.erase(it1);it1=it2;it2=Pre(it1);}
    it1=Next(it);it2=Next(it1);
    while((((*it1)-(*it2))^(now-(*it2)))>=0){S.erase(it1);it1=it2;it2=Next(it1);}
}
 
inline bool Query(ld x,ld y){
    // printf("here\n");
    ld ho=atan2(y-O.y,x-O.x);
    Node now=Node(x,y,ho);
    auto it=S.lower_bound(now);
    if(it==S.end()) it=S.begin();
    auto it2=Pre(it);
    return (((*it)-now)^((*it2)-now))<=0;
}
 
signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    ld MaxX=-INF,MinX=INF,MaxY=-INF,MinY=INF;
    for(int i=1;i<=3;i++){
        int op,x,y;read(op);read(x);read(y);
        p[i].x=x;p[i].y=y;p[i].x*=3;p[i].y*=3;
    }
    O.x=(p[1].x+p[2].x)/2;O.y=(p[1].y+p[2].y)/2;
    O.x=(O.x+p[3].x)/2;O.y=(O.y+p[3].y)/2;
    // printf("%Lf %Lf\n",O.x,O.y);
    for(int i=1;i<=3;i++){
        p[i].horn=atan2(p[i].y-O.y,p[i].x-O.x);
        S.insert(p[i]);
    }
    for(int i=4;i<=n;i++){
        // printf("i=%d\n",i);
        int op,x,y;read(op);read(x);read(y);
        x*=3;y*=3;
        if(op==1) Insert(x,y);
        else puts(Query(x,y)==1?"YES":"NO");
    }
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M 4000010
using namespace std;

const int INF=0x3f3f3f3f;
const int Len=200000;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int R,C,m,Q,sr,sc,Maxx,Maxy,Minx,Miny;
char s[N];

struct Point{
    int x,y;
    inline Point(){}
    inline Point(int x,int y) : x(x),y(y) {}
    inline bool operator < (const Point &b) const{
        if(x!=b.x) return x<b.x;return y<b.y;
    }
    inline bool operator == (const Point &b) const{
        return x==b.x&&y==b.y;
    }
};

vector<Point> q[4];

struct Node{
    int ls,rs,sum;
    inline void Print(){
        printf("ls=%d rs=%d sum=%d\n",ls,rs,sum);
    }
    inline Node(){}
    inline Node(int ls,int rs,int sum) : ls(ls),rs(rs),sum(sum) {}
};

#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct Segment_Tree{
    Node p[M];int root[N],tot;
    inline int NewNode(){return ++tot;}
    inline void PushUp(int k){p[k].sum=p[ls(k)].sum+p[rs(k)].sum;}
    inline void Change(int &k,int last,int l,int r,int w,int x){
        k=NewNode();p[k]=p[last];int mid=(l+r)>>1;
        if(l==r){p[k].sum+=x;return;}
        if(w<=mid) Change(ls(k),ls(last),l,mid,w,x);
        else Change(rs(k),rs(last),mid+1,r,w,x);PushUp(k);
    }
    inline int AskSum(int lk,int rk,int l,int r,int z,int y){
        // printf("lk=%d rk=%d\n",lk,rk);p[lk].Print();p[rk].Print();
        if(l==z&&r==y) return p[rk].sum-p[lk].sum;
        int mid=(l+r)>>1;
        if(y<=mid) return AskSum(ls(lk),ls(rk),l,mid,z,y);
        else if(z>mid) return AskSum(rs(lk),rs(rk),mid+1,r,z,y);
        else return AskSum(ls(lk),ls(rk),l,mid,z,mid)+AskSum(rs(lk),rs(rk),mid+1,r,mid+1,y);
    }
    inline void AddPoint(int x,int y){
        Change(root[x],root[x],1,Len,y,1);
        root[x+1]=root[x];
    }
    inline int Query(int ar,int ac,int br,int bc){
        if(bc<ac||br<ar) return 0;
        // printf("Query: %d %d %d %d\n",ar,ac,br,bc);
        return AskSum(root[ar-1],root[br],1,Len,ac,bc);
    }
    inline void Init(){
        for(int i=1;i<=R;i++) if(!root[i]) root[i]=root[i-1];
    }
}tr[4];

inline void AddPoint(int x,int y){
    for(int i=0;i<=3;i++) q[i].push_back(Point(x,y));
    if(x>1) q[1].push_back(Point(x-1,y)),q[3].push_back(Point(x-1,y));
    if(y>1) q[2].push_back(Point(x,y-1)),q[3].push_back(Point(x,y-1));
    if(x>1&&y>1) q[3].push_back(Point(x-1,y-1));
}

inline void Init(){
    read(R);read(C);read(m);read(Q);read(sr);read(sc);AddPoint(sr,sc);Maxx=Minx=sr;Maxy=Miny=sc;
    if(m!=0) scanf("%s",s+1);
    for(int i=1;i<=m;i++){
        if(s[i]=='N') sr--;else if(s[i]=='S') sr++;else if(s[i]=='W') sc--;else if(s[i]=='E') sc++;
        AddPoint(sr,sc);Maxx=max(Maxx,sr);Maxy=max(Maxy,sc);Minx=min(Minx,sr);Miny=min(Miny,sc);
    }
    for(int i=0;i<=3;i++){
        sort(q[i].begin(),q[i].end());
        vector<Point>::iterator it=unique(q[i].begin(),q[i].end());
        q[i].erase(it,q[i].end());
    }
    for(int i=0;i<=3;i++){
        // printf("i=%d\n",i);
        for(int j=0;j<(int)q[i].size();j++){
            Point now=q[i][j];
            tr[i].AddPoint(now.x,now.y);
            // printf("now.x=%d now.y=%d\n",now.x,now.y);
        }
        tr[i].Init();
    }
    // printf("Complete Initing\n");
}

inline void Solve(){
    for(int i=1;i<=Q;i++){
        // printf("i=%d\n",i);
        int ar,ac,br,bc,ans=0;read(ar);read(ac);read(br);read(bc);
        int ans1=(br-ar+1)*(bc-ac+1)-tr[0].Query(ar,ac,br,bc);
        int ans2=(br-ar)*(bc-ac+1)-tr[1].Query(ar,ac,br-1,bc);
        // printf("%d\n",tr[1].Query(ar,ac,br-1,bc));
        int ans3=(br-ar+1)*(bc-ac)-tr[2].Query(ar,ac,br,bc-1);
        int ans4=(br-ar)*(bc-ac)-tr[3].Query(ar,ac,br-1,bc-1);
        // printf("ans1=%d ans2=%d ans3=%d ans4=%d\n",ans1,ans2,ans3,ans4);
        ans=ans1-ans2-ans3+ans4;
        if(ar<Minx&&ac<Miny&&br>Maxx&&bc>Maxy) ans++;
        printf("%d\n",ans);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();
}
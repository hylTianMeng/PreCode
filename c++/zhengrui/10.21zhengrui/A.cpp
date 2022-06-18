#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1<<20
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

int n,a[N],ans[N],Anstot;

struct Node{
    int Maxx,ls,rs,Dep,SecMaxx;
};
#define ls(k) p[k].ls
#define rs(k) p[k].rs
struct SegmentTree{
    Node p[N];
    int tot,root;
    inline SegmentTree(){tot=1;root=1;}
    inline int NewNode(){return ++tot;}
    inline void PushUp(int k){
        p[k].Maxx=Max(p[ls(k)].Maxx,p[rs(k)].Maxx);p[k].Dep=p[ls(k)].Dep+1;
        p[k].SecMaxx=(p[ls(k)].Maxx==p[k].Maxx)?p[rs(k)].Maxx:p[ls(k)].Maxx;
        p[k].SecMaxx=Max(p[k].SecMaxx,Max(p[ls(k)].SecMaxx,p[rs(k)].SecMaxx));
    }
    inline void build(int &k,int l,int r){
        if(!k) k=NewNode();
        if(l==r){p[k].Dep=0;p[k].Maxx=a[l];p[k].SecMaxx=-INF;return;}
        int mid=(l+r)>>1;build(ls(k),l,mid);build(rs(k),mid+1,r);
        PushUp(k);
    }
    inline void Build(){build(root,1,1<<n);}
    inline void GetAns(){
        Anstot=1<<n;
        queue<int> q;while(q.size()) q.pop();q.push(1);
        while(q.size()&&Anstot){
            int top=q.front();q.pop();
            // printf("top=%d\n",top);
            while(p[top].SecMaxx<Anstot&&Anstot){
                // printf("SecMaxx=%d\n",p[top].SecMaxx);
                ans[Anstot]=p[top].Dep;
                Anstot--;
            }
            q.push(ls(top));q.push(rs(top));
        }
    }
}st;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=1<<n;i++) read(a[i]);
    // printf("finish Initing\n");
    st.Build();st.GetAns();
    for(int i=1;i<=1<<n;i++) printf("%d ",ans[i]);
    return 0;
}
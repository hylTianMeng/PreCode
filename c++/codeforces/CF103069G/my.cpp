#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

int n,a[N],m,qt,ans[N];
int pre[N],L[N];

typedef pair<int,int> P;
vector<P> ques[N];

struct Node{
    int s0,s1,sum,nowsum,cnt,retag,adtag;
}p[N<<2];

#define ls(k) k<<1
#define rs(k) k<<1|1
struct SegmentTree{
    inline void PushUp(int k){
        p[k].s0=p[ls(k)].s0+p[rs(k)].s0;
        p[k].s1=p[ls(k)].s1+p[rs(k)].s1;
    }
    inline void S(int k){
        p[k].cnt+=p[k].adtag;p[k].adtag=0;p[k].sum+=p[k].nowsum*p[k].cnt;p[k].nowsum=0;p[k].cnt=0;
        swap(p[k].s0,p[k].s1);p[k].nowsum=p[k].s1;
        p[k].retag=1;
    }
    inline void A(int k,int x){
        p[k].cnt+=x;p[k].adtag+=x;
    }
    inline void PushDown(int k){
        if(p[k].retag){
            S(ls(k));S(rs(k));p[k].retag=0;
        }
        if(p[k].adtag){
            A(ls(k),p[k].adtag);A(rs(k),p[k].adtag);p[k].adtag=0;
        }
    }
    inline void Reverse(int k,int l,int r,int z,int y){
        if(l==z&&r==y){S(k);return;}
        PushDown(k);
        int mid=(l+r)>>1;
        if(y<=mid) Reverse(ls(k),l,mid,z,y);
        else if(z>mid) Reverse(rs(k),mid+1,r,z,y);
        else{Reverse(ls(k),l,mid,z,mid);Reverse(rs(k),mid+1,r,mid+1,y);}
        PushUp(k);
    }
    inline void Update(){
        p[1].adtag++;
    }
    inline void Build(int k,int l,int r){
        if(l==r){p[k].s0=1;return;}
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);
        PushUp(k);
    }
    inline int GetAns(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k].sum+p[k].nowsum*p[k].cnt;
        PushDown(k);
        int mid=(l+r)>>1;
        if(y<=mid) return GetAns(ls(k),l,mid,z,y);
        else if(z>mid) return GetAns(rs(k),mid+1,r,z,y);
        else return GetAns(ls(k),l,mid,z,mid)+GetAns(rs(k),mid+1,r,mid+1,y);
    }
}tr;

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
        L[i]=pre[a[i]];pre[a[i]]=i;
    }
    tr.Build(1,1,n);
    read(m);
    for(int i=1;i<=m;i++){
        int l,r;read(l);read(r);
        ques[r].push_back(make_pair(l,i));
    }
    for(int i=1;i<=n;i++){
        printf("Re: %d %d\n",L[i]+1,i);
        tr.Reverse(1,1,n,L[i]+1,i);
        tr.Update();
        for(auto j:ques[i]){
            printf("GA: %d %d\n",j.first,i);
            ans[j.second]=tr.GetAns(1,1,n,j.first,i);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}

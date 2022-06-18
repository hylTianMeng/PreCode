#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 40010
#define M 400010
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

struct Node{
    int Sum,PreSum,SufSum;
    inline Node(){}
    inline Node(int Sum,int PreSum,int SufSum) : Sum(Sum),PreSum(PreSum),SufSum(SufSum) {}
    inline Node operator + (const Node &b)const{
        Node c(0,0,0);
        c.Sum=Sum+b.Sum;
        c.PreSum=Max(PreSum,Sum+b.PreSum);
        c.SufSum=Max(b.SufSum,b.Sum+SufSum);return c;
    }
}p[M];

int Root[N],rtt,tot,Ls[M],Rs[M];

#define ls(k) Ls[k]
#define rs(k) Rs[k]
struct SegmentTree{
    inline int NewNode(){return ++tot;}
    inline void PushUp(int k){p[k]=p[ls(k)]+p[rs(k)];}
    inline void Build(int &k,int l,int r){
        k=NewNode();
        if(l==r){
            p[k]=Node(1,1,1);return;
        }
        int mid=(l+r)>>1;
        Build(ls(k),l,mid);Build(rs(k),mid+1,r);
        PushUp(k);
    }
    inline void Insert(int &k,int last,int l,int r,int w,int x){
        k=NewNode();p[k]=p[last];ls(k)=ls(last);rs(k)=rs(last);
        if(l==r){
            p[k]=Node(x,x,x);return;
        }
        int mid=(l+r)>>1;
        if(w<=mid) Insert(ls(k),ls(last),l,mid,w,x);
        else Insert(rs(k),rs(last),mid+1,r,w,x);
        PushUp(k);
    }
    inline Node AskMax(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k];
        int mid=(l+r)>>1;
        if(y<=mid) return AskMax(ls(k),l,mid,z,y);
        else if(z>mid) return AskMax(rs(k),mid+1,r,z,y);
        else return AskMax(ls(k),l,mid,z,mid)+AskMax(rs(k),mid+1,r,mid+1,y);
    }
}tr;

int n,Q,a[N],b[N],len,rk[N];
vector<int> v[N];

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);b[i]=a[i];
    }
    sort(b+1,b+n+1);
    len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++){
        int Rank=lower_bound(b+1,b+n+1,a[i])-b;
        rk[Rank]=a[i];a[i]=Rank;v[a[i]].push_back(i);
    }
    tr.Build(Root[1],1,n);rtt=1;
    for(int i=2;i<=len;i++){
        // printf("i=%d\n",i);
        rtt++;int last=Root[rtt-1];
        for(int now:v[i-1]){
            // printf("now=%d\n",now);
            tr.Insert(Root[rtt],last,1,n,now,-1);
            last=Root[rtt];
        }
        // printf("%d\n",p[Root[rtt]].Sum);
    }
    // printf("rtt=%d\n",rtt);
    // for(int i=0;i<=rtt;i++) printf("%d ",Root[i]);puts("");
    // for(int i=0;i<=rtt;i++){
    //     printf("p[%d].sum=%d\n",Root[i],p[Root[i]].Sum);
    // }
}

inline bool Check(int mid,int a,int b,int c,int d){
    // printf("mid=%d a=%d b=%d c=%d d=%d\n",mid,a,b,c,d);
    Node Max1=tr.AskMax(Root[mid],1,n,a,b);
    Node Max2=tr.AskMax(Root[mid],1,n,c,d);
    Node Max3(0,0,0);
    if(b+1<=c-1) Max3=tr.AskMax(Root[mid],1,n,b+1,c-1);
    // printf("Max1.sum=%d\n",Max1.SufSum);
    // printf("Max2.sum=%d\n",Max2.PreSum);
    // printf("Max3.sum=%d\n",Max3.Sum);
    return Max1.SufSum+Max3.Sum+Max2.PreSum>=0;
}

inline int Binary(int a,int b,int c,int d){
    int l=1,r=len,ans=1;
    // printf("%d %d %d %d\n",a,b,c,d);exit(0);
    while(l<=r){
        int mid=(l+r)>>1;
        if(Check(mid,a,b,c,d)){
            ans=mid;l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

int Ans,P[6];

inline void Solve(){
    read(Q);
    for(int i=1;i<=Q;i++){
        read(P[0]);read(P[1]);
        read(P[2]);read(P[3]);
        for(int j=0;j<=3;j++) P[j]=(P[j]+Ans)%n;
        for(int j=0;j<=3;j++) P[j]++;
        sort(P,P+4);
        int ans=Binary(P[0],P[1],P[2],P[3]);
        // printf("ans=%d\n",ans);
        Ans=rk[ans];
        printf("%d\n",Ans);
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    Solve();
}
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

int n,a[N],b[N],m,ans[N],posi[N],Len;

struct Ques{
    int l,r,id;
}ques[N];
vector<int> q1[N],q2[N];

typedef pair<int,int> P;

struct Queue{
    int minn[N],maxx[N],top,Ans;
    pair<P,P> Stack[N];
    inline void Init(int l,int r){
        for(int i=l;i<=r;i++){minn[a[i]]=INF;maxx[a[i]]=-INF;}
        Ans=0;
    }
    inline void Add(int k){
        Stack[++top]=make_pair(make_pair(k,Ans),make_pair(minn[a[k]],maxx[a[k]]));
        minn[a[k]]=min(minn[a[k]],k);
        maxx[a[k]]=max(maxx[a[k]],k);
        Ans=max(Ans,maxx[a[k]]-minn[a[k]]);
    }
    inline void RollOnce(){
        int k=Stack[top].first.first;
        minn[a[k]]=Stack[top].second.first;
        maxx[a[k]]=Stack[top].second.second;
        Ans=Stack[top].first.second;top--;
    }
    inline void RollBack(){
        while(top) RollOnce();
    }
}q;

inline void Solve1(){
    for(int i=1;i<=posi[n];i++){
        // printf("i=%d size=%d\n",i,(int)q1[i].size());
        for(int j:q1[i]){
            q.Init(ques[j].l,ques[j].r);
            for(int k=ques[j].l;k<=ques[j].r;k++) q.Add(k);
            ans[ques[j].id]=q.Ans;
            q.RollBack();
        }
    }
}

inline bool cmp(int a,int b){
    return ques[a].r<ques[b].r;
}

inline void Solve2(){
    for(int i=1;i<=posi[n];i++){
        sort(q2[i].begin(),q2[i].end(),cmp);
        int l=i*Len+1,r=i*Len;
        q.Init((i-1)*Len+1,n);
        for(int j:q2[i]){
            int nl=l;
            while(r<ques[j].r) q.Add(++r);
            q.top=0;
            while(ques[j].l<nl) q.Add(--nl);
            ans[ques[j].id]=q.Ans;
            q.RollBack();
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
    sort(b+1,b+n+1);int len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
    Len=sqrt(n)+1;
    // printf("Len=%d\n",Len);
    for(int i=1;i<=n;i++) posi[i]=(i-1)/Len+1;
    read(m);
    for(int i=1;i<=m;i++){
        read(ques[i].l);read(ques[i].r);ques[i].id=i;
        if(posi[ques[i].l]==posi[ques[i].r]) q1[posi[ques[i].l]].push_back(i);
        else q2[posi[ques[i].l]].push_back(i);
    }
    Solve1();Solve2();
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
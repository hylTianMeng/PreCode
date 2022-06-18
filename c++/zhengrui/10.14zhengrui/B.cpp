#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

int Prime[N],tail,Mu[N],n,a[N],Q,qcnt,ans[N],c[N];
bool NotPrime[N];

struct Ques{
    int r,x,type,id;
    inline Ques(){}
    inline Ques(int r,int x,int type,int id) : r(r),x(x),type(type),id(id) {}
    inline bool operator < (const Ques &b)const{return r<b.r;}
}ques[N<<1];

inline void GetMu(int n){
    NotPrime[1]=1;Mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!NotPrime[i]) Prime[++tail]=i,Mu[i]=-1;
        for(int j=1;j<=tail&&Prime[j]*i<=n;j++){
            NotPrime[i*Prime[j]]=1;
            if(i%Prime[j]==0) break;
            else Mu[i*Prime[j]]=-Mu[i];
        }
    }
}

inline void Init(){
    read(n);read(Q);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=Q;i++){
        int l,r,x;read(l);read(r);read(x);
        if(l-1>0) ques[++qcnt]=Ques(l-1,x,-1,i);
        ques[++qcnt]=Ques(r,x,1,i);
    }
    sort(ques+1,ques+qcnt+1);
}

inline void Insert(int x){
    int i;for(i=1;i*i<x;i++) if(x%i==0){c[i]++;c[x/i]++;}if(i*i==x) c[i]++;
}

inline int Query(int x){
    int i,nowans=0;
    for(i=1;i*i<x;i++) if(x%i==0){nowans+=Mu[i]*c[i];nowans+=Mu[x/i]*c[x/i];}if(i*i==x) nowans+=Mu[i]*c[i];
    return nowans;
}

inline void Solve(){
    for(int i=1,j=0;i<=n;i++){
        Insert(a[i]);
        while(j+1<=qcnt&&ques[j+1].r<=i){j++;ans[ques[j].id]+=Query(ques[j].x)*ques[j].type;}
    }
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    GetMu(100000);
    Init();Solve();
}
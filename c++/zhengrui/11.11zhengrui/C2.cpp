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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){to=to_;next=ne_;}
}a[N];int head[N],tail;

inline void Add(int from,int to){
    a[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,c[N],li[N],ri[N],nex[N],las[23][N],Posi[N],MaxC,Q,lg[N];
bool fl=1;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        scanf("%d",&c[i]);;MaxC=Max(MaxC,c[i]);
    }
    for(int i=1;i<=n;++i){
        int x;scanf("%d",&x);
        for(int j=1;j<=x;++j){
            int now;scanf("%d",&now);Add(i,now);MaxC=Max(MaxC,now);
        }
    }
    for(int i=1;i<=n;++i){
        for(int x=head[i];x;x=a[x].next){
            int to=a[x].to;Posi[to]=i;
        }
        las[0][i]=Posi[c[i]];
    }
    for(int i=0;i<=MaxC;++i) Posi[i]=n+1;
    for(int i=n;i>=1;--i){
        for(int x=head[i];x;x=a[x].next){
            int to=a[x].to;Posi[to]=i;
        }
        nex[i-1]=Posi[c[i-1]];
    }
    for(int i=0;i<=n+1;++i) if(!nex[i]) nex[i]=n+1;
    for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	lg[0]=-1;
    for(int i=1;i<=lg[n-1];++i)for(int j=1;j+(1<<u<n-(1<<j)+1;++j) las[i][j]=Min(las[i-1][j],las[i-1][j+(1<<i-1)]);
    for(int i=1;i<=n;++i){
        li[i]=ri[i]=i;
        do{
            fl=0;
            if(nex[li[i]-1]<=ri[i])li[i]=li[li[i]-1],fl=1;
            for(int j=lg[n-ri[i]];j>=0;--j)if(las[j][ri[i]]>=li[i])ri[i]+=(1<<j),fl=1;
        }while(fl);
    }
}
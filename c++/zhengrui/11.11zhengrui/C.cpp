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
}li[N];int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

int n,c[N],L[N],R[N],Next[N],Pre[23][N],Posi[N],MaxC,Q,lg2[N];
bool op=1;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&c[i]);;MaxC=Max(MaxC,c[i]);
    }
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int now;scanf("%d",&now);Add(i,now);MaxC=Max(MaxC,now);
        }
    }
    for(int i=1;i<=n;i++){
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;Posi[to]=i;
        }
        Pre[0][i]=Posi[c[i]];
    }
    for(int i=0;i<=MaxC;i++) Posi[i]=n+1;
    for(int i=n;i>=1;i--){
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;Posi[to]=i;
        }
        Next[i-1]=Posi[c[i-1]];
    }
    for(int i=0;i<=n+1;i++) if(!Next[i]) Next[i]=n+1;
    lg2[0]=-1;for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    for(int i=1;i<=lg2[n-1];i++){
        for(int j=1;j<n-(1<<i)+1;j++) Pre[i][j]=Min(Pre[i-1][j],Pre[i-1][j+(1<<(i-1))]);
    }
    for(int i=1;i<=n;i++){
        L[i]=R[i]=i;
        do{
            op=0;
            if(Next[L[i]-1]<=R[i]){L[i]=L[L[i]-1];op=1;}
            for(int j=lg2[n-R[i]];j>=0;j--) if(Pre[j][R[i]]>=L[i]){R[i]+=(1<<j);op=1;}
            assert(L[i]&&R[i]);
        }while(op);
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){int x,y;scanf("%d%d",&x,&y);if(L[x]<=y&&y<=R[x]) puts("YES");else puts("NO");}
    return 0;
}
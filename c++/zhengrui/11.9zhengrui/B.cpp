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

inline int GetMid(int a,int b,int c){
    if(a>b) swap(a,b);if(b>c) swap(b,c);if(a>b) swap(a,b);
    return b;
}

int b[N],t,n,a[N][3],Pre[N][3][3],ans[N];
bool f[N][3][3];

inline void Clear(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++) for(int k=0;k<=2;k++){
            f[i][j][k]=0;Pre[i][j][k]=-1;
        }
    }
}

inline void Init(){
    read(n);
    for(int i=3;i<=n;i++) read(b[i]);
    b[1]=b[2]=b[3];
    b[n+1]=b[n+2]=b[n];
    for(int i=1;i<=n;i++){
        a[i][0]=b[i];a[i][1]=b[i+1];a[i][2]=b[i+2];
        // printf("a[%d][0]=%d a[%d][1]=%d a[2][%d]=%d\n",i,a[i][0],i,a[i][1],i,a[i][2]);
    }
    for(int i=1;i<=2;i++) for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) f[i][j][k]=1;
}

inline void Solve(){
    for(int i=3;i<=n;i++)
        for(int j=0;j<=2;j++)
            for(int k=0;k<=2;k++){
                if(!f[i-1][k][j]) continue;
                for(int l=0;l<=2;l++){
                    if(GetMid(a[i][l],a[i-1][k],a[i-2][j])!=b[i]) continue;
                    f[i][l][k]=1;Pre[i][l][k]=j;
                    // printf("f[%d][%d][%d]=%d\n",i-1,k,j,f[i-1][k][j]);
                    // printf("f[%d][%d][%d]=%d\n",i,l,k,f[i][l][k]);
                    // printf("Pre[%d][%d][%d]=%d\n",i,l,k,Pre[i][l][k]);
                }
            }
    int nowj=-1,nowk=-1;
    for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) if(f[n][j][k]){nowj=j;nowk=k;break;}
    // printf("nowj=%d nowk=%d\n",nowj,nowk);
    if(nowj==-1&&nowk==-1) return(void)puts("-1");
    int now=n;
    while(nowj!=-1&&nowk!=-1){
        ans[now]=a[now][nowj];
        // printf("a[%d][%d]=%d\n",now,nowj,a[now][nowj]);
        int Next=Pre[now][nowj][nowk];nowj=nowk;nowk=Next;now--;
        // printf("Next=%d\n",Next);
        if(Next==-1){
            ans[now]=a[now][nowk];break;
        }
    }
    ans[1]=b[1];
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    memset(f,0,sizeof(f));memset(Pre,-1,sizeof(Pre));
    read(t);
    while(t--){
        Init();Solve();Clear();
    }
    return 0;
}
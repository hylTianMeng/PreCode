#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
#define M 40010
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int n,m,t,lim,f[N],g[N],h[M][4],ans[N],F[N][M],b[N];
char s[N];

inline int ID(char c){
    if(c=='A') return 0;else if(c=='C') return 1;else if(c=='G') return 2;else if(c=='T') return 3;
    assert(0);return -1;
}

inline char InvID(int x){
    if(x==0) return 'A';else if(x==1) return 'C';else if(x==2) return 'G';else if(x==3) return 'T';
    assert(0);return -1;
}

inline void Init(){
    scanf("%s",s+1);read(m);n=strlen(s+1);lim=(1<<n)-1;
}

inline int TRANS(int S,char c){
    for(int i=0;i<=n-1;i++) f[i+1]=(S>>i)&1;
    for(int i=1;i<=n;i++) f[i]+=f[i-1];
    for(int i=1;i<=n;i++){
        if(s[i]==c){
            g[i]=f[i-1]+1;
        }
        else g[i]=Max(g[i-1],Max(f[i],f[i-1]));
    }
    for(int i=1;i<=n;i++) b[i]=g[i];
    for(int i=1;i<=n;i++) g[i]=g[i]-b[i-1];
    int now=0;
    for(int i=1;i<=n;i++) if(g[i]) now|=(1<<(i-1));
    return now;
}

inline void GetPre(){
    for(int i=0;i<=lim;i++){
        for(int j=0;j<=3;j++){
            h[i][j]=TRANS(i,InvID(j));
            // printf("h[%d][%d]=%d\n",i,j,h[i][j]);
        }
    }
}

inline void Solve(){
    F[0][0]=1;
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=lim;j++){
            // printf("F[%d][%d]=%d\n",i,j,F[i][j]);
            if(!F[i][j]) continue;
            for(int k=0;k<=3;k++){
                (F[i+1][h[j][k]]+=F[i][j])%=mod;
            }
        }
    }
    for(int i=0;i<=lim;i++){
        // printf("F[%d][%d]=%d\n",m,i,F[m][i]);
        (ans[__builtin_popcount(i)]+=F[m][i])%=mod;
    }
}

inline void Print(){
    for(int i=0;i<=n;i++){
        printf("%d\n",ans[i]);
    }
}

inline void Clear(){
    fill(ans,ans+n+1,0);
    memset(F,0,sizeof(F));
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();GetPre();Solve();Print();Clear();
    }
    return 0;
}
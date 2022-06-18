#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 4010
#define M number
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

struct edge{
    int from,to,next;
    inline void Init(int fr_,int to_,int ne_){
        from=fr_;to=to_;next=ne_;
    }
}li[N<<1];
int head[N],tail=1;

inline void Add(int from,int to){
    li[++tail].Init(from,to,head[from]);
    head[from]=tail;
}

int d[N][N][2],Dep[N],sum[N][N][2],Root,n,m,Tag,TwoPow[N];

inline int ksm(int a,int b,int mod){
    int res=1;while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

inline void dfs(int k,int fa,int op){
    Dep[k]=Dep[fa]+1;d[Root][Dep[k]][op]++;
    for(int x=head[k];x;x=li[x].next){
        int to=li[x].to;
        if(Tag==x||(Tag^1)==x) continue;
        if(to==fa) continue;
        dfs(to,k,op);
    }
}

inline void Init(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int from,to;read(from);read(to);
        Add(from,to);Add(to,from);
    }
    Dep[0]=-1;
    for(int i=2;i<=tail;i++){
        Tag=i;Root=i;dfs(li[i].from,0,0);dfs(li[i].to,0,1);
        sum[i][0][0]=d[i][0][0];sum[i][0][1]=d[i][0][1];
        for(int j=1;j<=n;j++){
            sum[i][j][0]=sum[i][j-1][0]+d[i][j][0];
            sum[i][j][1]=sum[i][j-1][1]+d[i][j][1];
        }
        // printf("li[%d].from=%d li[%d].to=%d\n",i,li[i].from,i,li[i].to);
        // for(int j=1;j<=n;j++){
        //     printf("d[%d][%d][0]=%d d[%d][%d][1]=%d\n",i,j,d[i][j][0],i,j,d[i][j][1]);
        // }
    }
    TwoPow[0]=1;
    for(int i=1;i<=n;i++) TwoPow[i]=1ll*TwoPow[i-1]*2%mod;
}

inline void Solve(){
    read(m);
    for(int i=1;i<=m;i++){
        int di;read(di);
        int Ans=0;
        if(di&1){
            int len=di/2;
            for(int j=2;j<=tail;j+=2){
                int n1=d[j][len][0];
                int n2=d[j][len][1];
                int m=0;
                if(len>=1) (m+=sum[j][len-1][0]+sum[j][len-1][1])%=mod;
                Ans=(Ans+1ll*(TwoPow[n1]-1)*(TwoPow[n2]-1)%mod*TwoPow[m])%mod;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                int sum1=0,sum2=1;
                for(int x=head[i];x;x=li[x].next){
                    // sum1=(sum1+d[x][di/2-1][1]);
                    if(di/2>=2) sum2=(sum2+sum[x][di/2-2][1])%mod;
                }
                int now=1;
                for(int x=head[i];x;x=li[x].next){
                    // now=(now+1ll*(sum1-d[x][di/2-1][1])*d[x][di/2-1][1]%mod)%mod;
                    // now=1ll*now*(d[x][di/2-1][1]+1);
                    now=1ll*now*((TwoPow[d[x][di/2-1][1]]-1)+1)%mod;
                    (sum1+=(TwoPow[d[x][di/2-1][1]]-1))%=mod;
                }
                now--;now-=sum1;
                Ans=(Ans+1ll*now*TwoPow[sum2]%mod)%mod;
            }
        }
        printf("%d\n",(Ans%mod+mod)%mod);
    }
}

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();Solve();
    return 0;
}
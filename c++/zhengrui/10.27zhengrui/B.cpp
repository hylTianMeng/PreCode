#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Operation{
    int op,id,val;
    inline Operation(){}
    inline Operation(int op,int id,int val) : op(op),id(id),val(val) {}
}o[N];

int k,n,m,a[N],Cover[N],ans=1;
bool is_Cover[N];
vector<int> v[N];

struct Node{
    ld val;Operation ope;
    inline Node(){}
    inline Node(ld val,Operation ope) : val(val),ope(ope) {}
    inline bool operator < (const Node &b)const{return val>b.val;}
};
vector<Node> v2;

inline bool Cmp(int a,int b){return a>b;}

inline void Init(){
    memset(Cover,-INF,sizeof(Cover));
    read(k);read(n);read(m);
    for(int i=1;i<=k;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        read(o[i].op);read(o[i].id);read(o[i].val);
        if(o[i].op==2){v[o[i].id].push_back(o[i].val);}
        else if(o[i].op==1){is_Cover[o[i].id]=1;Cover[o[i].id]=Max(Cover[o[i].id],o[i].val);}
        else if(o[i].op==3){v2.push_back(Node((ld)o[i].val,o[i]));}
    }
    for(int i=1;i<=k;i++){
        // printf("Cover[%lld]=%lld\n",i,Cover[i]);
    }
    for(int i=1;i<=k;i++){
        if(!is_Cover[i]) continue;
        v[i].push_back(Cover[i]-a[i]);
    }
    // printf("val=%lld\n",(int)v2[0].val);
    for(int i=1;i<=k;i++){
        // printf("i=%d\n",i);
        sort(v[i].begin(),v[i].end(),Cmp);
        // for(int j=0;j<v[i].size();j++) printf("%d ",v[i][j]);puts("");
    }
    for(int i=1;i<=k;i++){
        int sum=a[i];
        for(int j=0;j<v[i].size();j++){
            int now=sum+v[i][j];
            v2.push_back(Node(1+(ld)v[i][j]/(ld)sum,Operation(2,i,v[i][j])));
            sum=now;
        }
    }
    sort(v2.begin(),v2.end());
    // for(int i=0;i<v2.size();i++) printf("%Lf ",v2[i].val);puts("");
    for(int i=0;i<v2.size()&&i<m;i++){
        Node now=v2[i];
        if(now.val<1) break;
        if(now.ope.op==3) ans=1ll*ans*now.ope.val%mod;
        else if(now.ope.op==2) (a[now.ope.id]+=now.ope.val)%=mod;
    }
    for(int i=1;i<=k;i++) ans=1ll*ans*a[i]%mod;
    printf("%lld",ans);
}

signed main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    Init();
}
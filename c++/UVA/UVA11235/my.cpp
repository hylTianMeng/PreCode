#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define mul(a,b) 1ll*(a)*(b)%mod
#define sgn(a) (((a)&1)?(mod-1):1)
#define cmax(a,b) (((a)<(b))?(a=b):(a))
#define cmin(a,b) (((a)>(b))?(a=b):(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 500010
#define M 710
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//#define int long long
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,m,a[N],ans,len,posi[N],L[N],R[N],t,cnt[N],b[N],f[M][M],id[N];
vi v[N];

inline void Clear(){
    rep(i,1,posi[n])rep(j,1,posi[n])f[i][j]=0;rep(i,1,n) v[i].clear(),id[i]=0;
    rep(i,1,n) L[i]=R[i]=cnt[i]=b[i]=0;
    n=0;m=0;rep(i,1,n) a[i]=0;ans=0;len=0;rep(i,1,n) posi[i]=0;
}

int main(){
    freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    while(scanf("%d",&n)!=EOF&&n){
        // printf("here\n");
        read(m);rep(i,1,n) read(a[i]),a[i]+=100000,b[i]=a[i];
        sort(b+1,b+n+1);len=unique(b+1,b+n+1)-b-1;rep(i,1,n) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
        len=sqrt(n)+1;
        rep(i,1,n) posi[i]=(i-1)/len;
        rep(i,1,n){
            if(!L[posi[i]]) L[posi[i]]=i;
            R[posi[i]]=i;
        }
        int maxx=0;
        rep(i,1,posi[n]){
            int l=L[i];maxx=0;
            rep(i,1,n) cnt[i]=0;
            rep(j,i,posi[n]){
                rep(k,l,R[j]) cnt[a[k]]++,maxx=max(maxx,cnt[a[k]]);
                l=R[j]+1;f[i][j]=maxx;
            }
        }
        rep(i,1,n) v[a[i]].pb(i),id[i]=v[a[i]].size()-1;
        rep(i,1,m){
            int l,r;read(l);read(r);
            int lp=posi[l]+1;int rp=posi[r]-1;
            ans=f[lp][rp];
            dec(j,l,R[posi[l]]){
                int nowid=id[j]+ans;
                if((int)v[a[j]].size()-1>=nowid&&v[a[j]][nowid]<=r) ans++;
            }
            rep(j,L[posi[r]],r){
                int nowid=id[j]-ans;
                if(nowid>=0&&v[a[j]][nowid]>=l) ans++;
            }
            printf("%d\n",ans);
        }
        Clear();
    }
    return 0;
}
#include<bits/stdc++.h>
#define mset(a,b) memset((a),(b),sizeof((a)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dec(i,l,r) for(int i=(r);i>=(l);i--)
#define inc(a,b) (((a)+(b))>=mod?(a)+(b)-mod:(a)+(b))
#define sub(a,b) (((a)-(b))<0?(a)-(b)+mod:(a)-(b))
#define sgn(a) (((a)&1)?(mod-1):1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define N 1000100
#define M number
using namespace std;

typedef double dd;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;

const int INF=0x3f3f3f3f;
const dd eps=1e-9;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

char s[N],t[N];
int f[N][2],T,n;
int op;

inline int dfs(int posi,int lim){
    if(posi==((n+1)/2)+1){
        if(lim) return op;
        else return 1;
    }
    if(f[posi][lim]!=-1) return f[posi][lim];
    int up=(lim==1)?(s[posi]-'A'):(25);
    int ans=0;
    rep(i,0,up){
        ans=inc(ans,dfs(posi+1,lim&&(i==up)));
    }
    f[posi][lim]=ans;
    return ans;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(T);
    mset(f,-1);
    while(T--){
        read(n);
        scanf("%s",s+1);
        rep(i,1,n) t[i]=s[i];
        reverse(t+1,t+n+1);
        bool pd=1;
        dec(i,1,n/2){
            if(s[i]!=t[i]){if(s[i]<t[i]){pd=1;break;}else{pd=0;break;}}
        } 
        op=pd;
        printf("%d\n",dfs(1,1));
        rep(i,1,n) f[i][0]=f[i][1]=-1;
    }
    return 0;
}
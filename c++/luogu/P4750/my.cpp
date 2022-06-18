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
#define N 6010
#define M number
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
const int mod=2500;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,a[N][N],b[N][N];
char s[2];
bool vis[N][N][4];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    rep(i,1,n){
        int x,y,d;
        scanf("%s",s);read(x);read(y);read(d);
        // cout<<s<<endl;
        if(s[0]=='A'){
            a[x+d/2+mod][y-d/2+mod]++;
            a[x-d/2+mod][y+d/2+mod]++;
            a[x-d/2+mod][y-d/2+mod]--;
            a[x+d/2+mod][y+d/2+mod]--;
        }
        else{
            int dx,dy;
            dx=x+d/2;dy=y;
            b[dx+dy+mod][dy-dx+mod]++;
            dx=x-d/2;dy=y;
            b[dx+dy+mod][dy-dx+mod]++;
            dx=x;dy=y+d/2;
            b[dx+dy+mod][dy-dx+mod]--;
            dx=x;dy=y-d/2;
            b[dx+dy+mod][dy-dx+mod]--;
        }
    }
    dec(i,1,N-10){
        rep(j,1,N-10){
            a[i][j]+=a[i+1][j]+a[i][j-1]-a[i+1][j-1];
            b[i][j]+=b[i+1][j]+b[i][j-1]-b[i+1][j-1];
            // printf("%d ",a[i][j]);
        }
        // puts("");
    }
    rep(i,1,N-10)rep(j,1,N-10){
        if(a[i][j]){
            rep(k,0,3){
                vis[i][j][k]=1;
                // printf("vis[%d][%d][%d]=%d\n",i,j,k,vis[i][j][k]);
            }
        }
    }
    rep(i,1,N-10)rep(j,1,N-10){
        if(!b[i][j]) continue;
        int x=i-mod,y=j-mod;
        if((x+y)%2==0){
            int dx=(x-y)/2,dy=(x+y)/2;
            dx+=mod;dy+=mod;
            // printf("dx=%d dy=%d\n",dx,dy);
            vis[dx][dy][2]=1;
            dy--;
            vis[dx][dy][0]=1;
        }
        else{
            // printf("x=%d y=%d\n",x,y);
            dd dx=(dd)(x-y)/2,dy=(dd)(x+y)/2;
            dx+=mod;dy+=mod;
            // printf("dx=%d.5 dy=%d.5\n",dx,dy);
            int fx=dx,fy=dy;
            vis[fx][fy][1]=1;
            fx++;
            vis[fx][fy][3]=1;   
        }
    }
    // puts("");
    int cnt=0;
    rep(i,1,N-10)rep(j,1,N-10){
        rep(k,0,3) if(vis[i][j][k]){
            cnt++;
            // printf("vis[%d][%d][%d]=%d\n",i,j,k,vis[i][j][k]);
        }
    }
    printf("%d",cnt/4);
    int d=cnt%4;
    if(d==1){
        puts(".25");
    }
    else if(d==2) puts(".50");
    else if(d==3) puts(".75");
    else puts(".00");
    return 0;
}
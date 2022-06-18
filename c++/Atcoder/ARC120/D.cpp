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
#define N 600010
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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n;
P a[N],b[N];
bool vis[N];

int sta[N],top;
int ans[N];

int main(){
    read(n);n<<=1;
    rep(i,1,n){
        read(a[i].fi);a[i].se=i;b[i]=a[i];
    }
    sort(b+1,b+n+1);P mid=b[n/2];
    rep(i,1,n) if(a[i]<=mid) vis[i]=1;else vis[i]=0;
    rep(i,1,n){
        if(vis[sta[top]]==vis[i]||top==0) sta[++top]=i;
        else{ans[sta[top]]=1;ans[i]=-1;top--;}
    }
    rep(i,1,n) if(ans[i]>0) putchar('(');else putchar(')');
    return 0;
}

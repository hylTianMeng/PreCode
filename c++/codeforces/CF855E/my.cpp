#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100
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

int w[N],t,tt,b,l,r;
int f[N][1<<12][11];

inline int Solve(int p,int S,int b,int lim,int pre){
    // printf("p=%lld S=%lld b=%lld lim=%lld pre=%lld\n",p,S,b,lim,pre);
    if(p==0){
        if(S==0&&!pre) return 1;
        return 0;
    }
    if(!lim&&!pre&&f[p][S][b]!=-1) return f[p][S][b];
    int up=(lim==1)?w[p]:(b-1),ans=0;
    for(int i=1;i<=up;i++){
        ans+=Solve(p-1,S^(1<<i),b,lim&&(i==up),0);
    }
    if(pre) ans+=Solve(p-1,S,b,0,1);
    else ans+=Solve(p-1,S^1,b,lim&&(up==0),0);
    if(!lim&&!pre) f[p][S][b]=ans;
    return ans;
}

inline int Work(int k){
    t=0;
    while(k){
        w[++t]=k%b;k/=b;
    }
    return Solve(t,0,b,1,1); 
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    memset(f,-1,sizeof(f));
    read(tt);
    while(tt--){
        read(b);read(l);read(r);
        printf("%lld\n",Work(r)-Work(l-1));
    }
    return 0;
}
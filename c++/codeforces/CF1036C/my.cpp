#include<bits/stdc++.h>
#define dd double
#define ld long double
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20
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

int t,L,R,w[N],wt;
int f[N][N];

inline int Solve(int p,int num,int lim,int pre){
    if(p==0){
        if(num<=3&&!pre) return 1;
        return 0;
    }
    if(num>3) return (f[p][num]=0);
    if(!lim&&!pre&&f[p][num]!=-1) return f[p][num];
    int up=(lim==1)?w[p]:9,ans=0;
    for(int i=1;i<=up;i++){
        ans+=Solve(p-1,num+1,lim&&(i==up),0);
    }
    if(pre){
        ans+=Solve(p-1,num,0,1);
    }
    else{
        ans+=Solve(p-1,num,lim&&(0==up),0);
    }
    if(!lim&&!pre) f[p][num]=ans;
    return ans;
}

inline int Work(int k){
    wt=0;
    while(k){
        w[++wt]=k%10;k/=10;
    }
    return Solve(wt,0,1,1);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    memset(f,-1,sizeof(f));
    while(t--){
        read(L);read(R);
        // printf("%lld\n",Work(R));
        // printf("%lld\n",Work(L-1));
        printf("%lld\n",Work(R)-Work(L-1));
    }
    return 0;
}
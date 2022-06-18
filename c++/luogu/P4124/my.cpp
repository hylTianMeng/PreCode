#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 15
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

int L,R,w[N],t;
int f[N][N][10][2][2][2];

inline int Solve(int p,int cnt,int num,int eight,int four,int threecon,int lim){
    if(p==0){
        if((!eight||!four)&&threecon) return 1;
        return 0;
    }
    int up=(lim==1)?w[p]:9,ans=0;
    if(!lim&&f[p][cnt][num][eight][four][threecon]!=-1) return f[p][cnt][num][eight][four][threecon];
    for(int i=1;i<=up;i++){
        if(i==num){
            ans+=Solve(p-1,cnt+1,num,eight||(i==8),four||(i==4),threecon||(cnt+1>=3),lim&&(i==up));
        }
        else{
            ans+=Solve(p-1,1,i,eight||(i==8),four||(i==4),threecon,lim&&(i==up));
        }
    }
    if(p==t){}
    else{
        if(num==0) ans+=Solve(p-1,cnt+1,num,eight,four,threecon||(cnt+1>=3),lim&&(up==0));
        else ans+=Solve(p-1,1,0,eight,four,threecon,lim&&(up==0));
    }
    if(!lim) f[p][cnt][num][eight][four][threecon]=ans;
    return ans;
}

inline int Work(int k){
    t=0;
    while(k){
        w[++t]=k%10;k/=10;
    }
    if(t!=11) return 0;
    return Solve(t,0,-1,0,0,0,1);
}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(L);read(R);
    memset(f,-1,sizeof(f));
    // printf("%lld\n",Work(R));
    // printf("%lld\n",Work(L-1));
    printf("%lld\n",Work(R)-Work(L-1));
    return 0;
}
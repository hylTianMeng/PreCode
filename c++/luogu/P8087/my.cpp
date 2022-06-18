#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 4000100
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

int n,a[N],f[N],pos[N],maxx[N],minn[N],g[N];

int main(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(f[i]);
    for(int i=1;i<=n;i++){
        pos[a[i]]=i;
    }
    maxx[0]=0;minn[0]=INF;
    for(int i=1;i<=n;i++){
        maxx[i]=max(maxx[i-1],pos[i]);
        minn[i]=min(minn[i-1],pos[i]);
    }
    for(int i=1;i<=n;i++) g[i]=maxx[i]-minn[i]+1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f[i]<=n&&g[f[i]]<=i){
            ans=i;break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
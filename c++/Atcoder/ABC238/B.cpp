#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000
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

int n,a[N],b[N],tot,now=0,cnt[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        tot++;
        int End=(now+a[i])%360;
        int val=b[End];
        for(int j=now;j<=360+now;j++){
            int nowj=j%360;
            if(nowj==End) break;
            if(b[nowj]==val) b[nowj]=tot;
        }
        now=End;
        // for(int i=0;i<=359;i++) printf("%d ",b[i]);puts("");
    }
    for(int i=0;i<=359;i++) cnt[b[i]]++;
    int maxx=-INF;
    for(int j=0;j<=360;j++) maxx=max(maxx,cnt[j]);
    printf("%d\n",maxx);
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

int t,n,p[N],a[N],head,cnt;

int main(){
    // freopen("my.in","r",stdin);
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(p[i]);
        for(int i=1;i<=n;i++) a[p[i]]=i;
        head=n;cnt=0;
        for(int i=n;i>=1;i--){
            if(a[i]>head) continue;
            while(p[head]>i&&head>1){
                head--;cnt++;
            }
            int minn=INF;
            while(p[head]!=i&&head>1){
                minn=min(minn,p[head]);head--;
            }
            minn=min(minn,i);p[head]=minn;
        }
        printf("%d\n",cnt+head);
    }
    return 0;
}
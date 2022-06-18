#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2010
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

int cnt[N];
int a[N][N],n,t,q;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++) read(a[0][i]);
}

inline void Change(int id){
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[a[id-1][i]]++;
    for(int i=1;i<=n;i++) a[id][i]=cnt[a[id-1][i]];
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();
        for(int i=1;i<=2000;i++) Change(i);
        read(q);
        for(int i=1;i<=q;i++){
            int x,k;read(x);read(k);
            if(k>2000) k=2000;
            printf("%d\n",a[k][x]);
        }
    }
}
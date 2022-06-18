#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 200010
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

int n,a[N],b[N],c[N];

int cha[N];

int main(){
    read(n);
    rep(i,1,n) read(a[i]);rep(i,1,n) read(b[i]);
    rep(i,1,n) if(b[i]) cha[i]=i-b[i]+1;
    int maxx=-INF;
    rep(i,1,n) maxx=max(maxx,cha[i]);

    int p=n;while(b[p]){p--;if(b[p+1]==1) break;}
    p++;
    bool op=1;
    for(int i=p;i<=n&&op;i++){
        if(b[i]!=i-p+1) op=0;
    }
    // printf("p=%d\n",p);
    int maxx2=0;
    for(int i=1;i<=p-1;i++){
        if(!b[i]) continue;
        maxx2=max(maxx2,i-(b[i]-(n-p+1))+1);
    }
    // printf("maxx=%d\n",maxx);

    if(op&&maxx2==0){
        printf("%d\n",p-1);return 0;
    }
    
    printf("%d\n",maxx+n);
    return 0;
}
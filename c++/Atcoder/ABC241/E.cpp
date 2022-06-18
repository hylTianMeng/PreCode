#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
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

int n,k,a[N];

int sum[N],b[N];
int tot;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(k);for(int i=0;i<=n-1;i++) read(a[i]);
    int X=0;
    int nowk=k;
    while(b[X%n]==0&&nowk){
        nowk--;
        ++tot;sum[tot]=X;b[X%n]=tot;
        X+=a[X%n];
        // printf("X=%lld\n",X);
    }
    if(!nowk){
        printf("%lld\n",X);return 0;
    }
    int m=X%n;
    // printf("m=%d\n",m);
    int s1=X-sum[b[m]];
    // printf("s1=%d\n",s1);
    int t1=tot-b[m]+1;
    // printf("t1=%d\n",t1);
    int t2=b[m]-1;
    k-=t2;
    // printf("t2=%d\n",t2);
    int chu=k/t1;
    int yu=k%t1;
    // printf("chu=%d yu=%d\n",chu,yu);
    int ans=sum[b[m]]+chu*s1;

    int now=m;

    while(yu){
        yu--;
        ans+=a[ans%n];
    }
    printf("%lld\n",ans);
    return 0;
}
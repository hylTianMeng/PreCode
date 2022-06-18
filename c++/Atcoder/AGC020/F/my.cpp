#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 310
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

int n,c,l[N];
dd Ans,ans1,ans2,f[N][N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(c);for(int i=1;i<=n;i++) read(l[i]);
    sort(l+1,l+n+1);
    while(1){
        // printf("_________________________________________________\n");
        for(int i=1;i<=n*c+1;i++) for(int j=0;j<1<<(n-1);j++) f[i][j]=0;
        f[l[n]*n+1][0]=1;
        for(int i=1;i<=n*c+1;i++){
            if(i%n==1) continue;
            // printf("i=%d\n",i);
            int p=(i-1)%n;
            // printf("p=%d\n",p);
            for(int j=i;j<=n*c+1;j++){
                for(int s=0;s<(1<<(n-1));s++){
                    if(!((s>>(p-1))&1)){
                        // printf("f[%d][%d]=%d\n",j,s,f[j][s]);
                        f[min(n*c+1,max(j,i+l[p]*n))][s|(1<<(p-1))]+=f[j][s];
                        // printf("now f[%d][%d]=%d\n",min(n*c,max(j,i+l[p]*n)),s|(1<<(p-1)),f[min(n*c,max(j,i+l[p]*n))][s|(1<<(p-1))]);
                    }
                }
            }
        }
        Ans+=f[n*c+1][(1<<(n-1))-1];ans1++;
        if(!next_permutation(l+1,l+n)) break;
    }
    // printf("Ans=%lf\n",Ans);
    ans2=1;
    for(int i=1;i<=n-1;i++){
        ans2=ans2*c;
    }
    printf("%0.11Lf\n",(ld)Ans/(ld)ans1/(ld)ans2);
    return 0;
}
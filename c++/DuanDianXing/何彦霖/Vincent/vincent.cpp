#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 201
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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

int n,a[N],ans;
int f[N][N];

int main(){
    freopen("vincent.in","r",stdin);
    freopen("vincent.out","w",stdout);
    bool op=1;
    read(n);for(int i=1;i<=n;i++){read(a[i]);ans=Max(ans,a[i]);if(a[i]!=1) op=0;}
    if(op){
        printf("%d\n",log2(n)+1);return 0;
    }
    for(int i=1;i<=n;i++) f[i][i]=a[i];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            int l=j,r=j+i-1;
            for(int k=l;k<=r-1;k++){
                if(f[l][k]==f[k+1][r]&&f[l][k]!=0) f[l][r]=Max(f[l][r],f[l][k]+1);
                ans=Max(ans,f[l][r]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
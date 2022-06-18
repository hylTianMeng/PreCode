#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

int a[N][N],n,m;

inline bool Check(int x){
    int now=(int)sqrt(x);return now*now==x;
}

int main(){
    read(n);m=(n*(n+2)+(n&1)-2)/2;printf("%d\n",m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x=a[j][a[j][0]];
            if(!x||Check(x+i)){a[j][++a[j][0]]=i;break;}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i][0];j++) printf("%d ",a[i][j]);puts("");
    }
    return 0;
}
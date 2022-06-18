#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200
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

int a[N][N];

int main(){
    int n,m;read(n);read(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            read(a[i][j]);
        }
    for(int i=1;i<=n*m;i++)
        for(int k=1;k<=n;k++)
            for(int j=1;j<=m;j++){
                if(a[k][j]==i) printf("%d %d\n",k,j);
            }
}
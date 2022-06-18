#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
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

int n,a[N],b[N],c[N],tot,d[N],f[N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==i) b[i]=1;
        else b[i]=0;
    }
    for(int i=1;i<=n-2;i++){
        if(b[i]==b[i+1]&&b[i+1]==b[i+2]&&b[i+2]==0){puts("No");return 0;}
    }
    tot=1;
    for(int i=1;i<=n;i++){
        c[i]=tot;
        if(b[i]==b[i+1]) tot++;
    }
    for(int i=1;i<=n;i++){
        if(c[a[i]]!=c[i]){puts("No");return 0;}
    }
    int L=-1,R=-1;
    for(int i=1;i<=n;i++){
        if(c[i]!=c[i-1]){L=-1;R=-1;}
        if(a[i]>i){
            if(a[i]>L) L=a[i];
            else{puts("No");return 0;}
        }
        if(a[i]<i){
            if(a[i]>R) R=a[i];
            else{puts("No");return 0;}
        }
    }
    puts("Yes");
    return 0;
}
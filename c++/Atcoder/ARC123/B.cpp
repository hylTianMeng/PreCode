#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define mset(a,b) memset(a,b,sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N number
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

int n,a[N],b[N],c[N],d[N];

inline void Change(int k){
    assert(k>=3&&k<=n);
    int now=a[k];
    a[k]=a[k-1];a[k-1]=a[k-2];a[k-2]=now;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    for(int i=1;i<=n;i++) c[a[i]]++;
    for(int i=1;i<=n;i++) d[b[i]]++;
    for(int i=1;i<=5000;i++) if(c[i]!=d[i]){puts("No");return 0;}
    for(int i=1;i<=5000;i++){
        if(c[i]>1){puts("Yes");return 0;}
    }
    for(int i=1;i<=n;i++){
        assert(a[i-1]==b[i-1]);
        if(i==n-1) break;
        int posi=-1;
        for(int j=i;j<=n;j++){
            if(a[j]==b[i]){posi=j;}
        }
        if(posi==-1){puts("No");return 0;}
        while(posi>=i+2){
            Change(posi);posi-=2;
        }
        if(posi!=i){Change(i+2);Change(i+2);}
    }
    if(a[n-1]!=b[n-1]||a[n]!=b[n]){
        puts("No");
    }
    else puts("Yes");
    return 0;
}
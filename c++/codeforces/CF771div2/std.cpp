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

int n,q;

int a[N],c[N];

int main(){
    freopen("my.in","r",stdin);
    freopen("std.out","w",stdout);
    read(n);read(q);
    for(int i=1;i<=q;i++){
        string s;cin>>s;
        if(s=="Color"){
            int l,r,x;read(l);read(r);read(x);
            for(int i=l;i<=r;i++) c[i]=x;
        }
        else if(s=="Add"){
            int l,x;read(l);read(x);
            for(int i=1;i<=n;i++) if(c[i]==l) a[i]+=x;
        }
        else{
            int x;read(x);
            printf("%d\n",a[x]);
        }
    }
    return 0;
}
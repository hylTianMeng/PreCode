#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
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

int t,n,p[N];

int main(){
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(p[i]);
        int l=-1;
        for(int i=1;i<=n;i++){
            if(p[i]!=i){l=i;break;}
        }
        int r=-1;
        for(int i=1;i<=n;i++){
            if(p[i]==l){r=i;break;}
        }
        if(l!=-1&&r!=-1) reverse(p+l,p+r+1);
        for(int i=1;i<=n;i++) printf("%d ",p[i]);
        puts("");
    }
}
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

int n;
struct Node{
    dd a,b;
}c[N];
dd t,dis;

int main(){
    read(n);
    for(int i=1;i<=n;i++){
        read(c[i].a);read(c[i].b);
        t+=c[i].a/c[i].b;
    }
    t/=2;
    for(int i=1;i<=n;i++){
        if(t*c[i].b>=c[i].a){
            t-=c[i].a/c[i].b;
            dis+=c[i].a;
        }
        else{
            dis+=c[i].b*t;
            break;
        }
    }
    printf("%0.10lf\n",dis);
    return 0;
}
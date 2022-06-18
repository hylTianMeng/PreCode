#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000
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

ll x;
int a[N],t;

int main(){
    read(x);
    while(x){
        int now=x%2;
        a[++t]=now;
        x>>=1;
    }
    reverse(a+1,a+1+t);
    for(int i=1;i<=t;i++){
        if(a[i]==1) a[i]++;
        printf("%d",a[i]);
    }
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 500010
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

priority_queue<int> q;

int n,a[N],k;

int main(){
    read(n);read(k);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=k;i++) q.push(-a[i]);
    printf("%d\n",-q.top());
    for(int i=k+1;i<=n;i++){
        int now=a[i];
        int minn=-q.top();
        if(now>minn){
            q.pop();q.push(-now);
        }
        int Ans=-q.top();
        printf("%d\n",Ans);
    }
    return 0;
}
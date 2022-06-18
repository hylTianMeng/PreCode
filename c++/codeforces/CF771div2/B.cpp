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

int t,n,a[N];
int b[N],bt,c[N],ct;

int main(){
    // freopen("my.in","r",stdin);
    read(t);
    while(t--){
        read(n);
        bt=ct=0;
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]&1) b[++bt]=a[i];
            else c[++ct]=a[i];
        }
        bool op1=1,op2=1;
        for(int i=1;i<=bt-1;i++){
            if(b[i+1]<b[i]){op1=0;break;}
        }
        for(int i=1;i<=ct-1;i++){
            if(c[i+1]<c[i]){op2=0;break;}
        }
        if(op1&&op2){puts("Yes");}
        else puts("No");
    }
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
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

int t;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        int a,s;read(a);read(s);
        int x=0,y=0,val=s-2*a;
        if(val<0){puts("No");continue;}
        bool op=1;
        for(int i=0;i<=60;i++){
            if(((a>>i)&1)==1){
                if(((val>>i)&1)==1){op=0;break;}
            }
        }
        if(op){puts("Yes");}
        else puts("No");
    }
    return 0;
}
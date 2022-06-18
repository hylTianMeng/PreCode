#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 30
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

ll a[N][N];

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    int n;read(n);
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=n;j++){
            a[i][j]=(1ll<<(i+j-2));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",a[i][j]);cout.flush();
        }
        puts("");cout.flush();
    }
    cout.flush();
    int q;read(q);
    int nowx,nowy;
    for(int i=1;i<=q;i++){
        ll x;read(x);
        nowx=1;nowy=1;
        printf("%d %d\n",1,1);cout.flush();
        x--;x>>=1;
        while(nowx!=n||nowy!=n){
            if(nowx&1){
                if(x&1){nowy++;}
                else nowx++;
            }
            else{
                if(x&1){nowx++;}
                else nowy++;
            }
            x>>=1;
            printf("%d %d\n",nowx,nowy);cout.flush();
        }
        cout.flush();
    }
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
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

inline int random(int n){return 1ll*rand()*rand()%n+1;}

int main(){
    srand(time(0));
    freopen("my.in","w",stdout);
    int t=random(10);printf("%d\n",t);
    while(t--){
        int n=2*random(5),m=n+random(5);
        printf("%d %d\n",n,m);
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(cnt1==cnt2){
                cnt1++;putchar('(');
            }
            else{
                if(cnt1<n/2){
                    int op=random(2);
                    if(op==1){putchar('(');cnt1++;}
                    else{putchar(')');cnt2++;}
                }
                else{putchar(')');cnt2++;}
            }
        }
        puts("");
    }

    return 0;
}
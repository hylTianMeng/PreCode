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

int n,q;

char s[3][N]={"Add","Query","Color"};

int main(){
    n=10;q=10;printf("%d %d\n",n,q);
    for(int i=1;i<=q;i++){
        int op=random(3)-1;
        cout<<s[op];
        if(op==0){
            int now=random(5);
        }
        else if(op==1){

        }
        else{

        }
    }
}
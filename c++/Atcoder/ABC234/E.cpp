#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000
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

ll a,b,c[N];
int w;

int main(){
    read(a);b=a;while(b){c[++w]=b%10;b/=10;}
    reverse(c+1,c+w+1);
    for(int i=c[1];i<=9;i++){
        int now;ll all=0;
        // printf("i=%d\n",i);
        for(int j=-9;j<=9;j++){
            now=i;bool op=1;all=i;
            for(int k=2;k<=w;k++){
                now+=j;
                // printf("now=%d\n",now);
                if(now<0||now>=10){op=0;break;}
                all*=10;all+=now;
            }
            // printf("all=%d\n",all);
            if(all<a) continue;
            if(op){
                printf("%lld\n",all);
                return 0;
            }
        }
    }
    // printf("HERE");
    return 0;
}
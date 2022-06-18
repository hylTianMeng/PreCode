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

int t,l,r,k;

int main(){
    read(t);
    while(t--){
        read(l);read(r);read(k);
        if(l==r){
            if(l!=1) puts("YES");
            else puts("NO");continue;
        }
        int len=r-l+1;
        if((len&1)==0){
            if(k>=len/2){puts("YES");}
            else puts("NO");
        }
        else{
            if(k>len/2){puts("YES");}
            else{
                if((k==len/2)&&r%2==0) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}
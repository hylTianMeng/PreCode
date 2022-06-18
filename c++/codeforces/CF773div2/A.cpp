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

typedef pair<int,int> P;
P a,b,c;

int t ;

int main(){
    // freopen("my.in","r",stdin);
    read(t);
    for(int i=1;i<=t;i++){
        read(a.first);read(a.second);
        read(b.first);read(b.second);
        read(c.first);read(c.second);
        int maxx=max(a.second,max(b.second,c.second));
        int l=-1,r=-1;
        if(a.second==maxx){
            if(l==-1) l=a.first;
            else r=a.first;
        }
        if(b.second==maxx){
            if(l==-1) l=b.first;
            else r=b.first;
        }
        if(c.second==maxx){
            if(l==-1) l=c.first;
            else r=c.first;
        }
        if(l==-1||r==-1){
            puts("0");continue;
        }
        printf("%d\n",abs(r-l));
    }
}
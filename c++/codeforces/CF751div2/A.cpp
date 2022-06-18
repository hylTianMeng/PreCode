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

int t;
string s;

int main(){
    read(t);
    while(t--){
        cin>>s;
        int len=s.length();
        int Minc=INF;
        for(int i=0;i<len;i++){
            Minc=min(Minc,(int)s[i]);
        }
        putchar((char)Minc);
        putchar(' ');
        for(int i=0;i<len;i++){
            if(s[i]==Minc) Minc=0;
            else putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
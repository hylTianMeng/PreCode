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

string s1,s2;

int main(){
    cin>>s1;cin>>s2;
    if(s1[0]=='.'){
        swap(s1[0],s1[1]);
        swap(s2[0],s2[1]);
    }
    if(s1[0]=='#'&&s2[1]=='#'&&s1[1]=='.'&&s2[0]=='.'){puts("No");}
    else puts("Yes");
    return 0;
}
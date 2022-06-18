#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3020
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

string s;
string t[N];
int tail,len;

inline string Left(string s){
    string now;now.clear();
    for(int i=1;i<len;i++) now+=s[i];
    now+=s[0];return now;
}

int main(){
    cin>>s;t[++tail]=s;
    len=s.length();
    for(int i=1;i<=len-1;i++){
        s=Left(s);t[++tail]=s;
    }
    sort(t+1,t+tail+1);
    cout<<t[1]<<'\n';
    cout<<t[tail];
    return 0;
}
#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
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

int n,m;
map<int,bool> Map;
string s[N];
map<string,int> Map2;

int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        cin>>s[i];Map2[s[i]]=i;Map[i]=0;
    }
    for(int j=1;j<=m;j++){
        string t;cin>>t;
        Map[Map2[t]]=1;
    }
    for(int i=1;i<=n;i++){
        if(Map[Map2[s[i]]]) puts("Yes");
        else puts("No");
    }
}
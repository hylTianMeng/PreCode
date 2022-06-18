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
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int f[N],Ans=1;
char s[N];

int main(){
    scanf("%s",s+1);
    f[1]=1;f[0]=1;
    for(int i=2;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int n=strlen(s+1);
    int len=0;
    char nowc=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='u'||s[i]=='n'){
            if(nowc==s[i]){
                len++;continue;
            }
            else{
                Ans=1ll*Ans*f[len]%mod;
                nowc=s[i];len=1;
            }
        }
        else{
            if(len!=0) Ans=1ll*Ans*f[len]%mod;
            len=0;nowc=0;
        }
        if(s[i]=='w'||s[i]=='m') Ans=0;
    }
    Ans=1ll*Ans*f[len]%mod;
    printf("%d\n",Ans);
    return 0;
}
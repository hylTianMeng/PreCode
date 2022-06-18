#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 10000100
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

int n,k,t;
bool vis[N];

int main(){
    read(t);
    while(t--){
        read(n);read(k);
        for(int i=0;i<=n-1;i++) vis[i]=0;
        int biao=n-1;
        if(k==0){
            for(int i=0;i<=n/2-1;i++){
                printf("%d %d\n",i,biao^i);
            }
            continue;
        }
        if(k<n-1){
            printf("%d %d\n",k,biao);
            printf("%d %d\n",0,k^biao);
            for(int i=1;i<=biao/2;i++){
                if(i==k||i==(k^biao)) continue;
                printf("%d %d\n",i,i^biao);
            }
        }
        if(k==n-1){
            if(n==4){puts("-1");continue;}
            int w=0;while(n>1){n>>=1;w++;}
            // printf("w=%d\n",w);
            if(w%2==0){
                for(int i=0;i<w;i+=2){
                    vis[(1<<i)]=1;
                    vis[(1<<(i+1))]=1;
                    vis[biao^(1<<i)]=1;
                    vis[biao^(1<<(i+1))]=1;
                    printf("%d %d\n",(1<<i),biao^(1<<(i+1)));
                    printf("%d %d\n",(1<<(i+1)),biao^(1<<i));
                }
                printf("%d %d\n",0,biao);
                for(int i=1;i<=biao/2;i++){
                    if(vis[i]) continue;
                    printf("%d %d\n",i,biao^i);
                }
            }
            else{
                for(int i=0;i<w;i++){
                    vis[(1<<i)]=1;
                    vis[(1<<((i+(w/2+1))%w))^biao]=1;
                    printf("%d %d\n",(1<<i),(1<<((i+(w/2+1))%w))^biao);
                }
                printf("%d %d\n",0,biao);
                for(int i=1;i<=biao/2;i++){
                    if(vis[i]) continue;
                    printf("%d %d\n",i,biao^i);
                }
            }
        }
    }
    return 0;
}
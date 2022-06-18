#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000010
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

int t,n,a[N],b[N],ans[N],tail;

typedef pair<int,int> P;

inline void Change(int k){
    int len=k*2-1;
    ans[++tail]=len;
    reverse(a+1,a+len+1);
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        tail=0;
        read(n);for(int i=1;i<=n;i++) read(a[i]);
        bool op=1;
        for(int i=1;i<=n;i++){
            if((a[i]&1)!=(i&1)){op=0;break;}
        }
        if(!op){
            puts("-1");continue;
        }
        for(int i=(n-1)/2;i>=1;i--){
            int fir=i*2+1,sec=i*2;
            // printf("fir=%d sec=%d\n",fir,sec);
            int fina=i*2+1;
            int posi=-1;
            for(int j=1;j<=n;j++){
                if(a[j]==fir){posi=j;break;}
            }
            // printf("posi=%d\n",posi);
            Change(posi/2+1);
            for(int j=1;j<=n;j++){
                if(a[j]==sec){posi=j;break;}
            }
            posi--;
            Change(posi/2+1);
            posi+=2;
            Change(posi/2+1);
            Change(2);
            Change(fina/2+1);
            // printf("%d\n",tail);
            // for(int i=1;i<=tail;i++) printf("%d ",ans[i]);puts("");
            // for(int i=1;i<=n;i++){
            //     printf("%d ",a[i]);
            // }puts("");
        }
        printf("%d\n",tail);
        for(int i=1;i<=tail;i++) printf("%d ",ans[i]);puts("");
        // for(int i=1;i<=n;i++){
        //     printf("%d ",a[i]);
        // }puts("");
    }
    return 0;
}
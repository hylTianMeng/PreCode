#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 1100

using namespace std;

char s[MAXN];
int map[MAXN][MAXN];
int fzs[MAXN][MAXN],fzx[MAXN][MAXN],fys[MAXN][MAXN],fyx[MAXN][MAXN]; //左上、左下、右上、右下为起点到(i,j)的方案数
int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(fzs,0,sizeof(fzs));
        memset(fzx,0,sizeof(fzx));
        memset(fys,0,sizeof(fys));
        memset(fyx,0,sizeof(fyx));
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s+1);
            for(int j=1; j<=m; j++)
                map[i][j]=s[j]=='1';
        }
        //左上角开始的路线的DP
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(!map[i][j])
                    fzs[i][j]=0;
                else if(!map[i][j-1]) fzs[i][j]=1;
                else fzs[i][j]=fzs[i-1][j-1]+2;
        //左下角路线开始的DP
        for(int i=n; i>=1; i--)
            for(int j=1; j<=m; j++)
                if(!map[i][j])
                    fzx[i][j]=0;
                else if(!map[i+1][j]) fzx[i][j]=1;
                else fzx[i][j]=fzx[i+1][j-1]+2;
        //右上角路线开始的DP
        for(int i=1; i<=n; i++)
            for(int j=m; j>=1; j--)
                if(!map[i][j])
                    fys[i][j]=0;
                else if(!map[i-1][j]) fys[i][j]=1;
                else fys[i][j]=fys[i-1][j+1]+2;
        //右下角路线开始的DP
        for(int i=n; i>=1; i--)
            for(int j=m; j>=1; j--)
                if(!map[i][j])
                    fyx[i][j]=0;
                else if(!map[i][j+1]) fyx[i][j]=1;
                else fyx[i][j]=fyx[i+1][j+1]+2;
        int maxans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                maxans=max(maxans,fzx[i][j]+fys[i][j]+fzs[i][j]+fyx[i][j]-3);
        printf("%d\n",maxans);
    }
    return 0;
}


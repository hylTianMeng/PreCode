<=n;i++){
        Del(mod-i);
        for(int j=m;j>=0;j--) RatSum[i]+=rat[j];
        Add(mod-i); 
        for(int j=m;j>=0;j--) RatSum[0]=(RatSum[0]+rat[j])%mod;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            Ans[i]=(Ans[i]+1ll*ans[i][j]*RatSum[j]%mod*fenmu[j]%mod)%mod;
        }
    }

    // for(int i=2;i<=n;i++){
    //     // printf("i=%lld\n",i);
    //     o^=1;
    //     for(int j=1;j<=tail;j++) f[o][fir[j]][sec[j]]=f[o^1][fir[j]][sec[j]];
    //     for(int j=1;j<=tail;j++){
    //         f[o][fir[j]^a[i]][sec[j]&a[i]]+=f[o^1][fir[j]][sec[j]];
    //         if(!vis[fir[j]^a[i]][sec[j]&a[i]]){
    //             vis[fir[j]^a[i]][sec[j]&a[i]]=1;
    //             Add(fir[j]^a[i],sec[j]&a[i]);
    //         }
    //     }
    //     f[o][a[i]][a[i]]++;
    //     if(!vis[a[i]][a[i]]){
    //         vis[a[i]][a[i]]=1;Add(a[i],a[i]);
    //     }
    // }
    // ll ans=0;
    // for(int i=0;i<=(1<<13)-1;i++){
    //     ans+=1ll*f[o][i][i];
    // }
    // printf("%lld\n",ans
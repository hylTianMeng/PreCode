memset(f, 0 ,sizeof(f));
    f[0][n-1][0] = (n - 1) * quick(n , mod - 2) % mod;
    f[0][n-1][1] = quick(n , mod - 2);
    
    int p = x * quick(y , mod - 2) % mod;
    int q = (y - x) * quick(y , mod - 2) % mod;
    P[0] = 1; Q[0] = 1;
    
    for(int i = 1 ; i <= n ; i ++)
        P[i] = P[i - 1] * p % mod;
    for(int i = 1 ; i <= n ; i ++)
        Q[i] = Q[i - 1] * q % mod;
                     
    for(int i = 1; i <= n - 1; i ++)
    {
        for(int j = 1 ; j <= n; j ++)
            for(int k = j ; k <= n; k ++)
                f[i][j][0] = (f[i][j][0] + f[i-1][k][0] * P[k - j] % mod * Q[j] % mod * C(k - 1, j - 1) % mod);
                
        for(int j = 0 ; j <= n-1; j ++)
            f[i][j][1] = f[i][j+1][0] * quick(j + 1 , mod - 2) % mod;
            
        for(int j = 1; j <= n - 1; j ++)
            f[i][j][0] = f[i][j+1][0] * j % mod * quick(j + 1, mod - 2) % mod; 
    } 
    for(int i = 0; i <= n - 1; i ++)
    {
        ans = 0;
        for(int j = 0 ; j <= n; j ++)
            ans = (ans + f[i][j][1]) % mod;
        printf("%lld " , ans);
    }
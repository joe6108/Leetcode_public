double myPow(double x, int n){
    if(!n || x==1) return 1;
    if(x == -1.0) return (n%2 ? -1.0 : 1.0);
    double temp = x;
    double once = x;
    int flag = 0, flag2 = 0;
    if(n<0){
        flag2 = 1;
        if(n == -2147483648){
            flag=1;
            n+=1;
        }
        n*=(-1);
    }
    int i;
    for(i=2;i<n;i*=2){
        x*=temp; // x = 2 , temp = 2 -> x = 4, temp = 2
        temp = x; // x = 4,  temp = 4
        printf("x = %f\n", x);
        if(i==1073741824) break;
        if(x > 1.7976931348623157E+308) return 0;
    }
    //printf("i = %d\n", i);
    i/=2;
    if(flag) i+=1;
    for(int j=0;j<(n-i);j++) x*=once;
    if(flag2) x = 1 / x;
    printf("x = %f", x);
    return x;
    
    
}
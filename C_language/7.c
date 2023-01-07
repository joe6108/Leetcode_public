int reverse(int x){
    int max = INT_MAX;
    int min = INT_MIN;
    if((x/10)==0) return x;
    printf("max : %d, min : %d\n", max, min);
    int test = x;
    int count = 0;
    int ans = 0;
    while((test/10) != 0){
        if (test > 0){
            max = (INT_MAX - test);
            if (max>9) max /= 10; 
        }
        if (test < 0){
            min = (INT_MIN - test);
            if (min<(-9)) min /= 10; 
        }
        if(max < ans || min > ans) return 0;
        ans = (ans*10) + test % 10;
        test/=10;
    }
    if (test > 0){
        max = (INT_MAX - test);
        if (max>9) max /= 10; 
    }
    if (test < 0){
        min = (INT_MIN - test);
        if (min<(-9)) min /= 10; 
    }
    if(max < ans || min > ans){
        printf("this math is over max");
        return 0;
    }
    ans = (ans*10) + test;
    return ans;
}
int mySqrt(int x){
    int length = 0;
    int tp = x, count = 1, key = -0.5;
    while(tp!=0){
        length++;
        key+=0.5;
        tp/=10;
    }
    for(int i=0;i<key;i++){
        count*=10;
    }
    while((2147483647/count>count) && (count*count)<x) count++;
    if((2147483647/count>count) && x==(count*count)) return count;
    return (count-1);
}
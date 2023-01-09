bool isPalindrome(int x){
    int length = 1;
    int tmp = x;
    while((tmp/10)!=0){
        length++;
        tmp/=10;
    }
    int r,l,r_sub,l_sub; //right pos, left pos
    int i,j;
    if(x<0) return false;
    if(length==1) return true;
    for(i=0;i<length/2;i++){ //依長度判斷次數
        //初始化
        r = x;  
        l = x;  
        r_sub = x;
        l_sub = x;
        tmp = pow(10, i+1);
        r%=tmp;
        tmp = pow(10, length-i-1);
        l/=tmp;
        tmp = pow(10, i);
        r_sub%=tmp;
        tmp = pow(10, length-i);
        l_sub/=tmp;
        if(i==0 && r==l) continue;
        
        r = (r-r_sub)/pow(10, i);
        l = l-(l_sub*10);
        if(r!=l){
            return false;
        }
    }
    return true;
}
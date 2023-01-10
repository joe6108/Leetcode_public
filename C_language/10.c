int maxArea(int* height, int heightSize){
    int max = 0;
    int left = 0;
    int right = 0;
    int length = 0;
    int i,j,tmp;
    for(i=0;i<heightSize-1;i++){
        left = height[i];
        printf("%d\n", i);
        for(j=heightSize-1;j>i;j--){
            right = height[j];
            if(right>=left){
                length = j - i;
                tmp = length * left;
                if(tmp > max) max = tmp;
                break;
            }
        }
    }
    
    for(i=heightSize-1;i>0;i--){
        right = height[i];
        for(j=0;j<i;j++){
            left = height[j];
            if(left>=right){
                length = i - j;
                tmp = length * right;
                if(tmp > max) max = tmp;
                break;
            }
        }
    }
    return max;
}
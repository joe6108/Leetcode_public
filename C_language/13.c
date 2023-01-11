int romanToInt(char * s){
    char *ten_a = "IXCM";
    char *five_b = "VLD";
    int length = strlen(s);
    int i,j;
    int sum = 0;
    for(i=0;i<length;i++){
        if(s[i]==ten_a[3]){
            sum+=1000;
            continue;
        }
        for(j=0;j<3;j++){
            if(s[i]==five_b[j]){
                sum += 5*pow(10, j);
                break;
            }
        }
        for(j=0;j<3;j++){
            if(s[i]==ten_a[j]){
                if(i+1!=length){
                    if(s[i+1]==ten_a[j+1]){
                        sum = sum + (1*pow(10, j+1) - 1*pow(10, j));
                        i++;
                        break;
                    }else if(s[i+1]==five_b[j]){
                        sum = sum + (5*pow(10, j) - 1*pow(10, j));
                        i++;
                        break;
                    }
                }
                sum += 1*pow(10, j);
                break;
            }
        }
    }
    return sum;
}
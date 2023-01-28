int divide(int dividend, int divisor){
    int ans=0, layer2=0, step=0, i;
    if(divisor==1) return dividend;
    if(divisor==-1){
        if(dividend==-2147483648) return 2147483647;
        else if(dividend==2147483647) return -2147483647;
    }
    /*
    First step: add once search range，max = 10's divisor.
    */
    if(divisor<0){
        for(i=0;i<10;i++){
            if(layer2 <= (-2147483648-divisor)) break;
            layer2+=divisor;
            step++;
        }
    }else{
        for(i=0;i<10;i++){
            if(layer2 >= (2147483647-divisor)) break;
            layer2+=divisor;
            step++;
        }
    }
    //printf("later2 = %d, step = %d\n", layer2, step);
    /*
    Secord step: start to finish this answer!
    
    first if: use four if to classification this problem

    */
    if(dividend>=0&divisor<0){
        //printf("1");
        // try to use max search range , if step = 0 represent this search range = 0, it cannot used .
        while(dividend>=0 && step!=0){
            dividend+=layer2;
            ans-=step;
        }
        //this is a compensate , because while() use >=0 , so it will extra add a execution times.
        if(step!=0){
            dividend-=layer2;
            ans+=step;
        }
        //one search
        while(dividend>=0){
            dividend+=divisor;
            ans-=1;
        }
        //this is a compensate
        ans++;
    }else if(dividend<=0&divisor>0){
        //printf("2");
        while(dividend<=0 && step!=0){
            dividend+=layer2;
            ans-=step;
        }
        if(step!=0){
            dividend-=layer2;
            ans+=step;
        }
        while(dividend<=0){
            dividend+=divisor;
            ans-=1;
        }
        ans++;
    }else{
        if(dividend<0){
            //printf("3");
            /*
            because it can use divisor to decide end, it not need to compensate.
            */
            while(dividend<=layer2 && step!=0){
                dividend-=layer2;
                ans+=step;
            }
            while(dividend<=divisor){
                dividend-=divisor;
                ans+=1;
            }
        }else{
            //printf("4");
            while(dividend>=layer2 && step!=0){
                dividend-=layer2;
                ans+=step;
            }
            while(dividend>=divisor){
                dividend-=divisor;
                ans+=1;
            }
        }
    }
    
    return ans;
}
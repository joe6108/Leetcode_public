int myAtoi(char * s){
    int length = strlen(s);
    int positive = 3;
    int ans = 0;
    int max = INT_MAX / 10;
    int pos;
    for(pos=0;pos<length;pos++){
        int s_pos_ = (s[pos] - '0');
        if(ans!=0){
            if(s_pos_ == -16){
                if(positive==1) ans*=(-1);
                return ans;
            }
        }
        if(positive == 3){
            if(s_pos_ == -16) continue;
        }else{
            if(s_pos_ == -16){
                if(positive==1) ans*=(-1);
                return ans;
            } 
        }
        if(ans!=0 && !(s_pos_>=0 && s_pos_<=9)) break;

        if(s[pos]=='+' || s[pos]=='-' || (s_pos_>=0 && s_pos_<=9)){
            if(s[pos]=='+' && ans==0){
                if(positive==3){
                    positive = 0;
                }else{
                    return 0;
                }
            }else if(s[pos]=='-' && ans==0){
                if(pos!=0){
                    if((s[pos-1] - '0')==0) return 0;
                }
                if(positive==3){
                    positive = 1;
                }else{
                    return 0;
                }
            }else{
                if(s_pos_==0 && ans==0){
                    if(pos+1!=length){
                        if(!((s[pos+1] - '0')>=0 && (s[pos+1] - '0')<=9)) return 0;
                    }
                }
                if(s_pos_!=0 && ans==0){
                    ans = s_pos_;
                }else{
                    if(ans < max){            
                        ans = ans*10 + s_pos_;
                    }else if(ans == max){
                        if(s_pos_ <= 7){
                            ans= ans*10 + s_pos_;
                        }else{
                            if(positive==1){
                                return INT_MIN;
                            }else{
                                return INT_MAX;
                            }         
                        }
                    }else{
                        if(positive==1){
                            return INT_MIN;
                        }else{
                            return INT_MAX;
                        } 
                    }
                }
            }
        }else{
            if(positive==1) ans*=(-1);
            return ans;
        }
    }
    if(positive==1) ans*=(-1);
    return ans;
}
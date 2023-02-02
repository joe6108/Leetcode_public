bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i,j,k;
    int ans  = 0;
    int table[9] = {0};
    for(i=0;i<9;i++){
        memset(table,0,sizeof(int)*9);
        for(j=0;j<9;j++){
            if(board[i][j]!='.'){
                ans = board[i][j] - '0';
                if(table[ans-1]==1){
                    return false;
                }else{
                    table[ans-1]=1;
                }
            }
        }
    }
    for(i=0;i<9;i++){
        memset(table,0,sizeof(int)*9);
        for(j=0;j<9;j++){
            if(board[j][i]!='.'){
                ans = board[j][i] - '0';
                if(table[ans-1]==1){
                    return false;
                }else{
                    table[ans-1]=1;
                }
            }
        }
    }
    for(k=0;k<9;k++){
        memset(table,0,sizeof(int)*9);
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(board[i+k/3*3][j+k%3*3]!='.'){
                    ans = board[i+k/3*3][j+k%3*3] - '0';
                    if(table[ans-1]==1){
                        return false;
                    }else{
                        table[ans-1]=1;
                    }
                }
            }
        }
    }
    return true;
}
/*
 * 這題使用的是回朔法，當找到第一個字元時，就進入repeat()迴圈逐個查找答案，每次尋找的方向從下上右左(任意順序都行)，逐一探究可能性，找到則回傳1。
 * 
 */


int repeat(char** board, int row, int col, char* word, int word_len, int x, int y, int level, bool** table){
    if(level == word_len) return 1;
    if(x+1<row && table[x+1][y]==false){
        if(board[x+1][y]==word[level]){
            table[x+1][y] = true;
            if(repeat(board, row, col, word, word_len, x+1, y, level+1, table)) return 1;
            table[x+1][y] = false;
        }
    }
    if(x>0 && table[x-1][y]==false){
        if(board[x-1][y]==word[level]){
            table[x-1][y] = true;
            if(repeat(board, row, col, word, word_len, x-1, y, level+1, table)) return 1;
            table[x-1][y] = false;
        }
    }
    if(y+1<col && table[x][y+1]==false){
        if(board[x][y+1]==word[level]){
            table[x][y+1] = true;
            if(repeat(board, row, col, word, word_len, x, y+1, level+1, table)) return 1;
            table[x][y+1] = false;
        }
    }
    if(y>0 && table[x][y-1]==false){
        if(board[x][y-1]==word[level]){
            table[x][y-1] = true;
            if(repeat(board, row, col, word, word_len, x, y-1, level+1, table)) return 1;
            table[x][y-1] = false;
        }
    }
    return 0;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int n = boardSize, m = boardColSize[0], len = strlen(word),i,j,k;
    if(len>(m*n)) return false;
    bool **table = malloc(sizeof(bool*)*n);
    for(k=0;k<n;k++) table[k] = malloc(sizeof(bool)*m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(board[i][j]==word[0]){
                for(k=0;k<n;k++) memset(table[k], false, sizeof(bool)*m);
                table[i][j] = true;
                if(repeat(board, n, m, word, len, i, j, 1, table)) return true;
            }
        }
    }
    return false;
}
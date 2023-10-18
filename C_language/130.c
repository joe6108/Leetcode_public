/*
 * 這題需要先觀察題目，找出會被判斷為X的O，也就是沒有和邊邊的O相連的O，因為只有邊邊的O不會被X給包圍，所以她必定
 * 可以為O，而沒有和邊邊的O相連的，必定會被包圍，所以會變成X，這代表我們可以先將確定是O的換成另一種字元，像是'A'
 * ，最後就可以將剩下的O(沒有和邊邊的O相連的)變成X，而A就改回原本的O就好。
 */
void DFS_search(char** board, int row, int col, int x, int y){
    if(x > row || y > col) return;
    board[x][y] = 'A';
    if(x > 0 && board[x-1][y] == 'O') DFS_search(board, row , col, x-1, y);
    if(x < row && board[x+1][y] == 'O' ) DFS_search(board, row , col, x+1, y);
    if(y > 0 && board[x][y-1] == 'O') DFS_search(board, row , col, x, y-1);
    if(y < col && board[x][y+1] == 'O') DFS_search(board, row , col, x, y+1);
}

void solve(char** board, int boardSize, int* boardColSize){
    if(boardSize==1 || boardColSize[0]==1) return;
    int row = boardSize - 1, col = boardColSize[0] - 1;
    for(int i=0 ; i<=col ; i++){
        if(board[0][i] == 'O') DFS_search(board, row, col, 0, i); 
        if(board[row][i] == 'O') DFS_search(board, row, col, row, i);
    }
    for(int i=1 ; i<row ; i++){
        if(board[i][0] == 'O') DFS_search(board, row, col, i, 0);
        if(board[i][col] == 'O') DFS_search(board, row, col, i, col);
    }
    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }else if(board[i][j] == 'A'){
                board[i][j] = 'O';
            }
        }
    }
    
}
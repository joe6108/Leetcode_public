/*
 * v1 最踏實的方式，每個都找一遍，但太久了。
 */

void step(int m, int n, int y, int x, int *sum){
    //printf("one");
    if((y==m)&&(x==n)){
        (*sum)++;
        return;
    }
    if(y<m) step(m,n,y+1,x,sum);
    if(x<n) step(m,n,y,x+1,sum);
}
int uniquePaths(int m, int n){
    int sum = 0;
    step(m-1,n-1,0,0,&sum);
    printf("sum = %d");
    return sum;
}

/*
 * v2 尋找規律的方式，可以依照下方的表格去看出規律，再來實現就行了。
 */

int uniquePaths(int m, int n){
    if(m==1 || n==1) return 1;
    int table[m][n];
    int i,j;
    for(i=0;i<m;i++) table[i][0] = 1;
    for(j=0;j<n;j++) table[0][j] = 1;
    for(i=1;i<m;i++){
        for(j=1;j<n;j++) table[i][j] = table[i-1][j] + table[i][j-1];
    }
    return table[m-1][n-1];
}

/*
 * 1 1 1 1 1 1 1                        (1)
 * 1 2 3 4 5 6 7                        (2) 
 * 1 3 6 10 15 21 28 --2 3 4 5 6        (3)
 * 1 4 10 20 35 56 84 --3 6 10 15 21    (4)
 * 1 5 15 35 70 126 210 --4 10 20 35 56 (5)
 */
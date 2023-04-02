int repeat(int n, int* table){
    if(table[n]!=0) return table[n];
    int count = 0, left = 0, right = 0;
    for(int i=1;i<=n;i++){
        left = repeat(i-1, table);
        right = repeat(n-i, table);
        count += left * right;
    }
    table[n] = count;
    return count;
}

int numTrees(int n){
    int* table = malloc(sizeof(int)*(n+1));
    memset(table,0,sizeof(int)*(n+1));
    table[0] = 1;
    table[1] = 1;
    return repeat(n, table);
}
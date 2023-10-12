/*
 * 這題算是有點麻煩的題目，一開始我是使用遞迴的方式去解題，但我發現遞迴在運行上花了太多的時間了，所以就算我能夠得出答案，也沒辦法讓這個題目接受。
 * 所以我就另尋了另一種方法，也就是暴力破解的方式，貪婪演算法，這個演算法是以局部的最小得出答案，也就是每次都選擇最短的數字去總和，可是這題同樣
 * 無法透過這個方法，因為答案會因為路徑的正負出現問題，所以我們必須思考出全局的方式去解決，也就是DP(Dynamic programing)路徑規劃，只有當當前結果
 * 會跟著前面的結果有所變化時才適合使用，簡單來說就是因為歸遞會從最開始的位置開始慢慢疊加，重複好幾次相同的行為，但其實我只要在每次的路徑上先加上
 * 前一個會走得路徑，就可以方便之後做計算，不過要理解這點最好是透過網路上的一些範例題目會更好理解，例如幾階的問題。
 */


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if(triangleSize==0) return 0;
    for(int i=1;i<triangleSize;i++){
        for(int j=0;j<triangleColSize[i];j++){
            if(j==0){ //最邊邊不需要選擇路徑。
                triangle[i][j] = triangle[i][j] + triangle[i-1][j];
            }else if(j==(triangleColSize[i] - 1)){ //最邊邊不需要選擇路徑。
                triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
            }else{ //非邊邊就需要從兩個最短路徑中，選出最小的值去前進即可。
                if(triangle[i-1][j-1] < triangle[i-1][j]){
                    triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
                }else{
                    triangle[i][j] = triangle[i][j] + triangle[i-1][j];
                }
            }
            if(i==(triangleSize-1) && j>0){ //找出最短的路徑，將結果放置於某個位置。
                if(triangle[i][j] < triangle[i][0]) triangle[i][0] = triangle[i][j];
            }
        }
    }
    //for(int i=0;i<triangleColSize[triangleSize-1];i++) printf("%d ", triangle[triangleSize-1][i]);
    return triangle[triangleSize-1][0];
}
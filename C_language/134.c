/*
 * 結果
 * Runtime : 112 ms Beats 90.1%of users with C
 * Memory  : 14.78MB Beats 65.19%of users with C
 */

/* 解題步驟
 * 這題其實比我預想的還要複雜許多，所以我的解題思維是參考網路上其他人的辦法，也就是先判斷第一點:
 * 什麼時候我能夠確定可以繞完一圈，那就是我的總油量 > 總消耗，透過總和每個index的 gas[i] - cost[i] 。
 * 這個判斷式會將答案從有解，無解分隔開來，那我們就能夠來到第二點，找到特定唯一的index就好。
 * 假設總油量 > 總消耗，那代表我們一定有解，那我們只要知道從哪個index開始，可以順利通過到假設是index+2的點，那代表index~index+2的路徑是一定可以通過的。
 * 通過代表到從index到index+2的總油量 - 總消耗 都會 > 0 ， 所以只要得到的結果會 < 0 ， 就代表車輛不是從index這個點開始的，接著只要從index+1之後
 * 繼續找即可找到唯一的解答
 */

/* 解題想法
 * 老實說這題有讓我覺得很怪的點，就是抵達的目的地，除非是終點，不然都會視為不能過(也就是剛好消耗完油量之後加油)，但可能是為了唯一解吧，不得而知。
 */

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    if(gasSize == 0) return 0;
    // gas_total = 總油量 cost_total = 總消耗 ans_total = 從特定index開始計算目前總油量>總消耗 pos = ans_total所指定的pos
    int gas_total = 0, cost_total = 0, ans_total = -1, pos = 0;
    for(int i=0;i<gasSize;i++){
        int temp = gas[i] - cost[i];
        if(ans_total == -1){ 
            if(temp > 0){
                ans_total = temp;
                pos = i;
            }
        }else{
            ans_total += temp;
            if(ans_total < 0) ans_total = -1;
        }
        gas_total+=gas[i];
        cost_total+=cost[i];
    }
    return gas_total >= cost_total ? pos : -1;
}
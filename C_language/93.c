/*
 * 這題我用的方式很單純，就是以後退的方式加上一些限制找出答案。
 * 由於題目的答案的要求為IP位址，所以我們可以推斷出相對應的大小，因而去限制一開始的答案長度是否正確，以及後續需要的字串長度。
 * 接著就到了需要使用repeat()函式的時候了，由於我打算限制我的記憶體使用量，所以我使用的記憶體數量是隨著答案的數量去做增加的。
 * 再來就是製作一個table，讓我去紀錄得到的正確IP位址，只要這個table是完整使用完題目所提供的所有IP位址，那他就是正確的答案。
 * 接著就以步驟的方式講解我的code:
 * 
 * 假設現在的題目為25525511135
 * 
 * 一 : 初期設定
 * step1 : 取得題目長度，確定是能夠取得合法IP位址的長度。
 * step2 : 設定一個初期提供的答案長度(byffer_length)，然後以此去做答案的記憶體配置。
 * step3 : 設置table的大小，以此為例，我的答案必定為255.255.111.35 或 255.255.11.135，以字串來看，長度為(14+1，1為結尾'\0')
 * 題目提供的為(11+1)，兩者相差3，但是以strlen(s)，得出的不會含'\0'，所以我們必須加上3，再補上1。
 * 二 : 將所有的資訊丟進遍歷迴圈中。
 * step1 : 是否將4個區塊的IP段落都填上了，這邊指的區塊為句點幫我們隔開的4段數字，以255.255.11.135為例，第一段為255,第二段為255,以此類推...
 * step2 : 如果沒有的話，先判斷我的table是否要先加上句點隔開。
 * step3 : 接著就嘗試將數字填入第一區，以temp暫存得到的數字，以此判斷大小是否超過範圍，last_range判斷剩餘的s_len長度是否足以讓剩餘的區域組成IP位址。
 * step4 : 如果以上兩點都合法，就可以將值填入table，繼續遍歷下個區段。
 *  ... 重複step1~4的步驟...
 * step5 : 當4個區塊的ip都填上了，代表我們已經有了完整的IP，那麼我們就能將table填入我們的答案了，但要記住的是要記得補上'\0'。
 * -------------------完成---------------------
 */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int repeat(char * s, int s_len, int s_pos, char* table, int table_len, int table_pos, char*** ans, int* buffer_length, int layer, int* returnSize){
    if(layer==4){
        if((*returnSize)==(*buffer_length)){
            (*buffer_length)*=2;
            char** temp = realloc((*ans), sizeof(char*)*(*buffer_length));
            if(temp==NULL){
                printf("memory allocation fail\n");
                exit(1);
            }
            (*ans) = temp;
        }
        table[table_pos++] = '\0';
        (*ans)[*returnSize] = malloc(sizeof(char)*table_pos);
        for(int i=0;i<table_pos;i++) (*ans)[*returnSize][i] = table[i];
        (*returnSize)++;
        return;
    }else{
        int temp = 0, last_range = 0;
        if(table_pos!=0) table[table_pos++] = '.';
        for(int i=0;i<3;i++){
            if(i==1 && s[s_pos] == '0') break;
            if(s_pos+i<s_len){
                temp = temp*10 + (s[s_pos+i] - '0');
                if(temp<0 || temp>255) break;
                last_range = s_len - (s_pos+i+1);
                table[table_pos+i] = s[s_pos+i];
                table[table_pos+i] = s[s_pos+i];
                if(last_range>=0 && last_range<=(3-layer)*3) repeat(s, s_len, s_pos+i+1, table, table_len, table_pos+i+1, ans, buffer_length, layer+1, returnSize);
            }
        }
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    int length = strlen(s);
    *returnSize = 0;
    if(length>12 || length<4) return NULL;
    int buffer_length = 10;
    char** ans = malloc(sizeof(char*)*buffer_length);
    char table[length+4];
    repeat(s, length, 0, table, length+4, 0, &ans, &buffer_length, 0, returnSize);
    return ans;
}
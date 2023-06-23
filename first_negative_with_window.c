#include <stdio.h>

void first_negative_with_window(int *arr, int arr_len,int k) {
    int result[arr_len - k + 1];
    int j =0; 
    int pos =0;
    int count =0;

    while (j < arr_len){

        if (arr[j] < 0){
            // append pos times.
            for (int i = 0; i < pos + 1; i++){
                result[count++] = arr[j];
            }
            pos =0;
        }
        else if (j <= (arr_len - k -1 )) {
            pos++;
        }
        // printf("j %d arr_len %d k %d pos %d arr %d\n",j,arr_len,k,pos,arr[j]);
        
        j++;
        
        // exit the loop if the last window not seeing positive element.
        if( (j>= (arr_len - k +1)) && (pos==0)){
            // printf("break");
            break;
        }
    }
    //print result array
    for (int i = 0; i < count; i++){
        printf("%d ", result[i]);
    }
}

int main(){
    //int arr[] = {8, -2, -3, 6, -10, -11, 15,12,-1,-2,3};
    int arr[] = {8, -2, -3, 6, -10, -11, 15};
    int k = 3;
    int arr_len =7;
    first_negative_with_window(arr,arr_len, k);
    return 0;
}

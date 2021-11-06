#include<stdio.h>
int list[3] = {1, 2, 3};
void Reverse(int list[], int length){
    length--;
    for ( int i = 0; i < length; i++){
        int temp = list[i];
        list[i] = list[length - i];
        list[length - i] = temp;
    }
}

int main(){
    int length = 3;
    Reverse(list, length);
    for( int i = 0; i < length; i++){
        printf("%d ", list[i]);
    }
}
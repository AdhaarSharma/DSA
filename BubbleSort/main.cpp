#include <iostream>

using namespace std;    

void BubbleSort(int input[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j+1<n-i; j++){
            if (input[j]>input[j+1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}

int main(){
    int array[]{2,4,5,8,1,3,7};
    BubbleSort(array,7);
    for(int i=0;i<7;i++){
        std::cout<<array[i]<<"\t";
    }
	return 0;
}


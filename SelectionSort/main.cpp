#include <iostream>

void SelectionSort(int input[],int n){
    for(int i=0;i<n-1;i++){
        int indexOfSmallest=i;
        for(int j=i+1;j<n;j++){
            if(input[indexOfSmallest]>input[j]){
                indexOfSmallest=j;
            }
        }
        //swap
        int temp=input[i];
        input[i]=input[indexOfSmallest];
        input[indexOfSmallest]=temp;
    }
}

int main(){
    int array[]{2,4,5,8,1,3,7};
    SelectionSort(array,7);
    for(int i=0;i<7;i++){
        std::cout<<array[i]<<"\t";
    }
	return 0;
}

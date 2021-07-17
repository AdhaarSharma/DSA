#include <iostream>
using namespace std;

void func(int k){
    k = 5;
}

void funcArray(int a[]){
    for(int i=0; i<10; i++){
        a[i]=9;
    }
}

int main(int argc, char **argv)
{
    int a=3;
    int b=4;
    func(a);
    cout<<a<<endl;
    func(b);
    cout<<b<<endl;
    int arr[10]{1,2,3,4,5,6,7,8,9,0};
    funcArray(arr);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<endl;
    }
    
	printf("hello world\n");
	return 0;
}

#include <iostream>

using namespace std;

void swapInt(int arg1, int arg2){
    int temp{arg1};
    arg1 = arg2;
    arg2 = temp;
}

void swapArray(int arr[], int arg1, int arg2){
    int temp{arr[arg1]};
    arr[arg1] = arr[arg2];
    arr[arg2] = temp;
}

void swapPointer(int* arg1, int* arg2){
    int temp{*arg1};
    *arg1 = *arg2;
    *arg2 = temp;
}

int main() {
    int a = 0, b=1;
    swapInt(a,b);
    cout << "ints: " << a << " " << b <<endl;

    int arr[] = {1,2,3,4};
    swapArray(arr,0,1);
    cout << "ints: " << arr[0] << " " << arr[1] <<endl;

    int c = 0, d = 1;
    swapPointer(&c, &d);
    cout << "ints: " << c << " " << d <<endl;

    return 0;
}





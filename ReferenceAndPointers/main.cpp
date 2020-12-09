#include <iostream>

using namespace std;

//int main() {
//    int x = 5;
//    int y = 15;
//    int *p1;
//    int *p2;
//
//    p1 = &x;       // x = 5 ; y =15
//    p2 = &y;       // x = 5 ; y =15
//    *p1 = 5;       // x = 5 ; y =15
//    *p1 = *p2;     // x = 15; y =15
//    p2 = p1;       // x = 15; y =15
//    *p1 = *p2 +10; // x = 25; y =15
//
//    return 0;
//}

void test(int& x, int* y, int** z){
    x++;
    y++;
    (*z)++;
}
int main(){
    int a = 7;
    int bb = 6;
    int* b = &bb;
    int** c = &b;
    test(a,b,c);
    cout<< a <<" "<< b << " "<< *c << endl; //8 7 7
    return 0;
}
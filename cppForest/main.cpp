#include <iostream>
//#include "./cgNode/cgNode.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;
    void swap(int *a, int*b){
        int t = *a;
        *a = *b;
        *b = t;
    }

    int main(){
        int a[10]{0};
        for (int i = 0; i < 10; i++){
            a[i] = (int)(rand() % 90 + 10);
        }
        int i = 0, j = 0;
        while (i < 10){
            j = i;
            while (j >= 0 && a[j + 1] < a[j]){
                swap(&a[j + 1], &a[j]);
                --j;
            }
            ++i;
        }
        for (int i = 0; i < 10; i++){
            cout << a[i] << endl;
        }
        return 0;
    }

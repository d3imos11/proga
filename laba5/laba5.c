#include <stdio.h>
//5
int function1(int A[], int n) {
    int i = 0; 
    while(A[i] > 0) {
        i++;
        if (i == n) 
            return 1;
    }
    return 0;
}
//15
void function2(int A[], int n) {
    int i, m;
    for (i = 0; i < n; i++) {
        for (m = 2; m < A[i]; m++) {
            if (A[i] % m == 0) 
                break;
        }
        if (m == A[i]) {
            for (int j = i; j < n - 1; j++) {
                A[j] = A[j + 1];
            }
            n--;
            i--;
        }
    }
}
//25
int function3(int c[], int n) {
    int i, j, k1, k2;
    for (i = 0; i < n; i++) {
        for (j = k1 = k2 = 0; j < n; j++) {
            if (c[i] != c[j]) {
                if (c[i] < c[j]) 
                    k1++;
                else 
                    k2++;
            }
        }
        if (k1 == k2) 
            return i;
    }
    return -1; 
}
//35 
void function4(int A[], int n) {
    int i, k, c;
    while (n != 0) {
        for (k = 0, i = 1; i < n; i++) {
            if (A[i] < A[k]) 
                k = i;
        }
        c = A[k]; A[k]=A[n-1]; A[n-1] = c;
        n--;
    }
}
//45 
int function5(int A[]) {
    int i, s;
    for (i = 1, s = 0; i < 10; i++) {
         if (A[i] > 0 && A[i - 1] < 0) 
             s++;
    }
    for (s = A[0], i = 1; i < 10; i++) {
         A[i - 1] = A[i];
    }
    A[9] = s;
    return s;
}

int main() {
    int A[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int B[] = {2, 4, 6, 8, 9, 10, 12, 14, 16, 18};
    int C[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n1 = 10, n2 = 10, n3 = 10;

    function1(A, n1);
    function2(B, n2);
    function3(C, n3);
    function4(A, n1);
    function5(A);

    return 0;
}
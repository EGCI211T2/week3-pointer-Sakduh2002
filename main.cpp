#include <iostream>
#include <iomanip>
#include <cstdlib>  

using namespace std;

int main(int argc, char *argv[]) {
    int *pa, *pb, i, temp;
    int n;

    
    if (argc > 1) {
        n = argc - 1;
        pa = new int[n];
        for (i = 0; i < n; i++) {
            pa[i] = atoi(argv[i+1]);
        }
    } else {
        cin >> n;
        pa = new int[n];
        for (i = 0; i < n; i++) {
            cin >> pa[i];
        }
    }

    cout << "Original: ";
    for (i = 0; i < n; i++) {
        cout << setw(3) << pa[i];
    }
    cout << endl;

    pb = pa + (n - 1);
    for (i = 0; i < n/2; i++) {
        temp = *pa;
        *pa = *pb;
        *pb = temp;
        pa++;
        pb--;
    }

    cout << "Reversed: ";

    pa = pa - (n/2);
    for (i = 0; i < n; i++) {
        cout << setw(3) << pa[i];
    }
    cout << endl;

    delete[] pa;
    return 0;
}
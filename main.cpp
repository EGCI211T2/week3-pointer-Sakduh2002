#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int *pa, *pb, i, temp;
    int n = 0;
    vector<int> nums;

    
    char* var_env = getenv("var");
    if (var_env != nullptr) {
        
        stringstream ss(var_env);
        int val;
        while (ss >> val) {
            nums.push_back(val);
        }
        n = nums.size();
    } else {
        
        cin >> n;
        for (i = 0; i < n; i++) {
            int val;
            cin >> val;
            nums.push_back(val);
        }
    }

    
    pa = new int[n];
    for (i = 0; i < n; i++) {
        pa[i] = nums[i];
    }

    
    cout << "Original: ";
    for (i = 0; i < n; i++) {
        cout << setw(3) << pa[i];
    }
    cout << endl;

    
    pb = pa + (n - 1);
    int *p = pa;
    for (i = 0; i < n / 2; i++) {
        temp = *p;
        *p = *pb;
        *pb = temp;
        p++;
        pb--;
    }

    cout << "Reversed: ";
    for (i = 0; i < n; i++) {
        cout << setw(3) << pa[i];
    }
    cout << endl;

    
    delete[] pa;
    return 0;
}
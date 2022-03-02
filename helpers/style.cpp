//
// Created by admin on 3/2/2022.
//

#include <iostream>
#include <iomanip>
using namespace std;

static void printLine(int n) {
    cout << setw(8);
    for (int i = 0; i < n; i++)
        (i < n - 1) ? (cout << "_") : (cout << endl);
}
#include <iostream>
#include "console.h"
#include "SimpleTest.h"
#include "perfect.h"
#include "soundex.h"
#include <chrono>

using namespace std;
using namespace std::chrono;


int main() {
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }

    auto start = high_resolution_clock::now();
//    findPerfects(1000);
    // Comment out the above line and uncomment below line 
    // to switch between running perfect.cpp and soundex.cpp
    soundexSearch("res/surnames.txt");

    cout << endl << "main() completed." << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;
    return 0;
}


// Do not remove or edit below this line. It is here to tom confirm that your code
// conforms to the expected function prototypes needed for grading
void confirmFunctionPrototypes() {
    long n = 0;
    bool b;
    string s;

    n = divisorSum(n);
    b = isPerfect(n);
    findPerfects(n);

    n = smarterSum(n);
    b = isPerfectSmarter(n);
    findPerfectsSmarter(n);

    n = findNthPerfectEuclid(n);

    s = lettersOnly(s);
    s = soundex(s);
    soundexSearch(s);
}

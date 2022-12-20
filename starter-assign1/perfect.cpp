/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include "console.h"
#include <iostream>
#include "SimpleTest.h" // IWYU pragma: keep (needed to quiet spurious warning)
using namespace std;

/* The divisorSum function takes one argument `n` and calculates the
 * sum of proper divisors of `n` excluding itself. To find divisors
 * a loop iterates over all numbers from 1 to n-1, testing for a
 * zero remainder from the division using the modulus operator %
 *
 * Note: the C++ long type is a variant of int that allows for a
 * larger range of values. For all intents and purposes, you can
 * treat it like you would an int.
 */
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

/* The isPerfect function takes one argument `n` and returns a boolean
 * (true/false) value indicating whether or not `n` is perfect.
 * A perfect number is a non-zero positive number whose sum
 * of its proper divisors is equal to itself.
 */
bool isPerfect(long n) {
    return (n > 0) && (n == divisorSum(n));
}

/* The findPerfects function takes one argument `stop` and performs
 * an exhaustive search for perfect numbers over the range 1 to `stop`.
 * Each perfect number found is printed to the console.
 */
void findPerfects(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: This smarterSum funcrion runs a loop from 1 to squrate root n
 * and directly compute what the corresponding pairwise factor for that
 * divisor. Return the sum of all divisior and its pairwais factor.
 */
long smarterSum(long n) {
    long total;
    if(n<=1){
        total = 0;
    }else{
        total = 1;
        for (long divisor = 2; divisor < sqrt(n); divisor++) {
            if (n % divisor == 0) {
                long pairDivisor = n / divisor;
                total += (divisor + pairDivisor);
            }
        }
    }
    return total;
}

/* The isPerfectSmarter function takes one argument `n` and returns
 * a boolean (true/false) value indicating whether or not `n` is perfect.
 * A perfect number is a non-zero positive number whose sum
 * of its proper divisors is equal to itself.
 */
bool isPerfectSmarter(long n) {
    /* TODO: Fill in this function. */
    return (n > 0) && (n == smarterSum(n));
}

/* The findPerfectsSmarter function takes one argument `stop` and performs
 * an exhaustive search for perfect numbers over the range 1 to `stop`.
 * Each perfect number found is printed to the console.
 */
void findPerfectsSmarter(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfectSmarter(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: The findNthPerfectEuclid function takes one arguement 'n'
 * and search and return nth Mersenne prime
 */
long findNthPerfectEuclid(long n) {
    long m = 0;
    long N = 0;
    long mp = 0;
    for(long k = 1; k<9999;k++){
        m = pow(2.0,k) - 1;
        mp = pow(2.0,k-1);
        if (smarterSum(m) == 1 && isPerfectSmarter(mp*m)){
            N++;
        }
       if (N==n){
            break;
        }
    }
    return mp*m;
}


/* * * * * * Test Cases * * * * * */

/* Note: Do not add or remove any of the PROVIDED_TEST tests.
 * You should add your own STUDENT_TEST tests below the
 * provided tests.
 */

PROVIDED_TEST("Confirm divisorSum of small inputs") {
    EXPECT_EQUAL(divisorSum(1), 0);
    EXPECT_EQUAL(divisorSum(6), 6);
    EXPECT_EQUAL(divisorSum(12), 16);
}

PROVIDED_TEST("Confirm 6 and 28 are perfect") {
    EXPECT(isPerfect(6));
    EXPECT(isPerfect(28));
}

PROVIDED_TEST("Confirm 12 and 98765 are not perfect") {
    EXPECT(!isPerfect(12));
    EXPECT(!isPerfect(98765));
}

PROVIDED_TEST("Test oddballs: 0 and 1 are not perfect") {
    EXPECT(!isPerfect(0));
    EXPECT(!isPerfect(1));
}

PROVIDED_TEST("Confirm 33550336 is perfect") {
    EXPECT(isPerfect(33550336));
}

PROVIDED_TEST("Time trial of findPerfects on input size 1000") {
    TIME_OPERATION(1000, findPerfects(1000));
}


// TODO: add your student test cases here

/*
 * Below is a suggestion of how to use a loop to set the input sizes
 * for a sequence of time trials.
*/
STUDENT_TEST("Multiple time trials of findPerfects on increasing input sizes") {

    int smallest = 10000, largest = 20000;

    for (int size = smallest; size <= largest; size *= 2) {
        TIME_OPERATION(size, findPerfects(size));
    }
}

STUDENT_TEST("Negative number is not perfect: confirm -12 and -9812 are not perfect"){
    EXPECT(!isPerfect(-12));
    EXPECT(!isPerfect(-9812));
}

STUDENT_TEST("smarterSum Test: test pervious number in divisorSum"){
    EXPECT_EQUAL(smarterSum(1), 0);
    EXPECT_EQUAL(smarterSum(6), 6);
    EXPECT_EQUAL(smarterSum(12), 16);
}

STUDENT_TEST("smarterSum Test: test negative number"){
    EXPECT_EQUAL(smarterSum(-1), 0);
    EXPECT_EQUAL(smarterSum(-19), 0);
}

STUDENT_TEST("smarterSum Test: test perfect number"){
    EXPECT_EQUAL(smarterSum(6), 6);
    EXPECT_EQUAL(smarterSum(28), 28);
    EXPECT_EQUAL(smarterSum(496), 496);
    EXPECT_EQUAL(smarterSum(8128), 8128);
}

STUDENT_TEST("findPerfectsSmarter Test: Time trial of findPerfectsSmarter") {
    int smallest = 20000, largest = 40000;

    for (int size = smallest; size <= largest; size *= 2) {
        TIME_OPERATION(size, findPerfectsSmarter(size));
    }
}

STUDENT_TEST("findNthPerfectEuclid Test: Test the nth Perfect number"){
    EXPECT_EQUAL(findNthPerfectEuclid(1),6);
    EXPECT_EQUAL(findNthPerfectEuclid(5),33550336);
}

STUDENT_TEST("findNthPerfectEuclid Test: Test the nth number is perect"){
    EXPECT(isPerfect(findNthPerfectEuclid(1)));
    EXPECT(isPerfect(findNthPerfectEuclid(3)));

}


#include "power.h"

/**
 * Calculates a to the power of b
 * @param a: base
 * @param b: power
 * @param c: result of the calculation
 * @return the value of c
 */
void power(int a, int b, int& c) {
    c = a;
    for (int i = 0; i < b-1; i++)
        c *= a;
}
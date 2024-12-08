#include <stdio.h>
#include "newton.h"

int main() {

    printf("\n");

    printf(" Testfunktion f1(x) = sin(x):\n");
    test(f1,3.0,3.0,3.5); /* Startwert nahe Pi */

    printf("\n Testfunktion f2(x) = x^2 - 3:\n");
    test(f2,2.0,1.0,4.0); /* Startwert nahe Wurzel 3 */

    printf("\n Testfunktion f3(x) = tan(x) - x:\n");
    test(f3,4.7,4.4,4.6); /* Startwert nahe der ersten Nullstelle x=4,49 von tan(x) - x */

    printf("\n Gesamt: Newton-Counter: %d || Bisection-Counter: %d || Regula-Falsi-Counter: %d \n",
        iteNewton,iteBisection,iteRegula);

    return 0;
}

#ifndef NEWTON_H
#define NEWTON_H
#define MAX_ITERATIONS 128 /* maximal number of iteration */
#define EPS 1.E-12 /* precision to reach */

/*
 * calculate point x with f(x)=0 within EPS precision.
 * If no solution found return IEEE NaN (not a number).
 *@param f function to use
 *@param x0 the starting point
 *@return x with f(x)=0 (or NaN in case of an error).
 */
double newton(double (*f)(double), double x0);
/*
 * calculate point x with f´(x)=0 within EPS precision.
 * @param f function to use
 * @param x the starting point
 * @return x with f´(x)=0.
 */
double dF (double (*f)(double), double x);

void test(double (*f)(double),double x,double a,double b);
double f1(double x);
double f2(double x);
double f3(double x);


/* global counter for newton-iteration  */
extern int iteNewton;

/* global counter for regula-iteration  */
extern int iteRegula;

/* global counter for bisection-iteration  */
extern int iteBisection;

/* Find x with f(x)=0 and a <= x <= b using bisection method
 * @param f function to use.
 * @param a left interval limit.
 * @param b right interval limit.
 * @return x with f(x)=0 (or NaN in case of an error).
 *
 */
double bisection(double (*f)(double), double a, double b);

/* Find x with f(x)=0 and a <= x <= b using falsi method
 * @param f function to use.
 * @param a left interval limit.
 * @param b right interval limit.
 * @return x with f(x)=0 (or NaN in case of an error).
 */
double regulafalsi(double (*f)(double), double a, double b);

#endif //NEWTON_H

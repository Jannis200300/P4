#include <math.h>
#include <stdio.h>
#include "newton.h"

int iteNewton = 0;
int iteBisection = 0;
int iteRegula = 0;

double f1(double const x) {
    return sin(x);
}
double f2(double const x) {
    double const help = pow(x,2)-3.0;
    return help;
}
double f3(double const x) {
    return tan(x)-x;
}

void test(double (*f)(double), double const x,double const a,double const b){

    double result_newton;
    double result_bisection;
    double result_regula;

    result_newton = newton(f,x);
    result_bisection = bisection(f,a,b);
    result_regula = regulafalsi(f,a,b);
    printf(" Mit dem Newton-Verfahren fuer x = %f, Nullstelle: %f \n",x,result_newton);
    printf(" Mit dem Bisektions-Verfahren fuer a = %f, b= %f Nullstelle: %f \n",a,b,result_bisection);
    printf(" Mit dem Regula-Falsi-Verfahren fuer a = %f, b= %f, Nullstelle: %f \n",a,b,result_regula);
}

double newton(double (*f)(double), double const x0) {

    double x_n,x_n_1,delta;
    int n=0;
    x_n = x0;
    double result_f;
    double result_dF;

    do {
        result_f = f(x_n);
        result_dF = dF(f,x_n);

        if (fabs(result_dF) < EPS) { /* Ableitung darf nicht zu klein sein */
            printf("Ableitung nahe Null, keine Konvergenz \n");
            return NAN;
        }

        x_n_1 = x_n; /* Speichern des Zwischenwertes */
        x_n = x_n - result_f / result_dF;  /* Newton-Verfahren mit x_n_1 = x_n - f(x)/f'(x) */
        delta = fabs(x_n - x_n_1);
        iteNewton++;
    }
    while (delta > EPS && ++n < MAX_ITERATIONS);

    if(n >= MAX_ITERATIONS) {
        printf("no convergence! \n");
        return NAN;
    }
    printf(" Zwischenwert : Newton-Counter: %d \n", n);
    return x_n;
}

double dF (double (*f)(double), double const x) {

    double h=0.1, df, df_0, err;
    df_0 = (f(x+h)-f(x-h))/(2*h);

    do {
        h /= 2.0;
        df = (f(x+h)-f(x-h))/(2*h);
        err = fabs(df-df_0);
        df_0 = df;
    }
    while (err > EPS);

    return df;
}

double bisection(double (*f)(double), double a, double b) {

   double ck;
    int n = 0;

    if(f(a)*f(b)>=0){
        printf("Fehler: f(a) und f(b) haben das gleiche Vorzeichen.\n");
        return NAN;
    }
        do {
            ck = (a+b)/2; /* Mittelpunkt berechnen & Definition der Methode */

            if (ck < EPS) { /* Genaugikeit erreicht */
                return ck;
            }
            /* Intervall anpassen */
            if(f(a)*f(ck)<0){
                b = ck; /* Nullstelle liegt links */
            }else {
                a = ck; /* Nullstelle liegt rechts */
            }
            iteBisection++;
        }
        while(fabs(a-b) > EPS && ++n < MAX_ITERATIONS); /* Genauigkeit und Iterationsanzahl Abfrage */

        if(n >= MAX_ITERATIONS) { /* Überprüfen, ob Konvergenz erreicht wurde */
            printf("no convergence! \n");
            return NAN;
        }
        printf(" Zwischenwert : Bisektion-Counter: %d \n", n);
        return ck;
}

double regulafalsi(double (*f)(double), double a, double b) {

    double c;
    int n=0;

    if(f(a)*f(b)>=0){
        printf("Fehler: f(a) und f(b) haben das gleiche Vorzeichen.\n");
        return NAN;
    }
    do {
        if (fabs(f(b)-f(a)) < EPS) {
            printf("Fehler: Division durch Null in Regula-Falsi.\n");
            return NAN;
        }
        c = b - f(b)*(b-a)/(f(b)-f(a)); /* Definiton der Methode */
        if (fabs(f(c)) < EPS) { /* Genaugikeit erreicht */
            printf(" Zwischenwert : Regula-Falsi-Counter: %d \n", iteRegula);
            iteRegula++;
            return c;
        }
        if(f(a)*f(c)<0) {
            b = c; /* linkes Intervall beibehalten */
        }else {
            a = c; /* rechtes Intervall beibehalten */
        }
        iteRegula++;

    if (n >= MAX_ITERATIONS) {
        printf("Fehler: Maximale Iterationsanzahl erreicht.\n");
        return NAN;
    }
    }
    while(fabs(a-b) > EPS && ++n < MAX_ITERATIONS); /* Genauigkeit und Iterationsanzahl Abfrage */
    printf(" Zwischenwert : Regula-Falsi-Counter: %d \n", n);
    return c;
}
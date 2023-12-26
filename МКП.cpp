#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления эксцентрической аномалии методом итераций
double eccentricAnomalyIterations(double M, double e, double epsilon) {
    double E = M; // начальное приближение

    while (true) {
        double delta_E = e * sin(E) - (E - M);
        E -= delta_E;

        if (fabs(delta_E) < epsilon)
            break;
    }

    return E;
}

// Функция для вычисления эксцентрической аномалии методом половинного деления
double eccentricAnomalyBisection(double M, double e, double epsilon) {
    double a = -M; // начальные границы отрезка
    double b = M;

    while (true) {
        double c = (a + b) / 2; // деление отрезка пополам

        double f_c = c - e * sin(c) - M;

        if (fabs(b - a) < 2 * epsilon || fabs(f_c) < epsilon)
            break;

        if (f_c * (a - M) < 0)
            b = c;
        else
            a = c;
    }

    return (a + b) / 2;
}

// Функция для вычисления эксцентрической аномалии методом золотого сечения
double eccentricAnomalyGoldenSection(double M, double e, double epsilon) {
    double a = -M; // начальные границы отрезка
    double b = M;

    double phi = (1 + sqrt(5)) / 2; // золотое сечение

    double c = a + (b - a) / phi;
    double d = b - (b - a) / phi;

    while (true) {
        double f_c = c - e * sin(c) - M;
        double f_d = d - e * sin(d) - M;

        if (fabs(b - a) < 2 * epsilon || fabs(f_c) < epsilon)
            break;

        if (f_c * f_d < 0) {
            b = d;
        }
        else {
            a = c;
        }

        c = b - (b - a) / phi;
        d = a + (b - a) / phi;
    }

    return (a + b) / 2;
}

// Функция для вычисления эксцентрической аномалии методом Ньютона
double eccentricAnomalyNewton(double M, double e, double epsilon) {
    double E = 0; // начальное приближение

    while (true) {
        double f_E = E - e * sin(E) - M;
        double f_E_prime = 1 - e * cos(E);

        double delta_E = f_E / f_E_prime;
        E -= delta_E;

        if (fabs(delta_E) < epsilon)
            break;
    }

    return E;
}

int main() {
    double M = 0.1;
    double e = 0.5;
    double epsilon = 0.0001;

    double E_iterations = eccentricAnomalyIterations(M, e, epsilon);
    double E_bisection = eccentricAnomalyBisection(M, e, epsilon);
    double E_golden_section = eccentricAnomalyGoldenSection(M, e, epsilon);
    double E_newton = eccentricAnomalyNewton(M, e, epsilon);

    cout << "E (Iterations method): " << E_iterations << endl;
    cout << "E (Bisection method): " << E_bisection << endl;
    cout << "E (Golden section method): " << E_golden_section << endl;
    cout << "E (Newton method): " << E_newton << endl;

    return 0;
}
#include <iostream>
#include <cmath>

const double epsilon = 1e-10; // Точность вычислений

// Уравнение Кеплера
double keplerEquation(double E, double M, double e) {
    return E - e * sin(E) - M;
}

// Часть 1. Метод итераций
double eccentricAnomalyByIteration(double M, double e) {
    double E = M; // Нулевая итерация
    double diff;

    do {
        diff = (E - e * sin(E) - M) / (1 - e * cos(E));
        E -= diff;
    } while (fabs(diff) > epsilon);

    return E;
}

// Часть 2. Метод половинного деления
//double eccentricAnomalyByBisection(double M, double e) {
    //double a = 0.0;
    //double b = M;
    //double c;

    //do {
        //c = (a + b) / 2;
        //double fc = keplerEquation(c, M, e);

        //if (fc == 0) {
            //break;
        //}
        //else if (fc * keplerEquation(a, M, e) < 0) {
            //b = c;
        //}
        //else {
            //a = c;
        //}
    //} while (fabs(b - a) > 2 * epsilon || fabs(keplerEquation(c, M, e)) > epsilon);

    //return c;
//}

// Часть 3. Метод золотого сечения
//double eccentricAnomalyByGoldenSection(double M, double e) {
    //const double goldenRatio = (1 + sqrt(5.0)) / 2;
    //double a = 0.0;
    //double b = M;
    //double c = b - (b - a) / goldenRatio;
    //double d = a + (b - a) / goldenRatio;

    //while (fabs(c - d) > epsilon || fabs(keplerEquation(c, M, e)) > epsilon) {
        //if (keplerEquation(c, M, e) == 0 || keplerEquation(d, M, e) == 0) {
            //break;
        //}
        //else if (keplerEquation(c, M, e) > 0) {
           //a = c;
       // }
        //else {
            //b = d;
        //}

        //c = b - (b - a) / goldenRatio;
        //d = a + (b - a) / goldenRatio;
    //}

    //return (fabs(keplerEquation(c, M, e)) < fabs(keplerEquation(d, M, e))) ? c : d;
//}

// Часть 4. Метод Ньютона
//double eccentricAnomalyByNewton(double M, double e) {
    //double E = 0.0; // Нулевая итерация

    //do {
        //double f = keplerEquation(E, M, e);
        //double df = 1 - e * cos(E);
        //E -= f / df;
    //} while (fabs(keplerEquation(E, M, e)) > epsilon);

    //return E;
//}

int main() {
    // Данные для уравнения Кеплера
    double M = 4.6 * pow(10, 24); // Средняя аномалия
    double e = 0.82764717; // Эксцентриситет

    // Вычисление эксцентрической аномалии
    double E_iteration = eccentricAnomalyByIteration(M, e);
    //double E_bisection = eccentricAnomalyByBisection(M, e);
    //double E_goldenSection = eccentricAnomalyByGoldenSection(M, e);
    //double E_newton = eccentricAnomalyByNewton(M, e);

    // Вывод результатов
    std::cout << "Eccentric Anomaly (Iteration): " << E_iteration << std::endl;
    //std::cout << "Eccentric Anomaly (Bisection): " << E_bisection << std::endl;
    //std::cout << "Eccentric Anomaly (Golden Section): " << E_goldenSection << std::endl;
    //std::cout << "Eccentric Anomaly (Newton): " << E_newton << std::endl;

    return 0;
}







#include <iostream>
#include <cmath>

double calculateEccentricAnomalyByIteration(double M, double e, double epsilon) {
    double E = M; // Начальное значение для E

    // Итеративный расчет E
    double delta;
    do {
        double f = E - e * sin(E) - M; // Уравнение Кеплера
        double f_prime = 1 - e * cos(E); // Производная функции
        delta = f / f_prime;
        E -= delta;
    } while (std::abs(delta) >= epsilon);

    return E;
}

double calculateEccentricAnomalyByBisection(double M, double e, double epsilon) {
    double a = -M;
    double b = M;
    double E;

    if (M < 0) {
        a = M;
        b = -M;
    }

    double f_a = a - e * sin(a) - M;
    double f_b = b - e * sin(b) - M;

    while (std::abs(b - a) >= 2 * epsilon) {
        E = (a + b) / 2;
        double f_E = E - e * sin(E) - M;

        if (f_a * f_E < 0) {
            b = E;
            f_b = f_E;
        }
        else {
            a = E;
            f_a = f_E;
        }
    }

    return E;
}

double calculateEccentricAnomalyByGoldenSection(double M, double e, double epsilon) {
    double a = -M;
    double b = M;

    if (M < 0) {
        a = M;
        b = -M;
    }

    const double phi = (1 + sqrt(5)) / 2; // Золотое сечение
    double c = a + (b - a) / phi;
    double d = b - (b - a) / phi;

    while (std::abs(b - a) >= 2 * epsilon) {
        double f_c = c - e * sin(c) - M;
        double f_d = d - e * sin(d) - M;

        if (f_c * f_d < 0) {
            a = c;
            b = d;
        }
        else {
            if (f_c < f_d) {
                a = d;
            }
            else {
                b = c;
            }
        }

        c = a + (b - a) / phi;
        d = b - (b - a) / phi;
    }

    return (a + b) / 2;
}

double calculateEccentricAnomalyByNewton(double M, double e, double epsilon) {
    double E = M; // Начальное значение для E

    // Итеративный расчет E
    double delta;
    do {
        double f = E - e * sin(E) - M; // Уравнение Кеплера
        double f_prime = 1 - e * cos(E); // Производная функции
        delta = f / f_prime;
        E -= delta;
    } while (std::abs(delta) >= epsilon);

    return E;
}

int main() {
    double r_p = 6511.8;
    double r_a = 69051.8;
    double a = (r_p + r_a) / 2;
    double e = 0.82764717;
    double M = 4,87 * 10^24;
    double epsilon = 1e-6;

    double E_iteration = calculateEccentricAnomalyByIteration(M, e, epsilon);
    double E_bisection = calculateEccentricAnomalyByBisection(M, e, epsilon);
    double E_golden_section = calculateEccentricAnomalyByGoldenSection(M, e, epsilon);
    double E_newton = calculateEccentricAnomalyByNewton(M, e, epsilon);

    std::cout << "Eccentric Anomaly by Iteration: " << E_iteration << std::endl;
    std::cout << "Eccentric Anomaly by Bisection: " << E_bisection << std::endl;
    std::cout << "Eccentric Anomaly by Golden Section: " << E_golden_section << std::endl;
    std::cout << "Eccentric Anomaly by Newton: " << E_newton << std::endl;
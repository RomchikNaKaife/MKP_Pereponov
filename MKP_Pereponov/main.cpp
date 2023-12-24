//
//  main.cpp
//  MKP_Pereponov
//
//  Created by Роман Перепонов on 19.12.2023.
//

#include <iostream>
#include <cmath>
#include <iomanip>

double iterateMethod(double M, double e, double epsilon) {
    double E = M;
    double E_next;

    do {
        E_next = e * sin(E) + M;
        if (abs(E_next - E) < epsilon) {
            break;
        }
        E = E_next;
    } while (true);

    return E_next;
}

double bisectionMethod(double M, double e, double epsilon) {
    double a = 0, b = M + e;
    double c = (a + b) / 2;

    while ((b - a) > epsilon) {
        c = (a + b) / 2;
        double f_c = c - e * sin(c) - M;

        if (abs(f_c) < epsilon) {
            break;
        } else if (f_c * (a - e * sin(a) - M) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}



double goldenSectionMethod(double M, double e, double epsilon) {
    double a = 0, b = M + e;
    double phi = (sqrt(5) + 1) / 2;
    double c, d, f_c, f_d;

    while ((b - a) > epsilon) {
        c = b - (b - a) / phi;
        d = a + (b - a) / phi;

        f_c = c - e * sin(c) - M;
        f_d = d - e * sin(d) - M;

        if (f_c < f_d) {
            b = d;
        } else {
            a = c;
        }
    }

    return (a + b) / 2;
}


double newtonMethod(double M, double e, double epsilon) {
    double E = M;
    double f_E, f_prime_E;

    do {
        f_E = E - e * sin(E) - M;
        f_prime_E = 1 - e * cos(E);
        E = E - f_E / f_prime_E;
    } while (abs(f_E) > epsilon);

    return E;
}


int main() {
    double M = 3.1416;
    double e =  0.9855;
    double epsilon = 1.000001;

    
    std::cout << "Итерационный метод: " << iterateMethod(M, e, epsilon) << std::endl;
    std::cout << "Метод половинного деления: " << bisectionMethod(M, e, epsilon) << std::endl;
    std::cout << "Метод Ньютона: " << newtonMethod(M, e, epsilon) << std::endl;
    std::cout << "Метод золотого сечения: " << std::fixed << std::setprecision(10) << goldenSectionMethod(M, e, epsilon) << std::endl;



    return 0;
}


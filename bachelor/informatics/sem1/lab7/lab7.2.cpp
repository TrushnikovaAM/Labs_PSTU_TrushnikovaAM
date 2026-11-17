#include <iostream>
#include <cmath>
#include <cstdarg>
#include <clocale>
using namespace std;

double calcAngle(double a, double b, double c) {
    double cosA = (b * b + c * c - a * a) / (2 * b * c);
    if (cosA > 1.0) cosA = 1.0;
    if (cosA < -1.0) cosA = -1.0;
    return acos(cosA) * 180.0 / 3.14159265358979323846;
}

void angles(int count, ...) {
    va_list args;
    va_start(args, count);

    if (count == 3) {
        double a = va_arg(args, double);
        double b = va_arg(args, double);
        double c = va_arg(args, double);

        if (a + b > c && a + c > b && b + c > a) {
            cout << "Углы треугольника: "
                 << calcAngle(a, b, c) << "°, "
                 << calcAngle(b, a, c) << "°, "
                 << calcAngle(c, a, b) << "°" << endl;
        } else {
            cout << "Треугольник с такими сторонами не существует!" << endl;
        }
    } else {
        cout << "Для " << count << " параметров вычисление углов невозможно." << endl;
    }

    va_end(args);
}

int main() {
    setlocale(LC_ALL, ".65001");

    int count;
    cout << "Введите количество сторон (3, 9 или 11): ";
    cin >> count;

    if (count == 3) {
        double a, b, c;
        cout << "Введите 3 стороны треугольника: ";
        cin >> a >> b >> c;
        angles(3, a, b, c);
    } 
    else if (count == 9) {
        double s1, s2, s3, s4, s5, s6, s7, s8, s9;
        cout << "Введите 9 сторон: ";
        cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9;
        angles(9, s1, s2, s3, s4, s5, s6, s7, s8, s9);
    }
    else if (count == 11) {
        double s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
        cout << "Введите 11 сторон: ";
        cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 >> s10 >> s11;
        angles(11, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11);
    }
    else {
        cout << "Некорректное количество сторон. Введите 3, 9 или 11." << endl;
    }

    return 0;
}
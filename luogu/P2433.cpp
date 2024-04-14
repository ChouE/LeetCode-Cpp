#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    double const pi = 3.141593;
    switch (T)
    {
    case 1:
        cout << "I love Luogu!";
        break;
    case 2:
        cout << 6 << " " << 4;
        break;
    case 3:
        cout << 14 / 4 << '\n' << 14 / 4 * 4 << '\n' << 14 - 14 / 4 * 4;
        break;
    case 4:
        cout << fixed << setprecision(3) << 500.0 / 3;
        break;
    case 5:
        cout << (220 + 260) / (20 + 12);
        break;
    case 6:
        cout << sqrt(6 * 6 + 9 * 9);
        break;
    case 7:
        cout << 110 <<'\n' << 90 << '\n' << 0;
        break;
    case 8:
        cout << 5 * 2 * pi << '\n' << pi * 5 * 5 << '\n' << 4.0 / 3 * pi * 125;
        break;
    case 9:
        cout << (((((1 + 1) * 2) + 1)*2) + 1) * 2;
        break;
    case 10:
        cout << 9;
        break;
    case 11:
        cout << 100.0 / 3;
        break;
    case 12:
        cout << 13 << "\nR";
        break;
    case 13:
        cout << (int)(pow(4.0 / 3 * pi * (4 * 4 * 4 + 10 * 10 * 10), 1.0 / 3));
        break;
    case 14:
        cout << 50;
        break;
    default:
        break;
    }
}
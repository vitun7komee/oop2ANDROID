#include "Angle.h"

enum actions
{
    copy, sum, dif, range,radian,
    comparison, out, end
};


int main()
{
    setlocale(0, "");

    Angle A, B;
    std::cout << " enter first angle  : ";
    std::cin >> A;
    std::cout << " enter second angle : ";
    std::cin >> B;
    std::cout << " awesome! " << std::endl;

    std::cout << " 0 - copy  1 - sum  2 - dif  3 - range " << std::endl;
    std::cout << " 4 - radian  5 - comparison  6 - out  7 - end session " << std::endl;
    Angle S, D;
    Angle K1, K2, T1, T2;
    Angle r1;
    Angle r2;
    int r = 0;
    for (int i = 0; i < 133; i++) {
        std::cout << " Select action : " << std::endl;
        std::cin >> r;
        switch (r) {
        case actions::copy:
            int l;
            std::cout << " 1 to 2 or 2 to 1 : ";
            std::cin >> l;
            if (l == 12) { A = B; }
            else if (l == 21) { B = A; }
            else { std::cout << "incorrect input \n"; }
            break;
        case actions::sum:
            S = A + B;
            std::cout << S;
            break;
        case actions::dif:
            std::cout << " 1 to 2 or 2 to 1 : ";
            int e;
            std::cin >> e;
            if (e == 12) {
                K1 = A - B;
                std::cout << K1;
            }
            else if (e == 21) {
                K2 = B - A;
                std::cout << K2;
            }
            else { std::cout << "incorrect input \n"; }
            break;
        case actions::comparison:
            A.operetorsrv(B); 
            break;
        case actions::radian:
            std::cout << " which one angle? " << std::endl;
            int i;
            std::cin >> i;
            if (i == 1) { std::cout << A.ConversionToRadians() << std::endl; }
            else if (i == 2) { std::cout << B.ConversionToRadians() << std::endl; }
            break;
        case actions::range:
            std::cout << " which one angle? " << std::endl;
            int j;
            std::cin >> j;
            r1 = A.range0360();
            r2 = B.range0360();
            if (j == 1) { std::cout << r1 << std::endl; }
            else if (j == 2) { std::cout << r2 << std::endl; }
            break;
        case actions::out:
            std::cout << " which one angle? " << std::endl;
            int k;
            std::cin >> k;
            if (k == 1) { std::cout << A; }
            else if (k == 2) { std::cout << B; }
            else { std::cout << "incorrect input \n"; }
            break;
        case actions::end:
            return 0;
            break;
        }
    }
}
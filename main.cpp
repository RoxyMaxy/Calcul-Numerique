#include <iostream>
#include <string>
#include "Fonction.h"
#include "Solve.h"

using namespace std;

int main()
{
    string expr;
    double a, b;

    cout << "f(x) = ";
    getline(cin, expr); //Equivalent à cin, mais ne s'arrête pas s'il rencontre un espace
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    Fonction f;
    f.initialiseur(expr);

    cout << f.estContinue(a, b) << endl;
    cout << f.estMonotone(a, b) << endl;

    Dichotomie d;
    Newton n;
    cout << d.resoudre(f, a, b) << endl;
    cout << n.resoudre(f, a, b) << endl;

    return 0;
}

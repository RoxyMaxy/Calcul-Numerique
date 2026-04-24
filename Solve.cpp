#include "Solve.h"
#include <cmath>
#include <iostream>

using namespace std;

double Dichotomie::resoudre(Fonction& f, double a, double b, double precision, int maxIterations)
{
	double fGauche = f(a); //f(a)
	double fDroite = f(b); //f(b)
	double milieu, fMilieu;
	int i;

	if (fGauche * fDroite > 0.0) //Cas où f(a) et f(b) de même signe
	{
		cout << "Les valeurs f(" << a << ") et f(" << b << ") sont de même signe\n\t=>Recherche de racines avec la méthodes de Dichotomie: impossible." << endl;
		return 0;
	}

	if (!f.estContinue(a, b))
	{
		cout << "Fonction non-continue sur [" << a << ", " << b << "]\n\t=>Recherche de racines avec la méthodes de Dichotomie: impossible." << endl;
		return 0;
	}
	
    for (i = 0; i < maxIterations; i++)
    {
    	milieu = (a + b) / 2.0;
        fMilieu = f(milieu);

        if (abs(fMilieu) < precision || (b - a) / 2.0 < precision)
        {
            return milieu; //Racine
        }

        if (fGauche * fMilieu < 0.0)
        {
            b = milieu;
            fDroite = fMilieu;
        }
        else
        {
            a = milieu;
            fGauche = fMilieu;
        }
    }
    return milieu;
}

double Newton::resoudre(Fonction& f, double a, double b, double precision, int maxIterations)
{
    double xCourant = (a + b) / 2.0;
	int i;
	double fx, fdx;
    for (i=0; i < maxIterations; i++)
    {
        fx = f(xCourant); // f(x_n)

        if (abs(fx) < precision)
        {
            return xCourant;
        }

        fdx = f.derivee(xCourant); // f'(x_n)

        if (abs(fdx) < 1e-7)
        {
            cout << "Dérivée trop petite (point stationnaire)\n\t=>Usage de méthode de Newton-Raphson impossible." << endl;
            return 1;
        }
        xCourant = xCourant - fx / fdx; // Formule de Newton : x_{n+1} = x_n - f(x_n) / f'(x_n)
    }

    cout << "La fonction ne converge pas en " << maxIterations << " iterations.\n"; // Si on n'a pas convergé dans le nombre d'itérations
    return 1;
}

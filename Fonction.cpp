#include "Fonction.h"
#include <sstream> //Pour la conversion des string en nombre

Fonction::Fonction()
{
}

string Fonction::getExpression()
{
	return expression;
}

void Fonction::initialiseur(string& expr) //Utile pour éviter les erreurs de valeurs
{
	expression = expr;
	analyseur.SetExpr(expression); //Envoie l'expression à muParser
	analyseur.DefineVar("x", &varX); //Attribue x à varX
}

double Fonction::operator() (double x)
{
	varX = x;
	return analyseur.Eval(); //Calcul du résultat de la fonction en x
}

double Fontion::derivee (double x, double h)
{
	double valPlus = (*this)(x+h); //f(x+h)
	double valMoins = (*this)(x-h); //f(x-h)

	return (valPLus - valMoins) / (2.0 * h);
}

bool Fonction::estContinue(double a, double b, int precision)
{
	int i;
	double xActuel, fx;
	double pas = (b - a) / precision; //Calcule l'écart entre deux points
	for (i=0. i<=precision; i++)
		{
			xActuel = a + (i*pas);
			fx = (*this)(xActuel); //Calcul de f(x)

			if(isnan(fx) || isinf(fx)) //Au cas où la valeur de f(x) n'est pas un "nombre" ou est infinie
			{
				return false;
			}
		}
	return true;
}

bool Fonction::estMonotone(double a, double b, double precision)
{
	int i;
	int signePrecedent = 0;
	int signeActuel;
	double pas = (b - a) / precision;
	double xActuel, valDerivee;

	for (i=0; i<=precision; i++)
	{
		signeActuel = 0;
		xActuel = a + (i*pas);
		valDerivee = derivee(xActuel); //C'est f'(x)
	
		if (valDerivee > 1e-7)
		{
			signeActuel = 1; //Signe positif
		}
		else if (valDerivee < 1e-7)
		{
			signeActuel = -1; //Signe négatif
		}
	
		if (signeActuel != 0)
		{
			if (signePrecedent == 0)
			{
				signePrecedent = signeActuel;
			}
			else if ( signeActuel != signePrecedent)
			{
				return false; //Cas de changement de signe, donc non-monotone
			}
		}
	}
	return true;
}

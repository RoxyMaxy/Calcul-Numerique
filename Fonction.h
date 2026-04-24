#ifndef FONCTION_H
#define FONCTION_H

#include <string>
#include <cmath>
#include "muParser.h"

using namespace std;
using namespace mu;

class Fonction
{
	private:
		string expression; //C'est l'expression de la fonction que l'utilisateur entre
		mutable Parser analyseur; //C'est ce qui coupe et comprend l'expression
		mutable double varX; //"mutable" met la variable en mode 'write', modifiable; varX est le coefficient lié à la variable x de la fonction
	
	public:
		Fonction(); //constructeur
		void initialiseur(strin& expr);
		double operator() (double x) const;
		double derivee (double x, double h = 1e-5) const;
		bool estVontinue(double a, double b, precision = 100) const;
		bool estMonotone(double a, double b, precision = 100) const;
		string getExpression() const;
}
#endif

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
		void initialiseur(string& expr);
		double operator() (double x);
		double derivee (double x, double h = 1e-5);
		bool estContinue(double a, double b, int precision = 100);
		bool estMonotone(double a, double b, int precision = 100);
		string getExpression();
};
#endif

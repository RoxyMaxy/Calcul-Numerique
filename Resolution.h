#ifndef RESOLUTION_H
#define RESOLUTION_H

#include "Fonction.h"

class Solve
{
	public:
		virtual double resoudre(Fonction& f, double a, double b, double precision=1e-5, int maxIterations=100) = 0;
		virtual ~Solve(){}
};

class Dichotomie: public Solve
{
	public:
		double resoudre(Fonction& f, double a, double b, double precision=1e-5, int maxIterations=100) override;
};

class Newton: public Solve
{
	public:
		double resoudre(Fonction& f, double a, double b, double precision=1e-5, int maxIterations=100) override;
};
#endif

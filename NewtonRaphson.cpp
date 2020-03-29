# include <cmath>
# include <iostream>
// Exemplifies pointer functions
// Implementation of Newton-Raphson root search method

double firstDeriv(double (*pFunc)(double), double x);

double solveNewtonRaphson(double (*pFunc)(double), double guess)

{
	double x = guess;
	double step;
	do 
	{ 
		step = (*pFunc)(x) / firstDeriv((*pFunc), x);
		x -= step;
	} while (fabs(step) > 1.0e-5);
	return x;
}

double Sqrt2(double x)
{
	return sqrt(x) - 2;
}

double Pow3(double x)
{
	return x*x*x - 2*x - 300;
}

double functionalTest(double (*myFunc)(double*), double* x)
{
	return pow((*myFunc)(x),2);
}

double MyTest1(double *x)
{
	return x[1] * x[2] * x[2] - 2 * x[2] - 300;
}

double MyTest(double *x) // (double x[]) also works
{
	return x[0]*x[1]*x[2];  
}

double firstDeriv(double (*pFunc)(double), double x)
{
	return ((*pFunc)(x + 0.001) - (*pFunc)(x - 0.001)) / 0.002;
}

int main()
{
	/*std::cout << "root sqrt(x)=2, with guess 1.0 is " 
			  << solveNewtonRaphson(Sqrt2, 1.0) << "\n";
	std::cout << "x^3-2*x=300 with guess 1.0 is "
		<< solveNewtonRaphson(Pow3, 1.0) << "\n";
		*/

	double* x;
	x = new double[3];
	x[0] = 1.0; x[1] = 2.0; x[2] = 3.0;
	//std::cout << MyTest(x) << std::endl;
	std::cout << functionalTest(MyTest,x) << std::endl;
	return 0;

}
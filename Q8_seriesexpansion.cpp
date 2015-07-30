#include <iostream>
#include <math.h>

using namespace std;

long double sineOrCosine(double input, int terms, bool sine);
long double factorial(int n);


int main()
{
	double input;
	char charInput;
	bool sine;
	int terms;

	cout << "Enter s for sine or c for cosine: ";
	cin >> charInput;
	

	cout << "Enter the function input: ";
	cin >> input;

	cout << "Enter number of terms: ";
	cin >> terms;
	

	if(charInput == 's')
		cout << "sine(" << input << ") = " << sineOrCosine(input, terms, true) << endl;
	else if(charInput == 'c')
		cout << "cos(" << input << ") = " << sineOrCosine(input, terms, false) << endl;

	return 0;

}


long double sineOrCosine(double input, int terms, bool sine)
{

	long double result = 0;
	long double exponent;
	long double constant;


	if(sine == true)
	{
		for(int i = 0; i < terms; i++)
		{
			exponent = i*2+1;
			constant = pow(-1,i)/factorial(i*2+1);
			result += pow(input, exponent) * constant;

			cout << i << "th term: ";
			cout << pow(-1,i) << " * " << pow(input, exponent) << " / ";
			cout << factorial(i*2+1) << " = " << pow(input, exponent) * constant << endl;

		}
		
		return result;
	}


	else
	{
		for(int i = 0; i < terms; i++)
		{
			exponent = i*2;
			constant = pow(-1,i)/factorial(i*2);
			result += pow(input, exponent) * constant;

			cout << i << "th term: " << pow(input, exponent) * constant << endl;
		}
		
		return result;
	}
}


long double factorial(int number)
{
   long double factorial = 1;

   for (int i = 1; i <= number; i++)
      factorial = factorial * i;

   return factorial;
}


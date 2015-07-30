#include <iostream>

using namespace std;

int main()
{
	double numinput;
	double result =2;
	int iter;

	cout << "\nPlease input a number to find its square root: ";
	cin >> numinput;
	cout << "Iterations: ";
	cin >> iter;
	cout << endl;


	for(int index = 0; index < iter; index++)
		result = result - (result*result - numinput)/(2*result);

	cout << result << endl;

}

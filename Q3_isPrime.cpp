#include <iostream>
#include <math.h>

using namespace std;

bool * isPrime(int input_num);

int main()
{
	int primes_up_to;
	cout << "Enter a number up to which all primes will be listed:";
	cin >> primes_up_to;
	bool * primelist = isPrime(primes_up_to);

	int newline_count = 0;
	for(int index = 2; index < primes_up_to; index++)
	{
		if(newline_count == 10)
			{
				cout << endl;
				newline_count = 0;
			}
		if(primelist[index] == 1)
		{
			cout << index << '\t';
			newline_count++;
		}
	}
	delete primelist;
	
	
		
	cout << endl;

return 0;

}

bool * isPrime(int input_num)
{
	bool * natural_numbers = new bool[input_num + 1];
	fill_n(natural_numbers, input_num + 1, true);  //a boolean array for marking numbers from 2 to n where any index i equals the natural number i+2 (index 0 equals 2, index n-2 equals n)
	int prime;
	int multiplier;

	int p = 2;
	for(p*p + p*multiplier; p*p + p*multiplier <= input_num; multiplier++)
		natural_numbers[p*p + p*multiplier] = false;


	for(p=3; p<=pow(input_num, 0.5); p += 2) //not exceeding sqrt n
	{

		multiplier = 0;
		for(p*p + p*multiplier; p*p + p*multiplier <= input_num; multiplier++)
			natural_numbers[p*p + p*multiplier] = false;

	}
	return natural_numbers;
}



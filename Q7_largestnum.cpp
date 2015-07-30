#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;

int findLargest(int numArray[], int size);
int max(int num1, int num2);

int main()
{
	
	vector<int> numVect;
	int arraySize;
	cout << "Please input the desired array size: ";
	cin >> arraySize;

	int tempInt;

	cout << "Input each element followed by the 'enter' key" << endl;
	for(int i = 0; i < arraySize; i++)
	{
		cin >> tempInt;
		numVect.push_back(tempInt);
	}
			
		

	int numArray[arraySize];
	copy(numVect.begin(), numVect.end(), numArray);

	int size = sizeof(numArray)/sizeof(numArray[0]); 

	cout << endl << "The largest number of the array is: " << findLargest(numArray, size) << endl;

	return 0;
}

int findLargest(int numArray[], int size)
{	
	if(size == 1)
		return numArray[0];

	else
		return max(numArray[size-1], findLargest(numArray, size-1));
}

int max(int num1, int num2)
{
	if(num1 > num2)
		return num1;
	else
		return num2;
}

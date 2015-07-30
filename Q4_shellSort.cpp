#include <iostream>
#include <cstdlib>

using namespace std;

int * shellSort(int * numArray);

int main()
{
	int numArray[16384];

	for(int i = 0; i < 16384; i++)
		numArray[i] = rand();

/* Uncomment to print unsorted array
	for(int i = 0; i < 16384; i++)
	{
		cout << i << ": " << numArray[i] << '\t';

		if(i%5 == 0)
			cout << endl;
	}
	cout << endl;

*/

	shellSort(numArray);

/* Uncomment to print sorted array
	for(int i = 0; i < 16384; i++)
	{
		cout << i << ": " << numArray[i] << '\t';

		if(i%5 == 0)
			cout << endl;
	}
	cout << endl;

*/
	bool isSorted = true;
	for(int i = 1; i < 16384; i++)
	{
		if(numArray[i]<numArray[i-1])
		{
			cout << "Sequence not sorted" << endl;
			isSorted = false;
			break;
		}
	}
	if(isSorted == true)
		cout << "Sequence is sorted" << endl;

}


int* shellSort(int * numArray)
{
	//gap sequence with 8 elems
	int gapsequence[] = {701, 301, 132, 57, 23, 10, 4, 1};
	int index;
	int index1;
	int index2;
	int index3;

	for(index1 = 0; index1 < 8; index1++)
	{
		for(int index2 = gapsequence[index1]; index2<16384; index2++)
		{
			int temp = numArray[index2];

			for(index3 = index2; index3 >= gapsequence[index1] && numArray[index3-gapsequence[index1]] > temp; index3 -= gapsequence[index1])
			{
				numArray[index3] = numArray[index3-gapsequence[index1]];

			}

			numArray[index3] = temp;
		}

	}
}

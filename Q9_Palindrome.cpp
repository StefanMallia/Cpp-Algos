#include <iostream>
#include <vector>
#include <locale>

using namespace std;

bool isPalindrome(string inputstring);

int main()
{
	string input_string;

    cout << "Please input a string:\n" << endl;
	getline(cin, input_string); 
	//cin stops at ' ' so getline is used instead
	cout << endl;

	if(isPalindrome(input_string))
		cout << "This is a palindrome." << endl;

	else
		cout << "This is not a palindrome." << endl;

	return 0;

}

bool isPalindrome(string input_string)
{
	vector<char> charVector;
	for(int iter = 0; iter < input_string.length(); iter++)
	{	//check if either uppercase or lowercase letters
		//ignore all other chars

		if(isupper(input_string[iter]))
			charVector.push_back(tolower(input_string[iter]));

		else if(islower(input_string[iter]))
			charVector.push_back(input_string[iter]);
	}

	int	size = charVector.size();

	for(int iter = 0; iter < size/2; iter++)
	{	//iterate from beginning and end towards middle and compare

		if (charVector[iter] != charVector[(size-1)-iter])
			return false;
	}

	return true;
}


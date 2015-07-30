#include <iostream>
#include <string>

using namespace std;

string dec_to_rom(unsigned int value);



int main()
{
	int numinput;	
	cout << "Pick an integer from 1 to 1024 to convert to a roman numeral: ";
	cin >> numinput;

	if(numinput < 1 || numinput > 1024)
		cout << "\nPlease input a range from 1 to 1024\n" << endl;
	else
		cout << "\nRoman numeral is: " + dec_to_rom(numinput) + '\n' << endl;

	return 0;

}


string dec_to_rom(unsigned int value)
{
    struct Rom_node
	{
		unsigned int Dec_num;
		char const* Rom_num; 
	};


    const struct Rom_node roman_array[] =
    {
            {1000, "M"}, {900, "CM"},
            {500, "D"}, {400, "CD"},
            {100, "C"}, { 90, "XC"},
            { 50, "L"}, { 40, "XL"},
            { 10, "X"}, { 9, "IX"},
            { 5, "V"}, { 4, "IV"},
            { 1, "I"},
            { 0, NULL} 
    };

	string result;
	int roman_index = 0;

	while(value > 0)
	{
		if(value >= roman_array[roman_index].Dec_num)
		{		
			result += roman_array[roman_index].Rom_num;
			value -= roman_array[roman_index].Dec_num;
		}
		else
			roman_index += 1;
	}

	return result;
}

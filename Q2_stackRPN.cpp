#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

bool is_num(const string& input_string);
double conv_to_double(const string& input_string);
bool is_operat(const string& input_string);
void operate(const string& input_string, stack<double>& rpnStack);
void printcontents(stack<double>& rpnStack);

int main()
{
	stack<double> rpnStack;

	cout << "\nRPN calculator\nEnter 'q' to quit and 'c' to list stack contents" << endl;
	string input_string;

	while(true)
	{
		cout << ">>";

		cin >> input_string;

		double num;
		if(is_num(input_string))
			rpnStack.push(conv_to_double(input_string));

		else if(is_operat(input_string) && rpnStack.size()>1)
			operate(input_string, rpnStack);

		else if(input_string == "q")
			return 0;

		else if(input_string == "c")
			printcontents(rpnStack);

		else
			cout << "Invalid input" << endl;


	}

	return 0;
}

bool is_num(const string& input_string)
{
	const char * c_input_string = input_string.c_str();
	//convert to string

	char* endPointer = '\0';
	strtod(c_input_string, &endPointer);

	if(*c_input_string == '\0')
		return false;

	if(*endPointer !=  '\0' || endPointer == c_input_string)
		return false;

	return true;
}

double conv_to_double(const string& input_string)
{
	const char * c_input_string = input_string.c_str();
	char* endPointer = '\0';

	return strtod(c_input_string, &endPointer);
}


bool is_operat(const string& input_string)
{
	string operators[] = {"+", "-", "*", "/"};

	for(int iter = 0; iter < 4; iter++)
	{
		if(input_string == operators[iter])
			return true;
	}
	return false;
}

void operate(const string& input_string, stack<double>& rpnStack)
{
	double lvalue, rvalue, result;

	rvalue = rpnStack.top();
	rpnStack.pop();

	lvalue = rpnStack.top();
	rpnStack.pop();

	if(input_string == "+")
		result = lvalue + rvalue;
	
	else if(input_string == "-")
		result = lvalue - rvalue;

	else if(input_string == "*")
		result = lvalue * rvalue;

	else if(input_string == "/")
		result = lvalue / rvalue;

	cout << result << endl;
	rpnStack.push(result);


}

void printcontents(stack<double>& rpnStack)
{
	for(stack<double> copy = rpnStack; !copy.empty(); copy.pop())
		cout << copy.top() << endl;

}

		
		

#include "Bantuan.h"
#include "Stack.h"


char token; // variable for reading a charactor
Stack *st;

void GotError()
{
	puts("error found.\nplease check your input message.");
	exit(1);
}

void CheckAndGetChar(char tmp)
{
	if(tmp != token){
		GotError();
	}
	token = getchar();
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate addition and subtraction
 */
double sum()
{
	double temp = term();
	Data DataNumber;
	while(token == '+' || token == '-')
	{
		if(token == '+')
		{
			DataNumber.Operation = '+';
			CheckAndGetChar('+');
			temp += term();
			push(st, DataNumber, TRUE);
		}
		else if(token == '-')
		{
			DataNumber.Operation = '-';
			CheckAndGetChar('-');
			temp -= term();
			push(st, DataNumber, TRUE);
		}
	}
	return temp;
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate multiple and devision
 */
double term()
{
	double temp = factor();
	Data DataNumber;
	while(token == '*' || token == '/')
	{
		if(token == '*')
		{
			DataNumber.Operation = '*';
			CheckAndGetChar('*');
			temp *= factor();
			push(st, DataNumber, TRUE);
		}
		else if(token == '/')
		{
			DataNumber.Operation = '/';
			CheckAndGetChar('/');
			temp /= factor();
			push(st, DataNumber, TRUE);
		}
	}
	return temp;
}

/** \brief
 * push data in the stack with the method of post-fix
 * regards factor as a number
 */
double factor()
{
	double temp = 0.0;
	Data DataNumber;
	if(token == '(')
	{
		// start with new sum again
		CheckAndGetChar('(');
		temp = sum();
		CheckAndGetChar(')');
	}
	else if(token == '-')
	{
		// negation
		CheckAndGetChar('-');
		DataNumber.Operation = '-';
		temp = -factor();
		push(st, DataNumber, TRUE);
		return temp;
	}
	else if(token == '+')
	{
		// there is no meaning, but just exception dealing
		CheckAndGetChar('+');
		return factor();
	}
	else if(isdigit(token))
	{
		ungetc(token, stdin);
		scanf("%lf", &temp);
		DataNumber.Number = temp;
		push(st, DataNumber, FALSE);
		token = getchar();
	}
	else GotError();
	return temp;
}

void Menu(){
	
}



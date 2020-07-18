#include "Kalkulator.h"
#include "Stack.h"
#include "Tree.h"


char token; // variable for reading a charactor
Root *root;
Stack *st;

void GotError(){
	puts("Error.\nperiksa kembali masukan anda.");
	exit(1);
}

void CheckAndGetChar(char tmp){
	if(tmp != token){
		GotError();
	}
	token = getchar();
}

/* Push data stack dengan metode postfix 
 * Menghitung operasi penjumlahan dan pengurangan
 */
double sum(){
	double temp = term();
	Data DataNumber;
	while(token == '+' || token == '-'){
		if(token == '+'){
			DataNumber.Operation = '+';
			CheckAndGetChar('+');
			temp += term();
			PushStackNode(st, DataNumber, TRUE);
		}
		else if(token == '-'){
			DataNumber.Operation = '-';
			CheckAndGetChar('-');
			temp -= term();
			PushStackNode(st, DataNumber, TRUE);
		}
	}
	return temp;
}

//Menghitung operasi perkalian dan pembagian
double term(){
	double temp = factor();
	Data DataNumber;
	while(token == '*' || token == '/'){
		if(token == '*'){
			DataNumber.Operation = '*';
			CheckAndGetChar('*');
			temp *= factor();
			PushStackNode(st, DataNumber, TRUE);
		}
		else if(token == '/'){
			DataNumber.Operation = '/';
			CheckAndGetChar('/');
			temp /= factor();
			PushStackNode(st, DataNumber, TRUE);
		}
	}
	return temp;
}

//menganggap faktor sebagai angka
double factor(){
	double temp = 0.0;
	Data DataNumber;
	if(token == '('){
		// dimuali dengan sum lagi
		CheckAndGetChar('(');
		temp = sum();
		CheckAndGetChar(')');
	}
	else if(token == '-'){
		// negasi
		CheckAndGetChar('-');
		DataNumber.Operation = '-';
		temp = -factor();
		PushStackNode(st, DataNumber, TRUE);
		return temp;
	}
	else if(token == '+'){
		CheckAndGetChar('+');
		return factor();
	}
	else if(isdigit(token)){
		ungetc(token, stdin);//untuk mereplace input (token)
		scanf("%lf", &temp);
		DataNumber.Number = temp;
		PushStackNode(st, DataNumber, FALSE);
		token = getchar();
	}
	else GotError();
	return temp;
}


double powerof(){
	double temp=term();
	Data DataNumber;
	
	if(token == '#'){
		CheckAndGetChar('#');
		DataNumber.Operation = '#';
		temp=sqrt(factor());
		PushStackNode(st, DataNumber, TRUE);
	}
	else{
		temp = factor ();
	}
	while(token== '^'){//cek untuk operasi pangkat
		if(token== '^'){
			DataNumber.Operation= '^';
			CheckAndGetChar('^');
			temp=pow(temp,factor());
			PushStackNode(st,DataNumber,TRUE);
		}
	}
	return temp;
}

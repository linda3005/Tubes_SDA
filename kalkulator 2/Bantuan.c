#include "Bantuan.h"
#include "Stack.h"
#include "Tree.h"


char token; // variable for reading a charactor
Root *root;
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

//void input_awal(){
//	double value;
//	StackNode tmp;
//	NodeOfTree *tn = NULL;
//	/// make info structures for each cases
//	root = CreateRootNode();
//	st = make_stack();
//	
//	printf("Masukkan Operasi Bilangan :\n");
//
//	/// process
//    token = getchar();
//    value = sum();
//	// now, stack is already built
//
//	/// construct tree
//	while(!isEmpty_stack(st))
//	{
//		// As the stack is being removed, constructs tree
//		tmp = pop(st);
//		while(tmp.key)
//		{
//			// operator
//			tn = make_child(tn, tmp.info, tmp.key);
//			if(root->root == NULL)	root->root = tn;
//			tmp = pop(st);
//		}
//		// number
//		tn = make_child(tn, tmp.info, tmp.key);
//		if(root->root == NULL)	root->root = tn;
//	}
//	
//}
//
//void Menu(){
//	double value;
//	int input_token;
//
//	printf("Pilih yang akan di tampilkan :\n");
//	printf("1. Hasil Kalkulasi\n");
//	printf("2. Tampilan Berdasarkan Ekspresi Prefix\n");
//	printf("3. Kembali Memasukkan Operasi (jika salah memasukkan operasi)\n");
//	printf("4. Tampilkan Hasil Kalkuasi dan Ekspresi Prefix\n");
//	printf("5. Keluar\n");
//	printf("Masukkan pilihan Menu:");scanf("%d", &input_token);
//	if(input_token==1){
//			value = sum();
//			printf("Evaluation result : %g\n", value);
//    		printf("\n");
//	}else if (input_token==2){
//			 printf("prefix : ");
//    	AllTraversal(root, PREORDER);//prefix using preorder
//    	printf("\n");
//	}else if (input_token==3){
//		system("CLS");
//		input_awal();
//	}else if (input_token==4){
//		value=sum();
//			printf("Evaluation result : %g\n", value);
//    		printf("\n");
//    		printf("prefix : ");
//    		AllTraversal(root, PREORDER);//prefix using preorder
//    		printf("\n");
//	}else if (input_token==5){
//		exit(1);
//	}else{
//		printf("Masukkan Input yang benar");
//		return Menu();
//	}
//}



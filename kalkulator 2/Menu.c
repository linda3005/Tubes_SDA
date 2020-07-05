#include <stdio.h>
#include <stdlib.h>
#include "Common.h"
#include "Tree.h"
#include "Stack.h"

void  Menu(){
	int x;
	printf("1. Hasil perhitungan matematika\n");
	printf("2. urutan tree berdasarkan inorder (infix)\n");
	printf("3. ururtan tree berdasarkan preorder (prefix)\n");
	printf("4. urutan tree berdasarkan postorder (posfix)\n");
	printf("5. Tampilkan semua\n");
	printf("6. Exit\n");
	
	scanf("&x",%d);
	
	switch(x){
		case 1:
			printf("Hasil : %g\n",value);
			break;
		case 2:
			printf("Infix :\n");
			traversal(root, INORDER);
			break;
		case 3:
			printf("Prefix : \n");
			traversal(root, PREORDER);
			break;
		case 4:
			printf("Posfix : \n");
			traversal(root,POSTORDER);
			break;
		case 5:
			printf("prefix : ");
    		traversal(root, PREORDER);
    		printf("");
    		printf("infix : ");
    		traversal(root, INORDER);
    		printf("");
    		printf("postfix : ");
    		traversal(root, POSTORDER);
    		printf("");
    		printf("Evaluation result : %g\n", value);
    		printf("");
		
}
}

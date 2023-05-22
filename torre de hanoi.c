#include <stdio.h>

#define DISCOS 8

int A[DISCOS];
int B[DISCOS];
int C[DISCOS];

int posA = 0; 
int posB = 0;
int posC = 0; 

void pushA(int n)
{
	A[posA] = n;
	posA++;
}

int popA()
{
	posA--;
	return A[posA];
}

int peekA()
{
	return A[posA-1];
}
void pushB(int n)
{
	B[posB] = n;
	posB++;
}

int popB()
{
	posB--;
	return B[posB];
}

int peekB()
{
	return B[posB-1];
}

void pushC(int n)
{
	C[posC] = n;
	posC++;
}

int popC()
{
	posC--;
	return C[posC];
}

int peekC()
{
	return C[posC-1];
}

/* Mostra o conteudo das pilhas A, B e C */
void show()
{
	int i;
	printf("A:");
	for(i = 0; i < posA; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	
	printf("B:");
	for(i = 0; i < posB; i++){
		printf("%d ", B[i]);
	}
	printf("\n");
	
	printf("C:");
	for(i = 0; i < posC; i++){
		printf("%d ", C[i]);
	}
	printf("\n\n");
}

void initialize(){
	int i;
	for(i = DISCOS; i >= 1; i--)
	{
		pushA(i);
	}
}

void moveAB()
{
	if (posA == 0){
		pushA(popB());
		}else if(posB == 0){
			pushB(popA());
		}else if (peekA() < peekB())
		{
			pushB(popA());
		}else if (peekB() < peekA())
		{
			pushA(popB());
		}
}

void moveAC()
{
	if (posA == 0){
		pushA(popC());
		}else if(posC == 0){
			pushC(popA());
		}else if (peekA() < peekC())
		{
			pushC(popA());
		}else if (peekC() < peekA())
		{
			pushA(popC());
		}	
}

void moveBC()
{
	if (posB == 0){
		pushB(popC());
		}else if(posC == 0){
			pushC(popB());
		}else if (peekB() < peekC())
		{
			pushC(popB());
		}else if (peekC() < peekB())
		{
			pushB(popC());
		}
}
int main(int argc, char *argv[])
{
	initialize();
	show();
	while(posC < DISCOS)
	{
		moveAB();
		show();
		if(posC == DISCOS )break;
		moveAC();
		show();
		if(posC == DISCOS )break;
		moveBC();
		show();
	}
	show();
	return 0;
}

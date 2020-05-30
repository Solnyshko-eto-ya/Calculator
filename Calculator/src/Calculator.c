/*
============================================================================
Name        : Calculator.c
Author      : Andryfaciy
Version     : 3
Copyright   : maya and only maya
Description : Calculator with operations for calculating factorial, addition, difference, multiplication, exponentiation and division.
It can also count the difference, sum and scalar product of vectors.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

float factorial(int n)  //function for calculating the factorial(n-number)
{
float res;
int i;
res = 1;
i = 1;
while (i != (n + 1))
{
res = res * i;
i++;
}
return(res);
}

float stepen(float x, float y)  //function for calculating the degree(x-number, y-degree)
{
float res;
int i;
res = 1;
i = 0;
while (i < y)
{
res = res * x;
i++;
}
if (y < 0)
{
res = 1/res;
}
return(res);
}


	int main(int argc, char *argv[]){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	FILE *input, *output;
	float *vector1,*vector2,a,b, *result;
	int  size;
	char choose, operation, inputfile[100], outputfile[100], repeat, op;
	repeat = 'y';

	while(repeat == 'y'){
		printf("Enter input file name: ");
		scanf(" %s", inputfile);
		printf("Enter output file name: ");
		scanf(" %s", outputfile);
		input = fopen(inputfile, "r");
		output = fopen(outputfile, "w");
		while(feof(input) == 0){
		fscanf(input, "%c", &choose);
		fscanf(input, " %c", &operation);
		fscanf(input," %f",&a);
		fscanf(input," %f",&b);
		switch(choose){
		case 's':
			switch(operation)
			case '+': // addition
				fprintf(output,"%.2f + %.2f = %.2f", a, b, a+b);
			break;
			case '-':
				fprintf(output,"%.2f - %.2f = %.2f", a, b, a-b);
			break;
			case '*':
				fprintf(output,"%.2f * %.2f = %.2f", a, b, a*b);
			break;
			case '/':
			if(b !=0)
				fprintf(output,"%.2f / %.2f = %.2f", a, b, a/b);
			else
				fprintf(output,"No solution");
			break;
			case '^':
				fprintf(output, "%.2f ^ %.2f = %.2f", a, b, stepen(a,b));
			break;
			case '!':
				fscanf(input, "%f",&a);
			if (a >= 0)
				fprintf(output, "%.0f! = %.0f", a, factorial(a));
			else
				fprintf(output, "This operation is not valid");
			break;
			break;
		case 'v':

			                                   fscanf(input,"%i", &size);
			                                   vector1 = malloc(size*sizeof(int));
			                                   vector2 = malloc(size*sizeof(int));
			                                   result = malloc(size*sizeof(int));
			                               for (int i=0; i < size; i++)
			                                   fscanf(input, "%f", &vector1[i]);
			                               for (int i=0; i < size; i++)
			                                   fscanf(input, "%f", &vector2[i]);
			                               fscanf(input, " %c", &op);
			                               switch(op){
			                               case '+':
			                                  for (int i=0; i < size; i++)
			                                      fprintf(output, "%.2f ", vector1[i]+vector2[i]);
			                               break;
			                               case '-':
			                                   for (int i=0; i < size; i++) result[i] = vector1[i]-vector2[i];
			                                      fprintf(output, "%.f ", result);
			                               break;
			                               case '*':
			                                   for (int i=0; i < size; i++) result[i] = vector1[i] * vector2[i] + result[i];
			                                   fprintf(output, "%.f ", result);
			                               break;}
			                               break;
			                               free(vector1);
			                                     free(vector2);
		break;
		}}
		fclose(input);
		fclose(output);
	repeat = 0;
	printf("Continue?" "y-yes/n-no");
	scanf(" %c",&repeat);}// while.....
	return 0;
	}


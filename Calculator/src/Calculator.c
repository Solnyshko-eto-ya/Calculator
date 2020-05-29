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

int main(int argc, char *argv[])
    {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *input, *output;
    float *vector1,*vector2,a,b, res;
    int  size;
    char choose, operation, inputfile[100], outputfile[100], repeat;
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
    case's':   // choosing work with numbers
        switch(operation){
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
		else fprintf(output,"No solution");
		break;
	case '^':
		fprintf(output, "%.3f ^ %.3f = %.3f", a, b, stepen(a,b));
		break;
	case '!':
		fscanf(input, "%f",&a);
		if (a >= 0) fprintf(output, "%.0f! = %.0f", a, factorial(a));
		else fprintf(output, "This operation is not valid");
		break;
	default:
		fprintf(output, "Unknown operation");
	}
	break;
        case 'v': // choosing to work with vectors
        	printf("I want a cokes");}}
repeat = 0;
printf("Continue?" "y-yes/n-no");
scanf(" %c",&repeat);}
return 0;}




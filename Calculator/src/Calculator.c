/*
 ============================================================================
 Name        : Calculator.c
 Author      : Andryfaciy
 Version     : 4
 Copyright   : maya and only maya
 Description : Calculator with input and output from a file. Calculator with operations
 for calculating factorial, addition, difference, multiplication, exponentiation and division.
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
	while (i != (n + 1)) {
		res = res * i;
		i++;
	}
	return (res);
}

float stepen(float x, float y) //function for calculating the degree(x-number, y-degree)
{
	float res;
	int i;
	res = 1;
	i = 0;
	while (i < y) {
		res = res * x;
		i++;
	}
	if (y < 0) {
		res = 1 / res;
	}
	return (res);
}

int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float *vector1, *vector2, a, b, result;
	int size;
	char choose, operation, inputfile[100], outputfile[100], repeat = 'y';
	FILE *input, *output;

	while (repeat == 'y') {
		printf("Enter input file name:\n "); // Enter the name of the input and output file.
		scanf("%s", inputfile);
		printf("Enter output file name:\n ");
		scanf("%s", outputfile);
		input = fopen(inputfile, "r"); // Opening input and output files.
		output = fopen(outputfile, "w");
		while (feof(input) == 0) { // Loop to read the file to the end.
			fscanf(input, " %c", &choose); // Choose what to work with: numbers or vectors.
			fscanf(input, " %c", &operation); // Selecting an operation.
			switch (choose) {
			case 's': // Choosing to work with numbers.
				fscanf(input, " %f", &a);
				fscanf(input, " %f", &b);
				switch (operation) { // Selecting an operation for numbers.
				case '+': // Addition.
					fprintf(output, "%.2f + %.2f = %.2f", a, b, a + b);
					break;
				case '-': // Difference.
					fprintf(output, "%.2f - %.2f = %.2f", a, b, a - b);
					break;
				case '*': // Multiplication.
					fprintf(output, "%.2f * %.2f = %.2f", a, b, a * b);
					break;
				case '/': // Division.
					if (b != 0)
						fprintf(output, "%.2f / %.2f = %.2f", a, b, a / b);
					else
						fprintf(output, "No solution");
					break;
				case '^': // Exponentiation.
					fprintf(output, "%.2f ^ %.2f = %.2f", a, b, stepen(a, b));
					break;
				case '!': // Factorial calculation.
					fscanf(input, "%f", &a);
					if (a >= 0) {
						fprintf(output, "%.0f! = %.0f", a, factorial(a));
					} else
						fprintf(output, "This operation is not valid");
					break;
				}
				break;
			case 'v': // Choosing to work with vectors.
				fscanf(input, "%i", &size); // Entering the size of the vectors.
				vector1 = malloc(size * sizeof(float));
				vector2 = malloc(size * sizeof(float));

				for (int i = 0; i < size; i++) // Entering the coordinates of the vectors.
					fscanf(input, "%f", &vector1[i]);
				for (int i = 0; i < size; i++)
					fscanf(input, "%f", &vector2[i]);

				switch (operation) { // Selecting an operation for vectors.
				case '+': // Addition.
					fprintf(output, "( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", vector1[i]);
					fprintf(output, " ) + ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", vector2[i]);
					fprintf(output, " ) = ( ");
					for (int i = 0; i < size; i++) {
						fprintf(output, "%.2f ", vector1[i] + vector2[i]);
					}
					fprintf(output, " )");
					break;
				case '-': // Difference.
					fprintf(output, "( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", vector1[i]);
					fprintf(output, " ) - ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", vector2[i]);
					fprintf(output, " ) = ( ");
					for (int i = 0; i < size; i++) {
						fprintf(output, "%.2f ", vector1[i] - vector2[i]);
					}
					fprintf(output, " )");
					break;
				case '*': // Scalar product.
					fprintf(output, "( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", vector1[i]);
					fprintf(output, " ) * ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", vector2[i]);
					fprintf(output, " ) = ");
					for (int i = 0; i < size; i++) {
						result += vector1[i] * vector2[i];
					}
					fprintf(output, "%.2f ", result);
					break;
				}
				free(vector1); // Free memory.
				free(vector2);
				break;
			}
			fprintf(output, "\n");
		}

		fclose(input); // Closing input and output files.
		fclose(output);
		repeat = 0;
		printf("Do you want to continue?" " " "y-Yes/n-No \n"); // Choosing what to do next.
		scanf(" %c", &repeat);
	}
}


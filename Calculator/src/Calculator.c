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
    float *vector1,*vector2, result,a,b;
    int m, size;
    char choose, operation;
    m = 1;
    while(m == 1){
          printf("choose mode of the calculator:\n"); // Choosing what to work with
    printf("s. The numbers\n");
    printf("v. The vectors\n");
    scanf(" %c",&choose);
    switch(choose){
    case's':   // choosing how to work with numbers
    	printf("enter the first number:\n"); // entering the first number
    	        scanf(" %f",&a);
    	        printf("enter the operation"); // entering an operation
    	        scanf(" %c", &operation);
    	        if(operation != '!' ){
    	printf("enter the second number:\n"); // entering the second number
    	scanf(" %f",&b);}
        switch(operation){
        case '+': // addition
        	 printf("Answer:\n");
        	            printf(" %f",a+b);
        	break;
        case '-': //difference
        	printf("Answer:\n");
        	                printf("%f",a-b);
        	break;
        case '^':   // exponentiation
        	printf("Answer:\n");
        	                    printf("%f", stepen(a,b));
        	break;
        case '/': // division
        	printf("Answer:\n");
        	                    printf("%f",a/b);
        	break;
        case '*':  // multiplication
        	printf("Answer:\n");
        	                    printf("%f",a*b);
        	break;
        case '!': //factorial
        	printf("Answer:\n");
        	                    printf("%f",factorial(a));
        	break;

        }
        break;
        case 'v': // choosing how to work with vectors
                result = 0;
    	            printf("Enter the size of the vectors: "); // choosing the size of the vector
    	            scanf("%i", &size);
    	            vector1 = malloc(size*sizeof(int));
    	            vector2 = malloc(size*sizeof(int));
    	        printf("Enter the coordinates of the first vector: "); //entering the coordinates of the first vector
    	        for (int i=0; i < size; i++) scanf("%f", &vector1[i]);
    	        printf("Enter the coordinates of the second vector: "); // entering the coordinates of the second vector
    	        for (int i=0; i < size; i++) scanf("%f", &vector2[i]);
    	        printf("Select operation\n"); // choosing what to do with vectors
    	        printf("1. Vector addition\n"); // addition
    	        printf("2. Vector difference\n"); // difference
    	        printf("3. Scalar product of vectors\n"); // scalar product
    	        scanf("%c", &operation);
    	        if (operation == 1){
    	           printf("Answer:\n");
    	           for (int i=0; i < size; i++) printf("%.2f ", vector1[i]+vector2[i]);
    	        }
    	        else if (operation == 2){
    	            printf("Answer:\n");
    	            for (int i=0; i < size; i++) printf("%.2f ", vector1[i]-vector2[i]);
    	        }
    	        else if (operation == 3) {
    	            printf("Answer:\n");
    	            for (int i=0; i < size; i++) result = vector1[i] * vector2[i] + result;
    	            printf("%.2f ", result);
    	        }
    	        free(vector1); // free memory
    	        free(vector2);
    }
    	        printf("\nDo you want to continue? (0 - NO, 1 - YES)\n"); //repeating the calculator operation
    	                       scanf("%i",&m);
    	        }
    return 0;
    }

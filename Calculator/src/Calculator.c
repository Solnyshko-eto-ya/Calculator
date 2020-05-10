/*
 ============================================================================
 Name        : Calculator.c
 Author      : Andryfaciy
 Version     : 2
 Copyright   : maya and only maya
 Description : Калькулятор имеющий операции вычисления факториала, сложения, разности, умножения, возведения в степень и деления.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

float factorial(int n)  //функция для вычисления факториала(n - число)
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

float stepen(float x, float y)  //функция для вычисления степени(x - число, y - степень)
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
    char c;
    int m, mode, size, operation;
    m = 1;
    while(m == 1)
    {        printf("choose mode of the calculator:\n"); // Выбор с чем будет проводится работа
    printf("1. The numbers\n");
    printf("2. The vectors\n");
    scanf("%i", &mode);

    if (mode == 1){
        printf("inter the first number:\n");
        scanf("%f",&a);
        printf("inter the operation");
        scanf(" %c",&c);
        if (c != '!')
        {
            printf("inter the second number:\n");
            scanf("%f",&b);
        }
        if (c == '+')
        {
            printf("Answer:\n");
            printf("%f",a+b);
        }
        else
        {
            if (c == '-')
            {
                printf("Answer:\n");
                printf("%f",a-b);
            }
            else
            {
                if (c == '^')
                {
                    printf("Answer:\n");
                    printf("%f", stepen(a,b));
                }
                else
                {
                    if (c == '/')
                    {
                        printf("Answer:\n");
                        printf("%f",a/b);
                    }
                    else
                    {
                        if (c == '*')
                        {
                            printf("Answer:\n");
                            printf("%f",a*b);
                        }
                        else
                        {
                            if (c == '!')
                            {
                                printf("Answer:\n");
                                printf("%f",factorial(a));
                            }
                        }
                    }
                }
            }
        }
    }
    else{
    	result = 0;
    	            printf("Enter the size of the vectors: ");
    	            scanf("%i", &size);
    	            vector1 = malloc(size*sizeof(int));
    	            vector2 = malloc(size*sizeof(int));
    	        printf("Enter the coordinates of the first vector: ");
    	        for (int i=0; i < size; i++) scanf("%f", &vector1[i]);
    	        printf("Enter the coordinates of the second vector: ");
    	        for (int i=0; i < size; i++) scanf("%f", &vector2[i]);
    	        printf("Select operation\n");
    	        printf("1. Vector addition\n");
    	        printf("2. Vector difference\n");
    	        printf("3. Scalar product of vectors\n");
    	        scanf("%i", &operation);
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
    	        free(vector1);
    	        free(vector2);}
    	        printf("\nDo you want to continue? (0 - NO, 1 - YES)\n"); //повторение работы калькулятора
    	                       scanf("%i",&m);
    	        }
    return 0;
    }


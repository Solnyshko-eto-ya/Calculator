/*
 ============================================================================
 Name        : kalkulator.c
 Author      : Andryfaciy
 Version     : 5
 Copyright   : maya and only maya
 Description : kalkulyator programm
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float first_var, second_var , result , g;
char operation, next_time;
int main(int argc , char *argv[] ) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    next_time = 'y';
    while (next_time == 'y'){ // ���� �� ���������� ���������
        puts("enter the first var ");
        scanf("%f", &first_var);
        puts("enter your operation  ");
        scanf(" %c", &operation);
        g = first_var ;
        if (operation == '+') { // �������� ��������
            puts("enter the second  var ");
            scanf("%f", &second_var);
            result = first_var + second_var ;
        }else if (operation == '-') {   // ��������
            puts("enter the second  var ");
            scanf("%f", &second_var);
            result = first_var - second_var ;
        }else if (operation == '*') {    // ���������
            puts("enter the second  var ");
            scanf("%f", &second_var);
            result = first_var * second_var ;
        }else if (operation == '/') {   // �������
            puts("enter the second  var ");
            scanf("%f", &second_var);
            result = first_var / second_var ;
        }else if (operation == '^') {   // ���������� � �������
            puts("enter the second  var ");
            scanf("%f", &second_var);
            while (second_var >1){
                first_var = first_var * g;
                second_var = second_var - 1;
               }
            result = first_var ;
        }else if (operation == '!') {    // ���������� ����������
            while (g > 1 ){
                g = g - 1;
                first_var = first_var *g ;
            }
            result = first_var;
        }
        printf("%f" , result );    // ���������
        puts(" repeat it? (enter \"y\" to continue)");
        scanf(" %c", &next_time);
    }
    return 0;
}

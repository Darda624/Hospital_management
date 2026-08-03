#include<stdio.h>
void main (){
    int while_condition=1;
    while(while_condition){
        printf("\n==============================\n");
        printf("   HOSPITAL MANAGEMENT SYSTEM\n");
        printf("==============================\n");

        printf("1. Patient Management\n");
        printf("2. Doctor Management\n");
        printf("3. Appointment Management\n");
        printf("4. Room Management\n");
        printf("5. Pharmacy Management\n");
        printf("6. Billing\n");
        printf("7. Exit\n");
        int main_input;
        scanf("%d",&main_input);
        switch(main_input){
            case 1:{
            printf("patient Management");
            break;
            }case 2:{
            printf("Doctor Management");
            break;
            }case 3:{
            printf("Appointment Management");
            break;
            }case 4:{
            printf("Room Management");
            break;
            }case 5:{
            printf("Pharmacy Management");
            break;
            }case 6:{
            printf(" Billing ");
            break;
            }case 7:{
            printf(" Exit");
            while_condition= 0;
            break;
            }
            default:{
            printf("Invalid Input");
            }

        }

    }

}

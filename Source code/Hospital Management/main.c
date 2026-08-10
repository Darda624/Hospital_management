#include<stdio.h>
#include "Appointment.h"
#include "Room.h"
#include "Patient.h"
#include "Doctor.h"
#include "Pharmacy.h"
#include "Billing.h"
void fileCreate(){
    char yn;
printf("!!!!!!!!!!!!!!!!   DANGER: Only use when files are missing   !!!!!!!!!!!!!!!!!!\n!!!  Running this with existing files will overwrite/delete their contents  !!!\n");
printf("!!!!!!!!!!!!!!!!      Enter Y to proceed or N to return      !!!!!!!!!!!!!!!!!! \n");
scanf(" %c",&yn);
if (yn=='Y'||yn=='y'){
    fopen("Appointment.txt","w");
    fopen("Doctor.txt","w");
    fopen("Patient.txt","w");
    fopen("Room.txt","w");
    printf("\nSuccess Create/overwriting files \n");
}
else if (yn=='N'||yn=='n'){
    printf("Retuning to Home\n");
}

}
void main (){
    int while_condition=1;
    int while_coun=1;
    while(while_condition){
        printf("\n==============================\n");
        printf("   HOSPITAL MANAGEMENT SYSTEM\n");
        printf("==============================\n");

        printf("1. Appointment Management\n");
        printf("2. Room Management\n");
        printf("3. Patient Management\n");
        printf("4. Doctor Management\n");
        printf("5. Pharmacy Management\n");
        printf("6. Billing\n");
        printf("7. Exit\n");
        printf("8. Create .txt files \n");
        int main_input;
        scanf("%d",&main_input);
        switch(main_input){
            case 1:{
            system("cls");
            AppoinmentMain();
            break;
            }case 2:{
            system("cls");
            RoomMain();
            break;
            }case 3:{
            system("cls");
            PatientMain();
            break;
            }case 4:{
            system("cls");
            DoctorMain();
            break;
            }case 5:{
            system("cls");
            PharmacyMain();
            break;
            }case 6:{
            system("cls");
            BillMain();
            break;
            }case 7:{
            system("cls");
            printf(" Exit");
            while_condition= 0;
            break;
            }
            case 8:{
            system("cls");
            fileCreate();
            break;
            }
            default:{
            printf("Invalid Input");
            }

        }

    }

}

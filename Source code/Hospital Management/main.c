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
        system("cls");
        printf("\n>>>Success Create/overwriting files \n");
    }
    else if (yn=='N'||yn=='n'){
        system("cls");
        printf(">>>Operation canceled by User");
    }
    else{
        system("cls");
        printf(">>> Error encountered while talking input ");
    }
}
void Reception(){
    int Reciption_TF=1;
    while(Reciption_TF){
        printf("\n==============================\n");
        printf("     Reception MANAGEMENT       \n");
        printf("==============================\n");
        printf("1. Appointment Management\n");
        printf("2. Room Management\n");
        printf("3. Patient Management\n");
        printf("4. Billing\n");
        printf("5. Exit\n");
        char main_input;
        scanf(" %c",&main_input);
        switch(main_input){
            case '1':{
            system("cls");
            AppoinmentMain();
            break;
            }case '2':{
            system("cls");
            RoomMain();
            break;
            }case '3':{
            system("cls");
            PatientMain();
            break;
            }case '4':{
            system("cls");
            BillMain();
            break;
            }case '5':{
            system("cls");
            Reciption_TF=0;
            printf(" Exit");
            break;
            }
            default:{
            system("cls");
            printf(">>> Error encountered while talking input ");

            }
        }
    }
}
void Hospital_Ops(){
    int HospitalTF=1;
            while(HospitalTF){
                system("color 3F");
                printf("\n==============================\n");
                printf("         HOSPITAL ADMIN      \n");
                printf("==============================\n");

                printf("1. Doctor Management\n");
                printf("2. Exit\n");
            char Hospital_IO;
            scanf(" %c",&Hospital_IO);
            switch(Hospital_IO){

            case '1':{
            system("cls");
            DoctorMain();
            break;
            }
            case '2':{
            HospitalTF=0;
            break;
            }
            default:{
            system("cls");
            printf(">>> Error encountered while talking input ");
            }

        }
    }
}

int main (){

    int while_condition=1;
    while(while_condition){
        system("color 3F");
        printf("\n==============================\n");
        printf("   HOSPITAL MANAGEMENT SYSTEM\n");
        printf("==============================\n");

        printf("1. Hospital Admin Login \n");
        printf("2. Reception Login \n");
        printf("3. Pharmacy Login \n");
        printf("4. Exit\n");
        printf("5. Create .txt files \n");
        char main_input;
        scanf(" %c",&main_input);
        switch(main_input){
            case '1':{
            system("cls");
            Hospital_Ops();
            break;
            }case '2':{
            system("cls");
            Reception();
            break;
            }case '3':{
            system("cls");
            PharmacyMain();
            break;
            }case '4':{
            system("cls");
            printf(" Exit");
            while_condition= 0;
            break;
            }
            case '5':{
            system("cls");
            system("color 3E");
            fileCreate();
            break;
            }
            default:{
            system("cls");
            printf(">>> Error encountered while talking input ");
            }
        }
    }
    return 0;
}

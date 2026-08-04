#include<stdio.h>
#include "Appointment.h"
#include "Room.h"
#include "Patient.h"
#include "Doctor.h"
#include "Pharmacy.h"
#include "Billing.h"
void main (){
    int while_condition=1;
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
        int main_input;
        scanf("%d",&main_input);
        switch(main_input){
            case 1:{
            AppoinmentMain();
            break;
            }case 2:{
            RoomMain();
            break;
            }case 3:{
            PatientMain();
            break;
            }case 4:{
            DoctorMain();
            break;
            }case 5:{
            PharmacyMain();
            break;
            }case 6:{
            BillMain();
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

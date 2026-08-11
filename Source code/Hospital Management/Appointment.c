#include<stdio.h>
#include "Appointment.h"
void AppoinmentMain(){
    printf("1. Book Appointment\n");
    printf("2. View Appointment\n");
    printf("3. Search Appointment\n");
    printf("4. Cancel Appointment\n");
    printf("5. Exit \n");
    int AppoinmentTF=1;
    while(AppoinmentTF){
        char appoinmentIO;
        scanf(" %c",&appoinmentIO);
        switch (appoinmentIO){
            case '1':{
            bookAppointment();
            break;
            }
            case '2':{
            viewAppointments();
            break;
            }
            case '3':{
            searchAppointment();
            break;
            }
            case '4':{
            cancelAppointment();
            break;
            }
            case '5':{
            AppoinmentTF=0;
            break;
            }
            default:{
            printf(">>> Error encountered while talking input ");
            }

        }
    }
}
void bookAppointment(){



}
void viewAppointments(){



}
void searchAppointment(){


}
void cancelAppointment(){


}

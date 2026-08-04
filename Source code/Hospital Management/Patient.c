#include<stdio.h>
#include "patient.h"
void PatientMain(){
    printf("1. Add Patient \n");
    printf("2. View Patients \n");
    printf("3. Search Patient \n");
    printf("4. Update Patient \n");
    printf("5. Delete Patient \n");
    printf("6. Exit \n");
    int PatientTF=1;
    while(PatientTF){
        int PatientIO;
        scanf("%d",&PatientIO);
        switch (PatientIO){
            case 1:{
            addPatient();
            break;
            }
            case 2:{
            viewPatients();
            break;
            }
            case 3:{
            searchPatient();
            break;
            }
            case 4:{
            updatePatient();
            break;
            }
            case 5:{
            deletePatient();
            break;
            }
            case 6:{
            PatientTF =0;
            break;
            }
            default:{
            printf("Invalid Input");
            }

        }
    }
}
void addPatient(){


}
void viewPatients(){


}
void searchPatient(){


}
void updatePatient(){


}
void deletePatient(){


}

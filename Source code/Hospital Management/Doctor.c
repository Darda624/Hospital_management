#include<stdio.h>
#include "Doctor.h"
void DoctorMain(){
    printf("1. Add Doctor \n");
    printf("2. View Doctors \n");
    printf("3. Search Doctor \n");
    printf("4. Update Doctor \n");
    printf("5. DeleteDoctor \n");
    printf("6. Exit \n");
    int DoctorTF=1;
    while(DoctorTF){
        char DoctorIO;
        scanf(" %c",&DoctorIO);
        switch (DoctorIO){
            case '1':{
            addDoctor();
            break;
            }
            case '2':{
            viewDoctors();
            break;
            }
            case '3':{
            searchDoctor();
            break;
            }
            case '4':{
            updateDoctor();
            break;
            }
            case '5':{
            deleteDoctor();
            break;
            }
            case '6':{
            DoctorTF =0;
            break;
            }
            default:{
            printf(">>> Error encountered while talking input ");
            }

        }
    }
}
void addDoctor(){

}
void viewDoctors(){

}
void searchDoctor(){

}
void updateDoctor(){

}
void deleteDoctor(){

}

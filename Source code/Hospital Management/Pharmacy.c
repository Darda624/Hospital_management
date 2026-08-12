#include<stdio.h>
#include "Pharmacy.h"
void PharmacyMain(){
    int pharmacyTF=1;
    while(pharmacyTF){
    printf("1. Add Medicine\n");
    printf("2. View Medicine\n");
    printf("3. Search Medicine\n");
    printf("4. Update Stock\n");
    printf("5. Sell Medicine\n");
    printf("6. Exit \n");
        char pharmacyIO;
        scanf(" %c",&pharmacyIO);
        switch (pharmacyIO){
            case '1':{
            addMedicine();
            break;
            }
            case '2':{
            viewMedicines();
            break;
            }
            case '3':{
            searchMedicine();
            break;
            }
            case '4':{
            updateStock();
            break;
            }
            case '5':{
            sellMedicine();
            break;
            }
            case '6':{
            pharmacyTF=0;
            break;
            }
            default:{
            printf(">>> Error encountered while talking input ");
            }

        }
    }
}
void addMedicine(){

}
void viewMedicines(){

}
void searchMedicine(){

}
void updateStock(){

}
void sellMedicine(){

}

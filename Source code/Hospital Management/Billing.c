#include<stdio.h>
#include "Billing.h"
void BillMain(){
    printf("1. Generate Bill\n");
    printf("2. View Bil\n");
    printf("3. Exit \n");
    int BillingTF=1;
    while(BillingTF){
        char BillingIO;
        scanf(" %c",&BillingIO);
        switch (BillingIO){
            case '1':{
            generateBill();
            break;
            }
            case '2':{
            viewBill();
            break;
            }
            case '3':{
            BillingTF=0;
            break;
            }
            default:{
            printf(">>> Error encountered while talking input ");
            }

        }
    }
}
void generateBill(){


}
void viewBill(){


}

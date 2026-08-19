#include <stdio.h>
#include "Billing.h"

typedef struct
{
    char Name[50];
    int DocF;
    int RoomF;
    int MedicineF;
    int total;
    int days;
    int due;
    int paid;
} bl;

bl bData;

void BillMain()
{
    int BillingTF = 1;
    while (BillingTF)
    {
        printf("\n1. Generate Bill\n");
        printf("2. View Bill\n");
        printf("3. Exit \n");

        char BillingIO;
        if (scanf(" %c", &BillingIO) != 1) continue;

        switch (BillingIO)
        {
        case '1':
            generateBill();
            break;
        case '2':
            viewBill();
            break;
        case '3':
            BillingTF = 0;
            break;
        default:
            printf(">>> Error encountered while taking input\n");
            break;
        }
    }
}

void generateBill()
{
    char bill_IO;
    printf("\n1. Appointment Billing");
    printf("\n2. Patient Billing");
    printf("\n3. Exit\n ");

    scanf(" %c", &bill_IO);

    if (bill_IO == '1')
    {
        printf("Patient Found \nStarting billing Process\n");

        printf("Enter Doctor Fees: ");
        scanf("%d", &bData.DocF);

        printf("Medicine Fees: ");
        scanf("%d", &bData.MedicineF);

        printf("Paid Amount: ");
        scanf("%d", &bData.paid);

        bData.total = bData.DocF + bData.MedicineF ;
        bData.due = bData.total - bData.paid;

        printf("\nTotal bill: %d | Paid: %d | Remaining Due: %d\n", bData.total, bData.paid, bData.due);

        addbill();
        cancelAppointment(bData.Name);
    }
    else if (bill_IO == '2')
    {
        printf("Enter Patient Name: ");
        scanf(" %[^\n]", bData.Name);

        if (searchPatient(bData.Name))
        {
            printf("Patient Found \nStarting billing Process\n");

            printf("Enter Doctor Fees: ");
            scanf("%d", &bData.DocF);

            printf("Enter Room Fees: ");
            scanf("%d", &bData.RoomF);

            printf("Medicine Fees: ");
            scanf("%d", &bData.MedicineF);

            printf("Enter how many days patient stayed: ");
            scanf("%d", &bData.days);

            printf("Paid Amount: ");
            scanf("%d", &bData.paid);

            bData.total = bData.DocF + bData.MedicineF + (bData.RoomF * bData.days);
            bData.due = bData.total - bData.paid;

            printf("\nTotal bill: %d | Paid: %d | Remaining Due: %d\n", bData.total, bData.paid, bData.due);

            addbill();
            deletePatient(bData.Name);
        }
        else
        {
            printf("Patient not found!\n");
        }
    }
    else if (bill_IO == '3')
    {
        printf("Exiting Billing Menu...\n");
    }
    else
    {
        printf("Invalid input\n");
    }
}

int addbill()
{
    FILE *bill_f = fopen("Billing.txt", "a");
    if (!bill_f)
    {
        printf("File error!\n");
        return 0;
    }
    bData.due = bData.total - bData.paid;
    fprintf(bill_f, "%s.%d.%d.%d\n", bData.Name, bData.total, bData.paid, bData.due);
    fclose(bill_f);
    return 1;
}

void viewBill()
{
    FILE *bill_f = fopen("Billing.txt", "r");

    if (!bill_f)
    {
        printf("Error: Could not open Billing.txt!\n");
        return;
    }
    char line[256];

    while (fgets(line, sizeof(line), bill_f) != NULL)
    {

        sscanf(line, "%49[^.].%d.%d.%d", bData.Name, &bData.total, &bData.paid, &bData.due);

        printf("Name : s Total bill: %d Total Paid: %d Due: %d\n", bData.Name, bData.total, bData.paid, bData.due);

    }

    fclose(bill_f);
}


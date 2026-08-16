#include<stdio.h>
#include "Appointment.h"
void AppoinmentMain()
{
    int AppoinmentTF=1;
    while(AppoinmentTF)
    {
        printf("1. Book Appointment\n");
        printf("2. View Appointment\n");
        printf("3. Search Appointment\n");
        printf("4. Cancel Appointment\n");
        printf("5. Exit \n");
        char appoinmentIO;
        scanf(" %c",&appoinmentIO);
        switch (appoinmentIO)
        {
        case '1':
        {
            bookAppointment();
            break;
        }
        case '2':
        {
            viewAppointments();
            break;
        }
        case '3':
        {
            char search_p[50];
            printf("Enter Patient Name: ");
            scanf(" %[^\n]",search_p);
            int TF = searchAppointment(search_p);
            if(TF==0){
                system("cls");
                printf("Not Found");
            }

            break;
        }
        case '4':
        {
            cancelAppointment();
            break;
        }
        case '5':
        {
            AppoinmentTF=0;
            break;
        }
        default:
        {
            printf(">>> Error encountered while talking input ");
        }

        }
    }
}
void bookAppointment()
{

    char Name[15];
    char Age[3];
    char phone[12];
    char Nid[11];
    char Doctor[30];
    printf("Patient Name: ");
    scanf(" %10[^\n]",Name);
    printf("\nPatient Age: ");
    scanf(" %2[^\n]",Age);
    printf("\nPatient Phone: ");
    scanf(" %10[^\n]",phone);
    printf("\nPatient NID: ");
    scanf(" %[^\n]",Nid);
    printf("\nDoctor Assigned to Patient : ");
    scanf(" %3[^\n]",Doctor);
    system("cls");
    int EFR = searchDoctor(Doctor);
    FILE *appoint_f;
    appoint_f = fopen("Appointment.txt","a");
    if (EFR==1)
    {
        system("cls");
        fprintf(appoint_f,"\n%s   %s   %s  %s  %s ",Name,Age,phone,Nid,Doctor);
        printf(">>>Added to File Appointment.txt ");
    }
    if(appoint_f==NULL)
    {
        system("cls");
        printf(">>>Error encountered while Opening Appointment.txt ");
    }
    else if (EFR==0&&appoint_f!=NULL)
    {

        printf("Doctor Not Found");
    }

    fclose(appoint_f);



}
void viewAppointments()
{

    FILE *appoint_f;
    char str[10000];

    appoint_f = fopen("Appointment.txt", "r");
    if (appoint_f == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    while (fgets(str, 10000,appoint_f) != NULL)
    {
        printf("%s", str);
    }

    fclose(appoint_f);

}
int searchAppointment(char search[])
{

    char line[100];
    FILE *appoint_f = fopen("Appointment.txt", "r");

    if (appoint_f == NULL)
    {
        printf("Error: Error encountered while Opening Appointment.txt \n");
        return 0;
    }

    while (fgets(line, sizeof(line), appoint_f) != NULL)
    {
        if (strstr(line, search) != NULL)
        {
            system("cls");
            printf("%s", line);
            fclose(appoint_f);
            return 1;
        }
    }

    fclose(appoint_f);
    return 0;

}
void cancelAppointment()
{

    FILE *appoint_f1;
    FILE *appoint_f2;
    appoint_f1=fopen("Appoointment.txt","r");
    if(appoint_f1==NULL){
        printf("Error while opening file Appointment.txt\n");
        return;
    }

    appoint_f2=fopen("Temp.txt","w");
    if(appoint_f2==NULL){
        printf("Error while opening file Temp.txt\n");
        return;
    }

    char Name_Remove[50];
    printf("Enter Patient Name to delete:");
    scanf(" %49[^\n]",Name_Remove);

    char line[100];
    int found=0;

    while(fgets(line,100,appoint_f1)!=NULL){
        if(strstr(line,Name_Remove)==NULL){
            fputs(line,appoint_f2);
        }
        else{
            found=1;
        }
    }

    fclose(appoint_f1);
    fclose(appoint_f2);

    remove("Appointment.txt");
    rename("Temp.txt","Appointment.txt");

    if(found){
        system("cls");
        printf(">>>Appointment Removed Successfully!\n");
    }
    else{
        system("cls");
        printf(">>>Appointment Not Found!\n");
    }

}

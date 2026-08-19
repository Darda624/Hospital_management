#include<stdio.h>
#include "Pharmacy.h"
typedef struct
{
    char name[50];
    float price;
    int quantity;
    int exp_month;
    int exp_year;
} Medicine;

void PharmacyMain()
{
    int pharmacyTF=1;
    while(pharmacyTF)
    {
        printf("\n==============================\n");
        printf("           Pharmacy        \n");
        printf("==============================\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Update Stock\n");
        printf("5. Sell Medicine\n");
        printf("6. Delete Expired Medicines\n");
        printf("7. Exit \n");
        char pharmacyIO;
        scanf(" %c",&pharmacyIO);
        switch (pharmacyIO)
        {
        case '1':
        {
            system("cls");
            addMedicine();
            break;
        }
        case '2':
        {
            system("cls");
            viewMedicines();
            break;
        }
        case '3':
        {
            system("cls");
            searchMedicine();
            break;
        }
        case '4':
        {
            system("cls");
            updateStock();
            break;
        }
        case '5':
        {
            system("cls");
            sellMedicine();
            break;
        }
        case '6':
        {
            system("cls");
            deleteExpiredMedicines();
            break;
        }
        case '7':
        {
            system("cls");
            pharmacyTF=0;
            break;
        }
        default:
        {
            printf(">>> Error encountered while talking input ");
        }

        }
    }
}
int nameExists(char name[])
{
    Medicine temp;
    int found = 0;

    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp) return 0;


    while (fscanf(fp, "%s %f %d %d %d\n",temp.name, &temp.price, &temp.quantity, &temp.exp_month, &temp.exp_year) != EOF)
    {
        if (strcmp(temp.name, name) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sortMedicinesByName()
{
    Medicine list[100];
    Medicine temp;
    int count = 0;

    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp) return ;

    while (fscanf(fp, "%s %f %d %d %d\n", list[count].name, &list[count].price, &list[count].quantity, &list[count].exp_month, &list[count].exp_year) != EOF)
    {
        count++;
    }
    fclose(fp);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(list[j].name, list[j + 1].name) > 0)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    fp = fopen("Pharmacy.txt","w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %.2f %d %d %d\n", list[i].name, list[i].price, list[i].quantity, list[i].exp_month, list[i].exp_year);
    }
    fclose(fp);

    printf("Medicines sorted successfully by name!\n");
}

void addMedicine()
{
    Medicine m;
    FILE *fp = fopen("Pharmacy.txt", "a");
    if (!fp)
    {
        printf("File error!\n");
        return;
    }

    printf("\nEnter Medicine Name: ");
    scanf("%s", m.name);

    if (nameExists(m.name))
    {
        printf("Medicine with Name '%s' already exists!\n", m.name);
        fclose(fp);
        return;
    }

    printf("Enter Price: ");
    scanf("%f", &m.price);
    printf("Enter Quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter Expiry Month (1-12): ");
    scanf("%d", &m.exp_month);
    printf("Enter Expiry Year (e.g., 2027): ");
    scanf("%d", &m.exp_year);

    fprintf(fp, "%s %.2f %d %d %d\n", m.name, m.price, m.quantity, m.exp_month, m.exp_year);
    fclose(fp);

    sortMedicinesByName();
    system("cls");
    printf("Medicine added successfully.\n");
}

void viewMedicines()
{
    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp)
    {
        printf("No items found!\n");
        return;
    }

    Medicine m;
    int found = 0;
    printf("---------------------------------------------------------------------------\n");
    while (fscanf(fp, "%s %f %d %d %d", m.name, &m.price, &m.quantity, &m.exp_month, &m.exp_year) != EOF)
    {
        found = 1;
        char note[20] = "";

        if (m.quantity == 0)
        {
            strcpy(note, "Stock Out");
        }
        else if (m.quantity < 5)
        {
            strcpy(note, "Low Stock");
        }

        printf("Name: %s\t Price: %.2f\t Quantity: %d\t Exp: %d/%d\t Note: %s\n", m.name, m.price, m.quantity, m.exp_month, m.exp_year, note);
    }
    printf("---------------------------------------------------------------------------\n");

    if (found == 0)
    {
        printf("No items found!\n");
    }
    fclose(fp);
}

void searchMedicine()
{
    char searchName[50];
    int found = 0;
    Medicine m;

    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp)
    {
        printf("File error!\n");
        return;
    }

    printf("\nEnter Medicine Name to search: ");
    scanf(" %[^\n]", searchName);

    while (fscanf(fp, "%s %f %d %d %d", m.name, &m.price, &m.quantity, &m.exp_month, &m.exp_year) != EOF)
    {

        if (strcmp(m.name, searchName) == 0)
        {
            found = 1;
            system("cls");
            printf("\n--- Medicine Found! ---\n");
            printf("Name: %s\n", m.name);
            printf("Price: %.2f\n", m.price);
            printf("Quantity: %d\n", m.quantity);
            printf("Expiry Date: %d/%d\n", m.exp_month, m.exp_year);
            printf("\n");
            break;
        }
    }

    fclose(fp);

    if (found == 0)
    {
        system("cls");
        printf("Medicine '%s' not found.\n", searchName);
    }
}
void updateStock()
{
    char searchName[50];
    int found = 0;
    Medicine m;

    printf("Enter Medicine Name: ");
    scanf(" %[^\n]", searchName);

    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp)
    {
        printf("File error!\n");
        return;
    }

    while (fscanf(fp, "%s %f %d %d %d\n", m.name, &m.price, &m.quantity, &m.exp_month, &m.exp_year) != EOF)
    {
        if (strcmp(m.name, searchName) == 0)
        {
            found = 1;
            printf("\nMedicine Found!\n");
            printf("Current Quantity: %d\n", m.quantity);

            printf("Enter New Quantity: ");
            scanf("%d", &m.quantity);
            break;
        }
    }
    fclose(fp);

    if (found == 1)
    {
        delete_m(searchName);
        fp = fopen("Pharmacy.txt", "a");
        fprintf(fp, "%s %.2f %d %d %d\n", m.name, m.price, m.quantity, m.exp_month, m.exp_year);
        fclose(fp);
        printf("Stock updated successfully!\n");
    }
    else
    {
        printf("Medicine '%s' not found.\n", searchName);
    }
}
void sellMedicine()
{
    char searchName[50];
    int found = 0;
    int sellQuantity = 0;
    Medicine m;

    printf("Enter Medicine Name to Sell: ");
    scanf(" %[^\n]", searchName);

    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp)
    {
        printf("File error!\n");
        return;
    }

    while (fscanf(fp, "%s %f %d %d %d\n", m.name, &m.price, &m.quantity, &m.exp_month, &m.exp_year) != EOF)
    {
        if (strcmp(m.name, searchName) == 0)
        {
            found = 1;
            printf("\nMedicine Found!\n");
            printf("Available Stock: %d\n", m.quantity);
            printf("Price per unit: %.2f\n", m.price);

            printf("Enter Quantity to Sell: ");
            scanf("%d", &sellQuantity);

            if (sellQuantity > m.quantity)
            {
                printf("Error: Not enough stock available!\n");
                fclose(fp);
                return;
            }

            m.quantity = m.quantity - sellQuantity;
            float totalBill = sellQuantity * m.price;
            printf("Total Bill: %.2f\n", totalBill);
            break;
        }
    }
    fclose(fp);

    if (found == 1)
    {
        delete_m(searchName);
        fp = fopen("Pharmacy.txt", "a");
        fprintf(fp, "%s %.2f %d %d %d\n", m.name, m.price, m.quantity, m.exp_month, m.exp_year);
        fclose(fp);
        printf("Sale completed successfully! Stock updated.\n");
    }
    else
    {
        printf("Medicine '%s' not found.\n", searchName);
    }
}

void deleteExpiredMedicines()
{
    Medicine m[100];
    int count = 0;
    int found = 0;
    int current_year = 26;
    int current_month = 8;

    FILE *fp = fopen("Pharmacy.txt", "r");
    if (!fp)
    {
        printf("File error!\n");
        return;
    }

    while (fscanf(fp, "%s %f %d %d %d\n", m[count].name, &m[count].price, &m[count].quantity, &m[count].exp_month, &m[count].exp_year) != EOF)
    {
        if (m[count].exp_year < current_year || (m[count].exp_year == current_year && m[count].exp_month < current_month))
        {
            found = 1;
            printf("Expired: Medicine '%s' has been removed!\n", m[count].name);
        }
        else
        {
            count++;
        }
    }
    fclose(fp);

    fp = fopen("Pharmacy.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %.2f %d %d %d\n", m[i].name, m[i].price, m[i].quantity, m[i].exp_month, m[i].exp_year);
    }
    fclose(fp);

    if (found == 0)
    {
        printf("No expired medicines found in the system.\n");
    }
}
int delete_m(char D_name[])
{
    FILE *pharmacy_f1;
    FILE *pharmacy_f2;
    pharmacy_f1=fopen("Pharmacy.txt","r");
    if(pharmacy_f1==NULL)
    {
        printf("Error while opening file Phermacy.txt\n");
        return;
    }

    pharmacy_f2=fopen("Temp.txt","w");
    if(pharmacy_f2==NULL)
    {
        printf("Error while opening file Temp.txt\n");
        return;
    }

    char line[100];
    int found=0;

    while(fgets(line,100,pharmacy_f1)!=NULL)
    {
        if(strstr(line,D_name)==NULL)
        {
            fputs(line,pharmacy_f2);
        }
        else
        {
            found=1;
        }
    }

    fclose(pharmacy_f1);
    fclose(pharmacy_f2);

    remove("Pharmacy.txt");
    rename("Temp.txt","Pharmacy.txt");

    if(found)
    {
        system("cls");
        //  printf(">>>Medicine Removed Successfully!\n");
    }
    else
    {
        system("cls");
        //  printf(">>>Medicine Not Found!\n");
    }

}


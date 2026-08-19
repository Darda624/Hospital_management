#ifndef PHARMACY_H
#define PHARMACY_H
void addMedicine();
void viewMedicines();
void updateStock();
void deleteExpiredMedicines();
void sellMedicine();
void searchMedicine();
int nameExists(char name[]);
void sortMedicinesByName();
int delete_m(char m_name[]);
#endif

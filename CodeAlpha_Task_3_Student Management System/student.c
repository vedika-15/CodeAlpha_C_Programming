#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[30];
    float marks;
};

void addRecord() {
    FILE *fp;
    struct student s;

    fp = fopen("student.dat", "ab");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);   // allows full name with space

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayRecords() {
    FILE *fp;
    struct student s;

    fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nID      Name                     Marks\n");
    printf("------------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("%-8d%-25s%.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}

void searchRecord() {
    FILE *fp;
    struct student s;
    int searchId, found = 0;

    fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter student ID to search: ");
    scanf("%d", &searchId);

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == searchId) {
            printf("\nRecord Found!\n");
            printf("ID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Record not found!\n");
}

void updateRecord() {
    FILE *fp;
    struct student s;
    int updateId, found = 0;

    fp = fopen("student.dat", "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter student ID to update: ");
    scanf("%d", &updateId);

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == updateId) {
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Student updated successfully!\n");
    else
        printf("Record not found!\n");
}

void deleteRecord() {
    FILE *fp, *temp;
    struct student s;
    int deleteId, found = 0;

    fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("File error!\n");
        fclose(fp);
        return;
    }

    printf("Enter student ID to delete: ");
    scanf("%d", &deleteId);

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id != deleteId) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Record not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include<string.h>
#include <stdio.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

struct student s[100];
int count = 0;

/* Add Student */
void addstudent() {
    printf("\nEnter the Student Roll No: ");
    scanf("%d", &s[count].roll);

    printf("Enter the Student Name: ");
    scanf("%s", s[count].name);

    printf("Enter the Student Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student Added Successfully!\n");
}

/* Display Students */
void displaystudent() {
    if (count == 0) {
        printf("\nNo Record Found\n");
        return;
    }

    printf("\n--- All Students ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nRoll No: %d\nName: %s\nMarks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

/* Search Student */
void searchstudent() {
    int roll;
    printf("\nEnter the Student Roll No: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("\nRecord Found!\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n",
                   s[i].roll, s[i].name, s[i].marks);
            return;
        }
    }
    printf("Record Not Found\n");
}

/* Update Student */
void updatestudent() {
    int roll;
    printf("\nEnter the Roll No to Update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Enter New Name: ");
            scanf("%s", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record Updated Successfully!\n");
            return;
        }
    }
    printf("Record Not Found\n");
}

/* Delete Student */
void deletestudent() {
    int roll, i, j;
    printf("\nEnter the Roll No to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            for (j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("Record Deleted Successfully!\n");
            return;
        }
    }
    printf("Record Not Found\n");
}

/* Average Marks */
void averagemarks() {
    if (count == 0) {
        printf("\nNo Students Added\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += s[i].marks;
    }

    printf("\nClass Average Marks = %.2f\n", sum / count);
}

/* Save to File */
void savefile() {
    FILE *fp = fopen("Students.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %.2f\n",
                s[i].roll, s[i].name, s[i].marks);
    }

    fclose(fp);
    printf("\nData Saved to Students.txt Successfully!\n");
}




int main() {
    int choice;

    while (1) {
        printf("\n==== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Class Average\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addstudent(); break;
            case 2: displaystudent(); break;
            case 3: searchstudent(); break;
            case 4: updatestudent(); break;
            case 5: deletestudent(); break;
            case 6: averagemarks(); break;
            case 7: savefile(); break;
            case 8:
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }
}

// main.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "number_words.h"

#define MAX_STUDENT_ID_LEN 15
#define MAX_NAME_LEN 15

/* Function to check if a string contains only digits */
int isDigitsOnly(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to check if a string contains only letters */
int isLettersOnly(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to clear the input buffer */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    char student_id[MAX_STUDENT_ID_LEN + 1];
    char first_name[MAX_NAME_LEN + 1];
    char last_name[MAX_NAME_LEN + 1];
    char gender[10];
    int course;
    int year;
    int subjects;
    float amountTendered;

    /* get and validate student id */
    do {
        printf("Enter Student ID Number (Max 15 characters, numbers only): ");
        scanf("%s", student_id);
        if (strlen(student_id) > MAX_STUDENT_ID_LEN) {
            printf("Error: Student ID exceeds maximum length of %d characters.\n", MAX_STUDENT_ID_LEN);
        } else if (!isDigitsOnly(student_id)) {
            printf("Error: Student ID should contain numbers only.\n");
        }
    } while (strlen(student_id) > MAX_STUDENT_ID_LEN || !isDigitsOnly(student_id));

    /* get and validate first name */
    do {
        printf("Enter First Name (Max 15 characters, letters only): ");
        scanf("%s", first_name);
        if (strlen(first_name) > MAX_NAME_LEN) {
            printf("Error: First Name exceeds maximum length of %d characters.\n", MAX_NAME_LEN);
        } else if (!isLettersOnly(first_name)) {
            printf("Error: First Name should contain letters only.\n");
        }
    } while (strlen(first_name) > MAX_NAME_LEN || !isLettersOnly(first_name));

    /* get and validate last name */
    do {
        printf("Enter Last Name (Max 15 characters, letters only): ");
        scanf("%s", last_name);
        if (strlen(last_name) > MAX_NAME_LEN) {
            printf("Error: Last Name exceeds maximum length of %d characters.\n", MAX_NAME_LEN);
        } else if (!isLettersOnly(last_name)) {
            printf("Error: Last Name should contain letters only.\n");
        }
    } while (strlen(last_name) > MAX_NAME_LEN || !isLettersOnly(last_name));

    /* get and validate gender */
    int validGender = 0;
    do {
        printf("Enter Gender (Female, Male, Gay, Lesbian): ");
        scanf("%s", gender);
        if (strcmp(gender, "Female") == 0 || strcmp(gender, "Male") == 0 ||
            strcmp(gender, "Gay") == 0 || strcmp(gender, "Lesbian") == 0) {
            validGender = 1;
        } else {
            printf("Error: Please enter a valid gender (Female, Male, Gay, Lesbian).\n");
        }
    } while (!validGender);

    /* validate course selection */
    while (1) {
        printf("Select Course:\n");
        printf("1 - BSIT\n");
        printf("2 - BSHM\n");
        printf("3 - BSED\n");
        printf("4 - COMPE\n");
        printf("Enter the corresponding number for your course: ");
        if (scanf("%d", &course) != 1 || course < 1 || course > 4) {
            printf("Error: Please select a valid course number (1-4).\n");
            clearInputBuffer();
        } else {
            break;
        }
    }

    /* validate year level */
    while (1) {
        printf("Enter Year Level (1-5): ");
        if (scanf("%d", &year) != 1 || year < 1 || year > 5) {
            printf("Error: Year Level must be between 1 and 5.\n");
            clearInputBuffer();
        } else {
            break;
        }
    }

    /* validate number of subjects */
    while (1) {
        printf("Enter Number of Subjects Enrolled (Max 10): ");
        if (scanf("%d", &subjects) != 1 || subjects < 1 || subjects > 10) {
            printf("Error: Number of subjects must be between 1 and 10.\n");
            clearInputBuffer();
        } else {
            break;
        }
    }

    /* tuition fees and other fees per course */
    float tuitionPerUnit = 450.00;
    float registrationFee, miscellaneousFee = 1000.00, laboratoryFee;

    /* set fees based on course selection */
    switch (course) {
        case 1:
            registrationFee = 545.00;
            laboratoryFee = 3000.00;
            break;
        case 2:
            registrationFee = 550.00;
            laboratoryFee = 3500.00;
            break;
        case 3:
            registrationFee = 555.00;
            laboratoryFee = 1500.00;
            break;
        case 4:
            registrationFee = 560.00;
            laboratoryFee = 3000.00;
            break;
    }

    /* calculate total units and total tuition */
    int totalUnits = subjects * 3;
    float totalTuition = (totalUnits * tuitionPerUnit) + registrationFee + miscellaneousFee + laboratoryFee;
    int totalTuitionInt = (int) totalTuition;
    int cents = (int)((totalTuition - totalTuitionInt) * 100);

    /* validate amount tendered */
    do {
        printf("Enter Amount Tendered (Must be no less than %.2f): ", totalTuition);
        if (scanf("%f", &amountTendered) != 1 || amountTendered < totalTuition) {
            printf("Error: Amount tendered is less than the total assessment. Please provide a sufficient amount.\n");
            clearInputBuffer();
        } else {
            break;
        }
    } while (1);

    /* convert the total tuition to words */
    char totalInWords[500] = "";
    convertToWords(totalTuitionInt, totalInWords);

    /* print the official receipt */
    printf("\n\nUniversity of Cebu - Main Campus\nOFFICIAL RECEIPT\n\n");
    printf("ID #: %s\n", student_id);
    printf("Name: %s, %s\n", last_name, first_name);
    printf("Gender: %s\n", gender);
    printf("Course: ");
    switch (course) {
        case 1: printf("BSIT - ");
        break;
        case 2: printf("BSHM - ");
        break;
        case 3: printf("BSED - ");
        break;
        case 4: printf("COMPE - ");
        break;
    }
    printf("%d\n", year);
    printf("Total Units: %d\n", totalUnits);
    printf("Total Assessment: %.2f\n", totalTuition);

    /* print the amount in words */
    if (cents > 0) {
        printf("Amount in words: %sand %d/100\n", totalInWords, cents);
    } else {
        printf("Amount in words: %s\n", totalInWords);
    }

    return 0;
}

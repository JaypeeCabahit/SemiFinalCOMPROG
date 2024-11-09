/* number_words.c */
#include <string.h>
#include "number_words.h"

char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *thousands[] = {"", "Thousand", "Million"};

/* Helper function to convert a three-digit number into words */
void convertThreeDigit(int num, char *output) {
    if (num >= 100) {
        strcat(output, ones[num / 100]);
        strcat(output, " Hundred ");
        num %= 100;
    }
    if (num >= 20) {
        strcat(output, tens[num / 10]);
        strcat(output, " ");
        num %= 10;
    } else if (num >= 10) {
        strcat(output, teens[num - 10]);
        strcat(output, " ");
        num = 0;
    }
    if (num > 0) {
        strcat(output, ones[num]);
        strcat(output, " ");
    }
}

/* Main function to convert the total amount into words */
void convertToWords(int num, char *output) {
    int thousandCounter = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char temp[100] = "";
            convertThreeDigit(num % 1000, temp);
            strcat(temp, thousands[thousandCounter]);
            strcat(temp, " ");
            strcat(temp, output);
            strcpy(output, temp);
        }
        num /= 1000;
        thousandCounter++;
    }
    if (strlen(output) == 0) {
        strcpy(output, "Zero ");
    }
}

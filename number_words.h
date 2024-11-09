// number_words.h
#ifndef NUMBER_WORDS_H
#define NUMBER_WORDS_H

/* Arrays for converting numbers to words */
extern char *ones[];
extern char *teens[];
extern char *tens[];
extern char *thousands[];

/* Function declarations */
void convertThreeDigit(int num, char *output);
void convertToWords(int num, char *output);

#endif // NUMBER_WORDS_H

/** @mainpage
 * The program that guesses the number from 1 to 100 
 */
/** @page guess_number
 * The program that guesses the number from 1 to 100 
 * @section SYNOPSIS
 * `guess_number` [\a options]
 * @section DESCRIPTION
 * The program guesses a number from 1 to 100. It is possible to use Roman numbers (see OPTIONS).
 * @section OPTIONS
 * -h, --help - Prints the usage for the executable and exits.
 * 
 * -r - Enables roman numbers.
 */
#include <string.h>


/**
 *   Buffer for converting integer to a string
 */
char str_number[4] = {0};
/**
 *   A table for converting Arabic numbers from 1 to 100 to Roman numbers in string representation
*/
char* roman_numbers[100] = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
    "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
    "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
    "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
    "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
    "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
    "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
    "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"
};


/** A table for converting Arabic numbers to Roman numbers in string representation
 * @param number Arabic number 
 * @return Roman number in string representation
 */
char* arabic2roman(int number);


/** A table for converting Roman numbers in string representation to Arabic numbers
 * @param roman Roman number in string representation
 * @return integer Arabic number if Roman number from 1 to 100 
 * else return -1
 */
int roman2arabic(char *roman);


/** A table for converting Arabic numbers to string
 * @param number Arabic number 
 * @return number in string representation
 */
char* number2string(int number);

/** Main
 * @param argc a counter for the number of command line arguments passed to the program.
 * @param argv  pointer to an array of strings that contains program arguments.
 * @return 0 if program have executed without errors else other code indicates an error is encountered.
 */
int main(int argc, char **argv);

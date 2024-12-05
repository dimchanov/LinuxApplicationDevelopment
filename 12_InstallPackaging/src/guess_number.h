#pragma once


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
extern char str_number[4];
/**
 *   A table for converting Arabic numbers from 1 to 100 to Roman numbers in string representation
*/
extern char* roman_numbers[100];


/** A function for converting Arabic numbers to Roman numbers in string representation
 * @param number Arabic number 
 * @return Roman number in string representation
 */
char* arabic2roman(int number);


/** A function for converting Roman numbers in string representation to Arabic numbers
 * @param roman Roman number in string representation
 * @return integer Arabic number if Roman number from 1 to 100 
 * else return -1
 */
int roman2arabic(char *roman);


/** A function for converting Arabic numbers to string
 * @param number Arabic number 
 * @return number in string representation
 */
char* number2string(int number);

/** Start guessing
 * @param argc a counter for the number of command line arguments passed to the program.
 * @param argv  pointer to an array of strings that contains program arguments.
 * @return 0 if program have executed without errors else other code indicates an error is encountered.
 */
int start_guessing(int argc, char **argv);

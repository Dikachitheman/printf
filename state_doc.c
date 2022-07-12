/**
 * @file state_doc.c
 * @date 2022-07-12
 * 
 * 
 * this file contains the design for the state implementation for the custom printf (_printf)
 * 
 * the idea is to have a compact code to be applicable across all specifiers
 * 
 * The overall syntax of a conversion specification is:

           %[$][flags][width][.precision][length modifier]conversion

 * the program would start with _printf function. 
 * when the arguments has a % symbol -- the state function is called. 
 *    not the spec function
 * the state function checks is (position) = p + 1 is a flag
 * 
 * if true the flag function is called
 * if false, if p + 1 is width, width function is called
 * if false, if p + 1 is precision, precision is called
 * then length is called.
 * 
 * what arguments would state function take?? (va_list)
 * function pointer should be used to access the states.
 * 
 * 
 */
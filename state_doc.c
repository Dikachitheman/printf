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
 * the args should be va_list args. 
 * the spec function wouldnt be accessed from printf instead from state
 * 
 * the entire args would be checked one after the other.
 * example %4.2ld, 67.0987
 *      = 67.09
 * 
 * va_list would contain the entire elements --
 * 
 * flag not present, flag false.
 * length true in pos + 1, length function would print first four characters
 * precision would check for decimal point, print first two characters
 * long??
 * flag too??
 * 
 * 
 *
 * ****actual code instance******
 * printf ( takes in format specifier, and number of arguments)
 * 
 * as long as element after % isnt % or null -->
 * 
 * int _printf(const char *format, ...)
 * {
 * 
 *      if (postion(%) + 1) == - || +
 *          flag()
 *      if flag is true --> position ++
 *                  else -- > if (postion(%) + 1) == int
 *                            width()
 *      if width is true --> position ++
 *                  else -- > if (postion(%) + 1) == .
 *                            precision()
 *      if precision is true --> position ++
 *                  else -- > if (postion(%) + 1) == l || ll || h
 *                            length()
 * 
 * }
 */
#ifndef Calc_h

#define Calc_h

#include <iostream>
#include <string>

/* Lexical Unit used for distinction between different Symbols(i.e. +,-,*,/) and Numbers */
class Token{
public:
	char kind;
	double value;
};

/* Pseudo-Stream used for Buffering a single Value. */
class Token_Stream{
public:
	static void putback(Token buff);
	static Token get();
private:
	static Token buffer;
	static bool is_full;
};


void error(std::string error_message);
int factor(int input);
double expression();

/* Config Options
DONT USE THE FOLLOWING CHARS AS MAGIC NUMBERS: +, -, *, /, %, (, ), ., !, ^
*/
const char kind_number = '8';	// Magical Number for identifing Number-Tokens

const char kind_quit = 'q';		//Symbol used to quit(Cant be same as kind_number)
const char kind_print = '=';	// Symbol used to print the current Result(Cant be same as kind_number)

const char symbol_print = '=';	//Output Symbol used before every result
const char symbol_prompt = '>';	//Input Symbol used before every Input


#endif


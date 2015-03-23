

#include "Header.h"

/*
Simple Stack-based Calculator following Bjarne Stroustrups Model from Programming: Principles and Practices using C++(2nd Edition)

Input from cin and Output to cout.
Config is in Header.h
To qui,t write 'q'(Can be changed in config)
To get a result, write '=' after a calculation(Can be changed in config)
Multiple Calculations can be made at once

The following Grammar is used:

Statement:
Expression
Quit
Print

Expression:
Term
Expression + Term
Expression - Term

Term:
Factorial
Term * Factorial
Term / Factorial
Term % Factorial

Factorial:
Primary
Primary!
Primary^primary

Primary:
Number
( Expression )
- Number
+ Number

Number:
Floating-Point Number

The Input goes through a Token_Stream before it gets tokenized. Needed when a symbol is encountered which is not in the scope of the current function.
A Token is a symbol or a Number.

*/


/*Used for calculating factorials*/
int factor(int input){ 
	if (input <= 1) return 1.0;
	for (int i = input-1; i > 0; i--){
		input *= i;
	}
	return input;
}

/*Simple Error Handling*/
void error(std::string error_message){
	std::cout << "\nERROR: " << error_message;
	throw 0;
}

/*Prints the result and creates a new prompt symbol only when everything is calculated*/
void print_result(double result){
	std::cout << symbol_print << result << "\n";
	int i = std::cin.get();
	if (i == '\n') std::cout << symbol_prompt;
	else std::cin.putback(i);
}


int main(int argc, const char* argv[])

{
	std::cout << symbol_prompt;
	double val;
	while (true){
		try{
			Token t = Token_Stream::get();
			if (t.kind == kind_print) print_result(val);
			else if (t.kind == kind_quit) break;
			else{
				Token_Stream::putback(t);
				val = expression();
			}
		}
		catch (int e){

			std::cout << "\n" << symbol_prompt;
		}
	}
	return 0;
}


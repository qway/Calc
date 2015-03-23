# Calc
Simple Stack-Based Calculator following Bjarne Stroustrups Model from Programming: Principles and Practices using C++(2nd Edition)

Input from cin and Output to cout.

Config is in Header.h

To qui,t write 'q'(Can be changed in config)

To get a result, write '=' after a calculation(Can be changed in config)

Multiple Calculations can be made at once

The following Grammar is used:


Statement:
* 	Expression
* 	Quit
* 	Print

Expression:
*	Term
*	Expression + Term
*	Expression - Term

Term:
* Factorial
* Term * Factorial
* Term / Factorial
* Term % Factorial

Factorial:
* Primary
* Primary!
* Primary^primary

Primary:
*	Number
*	( Expression )
*	- Number
*	+ Number

Number:
*	Floating-Point Number

The Input goes through a Token_Stream before it gets tokenized. Needed when a symbol is encountered which is not in the scope of the current function.
A Token is a symbol or a Number.

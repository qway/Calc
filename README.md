# Calc
Simple Stack-Based Calculator following Bjarne Stroustrups Model from Programming: Principles and Practices using C++(2nd Edition)

Input from cin and Output to cout.

Config is in Header.h

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
*	Primary
*	Term * Primary
*	Term / Primary
*	Term % Primary

Primary:
*	Number
*	( Expression )
*	- Number
*	+ Number

Number:
*	Floating-Point Number

The Input goes through a Token_Stream ts before it gets tokenized. Needed when a symbol is encountered which is not in the scope of the current function.
A Token is a symbol or a Number.

#include "Header.h"
/*Basically just a bunch of switch statements that follow the model explained in Calc_Main.cpp*/

double primary(){
	Token next_token = Token_Stream::get();
	switch (next_token.kind){
	case '(':
	{
		double val = expression();
		if (Token_Stream::get().kind == ')') return val;
		else error("')' expected");
	}
	case kind_number:
		return next_token.value;
	case '+':
		return primary();
	case '-':
		return -primary();
	default:
		error("Primary expected!");
		break;
	}
}

double factorial(){
	double left = primary();
	Token next_token = Token_Stream::get();
	switch (next_token.kind){
	case '!':
		if (left < 0) error("Cant calculate factorial of something negative");
		return double(factor(int(left))); //Casting to Int, because you cant take the factorial of a double.
	case '^':
		return pow(left, primary());
	default:
		Token_Stream::putback(next_token);
		return left;
	}
}

double term(){
	double left = factorial();
	Token next_token;
	while (true){
		next_token = Token_Stream::get();
		switch (next_token.kind){
		case '*':
			left *= factorial();
			break;
		case '/':
		{
			double right = factorial();
			if (right == 0) error("Cant divide through 0");
			left /= right;
			break;
		}
		case '%':
		{
			double right = factorial();
			if (right == 0) error("Cant divide through 0");
			fmod(left, right);
			break;
		}
		default:
			Token_Stream::putback(next_token);
			return left;
		}
	}
}

double expression(){
	double left = term();
	Token next_token;
	while (true){
		next_token = Token_Stream::get();
		switch (next_token.kind){
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			Token_Stream::putback(next_token);
			return left;
		}
	}
}


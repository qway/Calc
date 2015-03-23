#include "Header.h"

bool Token_Stream::is_full = false;
Token Token_Stream::buffer;

/* Creates a new Token from the next char in the Input-Stream. If it's a number, it rereads it as a double and saves the value in the Token. */
inline Token get_Token(){
	char ch;
	std::cin >> ch;
	switch (ch){
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': {
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return Token{ kind_number, val };
	}
	case kind_quit:
	case kind_print:
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '%':
	case '!':
	case '^':
		return Token{ ch };
	default:
		error("Bad Token!");
		break;
	}
}


/* Gets next Token, if the buffer is full, gets the Token from the Buffer*/
Token Token_Stream::get(){
	if (is_full){
		is_full = false;
		return buffer;
	}
	else {
		return get_Token();
		is_full = true;
	}
}

/* Puts a Token back in the Token_stream, error if already full*/
void Token_Stream::putback(Token buff){
	if (is_full) error("Already full!");
	buffer = buff;
	is_full = true;
}




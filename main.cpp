#include "header.h"

int main() {
	//vars
	string command;
	string phrase;
	string encrypted = "";
	bool done = false;

	//input prompt
	cout << "Encrypt - Encrypt <phrase>" << endl;
	cout << "Decypt - Decrypts last encrypted phrase" << endl;
	cout << "done - Close program" << endl << endl;

	//infinite loop
	while (!done) {
		//takes input
		takeInput(command, phrase);

		//decides command taken
		if (command == "Encrypt" || command == "encrypt") {
			encrypt(phrase, encrypted);
		}
		else if ((command == "Decrypt" || command == "decrypt") && encrypted.length() > 0) {
			decrypt(encrypted);
		}
	}

	return 0;
}
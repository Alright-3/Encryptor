#include "header.h"

void takeInput(string& command, string& phrase) {
	bool done = false;
	string input;

	//takes command
	cin >> command;

	//checks for "done"
	if (command == "done") {
		exit(0);
	}
	else if (command == "Encrypt" || command == "encrypt") {
		//takes first word of phrase (protects program if no phrase is entered)
		cin >> phrase;

		//takes rest of phrase
		getline(cin, input);

		//completes phrase
		phrase += input;
	} 

	return;
}

void encrypt(string phrase, string& encrypted) {
	//converts to binary
	encrypted = stringToBinary(phrase);

	//encrypts using key
	useKey(encrypted);

	//outputs result
	cout << encrypted << endl;

	return;
}

void decrypt(string phrase) {
	//converts to binary
	string decryptedPhrase = stringToBinary(phrase);

	//encrypts using key
	useKey(decryptedPhrase);

	//outputs result
	cout << decryptedPhrase << endl;

	return;
}

void useKey(string& bin) {
	string result = ""; //result
	string key = stringToBinary(KEY); //binary value of the key

	//compares binary strings with XOR
	for (int i = 0; i < bin.length(); i++) {
		//and
		if ((bin[i] == '0' && key[i % key.length()] == '0') || (bin[i] == '1' && key[i % key.length()] == '1')){
			result = result + '0';
		} 
		//or
		else if 
			((bin[i] == '1' && key[i % key.length()] == '0') || (bin[i] == '0' && key[i % key.length()] == '1')) {
			result = result + '1';
		}
	}

	bin = binaryToString(result);
	
	return;
}

string stringToBinary(string str) {
	char parse; //character to be parsed
	int parseVal; //ascii value of parse
	string parseBinary; //binary value of parse
	string strBinary = ""; //binary value of phrase

	//loops through phrase characters
	for (int i = 0; i < str.length(); i++) {
		parse = str[i]; //takes 1 char
		parseVal = static_cast<int>(parse); //casts to ascii value
		parseBinary = bitset<8>(parseVal).to_string(); //converts ascii dec value to binary
		strBinary = strBinary + parseBinary; //adds value to strBinary
	}

	return strBinary;
}

string binaryToString(string str) {
	string result = "";
	string bin;

	for (int i = 0; i < str.length(); i += 8) {
		bin = str.substr(i, 8);
		result = result + binaryToChar(bin);
	}
   
	return result;
}

char binaryToChar(string bin) {
	// Create a bitset from the binary string
	bitset<8> bits(bin);

	// Convert the bitset to an unsigned long integer
	unsigned long decimal = bits.to_ullong();

	// Cast the integer to a character
	char character = static_cast<char>(decimal);

	return character;
}
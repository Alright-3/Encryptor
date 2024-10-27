#pragma once
#ifndef HEADER_H

#include <iomanip>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void takeInput(string& command, string& phrase);
void encrypt(string phrase, string& encrypted);
void decrypt(string phrase);
void useKey(string& bin);
string stringToBinary(string str);
string binaryToString(string str);
char binaryToChar(string bin);

const string KEY = "ilovelucy";

#define HEADER_H
#endif // !HEADER_H

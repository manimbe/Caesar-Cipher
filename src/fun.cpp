#include <iostream>
#include <string>
#include "fun.h"

std::string toMinus(std::string text){
	int tSize = text.size();
	while(tSize >= 0){
		if(text[tSize] > 64 & text[tSize] < 91){
			text[tSize] = text[tSize] + 32;
		}
		tSize--;
	}
	return text;
}

void cipher(std::string text, int key){
	text = toMinus(text);
	int tSize = text.size();
	
	while(tSize >= 0){
		int cValue = text[tSize] + key;
		if(text[tSize] >= 97 & text[tSize] <= 122){
			if(cValue > 122){
				text[tSize] = (cValue - 26); 
			} else{
				text[tSize] = text[tSize] + key;
			}
		}
		tSize--;
	}

	std::cout << text << "\n" << std::endl;
	
}

void decipher(std::string text, int key){
	text = toMinus(text);
	int tSize = text.size();
	
	while(tSize >= 0){
		int cValue = text[tSize] - key;
		if(text[tSize] >= 97 & text[tSize] <= 122){
			if(cValue < 97){
				text[tSize] = (cValue + 26); 
			} else{
				text[tSize] = text[tSize] - key;
			}
		}
		tSize--;
	}
	
	std::cout << text << "\n" << std::endl;
	
}

void start(){
	while(true){
		
		std::string text;
		int sKey;
		int sChoice;
		
		std::cout << "Key:" << std::endl;
		std::cin >> sKey;
		std::cin.ignore();
		if(sKey < 0 | sKey > 25){
			std::cout << "Please, enter a valid key\n" << std::endl;
			continue;
		}
		std::cout << "\nChoice:" << "\n1. Encrypt" << "\n2. Decrypt" << std::endl;
		std::cin >> sChoice;
		std::cin.ignore();
		if(sChoice == 1){
			std::cout << "\nText:" << std::endl;
			getline(std::cin, text);
			cipher(text, sKey);
		} else if(sChoice == 2){
			std::cout << "\nText:" << std::endl;
			getline(std::cin, text);
			decipher(text, sKey);	
		} else{
			std::cout << "\nPlease, select a valid option\n" << std::endl;
		}
			
		
	}
}


/*

// Copyright (c) varcredible. All rights reserved.

// The name of the program: Company Name Generator
// Verison of the program: 1.1.4
// Langauge: English
// Autor: Zorin Stepan 
// Nickname: varcredible
// Country: Russia
// City: Moscow
// Goal: Only for creator this program (for Zorin Stepan). Not for sale.

// Copyright (c) varcredible. All rights reserved.

*/

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>

using std::string;
using std::ofstream;

void startProcess(const int* length_name_company, const int* time_delay, ofstream& fout)
{
	srand(time(NULL));
	
	char value = ' ';

	char english_alphabet_consonants[6] =
	{ 'a', 'e', 'i',
	  'o', 'u', 'y',
	};

	char english_alphabet_vowels[20] =
	{
	  'b', 'c', 'd', 'f', 'g',
	  'h', 'j', 'k', 'l', 'm',
	  'n', 'p', 'q', 'r', 's',
	  't', 'v', 'w', 'x', 'z'
	};

	const int LENGTH_NAME_COMPANY = *length_name_company;

	while (true)
	{			
		char* generated_name_company = new char[LENGTH_NAME_COMPANY];
		int temp = 0;

		if (LENGTH_NAME_COMPANY < 7)
		{
			for (size_t i = 0; i < LENGTH_NAME_COMPANY; i++) // THE 1st RULE: If the name company begins with a vowel
			{
				if (i == 0 && temp == 0) // any first vowel letter
				{
					generated_name_company[i] = toupper(english_alphabet_vowels[rand() % 20]);
					fout << generated_name_company[i] << "";
				}

				else if (i > 0 && temp < 2) // any 2 consonant letters
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
					temp++;
				}

				else if (i > 0 && temp == 2) // any vowel letter
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
					temp = 0;
				}

				else
				{
					continue;
				}
			}

			fout << " | ";
			temp = 0;

			for (size_t i = 0; i < LENGTH_NAME_COMPANY; i++) // THE 2nd RULE: If the name company begins with a consonant letter
			{
				if (i == 0 && temp == 0) // any first consonant letter
				{
					generated_name_company[i] = toupper(english_alphabet_consonants[rand() % 6]);
					fout << generated_name_company[i] << "";
				}

				else if (i > 0 && temp < 2) // any 2 consonant letter
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
					temp++;
				}

				else if (i > 0 && temp == 2) // any 2 consonant letters
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
					temp = 0;
				}

				else
				{
					continue;
				}
			}

			fout << " | ";
			temp = 0;

			for (size_t i = 0; i < LENGTH_NAME_COMPANY; i++) // THE 3th RULE: If the name company begins with a vowel letter
			{
				if (i == 0) // any first vowel letter
				{
					generated_name_company[i] = toupper(english_alphabet_vowels[rand() % 20]);
					fout << generated_name_company[i] << "";
				}

				else if ((i > 0) && (i < 3)) // any 2 consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else if ((i > 2) && (i < 5)) // any 2 vowel letters
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
				}

				else if (i == (LENGTH_NAME_COMPANY - 1)) // any consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else
				{
					continue;
				}
			}
		}

		else if (LENGTH_NAME_COMPANY >= 7)
		{
			for (size_t i = 0; i < LENGTH_NAME_COMPANY - 4; i++) // THE 4th RULE: If the name company begins with a consonant letter + suffix "-soft"
			{
				if (i == LENGTH_NAME_COMPANY - 5)
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else if (i == 0 && temp == 0) // any first consonant letter
				{
					generated_name_company[i] = toupper(english_alphabet_consonants[rand() % 6]);
					fout << generated_name_company[i] << "";
				}

				else if (i > 0 && temp < 2) // any 2 vowel letters
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
					temp++;
				}

				else if (i > 0 && temp == 2) // any consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
					temp = 0;
				}

				else
				{
					continue;
				}
			}

			fout << "soft  |  ";
			temp = 0;

			for (size_t i = 0; i < LENGTH_NAME_COMPANY - 4; i++) // THE 5th RULE: If the name company begins with a vowel letter + suffix "-soft"
			{
				if (i == LENGTH_NAME_COMPANY - 5)
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else if (i == 0 && temp == 0) // any first vowel letter
				{
					generated_name_company[i] = toupper(english_alphabet_vowels[rand() % 20]);
					fout << generated_name_company[i] << "";
				}

				else if (i == 1 && temp == 0) // any second consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else if (i > 1 && temp < 2) // any 2 vowels letters
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
					temp++;
				}

				else if (i > 1 && temp == 2) // any 1 consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
					temp = 0;
				}

				else
				{
					continue;
				}
			}

			fout << "soft | ";
			temp = 0;

			for (size_t i = 0; i < LENGTH_NAME_COMPANY - 4; i++) // THE 6th RULE: If the name company begins with a consonant letter + suffix "-ware"
			{
				if (i == LENGTH_NAME_COMPANY - 5)
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else if (i == 0 && temp == 0) // any first consonant letter
				{
					generated_name_company[i] = toupper(english_alphabet_consonants[rand() % 6]);
					fout << generated_name_company[i] << "";
				}

				else if (i > 0 && temp < 2) // any 2 vowels letters
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
					temp++;
				}

				else if (i > 0 && temp == 2) // any 1 consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
					temp = 0;
				}

				else
				{
					continue;
				}
			}

			fout << "ware  |  ";
			temp = 0;

			for (size_t i = 0; i < LENGTH_NAME_COMPANY - 4; i++) // THE 7th RULE: If the name company begins with a vowel letter + suffix "-ware"
			{
				if (i == LENGTH_NAME_COMPANY - 5)
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6]; // any 1 consonant letter
					fout << generated_name_company[i] << "";
				}

				else if (i == 0 && temp == 0) // any first vowel letter
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
				}

				else if (i == 1 && temp == 0) // any second consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
				}

				else if (i > 1 && temp < 2) // any 2 vowels letters
				{
					generated_name_company[i] = english_alphabet_vowels[rand() % 20];
					fout << generated_name_company[i] << "";
					temp++;
				}

				else if (i > 1 && temp == 2) // any 1 consonant letter
				{
					generated_name_company[i] = english_alphabet_consonants[rand() % 6];
					fout << generated_name_company[i] << "";
					temp = 0;
				}

				else
				{
					continue;
				}
			}

			fout << "ware\n";
		}

		delete[] generated_name_company;
		Sleep(*time_delay);
	}
}


void showMenu()
{
	using std::cout;
	using std::cin;
	using std::endl;

	ofstream fout("NamesForCompany.txt", std::ios::app);
	int length_name_company = 0;
	int time_delay = 1001;
	int* ptr_length_name_company = &length_name_company;
	int* ptr_time_delay = &time_delay;
	cout << "Enter a length the name company: ";
	cin >> length_name_company;
	cout << "\nThe program process started successfully.\nGeneration occurs once per second.\nUpload the file name is \"NamesForCompany.txt\".";
	startProcess(ptr_length_name_company, ptr_time_delay, fout);

	fout.close();
	delete ptr_length_name_company;
	delete ptr_time_delay;
}

int main()
{
	showMenu();
	return 0;
}

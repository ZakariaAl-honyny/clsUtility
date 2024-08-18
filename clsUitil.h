#pragma once

#include <iostream>
#include <string>
#include "clsDate.h";

using namespace std;

class clsUitil
{

public:

	enum enCharType { SamallLetter = 1, CapitalLetter = 2, Digit = 3,
		MixChars = 4 , SepcialCharcter = 5};

	static void Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomCharcter(enCharType CharType)
	{
		//update this method to accept mixchars
		if (CharType == enCharType::MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
			case enCharType::SamallLetter:
			{
				return char(RandomNumber(97, 122));
				break;
			}
			case enCharType::CapitalLetter:
			{
				return char(RandomNumber(65, 90));
				break;
			}
			case enCharType::Digit:
			{
				return char(RandomNumber(48, 57));
				break;
			}
			case enCharType::SepcialCharcter:
			{
				return char(RandomNumber(33, 47));
				break;
			}
		}

	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharcter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key = Key +GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);

		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] ";
			cout << GenerateKey(CharType) << endl;
		}
	}	

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int RandNumFrom, int RandNumTo)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(RandNumFrom, RandNumTo);
	}

	static void FillArrayWithRandomWrods(string arr[], int arrLength, enCharType CharType , int WordLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, WordLength);
	}

	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(float& A, float& B)
	{
		float Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate::SwapDates(Date1, Date2);
	}
		
	static void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void SwapChar(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void ShuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i <= arrLength - 1; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i <= arrLength - 1; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (short i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t ";
			cout << t;
		}
		return t;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

};














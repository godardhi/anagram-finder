#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "quicksort.h"

using namespace std;

void procedure0(vector<string>& dictionnaire)
{
	string tmp;
	ifstream data_in("mot.txt");
	if(data_in.is_open())
	{
		while(getline(data_in, tmp))
		{
			dictionnaire.push_back(tmp);
		}
		data_in.close();
	}else
	{
		cout<<"ERROR"<<endl;
	}	
}

// Une fonction qui prend en paramètre deux mots et détermine s'ils sont anagrammes l'un de l'autre \\ A function that takes in two words as parameters and determines if those words are anagrams 
bool anagramme_check(string mot1, string mot2)
{
	string signature1;
	string signature2;

	signature1= findSignature(mot1);
	signature2= findSignature(mot2);

	if(signature1==signature2)
	{
		return true;
	}else 
	{
		return false; 
	}

}

void procedure1(vector<string>& dictionnaire)
{
	for(int i=0; i<dictionnaire.size(); i++)
	{
		cout<<"*"<<dictionnaire[i]<<endl; // A certain word is marked with *
		for(int j=i+1; j<dictionnaire.size(); j++)
		{
			if(anagramme_check(dictionnaire[i],dictionnaire[j])==true)
			{
				cout<<"-"<<dictionnaire[j]<<endl; // and its corresponding anagrams are marked with -
			}
		}
	}
}

int main()
{
	vector<string> dictionnaire;
	// Une fonction qui charger en mémoire la liste de mots contenus dans le fichier mot.txt \\ A function that loads the content of mot.txt file into a vector 
	procedure0(dictionnaire);
		
	// Une fonction qui vérifie si chacun des mots contenus dans le fichier mots.txt à un anagramme ou non \\ A function that checks if every word in the vector has an anagram and if so 
	// + affiche et enregristre les anagrammes dans un fichier anagrammes.txt. \\ it promps it on the console and saves those possesing anagrams and their anagrams in a text file.
	procedure1(dictionnaire);
	
	return 0;
}

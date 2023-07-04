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

bool anagramme_check(string mot1, string mot2)
{
	bool vraioufaux=false;
	string mot1_copy=mot1;
	string mot2_copy=mot2;

	if(mot1_copy.length()==mot2_copy.length())
	{
		 string signature1 = findSignature(mot1_copy);
		 string signature2 = findSignature(mot2_copy);	
		if(signature1==signature2)
		{
			vraioufaux=true;
		}
	}else
	{
		vraioufaux=false;
	}
	return vraioufaux;
}

void procedure1(vector<string>& dictionnaire)
{ 
	string mot1;
	string mot2;
	ofstream data_out("anagrammes.txt", ios::trunc);
	if(data_out.is_open())
	{
		for(int i=0; i<dictionnaire.size(); i++)
		{
			mot1 = dictionnaire[i];
			for(int j= i+1; j<dictionnaire.size(); j++)
			{
				mot2=dictionnaire[j];
				data_out<<mot1 +" - ";
				if(anagramme_check(mot1,mot2)==true)
				{ 
					data_out<<mot2+" - "; 
				}
			}
			data_out<<"\n";	
		}
		data_out.close();
	}else
	{
		cout<<"ERROR"<<endl;
	}	
}

int main()
{
	vector<string> dictionnaire;
	string mot1;
	string mot2;
	// Une fonction qui charger en mémoire la liste de mots contenus dans le fichier mot.txt
	procedure0(dictionnaire);
	// Une fonction qui prend en paramètre deux mots et détermine s'ils sont anagrammes l'un de l'autre
	anagramme_check(mot1,mot2);
	// Une fonction qui vérifie si chacun des mots contenus dans le fichier mots.txt à un anagramme ou non 
	// + affiche et enregristre les anagrammes dans un fichier anagrammes.txt.
	procedure1(dictionnaire);
	
	return 0;
}

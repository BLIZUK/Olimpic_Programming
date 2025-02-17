/*
Задача - Реконструкция ДНК
*/


#include <sstream>
#include <string>
#include <iostream>
#include <vector>


using namespace std;


//vector <string>
void split(const string& input, vector<string>& words)
{
	istringstream iss(input);
	//vector<string> words;
	string word;

	while (iss >> word)
	{
		words.push_back(word);
	}

	//return words;
}


void proces()
{
	int N, a, b;
	string input;
	vector<string> words;

	cin >> N;
	cin.ignore();
	getline(cin, input);

	split(input, words);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		words[b - 1] = words[b - 1] + words[a - 1];
		words[a - 1] = "";
	}
	for (const auto& s : words)
	{
		cout << s << endl;
	}
}


int main()
{
	proces();
	return 0;
}
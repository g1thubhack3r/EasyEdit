#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h> 
using namespace std;
void usage()
{
	cout << "Usage:" << endl;
	cout << "EasyEdit [-h] [filename]" << endl;
	cout << "EasyEdit is an easy editor" << endl;
	cout << "Will open the file named filename if filename exist & file exist" << endl;
	cout << "If file doesn't exist it will automaticly saved at quit" << endl;
	cout << "If filename doesn't exist this program will ask the open file" << endl;
	cout << "If open file doesn't exist / is blank it will create a new file and ask save filename when exit" << endl;
	cout << "-h: print this usage and quit" << endl;
}
string edit(string filename)
{
	fstream file(filename, ios::in | ios::out | ios::app);
	file.seekg(0L, ios::beg);
	file.seekp(0L, ios::beg);
	string buffer;
	while (!file) getline(file, buffer);
	file.clear();
	file.close();
	cout << buffer;
	while (true)
	{
		int input = getch();
		if (input == 27) break;
		if (input == 8)
		{
			system("cls");
			buffer.erase(buffer.end() - 1);
			cout << buffer;
		}
		else
		{
			cout << (char)input;
			buffer.push_back(input);
		}
	}
	return buffer;
}
int main(int argc, char** argv)
{
	if (argc > 2)
	{
		cerr << "error: too much arguments" << endl;
		usage();
	}
	if (argc == 2)
	{
		string argument(argv[1]);
		string buffer = edit(argument);
		fstream file(argument, ios::in | ios::out | ios::trunc);
		file << buffer;
		file.close();
	}
	else
	{
		cout << "Enter filename to open/save:";
		string filename;
		cin >> filename;
		system("cls");
		string buffer = edit(filename);
		fstream file(filename, ios::in | ios::out | ios::trunc);
		file << buffer;
		file.close();
	}
	return 0;
}

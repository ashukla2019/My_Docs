#include<iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;
	fout.open("myfile.txt");
	string line;
	//writing data to file
	while(fout)
	{
		getline(cin, line);
		if(line == -1)
		{
			break;
		}
		else
		{
			fout<<line<<endl;
		}
	}
	// Close the File 
	fout.close(); 
	ifstream fin;
	fin.open(myfile.txt);
	while(fin)
	{
		getline(fin, line);
		cout<<line<<endl;
	}
	fin.close();
	return 0;
}

/*
*This software is licensed under the Noran Restricted Public License (0.02)
*Author: Norton "dymatic" Jenkins <kzzear@hotmail.com>
*/
#include <iostream>
#include <fstream>
using namespace std;
/**
*Finds the number of lines in a file.
*@param filename - The path to the file
*@return lines - The number of lines in the file
*/
int linec(string filename)
{
    ifstream file(filename.c_str());
    int lines=0;
    string buffer;

    for(; getline(file,buffer);)
    {
        lines++;
    }
    file.close();
    return lines;
}

/**
*Orders the file by file length.
*@param filepath - The path to the file
*/
void orderFile(string filepath)
{

    ifstream file(filepath.c_str());
    int nlines=linec(filepath);

    string lines[nlines];

    for(int index=0; index<nlines; index++) //Make container
        getline(file,lines[index]);

    for(int index=0; index<nlines-1; index++) //Iterate through positions
    {
        while(lines[index].length()<lines[index+1].length())
        {
            string buffer;
            buffer=lines[index];

            lines[index]=lines[index+1];
            lines[index+1]=buffer;
            index--;
        }
    }
    file.close();
    ofstream writer(filepath.c_str());
    for(int index=0; index<nlines; index++)
        writer<<lines[index]<<endl;
    writer.close();
}

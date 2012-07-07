
/*
*This software is licensed under the Noran Restricted Public License (0.02)
*Author: Norton "dymatic" Jenkins <kzzear@hotmail.com>
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
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
/**
*A utility for generating passwords.
*They can contain uppercase, lowercase, and numbers.
*READ: YOU MUST CALL srand(TIME(NULL)) from cstdlib and time.h for this to work.
*@param labels - What kinds of characters to include. This is a string with numbers from 0 to 3.
* 0 = lowercase, 1=capital, 2=numbers, 3=symbols. They can be grouped like this: 032
*@param length - How long the password should be.
*@return psswd - The password
*/
int spew(string labels, intensity)
{
    stringstream buffer;

    string alphaL  = "abcdefghijklmnopqrstuvwxyz";
    string alphaC  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numeric = "0123456789";
    string symbols = "`~!@#$%^&*()_+-=,<.>/?; :'\"\\][{}";

    for(int index=0; index<intensity; index++)
    {
        if(labels.find("0")!=-1)
            buffer << alphaL.at(rand()%alphaL.length());

        if(labels.find("1")!=-1)
            buffer << alphaC.at(rand()%alphaC.length());

        if(labels.find("2")!=-1)
            buffer << numeric.at(rand()%numeric.length());

        if(labels.find("3")!=-1)
            buffer << symbols.at(rand()%symbols.length());
    }
    return buffer.str();
}
/**
*Finds the number of times a string occurs in a larger string.
*@param toFindIn - The string to look in
*@param lookingFor - The string you are looking for
*/
int numberOf(string toFindIn, string lookingFor)
{
    int counter=0;
    string buff;
    while(toFindIn.find(lookingFor)!=-1)
    {
        counter++;
        buff=toFindIn.substr((toFindIn.find(lookingFor)+1),toFindIn.length());
        toFindIn=buff;
    }
    return counter;
}

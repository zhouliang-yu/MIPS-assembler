/*
 * This is a driver to test pass1 and the Label Table functions.
 *
 * Author: Alyce Brady
 * Date: 2/18/99
 * Modified by: Caitlin Braun and Giancarlo Anemone to test pass2 of the assembler.
*/

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include "LableTable.h"
#include <sstream>
#include "phase2.h"
#include "phase1.h"
using namespace std;

LableTable phase1 (char * filename);
LableTable phase2 (char * filename, LableTable table);

int compare_files(ifstream& in_file1, ifstream& in_file2)
{

    while (!in_file1.eof() && !in_file2.eof())
    {   
        string line1;
        string line2;
        getline(in_file1, line1);
        getline(in_file2, line2);
        if(line1 != line2){
            cout << "line1:"<< line1 <<endl;
            cout << "line2:"<<line2 << endl;
			return -1;
		}
    }
    return 0;
}

int main (int argc, char * argv[])
{   
    if(argc < 4)
    {
        printf("Please enter an input file, an output file, and expected output file \n");
    }
    LableTable table;
    table = phase1(argv[1]);
    
    map<string, int>::iterator it;
    for (it = table.begin(); it != table.end(); it++)
        cout << it->first << " " << it->second << endl;
    (void)phase2(argv[1], table);

    FILE* fp1;
    FILE* fp2;
    fp1 = fopen(argv[3], "r");
    fp2 = fopen(argv[2], "r");

    if(fp1 == NULL || fp2 == NULL){
    	printf("Error: Files are not open correctly \n");
    }

    ifstream in_file1;
    ifstream in_file2;
    in_file1.open(argv[3]);
    in_file2.open(argv[2]);

    int res = compare_files(in_file1, in_file2);

    if(res == 0){
    	printf("ALL PASSED! CONGRATS :) \n");
    }else{
    	printf("YOU DID SOMETHING WRONG :( \n");
    }


    fclose(fp1);
    fclose(fp2);
    
    return 0;
}



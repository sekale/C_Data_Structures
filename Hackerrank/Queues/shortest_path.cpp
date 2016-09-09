#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>


//incomplete solution
//currently accepting values
//storing matrix
//begin and dest are pairs of int storing x & y dimensions

using namespace std;

void print_matrix(char **matrix, int N)
{
    for( int i = 0; i < N; i++)
    {
        cout <<endl ;
        for(int j = 0; j < N; j++){
            cout << "\t" << matrix[i][j];
        }
    }
}

int main() {
    
    string input_line;
    int counter = 1;
    int N = 0;
    int col = 0;
    char **matrix;
    while(cin)
    {
        getline(cin,input_line);
        if(counter == 1)
        {
            stringstream convert(input_line); //converts the entered text into a number if possible
            convert >> N;
            //cout << N;
            matrix = (char **)malloc(sizeof(char*));
            
            for(int i = 0; i < N; i++)
            {
                matrix[i] = (char *)malloc(sizeof(char));
            }
        }
        
        else
        {
            int r = counter - 2;
            int c = 0;
            
            if(r < N)
            {
                for(int c = 0; c < N; c++)
                {
                    matrix[r][c] = input_line[c];
                }
            }
            
        }
        //cout << input_line << endl;
        counter++;
    }
    print_matrix(matrix,N);
    
    vector<int> dim;
    vector<int>::iterator iter1;
    iter1 = dim.begin();
    pair<int,int> begin,dest;
    counter = 1;
    int temp;
    int i = 0;
    //cout << endl << endl << input_line[i];
    //c/out << endl << endl << input_line[i+1];
    //cout << endl << endl << input_line[i+2];
    
    while(i < input_line.length())
    {
        if(input_line[i] != ' '){
            //cout << input_line[i];
            temp = input_line[i] - '0';
            dim.push_back(temp);
        }
        i++;
    }
    iter1 = dim.begin();
    for(;iter1 != dim.end(); iter1++)
    {
        cout << "\t" << endl << *iter1;
    }
    
    begin.first = dim[0];
    begin.second = dim[1];
    dest.first = dim[2];
    dest.second = dim[3];
    
    //now we want to go from begin to dest in the matrix that we have created
    
    return 0;
}
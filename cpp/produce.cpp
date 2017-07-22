/* C++ code to generate a function y=f(x), which can be constant, linear, squared of cubic.
 *     output is written in a file where the name and location can be specified from the command line
 *
 * Input: --mode    : Zero, Linear, Square, Cubic
 *        --start   : initial value of the X-axis
 *        --end     : end value of the X-axis
 *        --location: path to the ressources
 *        --saveName: name of the output filed saved
 * Output: file with the X and Y axis stored in columns saved in the specified path.
 *
 * Author: Marko Stamenkovic
 * Site: https:mstamenk.github.io
 * Mail: stamenkovim@gmail.com
 *
 * This file is part of the Snakemake Tutorial. 
 * Please visit : https://mstamenk.github.io/2017/07/snakemake-tutorial-for-pyroot(root)-users.html
 * for more informations.
*/


#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

enum type {IN = 0, OUT=1 };

void parser(int argc,char *argv[],string& mode, int& begin, int& end, string& location, string& saveName);

int read_mode(const string& mode);
void check_borders(int& begin, const int& end);
string outfile(const string& location, const string& mode, const string& saveName);

vector<vector<int>> process(const string& mode, const int& begin, const int& end);

void print(ostream& out, const vector<vector<int>>& res);
void write(const string& outfile, const vector<vector<int>>& res);


int main(int argc, char *argv[]){
    
// Initialize the variables needed to compute the files
    int begin(0);
    int end(100);
    string mode="";
    string location="/Users/marko/snakemake-tutorial/ressource/";   
    vector<vector<int>> result;
    string saveName="";
    string filename;

// Parse the arguments of the script
    parser(argc,argv,mode,begin,end,location, saveName);
    check_borders(begin,end);
// Process the 
    result = process(mode,begin,end);
    print(cout,result);
    filename = outfile(location,mode,saveName);
    write(filename, result);

    cout << "The choosen mode is " << mode << " starting from " << begin << " to " << end << " in exponent " << read_mode(mode) << " with the file name "<< filename <<endl;
    return 0;

}


void parser(int argc,char *argv[],string& mode, int& begin, int& end, string& location, string& saveName){

    for (unsigned int i(0); i<argc; i++){
                if((string)argv[i] == "--mode")     mode=string(argv[i+1]);
                if((string)argv[i] == "--start")    begin=atoi(argv[i+1]);
                if((string)argv[i] == "--end")      end=atoi(argv[i+1]);
                if((string)argv[i] == "--location") location=string(argv[i+1]);
                if((string)argv[i] == "--saveName") saveName=string(argv[i+1]);
                                        }
}

int read_mode(const string& mode){
    int i(0);
    
    if (mode == "Zero" || mode == "zero") i=0;     
    else if (mode == "Linear" || mode == "linear") i=1;     
    else if (mode == "Square" || mode == "square") i=2;     
    else if (mode == "Cubic" || mode == "cubic")   i=3;     
    else { 
        i=0;
        cout << "Exponent set to 0! Available modes are : Zero - Linear - Square - Cubic " << endl;
         }
    return i;
}

void check_borders(int& begin, const int& end){
    if (begin > end) {
        begin=end;
        cout << "Warining, the START > END. Lower limit was modified." << endl;              
                     }

}

vector<vector<int>> process(const string& mode, const int& begin, const int& end){
    
    int out(0);

    vector<int> input;
    vector<int> output;
    
    vector<vector<int>> result(2);

    int exp(read_mode(mode));
    for (int in(begin); in < end; in++){
                                out = pow(in,exp);
                                input.push_back(in);
                                output.push_back(out);
                                    }

    result[type::IN] = input;
    result[type::OUT] = output;
    
    return result;    
}

void print(ostream& out, const vector<vector<int>>& res){
    for (unsigned int i(0); i < res[type::IN].size(); i++){
                                out << res[type::IN][i] << " " << res[type::OUT][i] << endl;
                                                           }
                                                
}

void write(const string& outfile, const vector<vector<int>>& res){
    ofstream out(outfile);
    if(out.is_open()){
                print(out, res);
                out.close();
                     }
    else cout << "Unable to open the file! " << endl;

}

string outfile(const string& location, const string& mode, const string& save){
      string result = "";
      if (save == "") result = location + mode + "_values.dat";
      else result = location + save;
      
      return result;
}

//Charles Regan
//cwr2gb
//change.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char **argv){

// verify the correct number of parameters
if ( argc != 2 ) {
cout << "Must supply the input file name as the one and only parameter" << endl;
exit(1);
}

// attempt to open the supplied file
ifstream file(argv[1], ifstream::binary);

// report any problems opening the file and then exit
if ( !file.is_open() ) {
cout << "Unable to open file '" << argv[1] << "'." << endl;
exit(2);
}

FILE *fp = fopen(argv[1], "r");
string monay;
double money;

while(money != -1.00){

file >> monay;

money = atof(monay.c_str());
if(money == -1)
  exit(3);
int dollar = (int)money;
double cents = money - dollar;
string qdnp = "";
int dodis = 0;


//Generate Quarters
if( (cents/.25) > 0){
dodis = cents/.25;
cents = cents-(dodis*.25);
for(int x = 0; x < dodis; x++){
qdnp += "Q ";
} 
}
//Generate Dimes
if( (cents/.10) > 0){
dodis = cents/.10;
cents = cents-(dodis*.10);
for(int x = 0; x < dodis; x++){
qdnp += "D ";
}
}
//Generate Nickels
if( (cents/.05) > 0){
dodis = cents/.05;
cents = cents-(dodis*.05);
for(int x = 0; x < dodis; x++){
qdnp += "N ";
}
}
//Generate Pennies
if( (cents/.01) > 0){
dodis = cents/.01;
if(dodis > 1){
cents = cents-(dodis*.01);
for(int x = 0; x < dodis; x++){
qdnp += "P ";
}
}
 else{
qdnp += "P ";
}
}

int sizem = monay.size();
int endofstring = 6;

while( (sizem - endofstring) > 0){

if(endofstring < monay.size() && endofstring != monay.size()){
monay.insert((sizem-endofstring),",");
}
endofstring += 3;
}

cout << "$" << monay << " " << qdnp << endl;

}

}

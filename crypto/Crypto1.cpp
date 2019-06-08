#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <bits/stdc++.h>
//#include <stringstream>
using namespace std;

//The following encoded string responds to morse code values.
//Is this a simple substitution cipher?
//Nope!
//Morse code pairs represent hex values
//translating to the resultant hex to ascii gives:
//Wp*lXtGQ8e8qnmMYU*svFHkjIt*RQ&JpZvjm!%%KDkfp#^N9fk4dU4lB3rToT0PZQmCQEKYB4ZMv*!Fk8l%bjqlPMfIGma%%FzG gigem{C1icK_cl1CK-y0u_h4v3_m4I1} uv4vzKZt4yomiDShLm8QEFnUtwJ@NuOYfX&8u@Gn!1%Tqv0VcRzV!j!vuup8BjdNIqE5w#$%V4UZOYZ2z7T25t7&xL@WO7410QI
//which contains the flag: gigem{C1icK_cl1CK-y0u_h4v3_m4I1}

int main(){
  string enc = "dah-dah-dah-dah-dah dah-di-di-dah di-di-di-di-dit dah-dah-di-di-dit dah-dah-di-di-dit dah-dah-dah-dah-dah di-di-dah-dah-dah di-dah dah-di-di-di-dit dah-di-dah-dit di-di-di-di-dit dah-dah-dah-di-dit dah-dah-di-di-dit di-di-di-di-dah di-di-di-di-dah dah-dah-di-di-dit di-di-di-di-dit di-dah-dah-dah-dah di-di-di-dah-dah dah-dah-dah-di-dit dah-di-di-di-dit di-di-di-di-dit di-di-di-dah-dah dah-dah-dah-di-dit dah-dah-di-di-dit di-dah-dah-dah-dah dah-di-di-di-dit dit dah-di-di-di-dit dah-di-dit di-di-di-di-dah dah-di-dit di-di-di-di-dit dah-dah-dah-dah-dit di-di-di-di-dit di-di-di-di-dit di-di-dah-dah-dah di-dah dah-dah-di-di-dit di-di-di-dah-dah dah-dah-di-di-dit dah-di-di-di-dit di-di-di-di-dah dah-di-di-di-dit di-di-di-di-dah dah-dah-dah-di-dit dah-di-di-di-dit dah-di-di-dit dah-di-di-di-dit di-dah di-di-di-di-dah dah-dah-dah-dah-dit dah-dah-di-di-dit di-di-di-di-dah di-di-dah-dah-dah di-dah di-di-di-di-dit di-di-dah-dah-dah di-di-di-di-dit di-dah-dah-dah-dah di-di-dah-dah-dah dah-di-di-di-dit di-di-di-di-dah di-dah dah-dah-di-di-dit dah-dah-dah-dah-dah di-di-di-di-dit di-dah dah-dah-di-di-dit dah-di-di-di-dit dah-di-di-di-dit di-dah dah-di-di-di-dit dah-di-dit di-di-dah-dah-dah di-dah-dah-dah-dah di-di-dah-dah-dah di-di-di-di-dit di-di-dah-dah-dah di-di-di-di-dit di-di-di-di-dah dah-di-di-dit di-di-di-di-dah di-di-di-di-dah dah-di-di-di-dit dah-di-di-dit dah-di-di-di-dit dah-di-di-di-dit dah-dah-di-di-dit dah-dah-dah-dah-dah di-di-dah-dah-dah di-di-di-dah-dah di-di-di-di-dit dit di-di-di-di-dah dit di-di-di-dah-dah dah-dah-dah-dah-dit dah-di-di-di-dit dah-di-di-di-dit dah-di-di-di-dit dah-di-di-dit di-di-di-dah-dah di-di-di-di-dah dah-di-di-di-dit di-di-di-di-dah di-di-di-di-dit di-di-di-di-dit di-di-di-dah-dah di-di-di-di-dah dah-di-di-di-dit dah-di-dah-dit di-di-di-di-dah di-di-dah-dah-dah di-di-di-dah-dah di-di-di-dah-dah dah-dah-di-di-dit di-di-dah-dah-dah di-di-di-di-dit di-di-di-di-dah dah-di-di-di-dit di-di-dah-dit di-di-di-di-dit di-di-di-di-dah di-di-di-dah-dah dah-dah-dah-dah-dah di-di-di-di-dit dah-dah-dah-dah-dah di-di-di-di-dit di-dah di-di-di-di-dit di-dah-dah-dah-dah dah-di-di-di-dit dah-di-dit di-di-di-di-dah di-di-di-dah-dah di-di-di-di-dit di-dah-dah-dah-dah di-di-di-di-dah di-di-di-di-dit di-di-di-di-dah dah-di-di-dit di-di-di-di-dit dah-dah-dah-dah-dit di-di-di-di-dah di-di-dah-dah-dah di-di-di-dah-dah di-di-di-di-dah di-di-di-di-dit di-dah di-di-di-di-dah dah-di-dit dah-dah-di-di-dit dah-di-di-di-dit di-di-dah-dah-dah di-dah di-di-dah-dah-dah di-dah-dah-dah-dah di-di-di-di-dah dah-di-di-di-dit dah-di-di-di-dit dah-di-di-dit di-di-di-dah-dah dah-dah-dah-di-dit dah-di-di-di-dit dah-di-dah-dit di-di-dah-dah-dah di-di-di-di-dit dah-di-di-di-dit di-di-dah-dah-dah dah-di-di-di-dit di-dah dah-dah-di-di-dit di-dah-dah-dah-dah dah-di-di-di-dit dah-di-dah-dit di-di-di-di-dit dah-dah-dah-dah-dah di-di-di-di-dah dah-di-dit dah-di-di-di-dit dah-di-di-di-dit di-di-di-di-dah dah-dah-dah-dah-dit di-di-di-di-dah dah-dah-di-di-dit dah-di-di-di-dit dah-di-dit dah-di-di-di-dit di-dah-dah-dah-dah di-di-dah-dah-dah di-di-di-di-dit di-di-dah-dah-dah di-di-di-di-dit di-di-di-di-dah dah-di-di-di-dit dah-dah-di-di-dit di-dah di-di-di-di-dah dah-dah-di-di-dit di-di-dah-dah-dah dah-dah-dah-dah-dah dah-di-di-di-dit dah-dah-di-di-dit dah-di-di-di-dit dah-dah-dah-dah-dit dah-di-di-di-dit dah-dah-di-di-dit dah-di-di-di-dit di-di-di-di-dit dah-di-di-di-dit dah-di-dit dah-dah-di-di-dit dah-di-di-dit di-di-di-di-dah di-di-di-dah-dah di-di-di-dah-dah di-dah-dah-dah-dah dah-di-di-di-dit dah-dah-dah-dah-dit dah-di-di-di-dit di-di-di-dah-dah di-di-di-di-dah dah-di-di-dit di-di-di-di-dit di-di-dah-dit dah-di-di-di-dit di-di-di-dah-dah dah-di-di-di-dit dah-di-dah-dit di-di-di-dah-dah di-dah-dah-dah-dah di-di-di-di-dah di-di-di-dah-dah di-di-di-di-dah dah-di-di-dit di-di-dah-dah-dah dah-di-dit dah-dah-di-di-dit dah-dah-dah-dah-dit di-di-di-dah-dah dah-dah-dah-dah-dah dah-dah-di-di-dit di-di-di-di-dit di-di-di-di-dit di-di-dah-dit dah-di-di-di-dit dah-dah-dah-di-dit di-di-di-dah-dah di-di-di-di-dah dah-dah-di-di-dit dah-di-di-di-dit di-di-di-dah-dah di-di-di-dah-dah di-di-di-di-dit di-di-dah-dit dah-di-di-di-dit dah-di-dit di-di-di-dah-dah di-di-di-di-dah di-di-di-di-dah dah-dah-dah-dah-dit di-di-di-dah-dah di-dah-dah-dah-dah dah-dah-di-di-dit dah-di-dit di-di-dah-dah-dah dah-dah-dah-dah-dah dah-dah-di-di-dit di-di-di-di-dit dah-dah-di-di-dit dah-di-di-di-dit di-di-di-dah-dah di-di-di-di-dah dah-dah-di-di-dit dah-di-di-di-dit dah-dah-di-di-dit di-dah di-di-di-di-dah dah-di-di-dit di-di-di-di-dit di-dah dah-dah-di-di-dit di-di-di-di-dah di-di-di-dah-dah di-di-di-di-dah dah-dah-di-di-dit dah-dah-dah-dah-dit dah-di-di-di-dit di-di-dah-dit dah-di-di-di-dit dah-di-dit dah-di-di-di-dit dah-dah-dah-dah-dit di-di-di-di-dah di-di-di-di-dah di-di-di-di-dit di-di-di-dah-dah dah-di-di-di-dit dah-dah-dah-di-dit di-di-di-di-dah dah-di-dah-dit dah-di-di-di-dit dah-di-dit di-di-di-dah-dah dah-dah-dah-di-dit di-di-di-di-dit di-dah-dah-dah-dah di-di-di-di-dah di-di-di-di-dit di-di-di-di-dah dah-di-di-di-dit dah-di-di-di-dit dit di-di-di-di-dit di-di-di-di-dit dah-dah-di-di-dit di-di-di-di-dah dah-dah-di-di-dit dah-dah-di-di-dit di-di-di-di-dah di-dah di-di-di-di-dah dah-dah-dah-dah-dah di-di-di-di-dah dit dah-dah-di-di-dit di-di-di-di-dit di-di-di-di-dah di-di-dah-dit di-di-di-di-dit dah-dah-dah-dah-dit dah-di-di-di-dit dah-di-di-di-dit di-di-di-di-dit dah-dah-dah-di-dit di-di-dah-dah-dah dah-di-di-di-dit di-di-di-dah-dah dah-dah-dah-di-dit dah-dah-di-di-dit di-di-di-di-dit di-di-di-di-dah dah-dah-dah-dah-dah di-di-di-di-dah dah-dah-di-di-dit dah-di-di-di-dit dit di-di-dah-dah-dah di-dah-dah-dah-dah di-di-di-dah-dah di-dah-dah-dah-dah di-di-dah-dah-dah di-di-di-di-dit di-di-di-di-dit di-di-di-di-dah dah-dah-di-di-dit di-dah-dah-dah-dah dah-dah-di-di-dit dah-di-di-di-dit di-di-di-dah-dah dah-dah-dah-dah-dah di-di-di-di-dit dah-di-di-di-dit dah-di-di-di-dit di-di-di-dah-dah di-di-di-di-dit di-di-dah-dah-dah dah-dah-di-di-dit di-dah di-di-di-di-dit dah-di-di-di-dit di-di-dah-dah-dah di-dah-dah-dah-dah dah-di-di-di-dit di-dah di-di-dah-dah-dah di-dah-dah-dah-dah dah-dah-di-di-dit dah-di-di-di-dit dah-dah-di-di-dit di-di-di-di-dit dah-dah-di-di-dit di-di-di-di-dit dah-dah-di-di-dit dah-dah-dah-dah-dah di-di-di-dah-dah dah-dah-dah-di-dit di-di-di-di-dah di-di-dah-dah-dah dah-di-di-di-dit di-dah dah-di-di-di-dit di-di-di-di-dah di-di-di-di-dah dit di-di-di-di-dah dah-dah-dah-dah-dit dah-dah-di-di-dit di-dah-dah-dah-dah di-di-di-di-dah di-di-di-di-dit di-di-di-dah-dah di-di-di-di-dit dah-dah-di-di-dit dah-dah-di-di-dit di-di-dah-dah-dah di-di-di-dah-dah di-di-dah-dah-dah di-di-di-di-dah di-di-dah-dah-dah di-di-di-di-dit di-di-di-di-dit dah-di-di-di-dit di-di-di-dah-dah di-di-di-di-dah di-di-di-di-dit di-di-di-di-dit di-di-di-di-dit di-dah di-di-di-di-dah di-di-dah-dit di-di-di-di-dit dah-dah-dah-dah-dit di-di-di-di-dit di-dah di-di-di-dah-dah di-di-dah-dah-dah dah-dah-di-di-dit di-dah di-di-di-dah-dah dah-dah-di-di-dit di-di-di-di-dit di-di-di-di-dah di-di-di-dah-dah di-di-dah-dah-dah di-di-di-dah-dah di-di-di-di-dit dah-dah-di-di-dit di-di-di-di-dah di-di-di-dah-dah dah-dah-di-di-dit di-di-dah-dah-dah dah-di-di-di-dit dah-dah-di-di-dit dah-dah-dah-di-dit di-di-di-di-dah dah-di-dah-dit di-di-di-di-dah dah-dah-dah-dah-dah di-di-di-di-dit dah-dah-di-di-dit di-di-di-di-dah di-di-dah-dit di-di-di-dah-dah dah-dah-di-di-dit di-di-di-dah-dah di-di-di-di-dah di-di-di-dah-dah di-dah-dah-dah-dah di-di-di-dah-dah dah-dah-dah-dah-dah di-di-di-di-dit di-dah-dah-dah-dah di-di-di-di-dah dah-dah-dah-dah-dit";
  map<string, int> map;
  vector<string> tok;
  stringstream check1(enc);
  string interm;

  while(getline(check1, interm, ' ')) {
    tok.push_back(interm);
    map[interm]++;
  }

  /*
  for(int i = 0; i < tok.size(); i++)
    cout << tok[i] << endl;
  */

  /*
  cout << endl << "Map: " << endl;
  for(auto elem : map) {
   cout << elem.first << " " << elem.second << "\n";
  }
  */

  cout << "Convert from ascii to hex for flag:" << endl << endl;
  for(int i = 0; i<tok.size(); i++){ //Forwards

      if(tok[i] == "dah-dah-dah-dah-dah") //0
      cout << '0';
      else if(tok[i] == "di-dah-dah-dah-dah") //1
      cout << '1';
      else if(tok[i] == "di-di-dah-dah-dah") //2
      cout << '2';
      else if(tok[i] == "di-di-di-dah-dah")  //3
      cout << '3';
      else if(tok[i] == "di-di-di-di-dah") //4
      cout << '4';
      else if(tok[i] == "di-di-di-di-dit") //5
      cout << '5';
      else if(tok[i] == "dah-di-di-di-dit") //6
      cout << '6';
      else if(tok[i] == "dah-dah-di-di-dit") //7
      cout << '7';
      else if(tok[i] == "dah-dah-dah-di-dit") //8
      cout << '8';
      else if(tok[i] == "dah-dah-dah-dah-dit") //9
      cout << '9';
      else if(tok[i] == "di-dah") //a
      cout << 'a';
      else if(tok[i] == "dah-di-di-dit") //b
      cout << 'b';
      else if(tok[i] == "dah-di-dah-dit") //c
      cout << 'c';
      else if(tok[i] == "dah-di-dit") //d
      cout << 'd';
      else if(tok[i] == "dit") //e
      cout << 'e';
      else if(tok[i] == "di-di-dah-dit") //f
      cout << 'f';
      else if(tok[i] == "dah-di-di-dah") //x
      cout << 'x';

      if((i+1)%2 == 0) cout << " ";
  }

  cout << endl;

  return 0;
}

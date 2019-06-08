#include <map>
#include <iostream>
#include <string>
using namespace std;
//encoded string looks like base64?
//Statisticalish analysis using map, didnt help
//decoded from base64, I can see a pattern in first 5 bytes that could match 'gigem'
//Attempt single byte XOR. char ':' returns gzgvm and ends with }. Im guessing its a 2bit XOR
//Wait, challenge is named ':)' why not try :) as my xor?
//It worked! got my flag: gigem{I'm not superstitious, but I am a little stitious.}


string xorshift(string, string);

int main(){
  //string enc = "XUBdTFdScw5XCVRGTglJXEpMSFpOQE5AVVxJBRpLT10aYBpIVwlbCVZATl1WTBpaTkBOQFVcSQdH";
  string enc;
  int raw[] = {93, 64, 93, 76, 87, 82, 115, 14, 87, 9
             , 84, 70, 78, 9, 73, 92, 74, 76, 72, 90
             , 78, 64, 78, 64, 85, 92, 73, 5, 26, 75
             , 79, 93, 26, 96, 26, 72, 87, 9, 91, 9
             , 86, 64, 78, 93, 86, 76, 26, 90, 78, 64
             , 78, 64, 85, 92, 73, 7, 71}; //57
  /*
  map<char, int> charmap;

  for(auto ch: enc ){
    charmap[ch]++;
  }

  cout << "size: " << enc.size() << endl;

  cout << endl << "Map: " << endl;
  for(auto elem : charmap ) {
   cout << elem.first << " " << elem.second << "\n";
  }
*/
  enc = "";
  for(int i = 0; i< 57; i++)
  enc += (char)raw[i];

  string xorstring = "";
  string output = "";

  for(int i = 0; i<1; i++){

    //xorstring +=
    //Add new bit to key
    xorstring = ":)";
    output = xorshift(enc,xorstring);

    //Check for flag
    if (output.find("gigem") != -1){
      cout << "output: " << output << endl;
      cout << "key: " << xorstring << endl;
      cout << "input: " << enc << endl;
    }
  }
  return 0;
}

string xorshift(string keyin, string xorstring){
  string output = "";
  //Shift char in input by bit in xorstring, allow wrap around
    for(int pos = 0; pos < keyin.length(); pos++)
      output += (char)(keyin[pos] ^ xorstring[pos % xorstring.length()]);
  return output;
}

//(2531257, 43) -- Is this the private key? 43 and 2531257 have GCD = 1

//Cipher text
//{906851  991083  1780304 2380434 438490 356019 921472  822283  817856  556932 2102538 2501908 2211404 991083   1562919 38268}
//2242926 1641760 1304575 822982  315930 465105 2208261 1505383 1573617 448056 1309652 2367845 2391651 1641760  1379175 204639
//22396E  190D20  13E7FF  C8EC6   4D21A  718D1  21B205  16F867  1802F1  6D638  13FBD4  242165  247E63  190D20   150B67  31F5F
/*
p = 509
q = 4973
n = 2531257
phi(n) = 248600
e = 43
d = 28907

103 105 103 101 109 123 83 97 118 97 103 101 95 83 105 120 95 70 108 121 105 110 103 95 84 105 103 101 114 115 125

*/

#include <iostream>
#include <algorithm>
using namespace std;

string transform(int num, int bits);

int main(){
  int bits = 22;
  int enc[16] = {906851, 991083, 1780304, 2380434, 438490, 356019,
              921472, 822283, 817856, 556932, 2102538, 2501908,
              2211404, 991083, 1562919, 38268};
  string binary = "";
  string interm = "";

  for(int i =0; i<16; i++){
    interm = transform(enc[i],bits);
    reverse(interm.begin(),interm.end());
    binary+=interm + "";
  }
  cout << binary << endl;

}

string transform(int num, int bits){
  int ctr = 0;
  int sum = 0;
  //int size = 8;
  string binary = "";

  while(ctr<bits){
    if(num%2 == 1){
      num = num/2;
      binary+='1';
    }
    else{
      num = num/2;
      binary+='0';
    }
    ctr ++;
  }
  //cout << binary << endl;
  return binary;
}

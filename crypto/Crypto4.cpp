//Backpack encryption method! Havent heard of this one in a while.
//Translated into decimal values.
/*
enc = "11b90d6311b90ff90ce610c4123b10c40ce60dfa123610610ce60d450d000ce61061106110c4098515340d4512361534098509270e5d09850e58123610c9"

11b9 0d63 11b9 0ff9 0ce6 10c4 123b 10c4 0ce6 0dfa 1236 1061 0ce6 0d45 0d00 0ce6 1061 1061 10c4 0985 1534 0d45 1236 1534 0985 0927 0e5d 0985 0e58 1236 10c9
4537 3427 4537 4089 3302 4292 4664 4292 3302 3578 4662 4193 3302 3397 3328 3302 4193 4193 4292 2437 5428 3397 4662 5428 2437 2343 3677 2437 3672 4662 4297
int dec[62] = {17, 185, 13, 99, 17, 185, 15, 249, 12, 230
             , 16, 196, 18, 59, 16, 196, 12, 230, 13, 250
             , 18, 54 , 16, 97, 12, 230, 13, 69 , 13, 0
             , 12, 230, 16, 97, 16, 97 , 16, 196, 9 , 133
             , 21, 52 , 13, 69, 18, 54 , 21, 52 , 9 , 133
             , 9 , 39 , 14, 93, 9 , 133, 14, 88 , 18, 54
             , 16, 201} //62

int pub[8] = {99, 1235, 865, 990, 5, 1443, 895, 1477} //8

//factors of key:
99:   1,    3,       9, 11, 33, 99
1235: 1,       5, 13, 19, 65, 95, 247, 1235
865:  1,       5, 173, 865
990:  1, 2, 3, 5, 6, 9, 10, 11, 15, 18, 22, 30, 33, 45, 55, 66, 90, 99, 110, 165, 198, 330, 495, 990
5:    1,       5
1443: 1,    3,          13, 37, 39, 111, 481, 1443
895:  1,       5,     179, 895
1477: 1,          7, 211, 1477

least common multiple is 105.

Multiples:
99,198,297,396,495,594,693,792,891,990,1089,1188,1287,1386,1485,1584,1683,1782,1881,1980,2079,2178,2277,2376,2475,2574,2673,2772,2871,2970,3069,3168,3267,3366,3465,3564,3663,3762,3861,3960,4059,4158,4257,4356,4455,4554,4653,4752,4851
                                                 1235                                                       ,2470                                                            ,3705                                                  ,4940
                            835                                     ,1670                                        ,2505                                   ,3340                                   ,4175
                                  990                                               1980                                              2970                                              3960                                         4950
                                                           1443                                                                  2886                                                                       4329
                                                           1477                                                                   2894                                                                      4341

mod(n) is likely somewhere between 2894 and 2970/2
possible range for n : {1478:1485}
// NOPE values dont check out. no super increasing sets, changine range to 1485-2000

//Was able to brute force possible bags:
possible bag: {3, 5, 10, 30, 65, 141, 400, 904}
possible w: 568 possible n: 1605

possible bag: {3, 7, 11, 30, 61, 135, 377, 851}
possible w: 1037 possible n: 1506

possible bag: {4, 10, 15, 40, 80, 178, 495, 1117}
possible w: 1506 possible n: 1975
//algorithm taking too long, I am rewriting in a recursive fashion.

//Recursive algorithm written and refined. Confirmed above possible bags.
//Algorithm is extremely fast, able to increase possible key range to whatever
//closeish to linear search time?
//Increased range to 1477 to 2*1477, found 7 possible private bag sets:

{ 3, 7, 11, 30, 61, 135, 377, 851 }
w: 1037 n: 1506
1217

{ 3, 5, 10, 30, 65, 141, 400, 904 }
w: 568 n: 1605
1297

{ 4, 10, 15, 40, 80, 178, 495, 1117 }
w: 1506 n: 1975
1596

{ 5, 13, 19, 50, 99, 221, 613, 1383 }
w: 1975 n: 2444
1975

{ 5, 11, 18, 50, 103, 227, 636, 1436 }
w: 1037 n: 2543
2055

{ 5, 9, 17, 50, 107, 233, 659, 1489 }
w: 1605 n: 2642
2135

{ 6, 16, 23, 60, 118, 264, 731, 1649, }
w: 2444 n: 2913
2354
//None of these work to decrypt :(

//Algorithm works but looks like recursion is unnecessary? may try to rewrite later.

// None of my brute force keys work :'(
//After chasing the brute force route, i realized that i wasnt decrypting fully. oops, back to my original method.


Hold on, we have a null bit. That means some linear combination of the public key is
some even multiple of the mod value.


*/
#include <map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int search_key(int key_num, int low, int size, int w, int n, int pub[], int priv[]);
void print_key(int key[], int size, int w, int n);
string transform(int num);
int transform(int num, int key[]);
void decrypt(int enc[], int priv[], int size,  int w, int n,int pub[]);

int main(){
  /*
  { 5, 11, 18, 50, 103, 227, 636, 1436 }
  w: 1037 n: 2543
  2055
  */

  int pub[8] = {99, 1235, 865, 990, 5, 1443, 895, 1477}
    , priv[8] = { 5, 11, 18, 50, 103, 227, 636, 1436 };
  int key_num = 0, low = 0, size = 8, large = 1477;
  int c =2055, n_const = 2543;
  map<int,string> binary;
  map<int,int> p_mod;

  int enc[31] = {4537, 3427, 4537, 4089, 3302, 4292, 4667, 4292, 3302, 3578
               , 4662, 4193, 3302, 3397, 3328, 3302, 4193, 4193, 4292, 2437
               , 5428, 3397, 4662, 5428, 2437, 2343, 3677, 2437, 3672, 4662
               , 4297};

  unsigned int dec[62];

/*
  //Search from largest to 2*largest
  for(int n=large; n<=(2*large); n++){
    for(int w=0; w<n; w++){
      key_num = 0;
      low = 0;
      search_key(key_num, low, size, w, n, pub, priv);
    }
  }
*/

  decrypt(enc,priv,size,c,n_const,pub);

  return 0;
}

//Recursive method to search for possible private keys
int search_key(int key_num, int low, int size, int w, int n, int pub[], int priv[]){
  //if still within key size, keep searching
  if(key_num < size){
    //Set high value to only search values that can be super-increasing
    int hi = w*((double)(key_num+1)/(double)(size*2)) + low;
    //Search between low and high for next possible key
    for(int i = low; (i<hi && i<n); i++){
      //If key found, store in array and continue recursion
      if((w*i)%n == pub[key_num]){
        priv[key_num] = i;
        search_key(key_num+1, low+i, size, w, n, pub, priv);
      }
    }
  } else if(key_num==size){
    print_key(priv, size, w, n);
  }
  return 0;
}

void decrypt(int enc[], int priv[], int size,  int w, int n,int pub[]){
  int interm = 0, bit = 0, ctr;
  //for (int p = 0; p<256;p++){
  for(int i = 0; i<31; i++){
    interm = 0;

    interm = (w*enc[i])%n;

    //cout << interm << endl;
    bit = 0;
    ctr = 0;

    while(ctr<8){
      //cout << "bit: " << bit << endl;
      //cout << "interm: " << interm << endl;
      //cout << "ctr: " << ctr << endl;
      //cout << "priv: " << priv[size-1-ctr] << endl << endl;
      if(interm >= priv[size-1-ctr]){
        bit+=pow(2,(size-1-ctr));
        interm -= priv[size-1-ctr];
      }
      ctr++;
    }
    //cout << "bit: " << bit << endl;
    cout << (char)(bit) << "";
  }
  cout << endl;
}
//Method to print key array
void print_key(int key[], int size, int w, int n){
    cout << "{ ";
    for(int j = 0; j<size; j++){
      cout << key[j] <<", ";
    }
    cout << "}" << endl;
    cout << "w: " << w << " n: " << n << endl << endl;
}

string transform(int num){
  int ctr = 0;
  int sum = 0;
  int size = 8;
  string binary = "";

  while(ctr<size){
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
  return binary;
}

int transform(int num, int key[]){
  int ctr = 0;
  int sum = 0;
  int size = 8;
  while(ctr<size){
    if(num%2 == 1){
      num = num/2;
      sum+=key[size-1-ctr];
    }
    else{
      num = num/2;
    }
    ctr ++;
  }
  return sum;
}

/* Brute forcing, found 3 keys. Is possible, but is labor intensive and feels sloppy and too manual.
int main(){
  for(int n=1484; n<=2000; n++){
    for(int w=0; w<n; w++){
      for(int i = 0; i<100; i++){
        for(int i2 = 0; i2<200;i2++){
          for(int i3 = 0; i3<400;i3++){

            if((i<i2 && i2< i3) && (i+i2)<i3){
              if(((w*i)%n)== 99 && ((w*i2)%n)== 1235 && ((w*i3)%n)== 865){
                cout << "possible bag: {" << i << ", " << i2 << ", " << i3 << "}" << endl;
                cout << "possible w: " << w << " possible n: " << n << endl << endl;
              }
            }
          }
        }
      }
    }
  }

  for(int i = 0; i<1484;i++){
    if(((1506*i)%1975)== 1477)
      cout << i << endl;
    }
    return 0;
}*/

/*  for(int i = 0; i<256; i++){
    //dec[i] = (c*transform(enc[i],priv))%n_const;
    //cout << (char)dec[i];
    binary[i] = transform(i);
  }

  for(int i = 0; i<62; i++){
    binary[enc[i]] = "0";
  }

  for(int i = 0; i<256; i++){
    if(binary[i]!="0"){
      int sum = 0;
      for(int j=0;j<8;j++){
        sum += (pub[j]*((int)binary[i][j]-48));
      }
      p_mod[sum]++;
      //cout << sum << endl;
    }
  }
  cout << "map: " << endl;
  for(auto elem : p_mod ) {
    //cout << elem.first;
    for(int c = 6; c<10; c++){
    if(elem.first > 1477 && elem.first < 2000){
    for(int w = 1; w < elem.first; w++){
      if((w*2816*c) % elem.first < 128 && (w*5150*c) % elem.first < 128 && (w*4155*c)%elem.first < 128){
        for(int t = 0; t<62; t++){
          cout<< (char)((w*transform(enc[t],pub))%elem.first);
        }
        cout << endl;
        cout << "w: " << w << " modn is: " << elem.first << endl;
      }
    }
  }
}
}
*/
/*
int h = 0;
for(int n=large; n<=(3*large); n++){
  for(int w=0; w<n; w++){
    for(int t = 0; t<62; t++){
      h = ((w*transform(enc[t],pub))%n);
      if(h == 0){
        cout << ' ' << endl;
      }
      else{
        cout << (char)h;
      }
    }
    cout << endl;
  }
}
*/

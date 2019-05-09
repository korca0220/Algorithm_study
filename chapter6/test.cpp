#include <iostream>
#include <cstdio>
using namespace std;

union {
    unsigned int bits32;
    unsigned char bytes[4];
} Values;

int to_little(int bits32){

  unsigned char bytes[4];
  int ret;

  bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
  bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
  bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
  bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);

  ret = ( (int)bytes[0] << 0) |
        ( (int)bytes[1] << 8) |
        ( (int)bytes[2] << 16) |
        ( (int)bytes[3] << 24);

  return ret;
}

int to_big(int bits32){

  unsigned char bytes[4];
  int ret;

  bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
  bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
  bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
  bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);

  ret = ( (int)bytes[0] << 24) |
        ( (int)bytes[1] << 16) |
        ( (int)bytes[2] << 8) |
        ( (int)bytes[3] << 0);

  return ret;
}


int main(){
  
  Values.bits32 = 1;
  int t_input;
  scanf("%d", &t_input);

  unsigned int bits32_input;


  while(t_input--){
    scanf("%u", &bits32_input);
    if(Values.bytes[0] == 0) bits32_input = to_little(bits32_input);
    else bits32_input = to_big(bits32_input);
    printf("%u\n", bits32_input);
  }
  
  return 0;
}
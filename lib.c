#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "listfxns.h"

struct song_node* table[27];

void print_lib(){
  int i = 0;
  while( i < 27){
    if( table[i] ){
    printf("index[%d] : ", i);
    print_list(table[i]);
    }
    i++;
  }
}
void print_letter(char letter){
  printf("print list %c: ", letter);
  if(letter < 97){
    print_list(table[letter - 65]);
  }
  else{
    print_list(table[letter - 97]);
  }
}
void add_song(char* name, char *artist){
  char* low_art = convert_lower(artist);
  int index = low_art[0] - 97;
  free(low_art);
  table[index]= insert_in_order(table[index], name, artist);
}

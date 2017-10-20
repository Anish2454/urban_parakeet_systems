#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "listfxns.h"

/* TODO:
Search for a song given song and artist name (return a pointer).
Search for an artist (return a pointer).
Print out all the songs of a certain artist
Shuffle - print out a series of randomly chosen songs.
Delete a song
Delete all the nodes.
Comments
Test Cases
*/

struct song_node* table[27];

int get_index(char letter){
  if(letter < 97){
    return letter - 65;
  }
  else{
    return letter - 97;
  }
}

struct song_node* get_list(char letter){
  int index = get_index(letter);
  return table[index];
}

void print_letter(char letter){
  printf("print list %c: ", letter);
  print_list(get_list(letter));
}

void print_lib(){
  int i = 0;
  while(i < 27){
    if(table[i]){
      printf("index[%d] : ", i);
      print_list(table[i]);
    }
    i++;
  }
}

void add_song(char* name, char *artist){
  char* low_art = convert_lower(artist);
  int index = get_index(low_art[0]);
  free(low_art);
  table[index]= insert_in_order(table[index], name, artist);
}

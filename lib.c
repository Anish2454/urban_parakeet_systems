#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "listfxns.h"

/* TODO:
Shuffle - print out a series of randomly chosen songs.
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

struct song_node* find_artist(char* artist){
	struct song_node* list = get_list(artist[0]);
	return find_song_by_artist(list, artist);
}

void print_artist(char* artist){
	print_list(find_artist(artist));
}

struct song_node* find_song_lib(char* name, char* artist){
	struct song_node* list = get_list(artist[0]);
	return find_song(list, name, artist);
}

void remove_song(char* name, char* artist){
	struct song_node* song = find_song_lib(name, artist);
	struct song_node* front = get_list(artist[0]);
	table[get_index(artist[0])] = remove_node(front, song);
}
/*
void shuffle(){
	for(i = 0; i < 3; i++){
		srand(time(NULL));
		int i;
		int randarr = rand() % size;
		while(randarr) if(table[i]) randarr--;
		i++;
		*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "listfxns.h"
#include "lib.h"

struct song_node* music_lib[26]; //maybe 27 for non letter?
int main(){

  /*LINKED LIST===================================================*/
  printf("\n\nLINKED LIST TEST\n=====================\n\n");
  printf("testing print_list\n");
  struct song_node* a = insert_in_order(NULL, "Hey Jude", "Beatles");
  //print_list(a);
  struct song_node* b = insert_in_order(a, "All my loving", "Beatles");
  //print_list(b);
  struct song_node*c = insert_in_order(b, "hehwh", "Bodak Black");
  //print_list(c);
  struct song_node*d = insert_in_order(c, "asdss", "Bodak Black");
  //print_list(d);
  struct song_node*e = insert_in_order(d, "Aobe", "Bodak Black");
  // print_list(e);
  struct song_node*f = insert_in_order(e, "X Gon' Give It To Ya", "DMX");
  //print_list(f);
  struct song_node*g = insert_in_order(f, "Smoke On The Water", "Deep Purple");
  print_list(g);
  printf("\n=====================\n\n");
  printf("Testing find node:\n");
  printf("FIND Beatles| All my loving: %s\n" , find_song(g, "all my loving", "Beatles") -> name);
  printf("FIND Beatles| fef: %s\n", find_song(g, "fef", "Beatles"));
  printf("\n=====================\n\n");
  printf("Testing find_artist:\n");
  printf("Looking for [%s] : ", find_song_by_artist(g, "Beatles") -> artist );
  print_list( find_song_by_artist(g, "Beatles"));
  printf("Looking for [%s] : ", find_song_by_artist(g, "Deep Purple") -> artist );
  print_list( find_song_by_artist(g, "Deep Purple"));
  printf("\n=====================\n\n");
  /* MY BAD MY MAN */
  struct song_node * random = random_node(g);
  printf("Random: %s:%s \n", random -> artist, random -> name );
  g = remove_node(g, a);
  print_list(e);
  g = remove_node(g, b);
  print_list(e);
  g = remove_node(g, b);
  print_list(e);
  g = remove_node(g, g->next);
  print_list(g);
  add_song("a","A");
  add_song("b","a");
  add_song("c","A");
  add_song("a","b");
  add_song("b","b");
  add_song("c","b");
  add_song("c","d");
  print_lib();
  print_letter('A');
  print_letter('a');
  print_artist("A");
  print_list(find_song_lib("a", "b"));
  print_list(find_song_lib("b", "b"));
  remove_song("b", "b");
  print_lib();
  remove_song("a", "a");
  print_lib();

}

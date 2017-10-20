#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "listfxns.h"
#include "lib.h"

struct song_node* music_lib[26]; //maybe 27 for non letter?
int main(){


  struct song_node* a = insert_in_order(NULL, "Hey Jude", "Beatles");
  print_list(a);
  struct song_node* b = insert_in_order(a, "AA", "Beatles");
  print_list(b);
  struct song_node*c = insert_in_order(b, "hehwh", "Bodak Black");
  print_list(c);
  struct song_node*d = insert_in_order(c, "asdss", "Bodak Black");
  print_list(d);
  struct song_node*e = insert_in_order(d, "Aobe", "Bodak Black");
  print_list(e);
  printf("%d\n", get_size(e));
  printf("FIND: %s\n" , find_song(e, "aA", "Beatles") -> name);
  printf("FIND: %s\n", find_song(e, "fef", "Beatles"));
  printf("First song by Beatles: %s\n", find_song_by_artist(e, "Beatles") -> name);
  printf("First song by Bodak Black: %s\n", find_song_by_artist(e, "BOdAk BLAck") -> name);
  struct song_node * random = random_node(e);
  printf("Random: %s:%s \n", random -> artist, random -> name );
  e = remove_node(e, a);
  print_list(e);
  e = remove_node(e, b);
  print_list(e);
  e = remove_node(e, b);
  print_list(e);
  e = remove_node(e, e->next);
  print_list(e);
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

}

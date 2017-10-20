#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listfxns.h"

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
  printf("FIND: %p\n" , find_song(e, "AA", "Beatles"));

  printf( "FIND: %p\n",find_song(e, "ddfs", "Beatles"));
  printf("By the Beatles:  |");
  print_list(find_song_by_artist(e, "Beatles"));
  printf("By Bodak Black:  |");
  print_list(find_song_by_artist(e, "Bodak Black"));
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

}

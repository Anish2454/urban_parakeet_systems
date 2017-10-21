#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "listfxns.h"
#include <unistd.h>
#include "lib.h"

int main(){
  /*LINKED LIST===================================================*/
  printf("\n\nLINKED LIST TEST\n=====================\n\n");

  printf("Testing insert_in_order & print_list:\n");
  printf("Inserting [Beatles: Hey Jude]\n");
  struct song_node* a = insert_in_order(NULL, "Hey Jude", "Beatles");
  print_list(a);
  printf("Inserting [Beatles: All my loving]\n");
  struct song_node* b = insert_in_order(a, "All my loving", "Beatles");
  print_list(b);
  printf("Inserting [Bodak Black: hehwh]\n");
  struct song_node*c = insert_in_order(b, "hehwh", "Bodak Black");
  print_list(c);
  printf("Inserting [Bodak Black: asdss]\n");
  struct song_node*d = insert_in_order(c, "asdss", "Bodak Black");
  print_list(d);
  printf("Inserting [Bodak Black: Adobe]\n");
  struct song_node*e = insert_in_order(d, "Aobe", "Bodak Black");
  print_list(e);
  printf("Inserting [DMX: X Gon' Give It To Ya]\n");
  struct song_node*f = insert_in_order(e, "X Gon' Give It To Ya", "DMX");
  print_list(f);
  printf("Inserting [Deep Purple: Smoke on the Water]\n");
  struct song_node*g = insert_in_order(f, "Smoke On The Water", "Deep Purple");
  print_list(g);

  printf("\n=====================\n\n");
  printf("Testing find node:\n");
  printf("FIND Beatles|All my loving: %s\n" , find_song(g, "all my loving", "Beatles") -> name);
  printf("FIND Beatles|fef: ");
  if(!find_song(g, "fef", "Beatles")) printf("Song Not Found!");
  printf("\n=====================\n\n");

  printf("Testing find_artist:\n");
  printf("Looking for [%s] : ", "Beatles");
  print_list( find_song_by_artist(g, "Beatles"));
  printf("Looking for [%s] : ", "Deep Purple");
  print_list( find_song_by_artist(g, "Deep Purple"));
  printf("\n=====================\n\n");

  printf("Testing Random Node:\n");
  srand(time(NULL));
  struct song_node * random1 = random_node(g);
  printf("Random: %s:%s \n", random1 -> artist, random1 -> name );
  struct song_node * random2 = random_node(g);
  printf("Random: %s:%s \n", random2 -> artist, random2 -> name );
  struct song_node * random3 = random_node(g);
  printf("Random: %s:%s \n", random3 -> artist, random3 -> name );
  printf("\n=====================\n\n");

  printf("Testing Songcmp (helper):\n");
  printf("Compare [%s:%s] and [%s:%s]: %d\n", a->artist, a -> name, b-> artist, b-> name, songcmp(a,b));
  printf("Compare [%s:%s] and [%s:%s]: %d\n", a->artist, a -> name, a-> next -> artist, a -> next -> name, songcmp(a,a -> next));
  printf("Compare [%s:%s] and [%s:%s]: %d\n", d->artist, d -> name, d-> artist, d-> name, songcmp(d,d));
  printf("\n=====================\n\n");

  printf("Testing get_size (helper):\n");
  printf("Size of: ");
  print_list(g);
  printf("%d\n", get_size(g));
  printf("\n=====================\n\n");

  printf("Testing insert_front (helper): \n");
  printf("Insert [Beatles: Let it be] in front of NULL:\n");
  struct song_node* first = insert_front(NULL, "Let it be", "Beatles");
  print_list(first);
  printf("Insert [Queen: Bohemian Rhapsody] in front of [Beatles: Let it be]:\n");
  print_list(insert_front(first, "Bohemian Rhapsody", "Queen"));
  printf("\n=====================\n\n");

  printf("Testing convert_lower (helper): \n");
  printf("Convert %s to lower: %s\n", "Anish", convert_lower("Anish"));
  printf("Convert %s to lower: %s\n", "ComPUTER ScieNCE", convert_lower("ComPUTER ScieNCE"));
  printf("\n=====================\n\n");

  printf("Testing Remove Node:\n");
  printf("Removing [%s:%s]:\n", a -> artist, a -> name);
  g = remove_node(g, a);
  print_list(e);
  printf("Removing [%s:%s]:\n", b -> artist, b -> name);
  g = remove_node(g, b);
  print_list(g);
  printf("Removing [%s:%s]:\n", b -> artist, b -> name);
  g = remove_node(g, b);
  print_list(g);
  printf("Removing [%s:%s]:\n", g -> next -> artist, g -> next -> name);
  g = remove_node(g, g->next);
  print_list(g);
  printf("\n=====================\n\n");

  printf("Testing Free_List: ");
  print_list(g);
  g = free_list(g);
  printf("List after free: ");
  print_list(g);
  printf("\n=====================\n\n");

  printf("\n\nMUSIC LIBRARY TEST\n=====================\n\n");

  printf("Testing print_library & add song:\n");
  add_song("Let It Be","Beatles");
  add_song("Another One Bites the Dust","Queen");
  add_song("Stubborn Love","Lumineers");
  add_song("Ive Just Seen a Face","Beatles");
  add_song("Fake Love","Drake");
  add_song("Take on Me","aha");
  add_song("Never Gonna Give You Up","Rick Astley");
  add_song("Broccoli","Anish Shenoy");
  add_song("Carrots","Jasper Cheung");
  add_song("I Will Wait","Mumford and Sons");
  add_song("All My Loving","Beatles");
  add_song("Lovely Rita","Beatles");
  add_song("Wouldn't It Be Nice","Beach Boys");
  add_song("Midnight Rider","Allman Brothers");
  add_song("Back to Black","Amy Winehouse");
  add_song("Heat Of The Moment","Asia");
  add_song("Jolene","Dolly Parton");
  print_lib();
  printf("\n=====================\n\n");

  printf("Testing print_letter:\n");
  printf("A: \n");
  print_letter('A');
  printf("D: \n");
  print_letter('D');
  printf("\n=====================\n\n");

  printf("testing find_song:\n");
  printf("looking for [Dolly Parton: Jolene]\n");
  print_list(find_song_lib("Jolene", "Dolly Parton"));
  printf("looking for [Beatles: Lovely Rita]\n");
  print_list(find_song_lib("Lovely Rita", "Beatles"));
  printf("looking for [Stuyvesant: Cool]\n");
  if(!find_song_lib("Cool", "Stuyvesant")) printf("Song Not Found!");
  printf("\n=====================\n\n");

  printf("Testing Find Artist:\n");
  printf("looking for [Beatles]\n");
  print_artist("Beatles");
  printf("looking for [Anish Shenoy]\n");
  print_artist("Anish Shenoy");
  printf("looking for [Kobe Bryant]\n");
  print_artist("Kobe Bryant");
  printf("\n=====================\n\n");

  printf("Testing remove_song:\n");
  printf("remove beatles: lovely rita:\n");
  remove_song("Lovely Rita", "Beatles");
  print_lib();
  printf("Remove Dolly Parton: Jolene:\n");
  remove_song("Jolene", "Dolly Parton");
  print_lib();
  printf("\n=====================\n\n");

  printf("Testing Shuffle:\n");
  shuffle();
  printf("\n");
  shuffle();
  printf("\n=====================\n\n");

  printf("Testing get_list (helper):\n");
  printf("Getting List 'a':\n");
  print_list(get_list('a'));
  printf("Getting List 'b':\n");
  print_list(get_list('b'));
  printf("\n=====================\n\n");

  printf("Testing get_index (helper):\n");
  printf("Geting index of 'a':\n");
  printf("%d Should be 0\n", get_index('a'));
  printf("Geting index of 'z':\n");
  printf("%d Should be 25\n", get_index('z'));
  printf("\n=====================\n\n");

  printf("Testing Delete Nodes\n");
  delete_nodes();
  printf("Library After Delete: \n");
  print_lib();
  printf("\n=====================\n\n");



}

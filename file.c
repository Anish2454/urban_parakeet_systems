#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
  char name[256];
  char artist[256];
  struct song_node* next;
};

struct song_node* music_lib[26]; //maybe 27 for non letter?

//size of node
size_t size = sizeof(struct song_node);

//Prints ALL SONGS
void print_list(struct song_node* node){
  if(!node){
    printf("\n");
    return;
  }
  //Use "->" to access data from a struct pointer
  printf("%s: %s | ", node->artist, node->name);
  return print_list(node->next);
}


int songcmp(struct song_node* song1, struct song_node* song2){
  int artist_cmp = strcmp(song1 -> artist, song2 -> artist);
  if(artist_cmp) return artist_cmp;
  return strcmp(song1 -> name, song2 -> name);
}

//Takes a pointer to an existing list and the data to be created
//Creates a new node with that data and puts it at the beginning
//of the list. Returns a pointer to the beginning of the list.
struct song_node * insert_front(struct song_node* node, char*name, char* artist){
  //Declare the pointer to our new node
  struct song_node* p;

  //Since the memory associated with this function will
  //dissappear once it's done, we need to malloc space
  //for our node.
  p = (struct song_node*) malloc(size);

  //Create the new node
  struct song_node new;
  strcpy(new.name, name);
  strcpy(new.artist, artist);
  new.next = node; //places at beginning
  *p = new;
  return p;
}

struct song_node* insert_in_order(struct song_node* nodeFront, char* name, char* artist){
  if(nodeFront == NULL) return insert_front(NULL, name, artist);
  struct song_node* p = (struct song_node*) malloc(size);
  struct song_node new;
  struct song_node* node = nodeFront;
  strcpy(new.name, name);
  strcpy(new.artist, artist);
  new.next = NULL;
  *p = new;
  while(node -> next ){
    int cmp = songcmp(p, node -> next);
    if(cmp <= 0){
      (p -> next)  = (node -> next);
      (node -> next) = p;
      //printf("%s\n", name);
      return nodeFront;
    }
    node = node -> next;
  }
  if(songcmp(p, node) < 0) return insert_front(node, p-> name, p-> artist);
  else node -> next = p;
  return nodeFront;
}

//Takes a pointer to a list
//Frees each node in the list
struct song_node * free_list(struct song_node* node){
  //If the node is null, we're done
  if(!node) return node;

  //Create a pointer to the next node
  struct song_node* next = node -> next;

  //Free the current node
  free(node);

  //move onto the next node
  return free_list(next);
}

int main(){
  struct song_node* a = insert_front(NULL, "Hey Jude", "Beatles");
  print_list(a);
struct song_node* b = insert_in_order(a, "AA", "Beatles");
  print_list(b);
  struct song_node*c = insert_in_order(b, "hehwh", "Bodak Black");
  print_list(c);
  struct song_node*d = insert_in_order(c, "asdss", "Bodak Black");
  print_list(d);
  struct song_node*e = insert_in_order(d, "kobe", "Bodak Black");
  print_list(e);
}

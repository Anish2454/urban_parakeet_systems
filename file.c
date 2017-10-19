#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int get_size(struct song_node* list){
  int i;
  for(i = 0; list; i++) list = list -> next;
  return i;
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

struct song_node* find_song(struct song_node* list, char* name, char* artist){
  while(list){
    if(!strcmp(list -> name, name) && !strcmp(list -> artist, artist)) return list;
    list = list -> next;
  }
  return NULL;
}

struct song_node* find_song_by_artist(struct song_node* list, char* artist){
  while(list){
    if(!strcmp(list -> artist, artist)) return list;
    list = list -> next;
  }
  return NULL;
}

struct song_node* remove_node(struct song_node* listFront, struct song_node* node){
  if(listFront == node){
    struct song_node* newFront = listFront -> next;
    listFront -> next = NULL;
    free(listFront);
    return newFront;
  }
  struct song_node* list = listFront;
  while(list -> next){
    if(list->next == node){
      list->next = list->next->next;
      node -> next = NULL;
      free(node);
      return listFront;
    }
    list = list -> next;
  }
  return listFront;
}

struct song_node* random_node(struct song_node* list){
  int size = get_size(list);
  srand(time(NULL));
  int random = rand() % size;
  int i;
  for(i = 0; i<random; i++){
    list = list->next;
  }
  return list;
}
int main(){
  struct song_node* a = insert_in_order(NULL, "Hey Jude", "Beatles");
  print_list(a);
  struct song_node* b = insert_in_order(a, "AA", "Beatles");
  print_list(b);
  struct song_node*c = insert_in_order(b, "hehwh", "Bodak Black");
  print_list(c);
  struct song_node*d = insert_in_order(c, "asdss", "Bodak Black");
  print_list(d);
  struct song_node*e = insert_in_order(d, "kobe", "Bodak Black");
  print_list(e);
  printf("%d\n", get_size(e));
  printf("%s\n", find_song(e, "AA", "Beatles")-> name);
  printf("%s\n", find_song(e, "ddfs", "Beatles")-> name);
  printf("%s\n", find_song_by_artist(e, "Beatles")-> name);
  printf("%s\n", find_song_by_artist(e, "Bodak Black")-> name);
  printf("Random: %s\n", random_node(e)->name);
  e = remove_node(e, a);
  print_list(e);
  e = remove_node(e, b);
  print_list(e);
  e = remove_node(e, b);
  print_list(e);
  e = remove_node(e, e->next);
  print_list(e);

}

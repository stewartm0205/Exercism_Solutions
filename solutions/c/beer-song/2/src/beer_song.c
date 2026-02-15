#include "beer_song.h"
#include "string.h"
#include "ctype.h"
#include "stdio.h"

#define BUFFER_SIZE   (1024)

void verse(char *response, int bottles)
{
  if (bottles > 2) {
    sprintf(response, "%d bottles of beer on the wall, %d bottles of beer.\n\
Take one down and pass it around, %d bottles of beer on the wall.\n", 
            bottles, bottles, bottles - 1);
  } else if (bottles == 2) {
    sprintf(response, "%d bottles of beer on the wall, %d bottles of beer.\n\
Take one down and pass it around, 1 bottle of beer on the wall.\n", 
            bottles, bottles);
  } else if (bottles == 1) {
    sprintf(response, "1 bottle of beer on the wall, 1 bottle of beer.\n\
Take it down and pass it around, no more bottles of beer on the wall.\n"); 
  } else {
    sprintf(response, "No more bottles of beer on the wall, no more bottles of beer.\n\
Go to the store and buy some more, 99 bottles of beer on the wall.\n"); 
  }
}

void sing(char *song, int start_bottles,
          int end_bottles)
{
  char response[BUFFER_SIZE];
	strcpy(song,"");
  for (int bottles=start_bottles; bottles>=end_bottles; bottles--){
    verse(response, bottles);
    strcat(song, response); 
    if (bottles > end_bottles) strcat(song, "\n"); 
  }
}

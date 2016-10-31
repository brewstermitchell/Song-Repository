/* A header file for the SongList class object.

Brewster Mitchell
10/20/2016

Sources: None
*/

#ifndef SONG_LIST_H
#define SONG_LIST_H

# include "Song.h"

const int NUM_OF_ELEMS = 1001;

class SongList {
  public:
    void printList();
    void printLength() const;
	void addToList(Song);
	void removeFromList(int);
	int returnLength();
	void searchByAlbum(char[]);
	void searchByArtist(char[]);
	Song returnSong(int);
    SongList();
  private:
    Song listOfSongs[NUM_OF_ELEMS];
    int length;

};

#endif
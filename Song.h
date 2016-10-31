/* A header file for the Song class object.

Brewster Mitchell
10/20/2016

Sources: None
*/

#ifndef SONG_H
#define SONG_H

const int MAX_CHAR = 64;

class Song {
  public:
    void setLength(char min[], char sec[]);
    void setArtist(char[]);
    void setTitle(char[]);
    void setAlbum(char[]);
	void printSong();
	void returnAlbum(char[]);
	void returnArtist(char[]);
	void returnSong(char[], char[], char[], char[], char[]);
    Song();

  private:
	char lengMin[MAX_CHAR];
    char lengSec[MAX_CHAR];
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char album[MAX_CHAR];
};

#endif
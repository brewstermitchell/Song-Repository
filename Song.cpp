/* Song.cpp

Defines the Song object and member attributes and functions.

Brewster Mitchell
10/20/2016

Sources: None
*/

# include "Song.h"
# include <iostream>
# include <iomanip>
# include <cstring>

using namespace std;

// CONSTRUCTORS

Song::Song()
{

}

// ACCESSORS

/*	This function prints the Song to the console in a specific format.
	In: None
	Out: console output
*/
void Song::printSong()
{
	cout << "'" << title << "' (";
	cout << setw(2) << setfill('0') << lengMin;
	cout << ":";
	cout << setw(2) << setfill('0') << lengSec;
	cout << ") from album " << "'" << album << "' by " << artist << "" << endl;
}

/* This function copies the value of 'album' to input char array.
	In: character array
	Out: None
*/
void Song::returnAlbum(char outStr[])
{
	strcpy(outStr, album);
}

/* This function copies the value of 'artist' to input char array.
In: character array
Out: None
*/
void Song::returnArtist(char outStr[])
{
	strcpy(outStr, artist);
}

/* This function copies the relevant Song attributes to char arrays.
In: five character arrays
Out: None
*/
void Song::returnSong(char outTitle[], char outLenMin[], char outLenSec[], char outAlbum[], char outArtist[])
{
	strcpy(outTitle, title);
	strcpy(outLenMin, lengMin);
	strcpy(outLenSec, lengSec);
	strcpy(outAlbum, album);
	strcpy(outArtist, artist);
}

// MUTATORS

/* This function adds the specified char array as the Song album
	In: char array
	Out: None
*/
void Song::setAlbum(char inputAlbum[])
{
	strcpy(album, inputAlbum);
}

/* This function adds the specified char array as the Song artist
In: char array
Out: None
*/
void Song::setArtist(char inputArtist[])
{
	strcpy(artist, inputArtist);
}

/* This function adds the specified char array as the Song title
In: char array
Out: None
*/
void Song::setTitle(char inputTitle[])
{
	strcpy(title, inputTitle);
}

/* This function adds the specified char array as the Song length
In: two char arrays
Out: None
*/
void Song::setLength(char min[], char sec[])
{
	strcpy(lengMin, min);
	strcpy(lengSec, sec);
}

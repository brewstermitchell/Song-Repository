/* SongList.cpp

Defines the SongList object and member attributes and functions.

Brewster Mitchell
10/20/2016

Sources: None
*/

# include "SongList.h"
# include <iostream>
# include <cstring>

using namespace std;

// CONSTRUCTORS

SongList::SongList() {
  length = 0;
}

// ACCESSORS

//	This function prints a message displaying the length of the current SongList before and after modifications to the SongList
void SongList::printLength() const
{
    cout << endl << "The list currently contains " << length << " songs." << endl;
}

//	This function prints the current SongList. Displays songs by index in the SongList.
void SongList::printList()
{
	for (int i = 0; i < length; i++)
	{
		cout << "Index " << i << ": ";
		listOfSongs[i].printSong();
	}
}

/* This function returns the current length of the SongList.
	In: None
	Out: int
*/
int SongList::returnLength()
{
	return length;
}

/* This function returns the Song object at the specified index.
	In: index
	Out: Song
*/
Song SongList::returnSong(int index)
{
	return listOfSongs[index];
}

/* This function searches the SongList for Songs with matching album member and prints matching Songs by index.
	In: char array
	Out: console output
*/
void SongList::searchByAlbum(char albumName[])
{
	bool found = false;
	for (int i = 0; i < length; i++)
	{
		char searchStr[MAX_CHAR];
		listOfSongs[i].returnAlbum(searchStr);
		if (strcmp(searchStr, albumName) == 0)
		{
			found = true;
			cout << "Index " << i << ": ";
			listOfSongs[i].printSong();
		}
	}
	if (!found)
	{
		cout << endl << "No songs from " << albumName << " found." << endl;
	}
}

/* This function searches the SongList for Songs with matching artist and prints matching Songs by index.
	In: char array
	Out: console output
*/
void SongList::searchByArtist(char artistName[])
{
	bool found = false;
	for (int i = 0; i < length; i++)
	{
		char searchStr[MAX_CHAR];
		listOfSongs[i].returnArtist(searchStr);
		if (strcmp(searchStr, artistName) == 0)
		{
			found = true;
			cout << "Index " << i << ": ";
			listOfSongs[i].printSong();
		}
	}
	if (!found)
	{
		cout << endl << "No songs by " << artistName << " found." << endl;
	}
}

// MUTATORS

/* This function appends a Song object to the end of the SongList and updates the Songlist
		length.
	In: Song
	Out: None
*/
void SongList::addToList(Song newSong) 
{
	listOfSongs[length] = newSong;
	length++;
}

/* This function removes the Song object at the specified index.
		Additionally, moves all subsequent Songs into the preceding index to keep
		the list tidy, and updates the Songlist length.
	In: int
	Out: None
*/
void SongList::removeFromList(int songIndex)
{
	for (int i = songIndex; i < (length - 1); i++)
	{
		int move = i + 1;
		listOfSongs[i] = listOfSongs[move];
	}
	length--;
}
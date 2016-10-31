/* CS 162 Project 3 - Song Storage
 * Brewster Mitchell
 * 10/30/2016
 * 
 * Program maintains a list of songs
 *      Features:
 *              - Enter new song
 *              - Display all stored songs
 *              - Remove a song
 *              - Search for songs by artist
 *              - Search for songs by album
 *              - Persistent storage via datafile
 * 
 *      Notes:
 *              Datafile songs.txt format: 
 *                      title;artist;durationmin;durationsec;album(delimiter)
 *                      delimiter = '\n'
 *		Sources:
 *			InputTools by Li Liang (2009)
 */

// INCLUDES

# include <cstdlib>
# include <iostream>
# include <fstream>
# include "InputTools.h"
# include "Song.h"
# include "SongList.h"


using namespace std;

// FUNCTION PROTOTYPES

int userMenu();
void readDataFile(SongList&, const char[]);
void saveDataFile(SongList&, const char[]);
void addPrompt(SongList&);
void albumSearch(SongList&);
void artistSearch(SongList&);
void removeSongByIndex(SongList&);

// MAIN PROGRAM

int main() 
{
	int			menuChoice;
    const char	datafile[] = "songs.txt";
    SongList	newList;

	cout << "Welcome to Song Repository 1.0." << endl;
	cout << "Loading songs from datafile..." << endl;
	// construct Songlist
	readDataFile(newList, datafile);
	
	// menu cycle
	do {
		newList.printLength();
		menuChoice = userMenu();
		// determine user action
		switch (menuChoice) {
		case 1: newList.printList(); continue; // print list
		case 2: addPrompt(newList); continue; // add Song to list
		case 3: removeSongByIndex(newList);  continue; // remove Song from list
		case 4: artistSearch(newList);  continue; // search list by artist
		case 5: albumSearch(newList); continue; // search list by album
		case 9: break; // end loop
		default: continue; // invalid selection will return to beginning of loop
		}
	} while (menuChoice != 9);

	// write list to file and exit
	cout << "Writing list to datafile and terminating..." << endl;
	saveDataFile(newList, datafile);
    cout << "Goodbye." << endl; 
	return 0;
} // end main

// FUNCTION DEFINITIONS

/* This function is the main menu interface.
	In: prompt
	Out: selection (int)
*/
int userMenu()
{
	int		choice;
	char	prompt[] = "Your choice: ";
	char	message[] = "Please make a selection from the list: \n \
		1: See all songs currently in the list.\n \
		2: Add a new song to the list.\n \
		3: Remove a song from the list (by index).\n \
		4: Search for songs by artist.\n \
		5: Search for songs by album.\n \
		9: Quit.\n \
		\n \
		(invalid menu choice will repeat menu)";
	cout << endl << message << endl;
	choice = readInt(prompt);

	return choice;
}

/* This is the interface to collect Song from user to add to Songlist
	In: prompt
	Out: None
*/
void addPrompt(SongList& inputList)
{
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char album[MAX_CHAR];
	char lenMin[MAX_CHAR];
	char lenSec[MAX_CHAR];
	char prompt1[] = "Please enter song title: ";
	char prompt2[] = "Please enter artist name: ";
	char prompt3[] = "Please enter song length (minutes): ";
	char prompt4[] = "Please enter song length (seconds): ";
	char prompt5[] = "Please enter album name: ";
	Song newSong; // init new Song object
	// get Song attributes from user
	cout << "New song. Required: Title, Artist, Duration (minutes, seconds), Album." << endl;
	readString(prompt1, title, MAX_CHAR);
	readString(prompt2, artist, MAX_CHAR);
	readString(prompt3, lenMin, MAX_CHAR);
	readString(prompt4, lenSec, MAX_CHAR);
	readString(prompt5, album, MAX_CHAR);
	// write attributes to Song object
	newSong.setAlbum(album);
	newSong.setArtist(artist);
	newSong.setLength(lenMin, lenSec);
	newSong.setTitle(title);
	// append Song to SongList
	inputList.addToList(newSong);
}

/* This is the interface to collect album title from user to search list
	In: Prompt
	Out: None
*/
void albumSearch(SongList& inputList)
{
	char album[MAX_CHAR];
	char prompt[] = "Please enter album name to search: ";
	readString(prompt, album, MAX_CHAR);
	inputList.searchByAlbum(album);
}

/* This is the interface to collect artist name from user to search list
	In: Prompt
	Out: None
*/
void artistSearch(SongList& inputList)
{
	char artist[MAX_CHAR];
	char prompt[] = "Please enter artist name to search: ";
	readString(prompt, artist, MAX_CHAR);
	inputList.searchByArtist(artist);
}

/* This function reads a datafile and populates a SongList with the Song contents of that file.
	In: SongList, datafile
	Out: None
*/
void readDataFile(SongList& inputList, const char inputFile[])
{	
	char		inName[MAX_CHAR];
	char		inArtist[MAX_CHAR];
	char		inLenMin[MAX_CHAR];
	char		inLenSec[MAX_CHAR];
	char		inAlbum[MAX_CHAR];
	ifstream in;
	Song newSong; // init new Song object

	in.open(inputFile);
	if (!in) // ensure file successfully opened. If not, crash.
	{
		in.clear();
		cerr << endl << "Failed to open " << inputFile << ". Exiting." << endl << endl;
		exit(1);
	}
	// get first item
	in.get(inName, MAX_CHAR, ';');
	while (!in.eof()) // loop through file
	{
		// get items on line
		in.get();
		in.get(inArtist, MAX_CHAR, ';');
		in.get();
		in.get(inLenMin, MAX_CHAR, ';');
		in.get();
		in.get(inLenSec, MAX_CHAR, ';');
		in.get();
		in.get(inAlbum, MAX_CHAR, '\n');
		in.ignore(100, '\n');
		// write file content to Song object
		newSong.setArtist(inArtist);
		newSong.setLength(inLenMin, inLenSec);
		newSong.setAlbum(inAlbum);
		newSong.setTitle(inName);
		// append Song to SongList
		inputList.addToList(newSong);
		// next line
		in.get(inName, MAX_CHAR, ';');

	}

	in.close();

}

/* This function is the interface to remove a Song from the Songlist by index.
	In: SongList, prompt
	Out: None
*/
void removeSongByIndex(SongList& inputList)
{
	int choice;
	char prompt[] = "Please enter the index of the song you wish to remove: ";
	choice = readInt(prompt);

	inputList.removeFromList(choice);
}

/* This function writes the current SongList to the datafile.
		!Currently overwrites entire datafile!
	In: SongList, datafile
	Out: None
*/
void saveDataFile(SongList& inputList, const char dataFile[])
{
	char delimiter = '\n';
	char separator = ';';
	ofstream out;

	out.open(dataFile);
	if (!out) // ensure file successfully opened. If not, crash.
	{
		out.clear();
		cerr << endl << "Failed to open " << dataFile << " for output. Exiting." << endl << endl;
		exit(1);
	}

	for (int i = 0; i < inputList.returnLength(); i++)
	{
		Song currSong = inputList.returnSong(i);
		char title[MAX_CHAR];
		char artist[MAX_CHAR];
		char lenMin[MAX_CHAR];
		char lenSec[MAX_CHAR];
		char album[MAX_CHAR];
		currSong.returnSong(title, lenMin, lenSec, album, artist);
		out << title << separator << artist << separator << lenMin << separator << lenSec << separator;
		out << album << delimiter;
	}

	out.close();
}
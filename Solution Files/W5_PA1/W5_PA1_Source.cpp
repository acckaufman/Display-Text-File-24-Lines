//This program displays the contents of a text file for the user, 24 lines at a time.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string fileName;		//Name of the file the user wants to display
	char ch;				//Temporary holder for each character in the file
	fstream file;			//File stream object
	int accumulator = 0;	//Counter used to control the number of lines displayed

	cout << "File Display Program" << endl;				//Program description
	cout << "--------------------" << endl << endl;

	cout << "Enter file name to display, including extension: ";
	getline(cin, fileName);

	cout << endl << "Opening file now..." << endl << endl;

	//Open the file for input, in order to read its data
	file.open(fileName, ios::in);

	//Check if there were any errors in opening the file.
	if (!file)
	{
		cout << "Error! The file could not be opened or does not exist." << endl;
		system("pause");
		return 0;
	}

	//If there were no errors, continue processing the file.
	else if (file)
	{
		//Display the file name as a heading for the display
		cout << fileName <<  endl << "------------------------------------------------------------------" << endl;

		do {
			//Reset the accumulator to 0 each time through
			accumulator = 0;

			//Create a visual break between pages
			cout << endl;

			//Get a character from the file.
			file.get(ch);

			//If the character read was a newline character, add 1 to the number of lines read
			if (ch == '\n')
				accumulator++;

			//Continue as long as a character was read
			while (file && accumulator < 24)
			{
				//Display the character to the screen
				cout << ch;

				//Read the next character
				file.get(ch);

				//If the character read was a newline character, add 1 to the number of lines read
				if (ch == '\n')
					accumulator++;
			}

			cout << endl;

			//After this iteration completes, if the end-of-file flag is set, tell the user there are no more lines to be read.
			if (file.eof())
			{
				cout << endl << "There are no more lines to be read." << endl;
			}

			//Otherwise, pause the system after displaying 24 lines and wait for user input to continue.
			else
			{
				cout << endl << "Press ENTER to view next 24 lines.";
				char pause;
				cin.get(pause);
			}

		} while (file);		//Keep repeating this process as long as there are contents to be read in the file
	}

	cout << endl << "Closing file now..." << endl;
	//Close the file.
	file.close();

	cout << "File has successfully been closed." << endl << endl;

	system("pause");

	return 0;
}
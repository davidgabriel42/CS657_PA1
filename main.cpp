#include <iostream>
#include <sys/stat.h>
#include <regex>
#include <string>
#include <dirent.h>
#include <errno.h>


using namespace std;
char scan_buffer;
int line_length[144];

/*
mkdir- function to create a directory, which is equivalent in our relational database to
a new database. 
Takes a string which is the directory name. Will create directory in "./" or return error 
*/

int mkdir(std::string dir_name)
{       

        std::string dir_path_complete_temp = "./" + dir_name;
       	char* dir_path_complete = &dir_path_complete_temp[0u];
        int dir_err;


        DIR* dir = opendir(dir_path_complete);
        if (dir)
        {
            /* Directory exists. */
                closedir(dir);
//                printf("1");
        	printf("-- !Failed to create database ");
                std::cout << dir_name;
                printf(" because it already exists.\r\n");
        }
        else if (ENOENT == errno)
        {
                dir_err = mkdir(dir_path_complete, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        	printf("-- Database ");
                std::cout << dir_name;
                printf(" created.\r\n");
                /* Directory does not exist. */
        }
        else
        {
            /* opendir() failed for some other reason. */
        }

}

/*
rename- depreciates unused databases
*/

int rmdir(std::string dir_name)
{
        //format strings
        std::string dir_path_complete_temp = "./" + dir_name;
       	char* dir_path_complete = &dir_path_complete_temp[0u];
        int dir_err;


        DIR* dir = opendir(dir_path_complete);
        if (dir)
        {
            /* Directory exists. */
                closedir(dir);
                //remove direcory
               	std::string rm_cmd = "rm -r -f ./" + dir_name;
                //cout<< rm_cmd;
        	system(&rm_cmd[0U]);
                //console output
                printf("-- Database ");
                std::cout << dir_name;
                printf(" deleted.\r\n");

        }
        else if (ENOENT == errno)
        {
        	printf("--!Failed to delete ");
                std::cout << dir_name;
                printf(" because it does not exist.\r\n");
                /* Directory does not exist. */
        }
        else
        {
            /* opendir() failed for some other reason. */
        }
}

/*
mktable- fuction to create a table within a database. The table is stored as a text file.
*/

int mktable()
{
	
	
}


int main()
{
	bool exit_switch = 1;

	while(exit_switch)
	{
		//interactive shell sdtio
		std::string line;
		std::cout << "dave-sql> ";
		getline (std::cin, line);

		std::string result;
                //regex detect command
		if(std::regex_match (line, std::regex("(CREATE DATABASE)(.*)" )))
		{
			std::string database_name = line.erase(0, 16);
			std::string::size_type semicolon = line.find(";");
                        database_name = database_name.erase(semicolon, 1);
			mkdir(database_name);
		}

		if(std::regex_match (line, std::regex("(DROP DATABASE)(.*)" )))
		{
			std::string database_name = line.erase(0, 14);
			std::string::size_type semicolon = line.find(";");
                        database_name = database_name.erase(semicolon, 1);
			rmdir(database_name);
		}

/*
		std::string::size_type i = t.find(s);

		if (i != std::string::npos)
		   t.erase(i, s.length());
*/

		if(line == "exit"){return 0;}
		if(line == "rmdir"){rmdir("dir1");}

		
		/*
		int input_size = line.size();

		for(int i = 0; i < input_size; i++)
		{
			scan_buffer = line[i];
			switch(scan_buffer)
				{
				case ';':
					line_count++;
					word_count[line_count] = 0;
				break;

				case ' ':
					//line_length[line_count]++;
					word_count[line_count]++;
				break;

				default:
				break;
				}
				*/
		line.clear();
	}
}

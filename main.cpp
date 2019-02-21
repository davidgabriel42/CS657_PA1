#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <regex>
#include <string>
#include <dirent.h>
#include <errno.h>

using namespace std;
char scan_buffer;
std::string use_path;
char* use_path_complete;
std::string use_path_complete_str;

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

return 1;
}

/*
rmdir- remove directory. Takes in a directory name and searches within "./" 
to find directory. If directory exists, will delete. Else returns error to console.
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
return 1;
}

/*
mktable- fuction to create a table within a database. The table is stored as a text file.
*/

int use(std::string use_name)
{
use_path_complete_str = "./" + use_name;
use_path_complete = &use_path_complete_str[0u];

cout<< use_path_complete_str;

return 1;
}

/*
mktable- fuction to create a table within a database. The table is stored as a text file.
*/

int mktable(std::string table_name)
{

std::string table_path = use_path_complete_str + "/" + table_name; 

if (std::ifstream(table_path))
{
	std::cout << "-- !Failed to create table "<< table_name << " because it already exists."  << std::endl;
	return false;
}
std::ofstream file(table_path);
if (!file)
{
     std::cout << "File could not be created" << std::endl;
     return false;
}

std::ofstream myfile;

myfile.open (table_path);
myfile << "This is the first cell in the first column.\n";
myfile << "a,b,c,\n";
myfile << "c,s,v,\n";
myfile << "1,2,3.456\n";
myfile << "semi;colon";
myfile.close();


return 1;
}


int rmtable(std::string table_name)
{
/*
std::string table_path = use_path_complete_str + "/" + table_name;

if( remove( table_path ) != 0 )
perror( "Error deleting file" );
else
puts( "File successfully deleted" );
*/

return 1;
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

                if(std::regex_match (line, std::regex("(USE)(.*)" )))
		{
			std::string use_name = line.erase(0, 4);
			std::string::size_type semicolon = line.find(";");
                        use_name = use_name.erase(semicolon, 1);
			use(use_name);
		}
		if(std::regex_match (line, std::regex("(CREATE TABLE)(.*)" )))
		{
			std::string table_name = line.erase(0, 13);
			std::string::size_type semicolon = line.find(";");
                        table_name = table_name.erase(semicolon, 1);
			mktable(table_name);
		}

		if(std::regex_match (line, std::regex("(DROP TABLE)(.*)" )))
		{
			std::string table_name = line.erase(0, 11);
			std::string::size_type semicolon = line.find(";");
                        table_name = table_name.erase(semicolon, 1);
			rmtable(table_name);
		}

		if(line == "exit"){return 0;}
		if(line == "rmdir"){rmdir("dir1");}

		line.clear();
	}
}

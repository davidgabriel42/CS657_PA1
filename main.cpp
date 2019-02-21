#include <iostream>
#include <sys/stat.h>
#include <regex>
#include <string>

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

        struct stat info;

        if( stat( pathname, &info ) != 0 )
                printf( "cannot access %s\n", pathname );
        else if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows 
                //printf( "%s is a directory\n", pathname );
		printf("!Failed to create database");
                printf(dir_name);
                printf("because it already exists.\r\n")
        else
                printf( "%s is no directory\n", pathname );
        	std::string dir_path_complete_temp = "./" + dir_name;
        	char* dir_path_complete = &dir_path_complete_temp[0u];
                int dir_err;
                dir_err = mkdir(dir_path_complete, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

}

/*
rename- depreciates unused databases
*/

int rmdir(std::string dir_name)
{
	std::string rm_cmd = "rm -r -f ./" + dir_name;
	system(&rm_cmd[0U]);
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
	int line_count = 0;
	int word_count[144];
	word_count[0] = 0;

	while(exit_switch)
	{
		//interactive shell sdtio
		std::string line;
		std::cout << "dave-sql> ";
		getline (std::cin, line);

		std::string result;
/*
		std::regex create_database ("CREATE DATABASE");
  		std::smatch match;
		if (std::regex_search(line, match, create_database) && match.size() > 1) 
		{
			result = match.str(1);
			mkdir("dir1");
			printf("make database"); 
		}
*/
		if(std::regex_match (line, std::regex("(CREATE DATABASE)(.*)" )))
		{
			//std::cout << "string literal matched\n";
			std::string database_name = line.erase(0, 16);
			std::string::size_type semicolon = line.find(";");
                        database_name = database_name.erase(semicolon, 1);
			mkdir(database_name);
			
                        std::cout << database_name + "\n";
                       
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

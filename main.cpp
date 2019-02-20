
#include <iostream>
#include <sys/stat.h>

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

	const int dir_err = mkdir(dir_path_complete, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (-1 == dir_err)
	{
	    printf("Error creating directory!n");
	    exit(1);
	}
}

/*
rename- depreciates unused databases

*/

int rmdir(std::string dir_name)
{

	std::string rm_cmd = "rm -r -f ./" + dir_name;
	system("rm -r -f ./dir1");


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

//	cin>>input_buffer;

	while(exit_switch)
	{
		//interactive shell sdtio
		std::string line;
		std::cout << "dave-sql> ";
		getline (std::cin, line);
//		std::cout << "Hello, " << line << "!\n";
		if(line == "exit"){return 0;}
		if(line == "mkdir"){mkdir("dir1");}
		if(line == "rmdir"){rmdir("dir1");}

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
		line.clear();

		}
		printf("line count:%i \n", line_count);
		printf("word_count:%i \n", word_count[0]);

	}
}

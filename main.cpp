#include <iostream>
#include <sys/stat.h>


using namespace std;

char sql_line[144];
char page_buffer[144][144];

char scan_buffer;
int line_length[144];

string input_buffer;

int mkdir(std::string)
{

	const int dir_err = mkdir("foo", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (-1 == dir_err)
	{
	    printf("Error creating directory!n");
	    exit(1);
	}

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
					page_buffer[line_count][word_count[line_count]] = 
scan_buffer;

				}

		}
		printf("line count:%i \n", line_count);
		printf("word_count:%i \n", word_count[0]);

	}
}

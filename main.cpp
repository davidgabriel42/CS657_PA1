#include <iostream>

using namespace std;

char sql_line[144];
char page_buffer[144][144];

char scan_buffer;
int line_length[144];

string input_buffer;

int main()
{
	bool exit_switch = 1;
	int line_count = 0;
	int word_count[144];
	word_count[0] = 0;

//	cin>>input_buffer;

	while(exit_switch)
	{
	std::string name;
	std::cout << "What is your name? ";
	getline (std::cin, name);
	std::cout << "Hello, " << name << "!\n";
	if(name == "exit"){return 0;}

	/*
			int input_size = input_buffer.size();

		for(int i = 0; i < input_size; i++)
		{
		scan_buffer = input_buffer[i];
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

	*/	
	//	line_count>>cout;
		printf("line count:%i \n", line_count);
		printf("word_count:%i \n", word_count[0]);
	}
//	return 0;
}

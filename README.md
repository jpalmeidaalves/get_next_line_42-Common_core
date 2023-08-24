# Get_next_line
## Reading a line from a file descriptor

## The rules
* Repeated calls to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time
* The returned line should include the terminating \n character (except if the end of file was reached)
* Forbidden:
    - lseek() is forbidden
    - Global variables are forbidden

### Bonus part:

## Learning Experience

* The utility of Static Variables
* How to read from a file in a program
* Handling file descriptors
* Increase string manipulation skills
## How to use
1. Clone the repository
2. To compile:
    * cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
    * cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
3. To execute:
    * ./a.out
    
PS: The repo include 2 files in order to test the program but you can use your own files if you want

// Global variables

#include "global.h"

using namespace std;

//Define global variable values
int ref_instruction_count = 0;		// holds number of instructions in the Instruction Set refeerence
int program_instruction_count = 0;	// holds number of instructions in the User Assembler Program
int error_count = 0;				// maintains an instruction/data/format error count
int last_add = 0;		// stores value of last address assigned - for use if last instruction is a Label so can add additional Address
int null_add = 765357;  // 765357 is Hex BADAD, which signifies BAD ADDRESS assigned as error address
int free_add = 63982;   // 63982 is Hex F9EE, which signifies FREE ADDRESS a valid instruction awaiting address assignment

char null_code = '0';	// 0 is written to blank out invalid or Label OpCodes

Cedar_Code ref_instruction_set[50];		// Array of Cedar_Code instructions object - Instruction Set Reference limit
Cedar_Code program_instructions[150];	// Array of Cedar_Code instructions object - Limits Program size
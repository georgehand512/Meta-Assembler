// Read program to be converted "Resource Files/Assembly_Program.txt"

#include "read_assembly_program.h"

void read_assembly_program()
{
    // Check file exists
    ifstream Assembly_Prog("Resource Files/Assembly_Program.txt");
    if (!Assembly_Prog)
    {
        cout << "Assembly program file: \"Assembly_Program.txt\" not found or does not exist";
    }

    // Function variable declarations/definitions
    int i = 0;
    string mneu, data_field;


    // Loop until end of file reading Instructions
    while (!Assembly_Prog.eof())
    {
        Assembly_Prog >> mneu >> data_field;
        Cedar_Code  blank(mneu, data_field);    // create blank of type "Cedar_Code" for each line of data
        program_instructions[i] = blank;        // move data into Array of type "Cedar_Code" (limit at 150 change in global if needed) 
        i++;
        program_instruction_count++;            // counts instruction for future "for loop" setting
        Assembly_Prog.ignore(1);                // prevents duplication of last line
    }
    Assembly_Prog.close();                      // close file after reading

   
    // Display data and instructions onto screen for User to review/reference
    // Static text displayed, then loop through Instructions
    // Display on screen
    // Pause and wait for user to move onto reading the User Program

    // Static Text
    cout << endl
        << "________________________________________________________________________________________________________________________________"
        << endl << endl << endl
        << "Assembly program read from \"Assembly_Program.txt\" located in the \"Resource Files\" Folder" << endl
        << endl << "There are " << program_instruction_count
        << " lines of prgram code to convert to CEDAR Logic RAM memory file format"
        << endl << endl;
    
    // Instruction Set Title Header Text
    cout << endl << setw(10) << "Mnemonic" << setw(20) << "Data Field" << endl;

    // Display full list of read instructions
    for (int i = 0; i < program_instruction_count; i++)
    {
        cout << setw(10) << program_instructions[i].get_Mnemonic()
            << setw(16) << program_instructions[i].get_Data_Field() << endl;
    }
    cout << endl << endl;

    // Pause and wait for user input before continuing
    system("pause");

}
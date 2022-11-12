// Read Instruction Set Reference from "Resource Files/Instruction_Set.txt"

#include "read_instruction_set_refernce.h"


void read_instruction_set_refernce()
{
    // Check file exists
    ifstream Instruction_Set("Resource Files/Instruction_Set.txt");
    if (!Instruction_Set)
    {
        cout << "Instruction set reference file: \"Instruction_Set.txt\" not found or does not exist";
    }

    // Function variable declarations/definitions
    int inst_type, i = 0, instruction_count = 0;
    string mneu, inst_comments;
    char c1, c2, c3, c4;

    // Loop until end of file reading Instruction Set Reference
    while (!Instruction_Set.eof())
    {
        Instruction_Set >> inst_type >> mneu >> c1 >> c2 >> c3 >> c4 >> inst_comments;

        for (int i = 0; i < inst_comments.size(); i++)
        {
            if (inst_comments[i] == '_') inst_comments[i] = ' ';    // replace "_" with " " in the instruction comments
        }

        Cedar_Code  blank(inst_type, mneu, c1, c2, c3, c4, inst_comments);  // create blank of type "Cedar_Code" for each line of data
        ref_instruction_set[i] = blank;     // move data into Array of type "Cedar_Code" (limit at 50 change in global if needed) 
        i++;
        ref_instruction_count++;            // counts instruction for future "for loop" setting

        Instruction_Set.ignore(1);          // prevents duplication of last line
    }
    Instruction_Set.close();                // close file after reading

    // Display data and instructions onto screen for User to review/reference
    // Static text displayed, then loop through Instruction Set Refernce
    // Display on screen
    // Pause and wait for user to move onto reading the User Program

    // Static Text
        cout << endl << "Meta Assembler for Cedar Logic Simulated Processor" << endl << endl << endl
        << "Instruction Set Reference" << endl << endl
        << "There are " << ref_instruction_count << " reference instructions , "
        << "as read from \"Instruction_Set.txt\" located in the \"Resource Files\" Folder" << endl;
    
    // Instruction Set Title Header Text
    cout << endl << setw(4) << "  Type" << setw(14) << "Mnemonic" << setw(12) << "OpCode"
        << "\t\t" << "Instruction Guide" << endl << endl;

    // Display full list of read instructions
    for (int i = 0; i < ref_instruction_count; i++)
    {
        cout << setw(4) << ref_instruction_set[i].get_Instruction_Type()
            << setw(16) << ref_instruction_set[i].get_Mnemonic()
            << setw(6) << ref_instruction_set[i].get_Code_1() << " " << ref_instruction_set[i].get_Code_2()
            << " " << ref_instruction_set[i].get_Code_3() << " " << ref_instruction_set[i].get_Code_4()
            << "\t\t" << ref_instruction_set[i].get_Description() << endl;
    }
    cout << endl;

    // Pause and wait for user input before continuing
    system("pause");

}
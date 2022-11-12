// Writes Cedar Logic "Resource Files/Cedar Logic Ram Memory File.cdm" and displays on screen

#include "write_CEDAR_Logic_RAM_file.h"

using namespace std;

void write_CEDAR_Logic_RAM_file()
{

    // Create and open a Cedar Logic RAM Memory .cdm file
    ofstream RAM_memory_file("Resource Files/Cedar Logic Ram Memory File.cdm");

    // Write standard Cedar Logic RAM Memory .cdm file comments as file header
    RAM_memory_file << "# CEDAR Logic RAM memory file." << endl
                    << "# The file format is :" << endl
                    << "# \"hex_address : hex_data\"" << endl
                    << "#" << endl
                    << "# For example, if the address \"0\" contained the decimal" << endl
                    << "# number \"18\", then the line for that address would be :" << endl
                    << "# \"0 : 12\"" << endl
                    << "#" << endl
                    << "# Note that if a memory location is not represented here," << endl
                    << "# then it is assumed to contain the data value \"0\"" << endl
                    << " " << endl;

    // Write Program to cdm file
    for (int i = 0; i < program_instruction_count; i++)
    {
        if (program_instructions[i].get_Address() != null_add)
        {
            RAM_memory_file << hex << program_instructions[i].get_Address() << program_instructions[i].get_Separator()
                << program_instructions[i].get_Code_1() << program_instructions[i].get_Code_2()
                << program_instructions[i].get_Code_3() << program_instructions[i].get_Code_4()
                << "\t" << program_instructions[i].get_Description() << endl;
        }

    }  
    RAM_memory_file.close();  // Close the file


    // Display Final Data conversion of ALL Instructions and error messages
    // This is the data prior to being written to the Cedar Logic RAM Memory file
    // Error data will NOT be written to the final file
    // Pause and wait for user to review the Actual cdm file data.

    // Static Text
    cout << endl
        << "________________________________________________________________________________________________________________________________"
        << endl
        << endl
        << "CEDAR Logic RAM memory file created" << endl << endl;

    cout << "*Important: There were " << error_count << " errors found with the code,"
        << "Error descriptions are displayed in the instruction comments field"
        << endl
        << endl
        << " Lines with BADAD addresses have not been written to the Output File"
        << endl
        << " The CEDAR Logic RAM memory file, \"Cedar Logic Ram Memory File.cdm\" "
        << "located in the \"Resource Files\" Folder"
        << endl << endl << endl << endl;

    // Instruction Set Title Header Text
    cout << " Type" << "      " << "Mnemonic" << "     " << "Address" << "   "
        << "      " << "code" << " " << "      " << "Data Feild" << "      " << "Comments" << endl;

    // Display full list of written instructions
    for (int i = 0; i < program_instruction_count; i++)
    {
        cout << setw(4) << program_instructions[i].get_Instruction_Type() << setw(15) << program_instructions[i].get_Mnemonic();
        cout << setw(12) << hex << program_instructions[i].get_Address() << setw(6) << program_instructions[i].get_Separator();
        cout << setw(2) << program_instructions[i].get_Code_1() << setw(2) << program_instructions[i].get_Code_2();
        cout << setw(2) << program_instructions[i].get_Code_3() << setw(2) << program_instructions[i].get_Code_4();
        cout << setw(16) << program_instructions[i].get_Data_Field() << "\t   " << program_instructions[i].get_Description();
        cout << endl;
    }

    cout << endl << endl << "Please review any errors above, before displaying the output CEDAR Logic RAM memory file";
    cout << endl << endl;

    system("pause");



    // Displays data contents WRITTEN to file for review/reference
    // Static text displayed, then loop through Instructions
    // Display on screen
    // Pause and wait for user to exit the program

    // Static Text
    cout << endl << endl;

    cout << endl
        << "________________________________________________________________________________________________________________________________"
        << endl
        << endl
        << "CEDAR Logic RAM memory file details" << endl << endl;

    cout << "# CEDAR Logic RAM memory file." << endl
        << "# The file format is :" << endl
        << "# \"hex_address : hex_data\"" << endl
        << "#" << endl
        << "# For example, if the address \"0\" contained the decimal" << endl
        << "# number \"18\", then the line for that address would be :" << endl
        << "# \"0 : 12\"" << endl
        << "#" << endl
        << "# Note that if a memory location is not represented here," << endl
        << "# then it is assumed to contain the data value \"0\"" << endl
        << " " << endl;

    for (int i = 0; i < program_instruction_count; i++)
    {
        if (program_instructions[i].get_Address() != null_add)
        {
            cout << program_instructions[i].get_Address() << program_instructions[i].get_Separator()
                << program_instructions[i].get_Code_1() << program_instructions[i].get_Code_2()
                << program_instructions[i].get_Code_3() << program_instructions[i].get_Code_4()
                << "\t" << program_instructions[i].get_Description() << endl;
        }

    }

    cout << endl << endl;

    // User message to keep output window open
    cout << "Thank you for using my Meta Assember, I hope you found it useful."
        << endl << endl << endl;

    system("pause");
}
// Function loads constants Address & Data into LOAD instructions
// 
// LOAD instruction MUST be in the format of LOAD AAA_DDDD (8 chars with the 3rd one being "_")


#include "set_load_constants.h"

void set_load_constants()
{
    // loop through each program instruction looking for LOAD instruction
    for (int i = 0; i < program_instruction_count; i++)
    {
        if (program_instructions[i].get_Mnemonic() == "LOAD")
        {
            // declare/define variables
            int a1 = 0, a2 = 0, a3 = 0;
            char c1 = '0', c2 = '0', c3 = '0', c4 = '0';
            bool valid_field_format = false, valid_char = true;

            string field = program_instructions[i].get_Data_Field(); // move datafield into string "field"
            int field_size = field.size();
            int m = 0, n = 0;

            if (field_size == 8 && field[3] == '_')     // checks for 3rd char "_"
            {
                for (int j = 0; j < field_size; j++)    // loops through field string
                {
                    if (valid_char && j >= 0 && j < 3)  // converts first 3 Hex chars to integer value for address
                    {
                        n = n * 16;
                        m = field[j];
                        if (m >= '0' && m <= '9')
                            n += m - '0';
                        else if (m >= 'A' && m <= 'F')
                            n += m + 10 - 'A';
                        else
                        {                               // If not valid zero's the address
                            program_instructions[i].set_Code_1(null_code);
                            program_instructions[i].set_Code_2(null_code);
                            program_instructions[i].set_Code_3(null_code);
                            program_instructions[i].set_Code_4(null_code);
                            program_instructions[i].set_Description("\"" + program_instructions[i].get_Data_Field() + "\" data field not valid ADDRESS value");
                            error_count++;
                            valid_char = false;
                        }

                    }
                    else if (valid_char && j > 3 && j < 8) // converts last 4 Hex chars for data
                    {
                        if ((field[j] >= '0' && field[j] <= '9') || (field[j] >= 'A' && field[j] <= 'F'))
                        {
                            program_instructions[i].set_Code_1(field[4]);
                            program_instructions[i].set_Code_2(field[5]);
                            program_instructions[i].set_Code_3(field[6]);
                            program_instructions[i].set_Code_4(field[7]);
                        }
                        else
                        {
                            program_instructions[i].set_Code_1(null_code);
                            program_instructions[i].set_Code_2(null_code);
                            program_instructions[i].set_Code_3(null_code);
                            program_instructions[i].set_Code_4(null_code);
                            program_instructions[i].set_Address(null_add);
                            program_instructions[i].set_Description("\"" + program_instructions[i].get_Data_Field() + "\" data field not valid DATA value");
                            error_count++;
                            valid_char = false;
                        }
                    }
                }
                program_instructions[i].set_Address(n);

            }
            else
            {   // NOT valid data found - write error Address & Message to Program instruction object
                program_instructions[i].set_Code_1(null_code);
                program_instructions[i].set_Code_2(null_code);
                program_instructions[i].set_Code_3(null_code);
                program_instructions[i].set_Code_4(null_code);
                program_instructions[i].set_Address(null_add);
                program_instructions[i].set_Description("\"" + program_instructions[i].get_Data_Field() + "\" data field not valid format of \"AAA_DDDD\"");
                error_count++;
            }

        }

    }

}
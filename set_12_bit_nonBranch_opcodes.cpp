// Function to set 12 bit op/field code instructions from data field
// 12 Bit Instructions contain data or address fields in the Hex format "AAA" or "DDD" (000 - FFF) 
// 12 Bit Instructions have been assigned as type - 3 (having 3 Hex chars in Data/Address field)

#include "set_12_bit_nonBranch_opcodes.h"

void set_12_bit_nonBranch_opcodes()
{
    // loop through each program instruction
    for (int i = 0; i < program_instruction_count; i++)
    {
        // instruction valid flag
        bool valid_field = false;

        // If type "1" then copies and validations it's data/address field information
        // Data field string size should be 3, but can cope with shorter entries
        // converts data field from string to char type and stores it in OpCode 2, 3, 4
        if (program_instructions[i].get_Instruction_Type() == 3)
        {
            char c2 = '0', c3 = '0', c4 = '0';
            string field = program_instructions[i].get_Data_Field();

            int field_size = field.size();

            if (field_size > 0 && field_size < 4)
            {
                if (field_size == 1)
                {
                    c4 = field[0];
                }
                else if (field_size == 2)
                {
                    c3 = field[0];
                    c4 = field[1];
                }
                else if (field_size == 3)
                {
                    c2 = field[0];
                    c3 = field[1];
                    c4 = field[2];
                }

                if (((c2 >= '0' && c2 <= '9') || (c2 >= 'A' && c2 <= 'F')) && ((c3 >= '0' && c3 <= '9') || (c3 >= 'A' && c3 <= 'F')) && ((c4 >= '0' && c4 <= '9') || (c4 >= 'A' && c4 <= 'F')))
                {
                    for (int j = 0; j < ref_instruction_count; j++)
                    {
                        if (program_instructions[i].get_Mnemonic() == ref_instruction_set[j].get_Mnemonic())
                        {
                            program_instructions[i].set_Code_2(c2);
                            program_instructions[i].set_Code_3(c3);
                            program_instructions[i].set_Code_4(c4);
                            valid_field = true;
                        }
                    }
                }

            }
            // NOT valid data found - write error Address & Message to Program instruction object
            if (!valid_field)
            {
                program_instructions[i].set_Code_1(null_code);
                program_instructions[i].set_Code_2(null_code);
                program_instructions[i].set_Code_3(null_code);
                program_instructions[i].set_Code_4(null_code);
                program_instructions[i].set_Address(null_add);
                program_instructions[i].set_Description("\"" + program_instructions[i].get_Data_Field() + "\" data field not valid");
                error_count++;
            }

        }

    }

}
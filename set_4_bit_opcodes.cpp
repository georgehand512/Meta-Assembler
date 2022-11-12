// Validate 4 Bit Instructions, complete OpCode or generate error message in comments
// 4 Bit Instructions are limited to ones with a single value to select a Register 0 - 3
// 4 Bit Instructions have been assigned as type - 1 (having 1 Hex char in Data field)

#include "set_4_bit_opcodes.h"

void set_4_bit_opcodes()
{
    // loop through each program instruction
    for (int i = 0; i < program_instruction_count; i++)
    {
        // instruction valid flag
        bool valid_field = false;

        // If type "1" then copies and validations it's data field information
        // Data field string size should be 1
        // converts data field from string to char type and stores it in OpCode 4
        if (program_instructions[i].get_Instruction_Type() == 1)
        {
            string field = program_instructions[i].get_Data_Field();
            char c4 = field[0];

            if ((c4 >= '0') && (c4 <= '3') && (program_instructions[i].get_Data_Field().size() == 1))
            {
                for (int j = 0; j < ref_instruction_count; j++)
                {
                    if (program_instructions[i].get_Mnemonic() == ref_instruction_set[j].get_Mnemonic())
                    {
                        program_instructions[i].set_Code_4(c4);
                        valid_field = true;
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
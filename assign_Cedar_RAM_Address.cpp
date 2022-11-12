// Assigns instruction Addresses from 000 or "ORG" instruction value
//
//

#include "assign_Cedar_RAM_Address.h"

void assign_Cedar_RAM_Address()
{
    // variable declare/define
    bool start_ins_found = false;
    int m = 0, n = 0;

    // loop through each program instruction looking for "ORG" instruction
    // also check for duplicate "ORG" instructions, only accept the first as valid
    // Then assign starting address to the next valid instruction
    for (int i = 0; i < program_instruction_count; i++)
    {
        if (program_instructions[i].get_Mnemonic() == "ORG")
        {
            bool valid_field_format = false, valid_char = true;

            string field = program_instructions[i].get_Data_Field();
            int field_size = field.size();

            if (field_size < 4 && !start_ins_found && valid_char)
            {
                for (int j = 0; j < field_size; j++)
                {
                    n = n * 16;
                    m = field[j];
                    if (m >= '0' && m <= '9')
                        n += m - '0';
                    else if (m >= 'A' && m <= 'F')
                        n += m + 10 - 'A';
                    else
                    {
                        program_instructions[i].set_Code_1(null_code);
                        program_instructions[i].set_Code_2(null_code);
                        program_instructions[i].set_Code_3(null_code);
                        program_instructions[i].set_Code_4(null_code);
                        program_instructions[i].set_Description("\"" + program_instructions[i].get_Data_Field() + "\" data field not valid ADDRESS value \"0AAA\"");
                        error_count++;
                        valid_char = false;
                    }
                }
                program_instructions[i].set_Address(null_add);
                program_instructions[i].set_Description("Address \"" + program_instructions[i].get_Data_Field() + "\" has been assigned to first valid instruction");
                start_ins_found = true;
            }
            else
            {
                program_instructions[i].set_Code_1(null_code);
                program_instructions[i].set_Code_2(null_code);
                program_instructions[i].set_Code_3(null_code);
                program_instructions[i].set_Code_4(null_code);
                program_instructions[i].set_Address(null_add);
                if (start_ins_found) program_instructions[i].set_Description("duplicate ORG instruction");
                if (field_size > 4) program_instructions[i].set_Description("\"" + program_instructions[i].get_Data_Field() + "\" data field not valid format of \"AAAA\"");
                error_count++;
            }

        }
    }

    // loop through each program instruction to set it's address
    // *Note Address is only assigned to instructions set to F9EE ( 0 could be a valid address so could not use as default)
    // *Note Address is NOT assigned to LABEL addresses - these point to the next valid address

    for (int i = 0; i < program_instruction_count; i++)
    {
        if (program_instructions[i].get_Address() == free_add && program_instructions[i].get_Instruction_Type() != 4)
        {
            if (n <= Max_Address)
            {
                program_instructions[i].set_Address(n);
                last_add = n;
                n++;
            }
            else
            {
                program_instructions[i].set_Address(n);
                program_instructions[i].set_Code_1(null_code);
                program_instructions[i].set_Code_2(null_code);
                program_instructions[i].set_Code_3(null_code);
                program_instructions[i].set_Code_4(null_code);
                program_instructions[i].set_Address(null_add);
                program_instructions[i].set_Description("Cedar Logic RAM address not available");
                error_count++;
            }

        }
    }
}

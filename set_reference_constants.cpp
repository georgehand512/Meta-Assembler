// Cross reference Assembly data to Instruction Set Reference and update constant OpCode values

#include "set_reference_constants.h"

void set_reference_constants()
{
    // loop through each program instruction
    for (int i = 0; i < program_instruction_count; i++)
    {
        // instruction valid flag
        bool valid_instruction = false; 

        for (int j = 0; j < ref_instruction_count; j++)
        {
            // valid instruction found - copy data from Instruction Set Reference object into Program instruction object
            if (program_instructions[i].get_Mnemonic() == ref_instruction_set[j].get_Mnemonic())   
            {
                program_instructions[i].set_Instruction_Type(ref_instruction_set[j].get_Instruction_Type());
                program_instructions[i].set_Code_1(ref_instruction_set[j].get_Code_1());
                program_instructions[i].set_Code_2(ref_instruction_set[j].get_Code_2());
                program_instructions[i].set_Code_3(ref_instruction_set[j].get_Code_3());
                program_instructions[i].set_Code_4(ref_instruction_set[j].get_Code_4());
                program_instructions[i].set_Description(ref_instruction_set[j].get_Description());
                valid_instruction = true;
            }

        }
            // NOT valid instruction found - write error Address & Message to Program instruction object
        if (!valid_instruction)
        {
            program_instructions[i].set_Code_1(null_code);
            program_instructions[i].set_Code_2(null_code);
            program_instructions[i].set_Code_3(null_code);
            program_instructions[i].set_Code_4(null_code);
            program_instructions[i].set_Address(null_add);
            program_instructions[i].set_Description("\"" + program_instructions[i].get_Mnemonic() + "\" instruction not found in Instrction Set Reference");
            error_count++;
        }

    }

}
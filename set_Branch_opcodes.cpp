// Complete LABEL destinations and Branch to Addresses to complete ALL OpCodes
// 
// Assign LABEL address as the address of the first valid instruction after the LABEL
// If the LABEL is the last instruction then the destination address is: Last Address + 1
// 
// Assign direct jump addresses to the LABEL assigned address
// For Branch instructions need to calculate relative data value: Branch Address +/- Label Address

#include "set_Branch_opcodes.h"

void set_Branch_opcodes()
{
    string label_text = "_";
    int label_address = free_add;
    bool label_address_set = false;

    for (int i = 0; i < program_instruction_count; i++)
    {
        // Look for LABEL Instructions - if address is still F9EE means this LABEL has not already been processed
        if (program_instructions[i].get_Mnemonic() == "LABEL:" && program_instructions[i].get_Address() == free_add)
        {
            label_text = program_instructions[i].get_Data_Field(); // store LABEL text

            program_instructions[i].set_Address(null_add);         // blank address once found & add message to object
            program_instructions[i].set_Description("Label Address has been assigned to next valid instruction");

            // look for valid address AFTER LABEL instruction
            for (int j = i + 1; j < program_instruction_count && label_address_set == false; j++)
            {
                if (program_instructions[j].get_Address() != null_add && program_instructions[j].get_Address() != free_add && label_address_set == false)
                {
                    label_address = program_instructions[j].get_Address();
                    label_address_set = true;
                }
                else if (j == (program_instruction_count - 1) && !label_address_set)
                {
                    label_address = last_add + 1;
                    label_address_set = true;
                }
            }

            // Add address if LABEL is last program instruction
            if (!label_address_set)
            {
                label_address = last_add + 1;
                label_address_set = true;
            }

            // Set JMP, JSR or Branch OpCodes to LABEL destination
            for (int j = 0; j < program_instruction_count; j++)
            {
                // if JMP or JSR put LABEL destination for direct jump to
                if (program_instructions[j].get_Data_Field() == label_text && (program_instructions[j].get_Mnemonic() == "JMP" || program_instructions[j].get_Mnemonic() == "JSR"))
                {
                    stringstream label_address_String;
                    label_address_String << hex << label_address;
                    string label_address_result = label_address_String.str();

                    int size = label_address_result.size();

                    if (size == 1)
                    {
                        program_instructions[j].set_Code_2('0');
                        program_instructions[j].set_Code_3('0');
                        program_instructions[j].set_Code_4(label_address_result[0]);
                    }
                    else if (size == 2)
                    {
                        program_instructions[j].set_Code_2('0');
                        program_instructions[j].set_Code_3(label_address_result[0]);
                        program_instructions[j].set_Code_4(label_address_result[1]);
                    }
                    else if (size == 3)
                    {
                        program_instructions[j].set_Code_2(label_address_result[0]);
                        program_instructions[j].set_Code_3(label_address_result[1]);
                        program_instructions[j].set_Code_4(label_address_result[2]);
                    }
                    else
                    {
                        program_instructions[j].set_Code_1(null_code);
                        program_instructions[j].set_Code_2(null_code);
                        program_instructions[j].set_Code_3(null_code);
                        program_instructions[j].set_Code_4(null_code);
                        program_instructions[j].set_Description("\"" + program_instructions[j].get_Data_Field() + "\" data field not valid ADDRESS value \"0AAA\"");
                        error_count++;
                    }
                }

                // if Branch calculate relative positions to jump
                if (program_instructions[j].get_Data_Field() == label_text && program_instructions[j].get_Mnemonic() != "JMP" && program_instructions[j].get_Mnemonic() != "JSR")
                {
                    int relative = 0;

                    relative = (label_address - 1) - program_instructions[j].get_Address();

                    stringstream relative_address_String;
                    relative_address_String << hex << relative;
                    string relative_address_result = relative_address_String.str();

                    int size = relative_address_result.size();

                    if (size == 1)
                    {
                        //program_instructions[j].set_Code_2('0');
                        program_instructions[j].set_Code_3('0');
                        program_instructions[j].set_Code_4(relative_address_result[0]);
                    }
                    else if (size == 2)
                    {
                        //program_instructions[j].set_Code_2('0');
                        program_instructions[j].set_Code_3(relative_address_result[0]);
                        program_instructions[j].set_Code_4(relative_address_result[1]);
                    }
                    else
                    {
                        program_instructions[j].set_Code_1(null_code);
                        program_instructions[j].set_Code_2(null_code);
                        program_instructions[j].set_Code_3(null_code);
                        program_instructions[j].set_Code_4(null_code);
                        program_instructions[j].set_Description("\"" + program_instructions[j].get_Data_Field() + "\" LABEL address assigned\"");
                        error_count++;
                    }
                    //else if (size == 3)
                    //{
                     //   program_instructions[j].set_Code_2(relative_address_result[0]);
                     //   program_instructions[j].set_Code_3(relative_address_result[1]);
                     //   program_instructions[j].set_Code_4(relative_address_result[2]);
                   // }
                }
            }
        }
        label_address_set = false;
    }
}

//
// Created by logan on 10/31/2023.
//

#ifndef MEM_H
#define MEM_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// defines the size of a pointer
#define ADDRESS_SIZE 65536
#define MAX_STR 128
enum OP {
    data, // indicates location stores data
    dumpmemory, // dump the contents of memory to stdout
    dumpCPU, // dump the contents of the CPU to stdout
    halt, // halts program
    jmp, jmpz, jmpn, // jump instructions
    call, ret, // function call/ret instructions
    mova, movr, // register move instructions
    lodi, loda, lorr, // memory load instructions reg --> memory
    stoa, stor, stoi, // memory store instructions memory --> reg
    add, sub, neg // arithmetic instructions
};
// as each line is read from the file, it will be:
// 1. stored into the instruction_string
// 2. cleaned up, as done in lab 4
// 3. broken into substrings stored in the associated char * variables
// 4. converted into functional values stored in the appropriate
// structure variables
struct location_contents {
    /*** information dot-instructions ***/
    /*** add your variables here ***/
    /*** information storage for data ***/
    unsigned short data;
    /*** information storage for an instruction ***/
    enum OP operation; // enum indicating operator being performed
    short reg_a; // the index of register a
    short reg_b; // the index of register b
    short immediate; // immediate value
    short address; // address value
    short index; // index value
    char *instruction_str; // original string from file
    // The substring identify operator being performed.
    char *operator_str;
    // The different parts of the string.
    // When a value is null, it does not exist in the
    // instruction_string.
    char *immediate_value_str;
    char *address_value_str;
    char *operand_a_str;
    char *operand_b_str;
    char *index_str;
};
void initialize_memory();
void free_memory();

struct location_contents *get_mem_at(int address);

int read_instructions(char* filename);
void load_instructions(int end_instructions);

int load_operand(char* operand, int op_num, int instruction_number);

void set_data(unsigned short address, unsigned short value);

short get_register(char* reg_string);
short get_immediate(char* immed_str);

#endif //MEM_H
#ifndef __DYNAREC_PRIVATE_H_
#define __DYNAREC_PRIVATE_H_

#define X86_FLAGS_NONE      0
#define X86_FLAGS_CHANGE    1
#define X86_FLAGS_USE       2

typedef struct instruction_x86_s {
    uintptr_t   addr;   //address of the instruction
    int32_t     size;   // size of the instruction
    int         flags;  // flags for this instruction (see X86_FLAGS_XXXX)
    int         barrier; // next instruction is a jump point, so no optim allowed
    uintptr_t   jmp;    // offset to jump to, even if conditionnal (0 if not), no relative offset here
    int         jmp_insts;  // instuction to jump to (-1 if out of the block)
} instruction_x86_t;

void printf_x86_instruction(zydis_dec_t* dec, instruction_x86_t* inst, const char* name);

#endif //__DYNAREC_PRIVATE_H_
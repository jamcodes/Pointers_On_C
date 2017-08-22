#include <stdio.h>


struct SGL_OP{
    unsigned int dst_reg  : 3;
    unsigned int dst_mode : 3;
    unsigned int opcode   : 10;
};

struct DBL_OP{
    unsigned int dst_reg    : 3;
    unsigned int dst_mode   : 3;
    unsigned int src_reg    : 3;
    unsigned int src_mode   : 3;
    unsigned int opcode     : 4;
};

struct BRANCH{
    unsigned int offset     : 8;
    unsigned int opcode     : 8;
};

struct REG_SRC{
    unsigned int dst_reg    : 3;
    unsigned int dst_mode   : 3;
    unsigned int src_reg    : 3;
    unsigned int opcode     : 7;
};

struct MISC
{
    unsigned int opcode : 16;
};


union MACHINE_INST{
    unsigned short  addr;
    struct SGL_OP   sgl_op;
    struct DBL_OP   dbl_op;
    struct BRANCH   branch;
    struct REG_SRC  reg_src;
    struct MISC     misc;
};
typedef union MACHINE_INST machine_inst;


void print_machine_inst(machine_inst* mi);


int main(void)
{
    machine_inst x = {0xFF11};
    printf("addr: 0x%x\n", x.addr);
    printf("x.misc.opcode: 0x%x\n"
        "x.branch.opcode: 0x%x\n"
        "x.sgl_op.dst_mode: 0x%x\n"
        "x.reg_src.src_reg: 0x%x\n"
        "x.dbl_op.opcode: 0x%x\n",
        x.misc.opcode, x.branch.opcode,
        x.sgl_op.dst_mode, x.reg_src.src_reg,
        x.dbl_op.opcode);

    return 0;
}

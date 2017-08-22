#include <stdio.h>

#define SET_BIT(V,N)      ((V) |= (1<<(N)))
#define CLEAR_BIT(V,N)    ((V) &= ~(1<<(N))) 
#define ASSIGN_BIT(V,N,B) ((B) ? SET_BIT((V),(N)) : CLEAR_BIT((V),(N)))


unsigned store_bit_field(int original_value, int value_to_store,
                    unsigned starting_bit, unsigned ending_bit);


int main(void)
{
    unsigned original_val;
    unsigned val_to_store;

    original_val = 0x0;
    val_to_store = 0x1;
    printf("Original val: 0x%x, to_store: 0x%x, start: %d, end: %d\nreturned: %x\n",
        original_val, val_to_store, 4, 4,
        store_bit_field(original_val, val_to_store, 4, 4));

    original_val = 0xFFFF;
    val_to_store = 0x123;
    printf("\nOriginal val: 0x%x, to_store: 0x%x, start: %d, end: %d\nreturned: %x\n",
        original_val, val_to_store, 15, 4,
        store_bit_field(original_val, val_to_store, 15, 4));

    original_val = 0xFFFF;
    val_to_store = 0x123;
    printf("\nOriginal val: 0x%x, to_store: 0x%x, start: %d, end: %d\nreturned: %x\n",
        original_val, val_to_store, 13, 9,
        store_bit_field(original_val, val_to_store, 13, 9));


    return 0;
}


unsigned store_bit_field(int original_value, int value_to_store,
                    unsigned starting_bit, unsigned ending_bit)
{
    unsigned mask = 0;
    for(unsigned shift = starting_bit; shift > ending_bit; --shift){
        mask |= (1 << shift);
    }
    original_value &= ~mask;
    original_value |= value_to_store << (starting_bit - ending_bit);
    return original_value;
}

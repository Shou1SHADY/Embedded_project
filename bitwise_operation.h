#ifndef bitwise_operation_h
#define bitwise_operation_h
#define SET_BIT(reg, bit) (reg |= (1<<bit))
#define CLEAR_BIT(reg, bit) (reg &= ~(1<<bit))
#define GET_BIT(reg, bit) ((reg >> bit)&1)
#define TOGGLE_BIT(reg, bit) (reg ^= (1<<bit))
#endif
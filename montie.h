#ifndef MONTIE_H
#define MONTIE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* Global Opcode Tokens */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Primary Interpreter Functions */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_montie(FILE *script_fd);
void set_op_tok_error(int error_code);

/* Opcode Functions */
void montie_push(stack_t **stack, unsigned int line_number);
void montie_pall(stack_t **stack, unsigned int line_number);
void montie_pint(stack_t **stack, unsigned int line_number);
void montie_pop(stack_t **stack, unsigned int line_number);
void montie_swap(stack_t **stack, unsigned int line_number);
void montie_add(stack_t **stack, unsigned int line_number);
void montie_nop(stack_t **stack, unsigned int line_number);
void montie_sub(stack_t **stack, unsigned int line_number);
void montie_div(stack_t **stack, unsigned int line_number);
void montie_mul(stack_t **stack, unsigned int line_number);
void montie_mod(stack_t **stack, unsigned int line_number);
void montie_pchar(stack_t **stack, unsigned int line_number);
void montie_pstr(stack_t **stack, unsigned int line_number);
void montie_rotl(stack_t **stack, unsigned int line_number);
void montie_rotr(stack_t **stack, unsigned int line_number);
void montie_stack(stack_t **stack, unsigned int line_number);
void montie_queue(stack_t **stack, unsigned int line_number);

/* Custom Standard Library Functions */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* Error Messages and Error Codes */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

#endif /* MONTIE_H */

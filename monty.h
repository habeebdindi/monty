#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * * struct stack_s - doubly linked list representation of a stack (or queue)
 * * @n: integer
 * * @prev: points to the previous element of the stack (or queue)
 * * @next: points to the next element of the stack (or queue)
 * *
 * * Description: doubly linked list node structure
 * * for stack, queues, LIFO, FIFO Holberton project
 * */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * * struct instruction_s - opcode and its function
 * * @opcode: the opcode
 * * @f: function to handle the opcode
 * *
 * * Description: opcode and its function
 * * for stack, queues, LIFO, FIFO Holberton project
 * */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **head, unsigned int line_number);
} instruction_t;


/**
 * * struct global_struct_s -
 * * @linenum: linenumber as integer
 * * @line: pointer to string
 * * @arglist: double pointer to list of line tokenized
 * *
 * * Description: global structure to hold common informatin
 * */
typedef struct global_struct_s
{
	char *line;
	unsigned int linenumber;
	char *arg;
	FILE *fp;
	stack_t *head;
	int flag;
} global_struct_t;

extern global_struct_t global_struct;

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_FAIL_2 "L%u: division by zero\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define MOD_FAIL_2 "L%u: division by zero\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, value out of range\n"
#define PCHAR_FAIL_2 "L%u: can't pchar, stack empty\n"

/* main_helpers.c */
void (*get_op_func(char *s))(stack_t **head, unsigned int linenumber);

/* str_helpers.c */
int _strlen(char *s);
void rm_nl(char **lineptr);
int wordcount(char *str);
char **strtow(char *str);
void strtok_list(char *line);

/* str_helpers_2.c */
int _atoi(int *num, char *s);
int _isnum(char c);

/* free_helpers */
void free_all(void);

/* global_helpers.c */
global_struct_t *create_global_struct(unsigned int linenumber, char *line,
		FILE *fp, stack_t *head);
void free_global_struct(global_struct_t *ptr);

/* ll_helpers_1.c */
stack_t *add_dnodeint_end(stack_t **head, const int n);

/* ll_helpers_2.c */
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
void delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t dlistint_len(const stack_t *h);

/* op_helpers_1 */
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **h, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);

/* op_helpers_2 */
void op_add(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);

/*op_helpers_3 */
/*void op_swap(stack_t **head, unsigned int line_number);*/
void op_stack(stack_t **head, unsigned int line_number);
void op_queue(stack_t **head, unsigned int line_number);
void op_rotl(stack_t **head, unsigned int line_number);
void op_rotr(stack_t **head, unsigned int line_number);
void op_swap(stack_t **head, unsigned int line_number);

/* op_helpers_4 */
void op_pchar(stack_t **head, unsigned int line_number);
void op_pstr(stack_t **head, unsigned int line_number);

#endif

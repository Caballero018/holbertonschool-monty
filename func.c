#include "monty.h"

/**
 * tamanio - size
 * @linea: linea
 * Return: linea
 */
int tamanio(char *linea)
{
	unsigned int contador = 0;

	while (linea[contador])
	{
		contador++;
	}
	return (contador);
}


/**
 * quitarsalto - remove line
 * @linea: linea
 * Return: linea
 */
char quitarsalto(char *linea)
{
	int ta = tamanio(linea);

	linea[ta - 1] = '\0';
	return (*linea);
}

/**
 * func - pointers to functions
 * @tokens: arguments
 * Return: NULL
 */

void (*func(char *tokens))(stack_t **stack, unsigned int num_linea)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"err", err},
		{"#", nop},
		{NULL, NULL}
	};
	int i = 0;
	int o;

	while (i < 19)
	{
		o = strcmp(ops[i].opcode, tokens);
		if (o == 0)
			return (ops[i].f);
		i++;
	}

	return (ops[17].f);
}

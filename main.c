#include "monty.h"

g_t hola;

/**
 * pop - delete first noce
 * @stack: head of the linked list
 * @num_linea: number of the line
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (ojo == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = ojo->next;
		(*stack)->prev = NULL;
		free(ojo);
	}
	else
		free_l(stack);
}

/**
 * main - main function
 * @argc: number of the arguments
 * @argv: argument
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t numbytes = 0;
	int bytesleidos = 0;
	unsigned int contador = 1;

	hola.flag = 1;
	hola.linea = NULL;
	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	hola.fil = fopen(argv[1], "r");
	if (hola.fil == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((bytesleidos = getline(&hola.linea, &numbytes, hola.fil)) != EOF)
	{
		quitarsalto(hola.linea);
		if (hola.linea[0] != 35)
		{
			hola.token = strtok(hola.linea, " \t\n");
			hola.opco = hola.token;
			if (hola.opco != NULL)
			{
				hola.token = strtok(NULL, " \t\n");
				func(hola.opco)(&stack, contador);
			}
			contador++;
		}
	}
	free_l(&stack);
	free(hola.linea);
	fclose(hola.fil);
	return (0);
}

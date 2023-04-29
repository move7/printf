#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: void
 */

void init_params(params_t *params, va_list ap)
{
	params->flags = 0;
	params->width = 0;
	params->precision = 0;
	params->size = 0;

}

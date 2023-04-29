#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	params_t params = PARAMS_INIT;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		init_params(&params, list);
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				_puts(&buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			_puts(&buffer, &buff_ind);
			handl_params(format, &i, list, &params);
			++i;
			printed = handle_print(format, &i, list, buffer, &params);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	_puts(&buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}


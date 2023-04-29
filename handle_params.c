#include "main.h"

/**
 * get_width - Calculates the width of printing
 * @format: Formatted string which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr;
	int width = 0;

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			width *= 10;
			width += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (width);
}

/**
 * get_size - Calculates the size
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int curr = *i + 1;
	int size = 0;

	if (format[curr] == 'l')
		size = SIZE_LONG;
	else if (format[curr] == 'h')
		size = SIZE_SHORT;

	else if (size == 0)
		*i = curr - 1;
	else
		*i = curr;

	return (size);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr = *i + 1;
	int precision = -1;

	if (format[curr] != '.')
		return (precision);

	precision = 0;

	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (precision);
}

/**
 * get_flags - Calculates flags caracters
 * @format: Formatted string * - + 0 # ' ' *
 * @i: parameter 1 2 4 8  16.
 * Return: Flags:
 */
int get_flags(const char *format, int *n)
{

	int i, curr;
	int num_flags = 0;
	const char FLAG_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int array[] = {FLAG_MIN, FLAG_PLUS, FLAG_ZERO,
		FLAG_HASH, FLAG_SPACE, 0};

	for (curr = *n + 1; format[curr] != '\0'; curr++)
	{

		for (i = 0; FLAG_CHAR[i] != '\0'; i++)
			if (format[curr] == FLAG_CHAR[i])
			{
				num_flags |= array[i];
				break;
			}

		if (FLAG_CHAR[i] == 0)
			break;
	}

	*n = curr - 1;

	return (num_flags);
}

/**
 * handl_params - handl_params
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
void handl_params(const char *format, int *i, va_list list, params_t *params)
{
	params->flags = get_flags(format, i);
	params->width = get_width(format, i, list);
	params->precision = get_precision(format, i, list);
	params->size = get_size(format, i);
}

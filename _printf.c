#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - produces printf function
 * @format: format string containing  characters and specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int i = 0, p = 0, p_ch = 0;
	int flags, width, precision, size, buf_ind = 0;
	va_list	list;
	char buffer[BUF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buf_ind++] = format[i];

			if (buf_ind == BUF_SIZE)
				p_buffer(buffer, &buf_ind);
			
			p_ch++;
		}
		else
		{
			p_buffer(buffer, &buf_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);

			p = handle_print(format, &i, list, buffer, flags, width, precision, size);

			if (p == -1)
				return (-1);
			p_ch += p;
		}
		i++;
	}
	p_buffer(buffer, &buf_ind);
	va_end(list);
	return (p_ch);
}
void p_buffer(char buffer[], int *buf_ind)
{
	if (*buf_ind > 0)
		write(1, &buffer[0], *buf_ind);
	*buf_ind = 0;
}

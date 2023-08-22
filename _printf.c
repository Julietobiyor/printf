#include "main.h"

/**
 * _printf - gives output according to a format
 * @format: A char string with zero or more directives
 *          conversion specifier for c,%,and s
 *          other characters are printed.
 * Return: To return number of characters printed
 */

int _printf(const char *format, ...)
{
	int _chara_print = 0;
	int jul;
	va_list list_ofargs;
	if (format == NULL)
		return (-1);
	va_start(list_ofargs, format);
	for (jul = 0; format && format[jul] != '\0'; jul++)
	{
		if (format[jul] != '%')
		{
			write(1, &format[jul], 1);
			_chara_print++;
		}
		else
		{
			jul++;
			if (format[jul] == '\0')
				break;
			if (format[jul] == '%')
			{
				write(1, &format[jul], 1);
				_chara_print++;
			}
			else if (format[jul] == 'c')
			{
				char c = va_arg(list_ofargs, int);

				write(1, &c, 1);
				_chara_print++;
			}
			else if (format[jul] == 's')
			{
				char *str = va_arg(list_ofargs, char*);

				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				_chara_print += str_len;
			}
		}
	}

	va_end(list_ofargs);
	return (_chara_print);
}

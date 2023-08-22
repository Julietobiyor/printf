#include "main.h"
int _printf(const char *format, ...);

/**
 * _printf - gives output according to a format
 * _printf - gives output according to a format
 * @format: A char string with zero or more directives
 *          conversion specifier for c,%,and s
 *          other characters are printed.
 * Return: To return number of characters printed
 */

int _printf(const char *format, ...)
{
	int _chara_print = 0;
		va_list list_ofargs;
	if (*format == '\0')
		return (-1);
	va_start(list_ofargs, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			_chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				_chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_ofargs, int);

				write(1, &c, 1);
				_chara_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_ofargs, char*);

				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				_chara_print += str_len;
			}
		}
		format++;
	}

	va_end(list_ofargs);
	return (_chara_print);
}

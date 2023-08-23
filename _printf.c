#include "main.h"
int _printf(const char *format, ...);

/**
 * _printf - Gives output according to a format
 * @format: A char string with zero or more directives
 *          conversion specifier for c, %, s, d and i,
 *          Other characters are printed.
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
			else if (format[jul] == 'd' || format[jul] == 'i')
			{
				int num1 = va_arg(list_ofargs, int);
				int num_digits = 0;
				int tmp = num1;
				int i;
				char *buffer;
				unsigned int num, temp; 

				if (num1 < 0)
				{
					write(1, "-", 1);
					_chara_print++;
					num = -num1;
					temp = -tmp;
				}
				else
				{
					num = num1;
					temp = tmp;
				}


				while (temp != 0)

				{
					temp /= 10;
					num_digits++;
				}


				buffer = malloc(num_digits + 1);
				if (buffer == NULL)
				{
					va_end(list_ofargs);
					return (-1);
				}

				buffer[num_digits] = '\0';


				for (i = num_digits - 1; i >= 0; i--)
				{
					buffer[i] = (num % 10) + '0';
					num /= 10;
				}

				write(1, buffer, num_digits);
				_chara_print += num_digits;

				free(buffer);
			}
		}
	}

	va_end(list_ofargs);
	return (_chara_print);
}

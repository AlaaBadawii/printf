#include "main.h"
/**
 * _printf - writes the character to stdout
 * @format: the specifier char that determine the type of data to be printed
 * Description: we make our printf function AHMED @ ALAA
 * Return: number of  characters printed excluding the null byte used to end output to strings.
 * On error, -1 is returned.
 */
int _printf(const char *format, ...)
{
	va_list argument;
	int n = 0, i = 0, length = 0;
	char *str;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(argument, format);
	/* error check */
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))/* check if NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && format[2] = '\0')/* check for only % in code */
		return (-1);
	while (format[length] != '\0')
	{
		if (format[length] != '%')
		{
			write(1, &format[length], 1);
			n++;
		}
		else
		{
			length++;
			switch (format[length])
			{
				case 'd':
					handle_int(va_arg(argument, int));
					n++;
					break;
				case 'i':
					handle_int(va_arg(argument, int));
					n++;
					break;
				case '%':
					_putchar(format[length]);
					n++;
					break;
				case 'c':
					_putchar(va_arg(argument, int));
					n++;
					break;
				case 's':
					str = va_arg(argument, char*);
					if ( str == NULL)
					{
						str = "(null)";
					}
					while (str[i] != '\0')
					{
						i++;
					}
					write(1, str, i);
					n += i;
					break;
			}
		}
		length++;
	}
	va_end(argument);

	return (n);
}

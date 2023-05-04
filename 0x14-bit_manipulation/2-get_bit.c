/**
 * get_bit - returns the value of a bit
 * @n: number to check
 * @index: index of the bit to return
 *
 * Return: value of the bit at index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	bit = (n >> index) & 1;

	return (bit);
}



unsigned int Factorial(unsigned int Number)
{
    unsigned int Result = 1;
    if (Number == 0) {
	Result = 1;
    } else {
	while(Number != 0)
	{
	Result *= Number ;
	Number--;

	}
    }

    return (Result);
}

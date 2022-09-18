
void Print_Fibno(unsigned int Number)
{
    unsigned int Result = 0 ,Current =1, Previous =0;
    
    if((0 == Number)||(Number < 0))
    {
	printf("In Valid Input !!!!\n ");
    } 
    else
    {
	while(Result <= Number)
	{
	    printf("%i ",Result);
	    Previous = Current;
	    Current = Result;
	    Result = Current + Previous;
	}
    }
    printf("\n");
}

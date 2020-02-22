/*****




*****/

int GCD(int a, int b)
{
	int i;
	int gcd;
	
	for(i = 1; i <= a && i <= b; ++i)
    {
        if(a % i == 0 && b % i == 0)
            gcd = i;
    }
	
	return gcd;
}
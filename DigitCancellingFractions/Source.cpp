/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include<iostream>
#include<vector>

bool CheckCancel(int num, int den, int i);

using namespace std;

int main()
{
	vector<int> numerators;
	vector<int> denominators;
	for (int den = 1; den < 10; den++)
	{
		for (int num = 1; num < 10; num++)
		{
			for (int i = 1; i < 10; i++)
			{
				if (CheckCancel(num, den, i))
				{
					numerators.push_back(num);
					denominators.push_back(den);
				}
			}
		}
	}

	//Product of the 4 fractions
	int numerator = 1;
	int denominator = 1;
	for (int i = 0; i < numerators.size(); i++)
	{
		numerator *= numerators[i];
		denominator *= denominators[i];
	}
	
	//Reduce the fraction
	int current = 2;
	while (current <= numerator)
	{
		if ((numerator % current == 0) && (denominator % current == 0))
		{
			numerator /= current;
			denominator /= current;
		}
	}

	cout << numerator << "/" << denominator << endl;
	system("pause");
	return 0;
}

bool CheckCancel(int num, int den, int i)
{
	//All possible combinations for the fraction that we want to check
	double num1 = ((10 * num) + i) / ((double)(den * 10) + i);
	double num2 = ((10 * i) + num) / ((double)(i * 10) + den);
	double num3 = ((10 * num) + i) / ((double)(i * 10) + den);
	double num4 = ((10 * i) + num) / ((double)(den * 10) + i);
	
	//Reduced number
	double reduced = num / (double)den;

	//See if the fraction is equivalent to it being reduced
	if (num1 == reduced && num1 < 1.0)
	{
		cout << num << i << "/" << den << i << endl;
		return true;
	}
	else if (num2 == reduced && num2 < 1.0)
	{
		cout << i << num << "/" << i << den << endl;
		return true;
	}
	else if (num3 == reduced && num3 < 1.0)
	{
		cout << num << i << "/" << i << den << endl;
		return true;
	}
	else if (num4 == reduced && num4 < 1.0)
	{
		cout << i << num << "/" << den << i;
		return true;
	}
	else
	{
		return false;
	}
}
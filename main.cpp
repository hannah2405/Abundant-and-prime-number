

// Handout #1: Source code of a C++ Program, which

// converts distance in miles to kilometers.



#include <iostream>  //inclusion of support for doing input & output
#include <string>
using namespace std; //declare access to standard stuff like cin, cout

void menu()
{
	cout << "\n				Menu";
	cout << "\n		A1: Abundant number test\n";
	cout << "		A2: Print all abundant numbers less than n\n";
	cout << "		A3: Find nth abundant number\n\n";
	cout << "		B1: Relatively prime numbers test\n";
	cout << "		B2: Numbers with same prime factors test\n";
	cout << "\n		C1: Print factorization of n\n";
	cout << "\n		D1: Decimal-to-binary conversion\n";
	cout << "		D2: Binary-to-decimal conversion\n";
}

bool abundantTest(int n)
{
	int sum=0;

	//check the value in parameter
	for (int divisor = 1; divisor < n; divisor++)
	{
		if (n%divisor == 0)
			sum = sum + divisor;
	}

	//return true if n is an abundant number
	//return false if n is NOT an abundant number
	if (sum > n)
	{
		return true;
	}
	else
	{
		return false;
	}


} //end of abundantTest function

void printAbundantLessThan(int n)
{
	
	for (int trial = 1; trial < n; trial++)
	{
		int sum = 0;
		for (int divisor = 1; divisor < trial; divisor++)
		{
			if (trial%divisor == 0)
				sum = sum + divisor;
		}
		if (sum > trial)
		{
			cout << trial << " ";
		}
	}
	cout << "\n";
}// end of print abundant less than function

int getTheNthAbundant(int n)
{
	int abundantCount = 0; //count of abundant numbers so far
	int trial=1;

	while (abundantCount<n+1)
	{
		int sum = 0;//sum of the divisors of a number

		for (int divisor=1; divisor < trial; divisor++)
		{
			if (trial%divisor == 0)
				sum = sum + divisor;
		}
		if (sum > trial)
		{
			abundantCount = abundantCount + 1;
		}
		if (abundantCount == n)
		{
			return trial;
			break;
		}

		trial++;
	}	

	cout << "\n";
} //end of nth abundant number function

bool areRelativelyPrime(int n, int m)
{ 
	int min;

	if (m > n)
		min = n;
	if (n > m)
		min = m;

	while (min > 0)
	{
		if (n%min == 0 && m%min == 0)
		{
			return false;
			break;
		}

		min--;
		if (min == 1)
		{
			return true;
			break;
		}
	}
} //End of relatively prime function

bool isPrime(int n)
{
	//Fill in your code for the isPrime function.


	int count = 0; // count of the factors
	int divisor; // number you're dividing with

	//determine and display all the factors of n between 1 and n in an increasing order

	for (divisor = 2; divisor < n; divisor++)
	{
		if (n%divisor == 0)
		{
			count = count + 1;
		}
	}


	if (n == 2)
		return true;	
		
	else if (count > 0)
		return false; // n isn't prime
	else if (n == 1 || n == 0)
		return false;   //n isn't prime
	
	else
		return true;  // n is prime


	//It should return either true or false based on
	// whether n is a prime number.
}

bool sameCollectionOfPrimeFactors(int n, int m)
{
	int min;

	if (m > n)
		min = n;
	if (n > m)
		min = m;

	for (int i = min; i > 1; i--)
	{
		if (isPrime(i) == true)
		{
			if (n%i == 0 && m%i == 0)
			{
				return true;
			}
			else if (n%i != 0 && m%i != 0)
			{
				return true;
			}
			else
			{
				return false;
				break;
			}
		}
	}
}

void  printFactorization(int n)
{
	int k=2; //divisor
	int count = 0;

	while (k <= n)
	{
		if (n%k == 0)
		{
			count = count + 1;
			if (count == 1)
			{
				cout << k;
				n = n / k;
				count = count + 1;
			}
			else if (count > 1)
			{
				cout << "*" << k;
				n = n / k;
			}
		}
		else
			k++;
	}
} // end of factorization function

void  decimal_to_binary()
{
	int n;
	cout << "Enter an integer in the range of 0 to 4095: ";
	cin >> n;
	while (n > 4095 || n < 0)
	{
		cout << "The number needs to be in the range of 0 to 4095: ";
		cin >> n;
	}
	int byte[12];
	int i=0;
	int count=0; //count number of spots used in array 
	int input = n;
	while (i<12)
	{
		if (input % 2 == 0 && input == 0)
		{
			break;
		}
		else if (input % 2 >= 0)
		{
			input = input / 2;
			count = count + 1;
		}
		
		i++;
	}

	for (int i = count; i > -1; i--)
	{
		byte[i] = n % 2;
		n = n / 2;
	}
	for (int i = 0; i < count+1; i++)
	{
		cout << byte[i];
	}
}

void  binary_to_decimal()
{
	int n[12];
	int sum=0; //sum of the weight of bits
	cout << "Enter 12 bits of 0 or 1 one by one\n";
	cout << "Press enter after each bit.\n";

	for (int i = 11; i >-1; i--)
	{
		cin >> n[i];
		while (n[i]>1)
		{
			cout << "Please re-enter the value: ";
			cin >> n[i];
		}
	}

	cout << "Converting ";
	for (int i = 11; i >-1; i--)
	{
		cout << n[i];
	}
	cout << " into a decimal number.";

	if (n[0] == 1)
	{
		sum = sum + 1;
	}
	if (n[1] == 1)
	{
		sum = sum + (2 );
	}
	if (n[2] == 1)
	{
		sum = sum + (2 * 2 );
	}
	if (n[3] == 1)
	{
		sum = sum + (2 * 2 * 2 );
	}
	if (n[4] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2);
	}
	if (n[5] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2);
	}
	if (n[6] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 );
	}
	if (n[7] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 * 2);
	}
	if (n[8] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2);
	}
	if (n[9] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2);
	}
	if (n[10] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2);
	}
	if (n[11] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2);
	}
	if (n[12] == 1)
	{
		sum = sum + (2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2);
	}
	cout << sum;
}

// Beginning of main function
int main()

{
	string option;
	bool isInService = true;

	
	while (isInService == true)
	{

		menu();

		cout << "\nEnter an option: ";
		cin >> option;
		cout << "\n";

		if (option=="A1")
		{
			int n;
			cout << "Enter a natural number: ";
			cin >> n;
			while (n < 1)
			{
				cout << "\nEnter a natural number: ";
				cin >> n;
			}
			if (abundantTest(n) == true)
			{
				cout << n << " is an abundant number.\n";
			}
			else
				cout << n << " is not an abundant number.\n";
		}

		else if (option == "A2")
		{
			int n;
			cout << "Enter a natural number: ";
			cin >> n;
			while (n < 1)
			{
				cout << "\nEnter a natural number: ";
				cin >> n;
			}

			printAbundantLessThan(n);
		}

		else if (option == "A3")
		{
			int n;
			cout << "Enter a natural number: ";
			cin >> n;
			while (n < 1)
			{
				cout << "\nEnter a natural number: ";
				cin >> n;
			}

			cout << getTheNthAbundant(n) << " is the #" << n << " abundant number.\n";
		}

		else if (option == "B1")
		{
			int n,m;
			cout << "Enter a natural number n: ";
			cin >> n;
			while (n < 1)
			{
				cout << "\nEnter a natural number: ";
				cin >> n;
			}

			cout << "Enter a natural number m: ";
			cin >> m;
			while (m < 1)
			{
				cout << "\nEnter a natural number: ";
				cin >> m;
			}
			while (m == n)
			{
				cout << "m has to be a different number: ";
				cin >> m;
			}

			if (areRelativelyPrime(n, m) == true)
			{
				cout << n << " and " << m << " are relatively prime to each other.\n";
			}
			else
				cout << n << " and " << m << " are not relatively prime to each other.\n";
		}
		else if (option == "B2")
		{
			int n, m;
			cout << "Enter a natural number n bigger than 1: ";
			cin >> n;
			while (n < 2)
			{
				cout << "\nn needs to be bigger than 1: ";
				cin >> n;
			}

			cout << "Enter a natural number m bigger than 1: ";
			cin >> m;
			while (m < 2)
			{
				cout << "\nm needs to be bigger than 1: ";
				cin >> m;
			}
			while (m == n)
			{
				cout << "m has to be a different number: ";
				cin >> m;
			}

			if (sameCollectionOfPrimeFactors(n, m) == true)
			{
				cout << n << " and " << m << " have the same collection of prime factors.\n";
			}
			else
				cout << n << " and " << m << " do not have the same collection of prime factors.\n";
		}
		else if (option == "C1")
		{
			int n;
			cout << "Enter a natural number bigger than 1: ";
			cin >> n;
			while (n < 2)
			{
				cout << "\nn needs to be bigger than 1: ";
				cin >> n;
			}

			printFactorization(n);
		}
		else if (option == "D1")
		{
			decimal_to_binary();
		}
		else if (option == "D2")
		{
			binary_to_decimal();
		}
	} //end of while isInService=true

	cin.get();
	cin.get();

	return 0;
}

//End of the main function.




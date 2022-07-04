#include<stdio.h>
/*
Enumeration (or enum) is a user defined data type in C. It is mainly used to 
assign names to integral constants, the names make a program easy to read and maintain.
*/
//Ex:1An example program to demonstrate working of enum in C

enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};

int main()
{
	enum week day;
	day = Wed;
	printf("%d",day); // o/p:2
	return 0;
}

//Two enum names can have same value. For example, in the following C program both
//‘Failed’ and ‘Freezed’ have same value 0.

enum State {Working = 1, Failed = 0, Freezed = 0};

int main()
{
	printf("%d, %d, %d", Working, Failed, Freezed);
	return 0;
}

//If we do not explicitly assign values to enum names, the compiler by default
//assigns values starting from 0. 
enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

int main()
{
	enum day d = thursday;
	printf("The day number stored in d is %d", d); // o/p: The day number stored in d is 4
	return 0;
}

//We can assign values to some name in any order. 
//All unassigned names get value as value of previous name plus one

enum day {sunday = 1, monday, tuesday = 5,
		wednesday, thursday = 10, friday, saturday};

int main()
{
	printf("%d %d %d %d %d %d %d", sunday, monday, tuesday, 
			wednesday, thursday, friday, saturday); //O/p: 1 2 5 6 10 11 12
	return 0;
}



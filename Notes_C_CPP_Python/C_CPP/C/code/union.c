#include <stdio.h>
#include <string.h>

/*
Union is an user defined data type in C programming language.
It is a collection of variables of different data types in the same memory location.
We can define a union with many members, but at a given point of time only one member 
can contain a value.
Unions can be very handy when you need to talk to peripherals through some memory 
mapped registers.
*/
// Ex: 1=> When all data types inside union are same: If one is updated,other will be 
//automatically updated.
union test 
{
	int x, y; //same integer
};
int main() 
{
	union test t;
	t.x = 3; // t.y also gets value 3
	printf ("after fixing x value the coordinates of t will be %d %d\n\n",t.x, t.y);
	t.y = 4; // t.x is also updated to 4
	printf ("After fixing y value the coordinates of t will be %d %d\n\n", t.x, t.y);
	printf("The coordinates of t1 are %d %d",t1.x,t1.y);
	return 0;
}

//Ex:2 When Union has different data types: only last updated data type will have correct
//value:
 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {

   union Data data;        

   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming"); //this value will be correct only

   printf( "data.i : %d\n", data.i); //garbage
   printf( "data.f : %f\n", data.f); //garbage
   printf( "data.str : %s\n", data.str); //C Programming

   return 0;
}

//Ex:3 When Union has different data types: we can use it efficiently if we assign value
//and use it then assign value to other variable and use it to access correct value.
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {

   union Data data;        

   data.i = 10;
   printf( "data.i : %d\n", data.i); //will print correct value 10
   
   data.f = 220.5;
   printf( "data.f : %f\n", data.f); //will print correct value 220.5
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str); //will print correct value C Programming

   return 0;
}
"""
Python is a high-level programming language and is widely being used among the developers community.
Python was mainly developed for emphasis on code readability, and its syntax allows programmers to express concepts in fewer lines of code.
"""
#Python Indentation:
#Python uses indentation to highlight the blocks of code. Whitespace is used for indentation in Python.

#Python Comments:
	#Single line comments: Python single line comment starts with hash tag symbol with no white spaces.
	# This is a comment 
	#Multi-line string as comment: Python multi-line comment is a piece of text enclosed in a delimiter (''') on each end of the comment.
""" 
This would be a multiline comment in Python that...
"""
#-----------------------------------------------------------------------------------------------------------------------------------------------
                                #Variables:
#We do not need to declare variables before using them or declare their type. A variable is created the moment we first assign a value to it.

# An integer assignment 
age = 45                     
   
# A floating point 
salary = 1456.8            
   
# A string   
name = "John"             
   
print(age) 
print(salary) 
print(name) 

#-----------------------------------------------------------------------------------------------------------------------------------------------
                                   # Operators:
#Arithmetic operators: Arithmetic operators are used to perform mathematical operations like addition, subtraction, multiplication and division.
# Examples of Arithmetic Operator 
a = 9
b = 4
   
# Addition of numbers 
add = a + b 
# Subtraction of numbers  
sub = a - b 
   
# print results 
print(add) 
print(sub) 

#Relational Operators: Relational operators compares the values. It either returns True or False according to the condition:
# Examples of Relational Operators 
a = 13
b = 33
   
# a > b is False 
print(a > b) 
   
# a < b is True 
print(a < b) 
   
# a == b is False 
print(a == b) 
   
# a != b is True 
print(a != b) 
   
# a >= b is False 
print(a >= b) 
   
# a <= b is True 
print(a <= b)


#Logical Operators: Logical operators perform Logical AND, Logical OR and Logical NOT operations.
# Examples of Logical Operator 
a = True
b = False
   
# Print a and b is False 
print(a and b) 
   
# Print a or b is True 
print(a or b) 
   
# Print not a is False 
print(not a) 

#Bitwise operators: Bitwise operator acts on bits and performs bit by bit operation.
# Examples of Bitwise operators 
a = 10
b = 4
   
# Print bitwise AND operation   
print(a & b) 
   
# Print bitwise OR operation 
print(a | b) 
   
# Print bitwise NOT operation  
print(~a) 
   
# print bitwise XOR operation  
print(a ^ b) 
   
# print bitwise right shift operation  
print(a >> 2) 
   
# print bitwise left shift operation  
print(a << 2)

#Assignment operators: Assignment operators are used to assign values to the variables.
#Special operators: Special operators are of two types-

#Identity operator that contains is and is not.
#Membership operator that contains in and not in.

# Examples of Identity and 
# Membership operator
  
a1 = 'GeeksforGeeks'
b1 = 'GeeksforGeeks'
 
# Identity operator
print(a1 is not b1)
print(a1 is b1)
 
# Membership operator
print("G" in a1)
print("N" not in b1)

#-----------------------------------------------------------------------------------------------------------------------------------------------

					#Taking input from user
#input(): This function first takes the input from the user and then evaluates the expression, which means Python automatically identifies whether the user entered 
#a string or a number or list. For example:
# Python program showing a use of input() 
   
val = input("Enter your value: ") 
print(val)

#-----------------------------------------------------------------------------------------------------------------------------------------------
                           #Printing output to console
# One object is passed 
print("GeeksForGeeks") 
   
x = 5
# Two objects are passed 
print("x =", x) 
   
# code for disabling the soft space feature  
#print('G', 'F', 'G', sep ='') 
   
# using end argument 
#print("Python", end = '@')   
#print("GeeksforGeeks")  Python@GeeksforGeeks

#-----------------------------------------------------------------------------------------------------------------------------------------------
					#Python Data Types
# Numeric(Integer, Float) --> In Python, numeric data type represent the data which has numeric value. Numeric value can be interger, 
# floating number or even complex numbers. These values are defined as int, float and complex.
print("Type of a: ", type(5)) 
print("\nType of b: ", type(5.0)) 
# Dictionary->
# Boolean 
# Set
# Sequence Type ----> Strings, List, Tuples

#-----------------------------------------------------------------------------------------------------------------------------------------------
# String: A string is a collection of one or more characters put in a single quote, double-quote or triple quote. 
# In python there is no character data type, a character is a string of length one. It is represented by str class. 
# Strings in Python can be created using single quotes or double quotes or even triple quotes.
#      				0  1  2  3  4  5  6  7  8  9  10
#      				A  N  K  I  T  S  H  U  K  L  A
#     				-11-10 -9 -8 -7 -6 -5 -4 -3 -2 -1 

#Creating a String
String1 = "GeeksForGeeks"
     
#Accessing characters in Python	 
# Printing First character 
print(String1[0])  
     
# Printing Last character 
print(String1[-1])  

String1 = "Hello, I'm a Geek"
     
# Updating a character, will throw an error.
#String1[2] = 'p' //can not modify character by index.
   
# Deleting a character using del will throw an error.  
#del String1[2]

#String Slicing
#To access a range of characters in the String, method of slicing is used. 
#Slicing in a String is done by using a Slicing operator (colon). 
String1 = "GeeksForGeeks"
# Printing 3rd to 12th character
print("\nSlicing characters from 3-12: ")
print(String1[3:12])

# Printing characters between
# 3rd and 2nd last character
print("\nSlicing characters between " +
    "3rd and 2nd last character: ")
print(String1[3:-2])

#Updating Entire String:
String1 = "Hello, I'm a Geek"
String1 = "Welcome to the Geek World"
print(String1)


#-----------------------------------------------------------------------------------------------------------------------------------------------
#Lists in Python can be created by just placing the sequence inside the square brackets[].
#Unlike Sets, list does not need a built-in function for creation of list.
#Note  Unlike Sets, list may contain mutable elements.
  
# Creating a List
List = []
print("Blank List: ")
print(List)
  
# Creating a List of numbers
List = [10, 20, 14]
print("\nList of numbers: ")
print(List)
  
# Creating a List of strings and accessing using index
List = ["Geeks", "For", "Geeks"]
print("\nList Items: ")
print(List[0]) 
print(List[2])
  
# Creating a Multi-Dimensional List (By Nesting a list inside a List)
List = [['Geeks', 'For'] , ['Geeks']]
print("\nMulti-Dimensional List: ")
print(List)
'''
Output:
Blank List: 
[]

List of numbers: 
[10, 20, 14]

List Items
Geeks
Geeks

Multi-Dimensional List: 
[['Geeks', 'For'], ['Geeks']]
'''

#Creating a list with multiple distinct or duplicate elements
#A list may contain duplicate values with their distinct positions and hence, multiple
#distinct or duplicate values can be passed as a sequence at the time of list creation.

# Creating a List with 
# the use of Numbers
# (Having duplicate values)
List = [1, 2, 4, 4, 3, 3, 3, 6, 5]
print("\nList with the use of Numbers: ")
print(List)
  
# Creating a List with mixed type of values
List = [1, 2, 'Geeks', 4, 'For', 6, 'Geeks']
print("\nList with the use of Mixed Values: ")
print(List)

'''
Output:
List with the use of Numbers: 
[1, 2, 4, 4, 3, 3, 3, 6, 5]

List with the use of Mixed Values: 
[1, 2, 'Geeks', 4, 'For', 6, 'Geeks']
'''

#Knowing the size of List
# Creating a List
List1 = []
print(len(List1))
  
# Creating a List of numbers
List2 = [10, 20, 14]
print(len(List2))

#Adding Elements to a List
#Using append() method
#Elements can be added to the List by using built-in append() function.
#Only one element at a time can be added to the list by using append() method,
#for addition of multiple elements with the append() method, loops are used. 
#Tuples can also be added to the List with the use of append method because tuples
#are immutable. Unlike Sets, Lists can also be added to the existing list with 
#the use of append() method.

# Creating a List
List = []
print("Initial blank List: ")
print(List)
  
# Addition of Elements 
# in the List
List.append(1)
List.append(2)
List.append(4)
print("\nList after Addition of Three elements: ")
print(List)
  
# Adding elements to the List
# using Iterator
for i in range(1, 4):
    List.append(i)
print("\nList after Addition of elements from 1-3: ")
print(List)
  
# Adding Tuples to the List
List.append((5, 6))
print("\nList after Addition of a Tuple: ")
print(List)
  
# Addition of List to a List
List2 = ['For', 'Geeks']
List.append(List2)
print("\nList after Addition of a List: ")
print(List)

'''
Output:
Initial blank List: 
[]

List after Addition of Three elements: 
[1, 2, 4]

List after Addition of elements from 1-3: 
[1, 2, 4, 1, 2, 3]

List after Addition of a Tuple: 
[1, 2, 4, 1, 2, 3, (5, 6)]

List after Addition of a List: 
[1, 2, 4, 1, 2, 3, (5, 6), ['For', 'Geeks']]
'''

#Using insert() method
#append() method only works for addition of elements at the end of the List,
#for addition of element at the desired position, insert() method is used. 
#Unlike append() which takes only one argument, insert() method requires two 
#arguments(position, value).

# Creating a List
List = [1,2,3,4]
print("Initial List: ")
print(List)
  
# Addition of Element at 
# specific Position
# (using Insert Method)
List.insert(3, 12)
List.insert(0, 'Geeks')
print("\nList after performing Insert Operation: ")
print(List)
'''
Output:
Initial List: 
[1, 2, 3, 4]

List after performing Insert Operation: 
['Geeks', 1, 2, 3, 12, 4]

'''
#Using extend() method
#Other than append() and insert() methods, there is one more method for Addition 
#of elements, extend(), this method is used to add multiple elements at the same 
#time at the end of the list.
#Note  append() and extend() methods can only add elements at the end.
    
# Creating a List
List = [1,2,3,4]
print("Initial List: ")
print(List)
  
# Addition of multiple elements
# to the List at the end
# (using Extend Method)
List.extend([8, 'Geeks', 'Always'])
print("\nList after performing Extend Operation: ")
print(List)
'''
Output:
Initial List: 
[1, 2, 3, 4]

List after performing Extend Operation: 
[1, 2, 3, 4, 8, 'Geeks', 'Always']
'''

#Accessing elements from the List
#In order to access the list items refer to the index number. 
#Use the index operator [ ] to access an item in a list.
#The index must be an integer.Nested list are accessed using nested indexing.

# Creating a List with the use of multiple values
List = ["Geeks", "For", "Geeks"]
  
# accessing a element from the 
# list using index number
print("Accessing a element from the list")
print(List[0]) 
print(List[2])
  
# Creating a Multi-Dimensional List
# (By Nesting a list inside a List)
List = [['Geeks', 'For'] , ['Geeks']]
  
# accessing an element from the 
# Multi-Dimensional List using
# index number
print("Accessing a element from a Multi-Dimensional list")
print(List[0][1])
print(List[1][0])
'''
Output:
Accessing a element from the list
Geeks
Geeks
Accessing a element from a Multi-Dimensional list
For
Geeks
'''

#Negative indexing
#In Python, negative sequence indexes represent positions from the end of the array. 
#Instead of having to compute the offset as in List[len(List)-3], it is enough 
#to just write List[-3]. Negative indexing means beginning from the end, -1 refers 
#to the last item, -2 refers to the second-last item, etc.


List = [1, 2, 'Geeks', 4, 'For', 6, 'Geeks']
  
# accessing an element using
# negative indexing
print("Accessing element using negative indexing")
  
# print the last element of list
print(List[-1])
  
# print the third last element of list 
print(List[-3])
'''
Output:
Accessing element using negative indexing
Geeks
For
'''
#Removing Elements from the List
#Using remove() method
#Elements can be removed from the List by using built-in remove() function but an Error
#arises if element does not exist in the set. Remove() method only removes one element at a time, 
#to remove range of elements, iterator is used. The remove() method removes the specified item.

#Note  Remove method in List will only remove the first occurrence of the searched element.
  
# Creating a List
List = [1, 2, 3, 4, 5, 6, 
        7, 8, 9, 10, 11, 12]
print("Initial List: ")
print(List)
  
# Removing elements from List
# using Remove() method
List.remove(5)
List.remove(6)
print("\nList after Removal of two elements: ")
print(List)
  
# Removing elements from List
# using iterator method
for i in range(1, 5):
    List.remove(i)
print("\nList after Removing a range of elements: ")
print(List)

'''
Output:
Initial List: 
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

List after Removal of two elements: 
[1, 2, 3, 4, 7, 8, 9, 10, 11, 12]

List after Removing a range of elements: 
[7, 8, 9, 10, 11, 12]

'''

#Using pop() method
#Pop() function can also be used to remove and return an element from the set, 
#but by default it removes only the last element of the set, to remove element 
#from a specific position of the List, index of the element is passed as an argument
#to the pop() method.

List = [1,2,3,4,5]
  
# Removing element from the 
# Set using the pop() method
List.pop()
print("\nList after popping an element: ")
print(List)
  
# Removing element at a 
# specific location from the 
# Set using the pop() method
List.pop(2)
print("\nList after popping a specific element: ")
print(List)
'''
Output:
List after popping an element: 
[1, 2, 3, 4]

List after popping a specific element: 
[1, 2, 4]
'''

#Slicing of a List
#In Python List, there are multiple ways to print the whole List with all the elements,
#but to print a specific range of elements from the list, we use Slice operation.
#Slice operation is performed on Lists with the use of a colon(:). 
#To print elements from beginning to a range use [: Index], to print elements 
#from end-use [:-Index], to print elements from specific Index till the end use [Index:], to print elements within a range, use [Start Index:End Index] and to print the whole List with the use of slicing operation, use [:]. Further, to print the whole List in reverse order, use [::-1].
#Note  To print elements of List from rear end, use Negative Indexes.

# Creating a List
List = ['G','E','E','K','S','F',
        'O','R','G','E','E','K','S']
print("Initial List: ")
print(List)
  
# Print elements of a range
# using Slice operation
Sliced_List = List[3:8]
print("\nSlicing elements in a range 3-8: ")
print(Sliced_List)
  
# Print elements from a 
# pre-defined point to end
Sliced_List = List[5:]
print("\nElements sliced from 5th "
      "element till the end: ")
print(Sliced_List)
  
# Printing elements from
# beginning till end
Sliced_List = List[:]
print("\nPrinting all elements using slice operation: ")
print(Sliced_List)
'''
Output:
Initial List: 
['G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S']

Slicing elements in a range 3-8: 
['K', 'S', 'F', 'O', 'R']

Elements sliced from 5th element till the end: 
['F', 'O', 'R', 'G', 'E', 'E', 'K', 'S']

Printing all elements using slice operation: 
['G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S']
'''
#Negative index List slicing
# Creating a List
List = ['G','E','E','K','S','F',
        'O','R','G','E','E','K','S']
print("Initial List: ")
print(List)
  
# Print elements from beginning
# to a pre-defined point using Slice
Sliced_List = List[:-6]
print("\nElements sliced till 6th element from last: ")
print(Sliced_List)
  
# Print elements of a range
# using negative index List slicing
Sliced_List = List[-6:-1]
print("\nElements sliced from index -6 to -1")
print(Sliced_List)
  
# Printing elements in reverse
# using Slice operation
Sliced_List = List[::-1]
print("\nPrinting List in reverse: ")
print(Sliced_List)
'''
Output:

Initial List: 
['G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S']

Elements sliced till 6th element from last: 
['G', 'E', 'E', 'K', 'S', 'F', 'O']

Elements sliced from index -6 to -1
['R', 'G', 'E', 'E', 'K']

Printing List in reverse: 
['S', 'K', 'E', 'E', 'G', 'R', 'O', 'F', 'S', 'K', 'E', 'E', 'G']
'''
#-------------------------------------------------------------------------------------
#Tuple is a collection of Python objects much like a list. The sequence of values stored in a tuple can be of any type, and they are indexed by integers. 
#Values of a tuple are syntactically separated by commas. Although it is not necessary, it is more common to define a tuple by closing the sequence of values in parentheses. This helps in understanding the Python tuples more easily.
#Creating a Tuple
#In Python, tuples are created by placing a sequence of values separated by comma with or without the use of parentheses for grouping the data sequence.
#Note: Creation of Python tuple without the use of parentheses is known as Tuple Packing. 
 
#Creating an empty Tuple
Tuple1 = ()
print("Initial empty Tuple: ")
print (Tuple1)
 
#Creating a Tuple with the use of string
Tuple1 = ('Geeks', 'For')
print("\nTuple with the use of String: ")
print(Tuple1)
 
# Creating a Tuple with the use of list
list1 = [1, 2, 4, 5, 6]
print("\nTuple using List: ")
print(tuple(list1))
 
#Creating a Tuple with the use of built-in function
Tuple1 = tuple('Geeks')
print("\nTuple with the use of function: ")
print(Tuple1)
'''
Output: 
Initial empty Tuple: 
()

Tuple with the use of String: 
('Geeks', 'For')

Tuple using List: 
(1, 2, 4, 5, 6)

Tuple with the use of function: 
('G', 'e', 'e', 'k', 's')
'''
 
#Creating a Tuple with Mixed Datatypes.
#Tuples can contain any number of elements and of any datatype (like strings, integers, list, etc.). 
#Tuples can also be created with a single element, but it is a bit tricky. 
#Having one element in the parentheses is not sufficient, there must be a trailing comma to make it a tuple.
 
#Creating a Tuple with Mixed Datatype
Tuple1 = (5, 'Welcome', 7, 'Geeks')
print("\nTuple with Mixed Datatypes: ")
print(Tuple1)
 
#Creating a Tuple with nested tuples
Tuple1 = (0, 1, 2, 3)
Tuple2 = ('python', 'geek')
Tuple3 = (Tuple1, Tuple2)
print("\nTuple with nested tuples: ")
print(Tuple3)
 
#Creating a Tuple with repetition
Tuple1 = ('Geeks',) * 3
print("\nTuple with repetition: ")
print(Tuple1)
 
#Creating a Tuple with the use of loop
Tuple1 = ('Geeks')
n = 5
print("\nTuple with a loop")
for i in range(int(n)):
    Tuple1 = (Tuple1,)
    print(Tuple1)
	
'''	
Output: 
 

Tuple with Mixed Datatypes: 
(5, 'Welcome', 7, 'Geeks')

Tuple with nested tuples: 
((0, 1, 2, 3), ('python', 'geek'))

Tuple with repetition: 
('Geeks', 'Geeks', 'Geeks')

Tuple with a loop
('Geeks',)
(('Geeks',),)
((('Geeks',),),)
(((('Geeks',),),),)
((((('Geeks',),),),),)
 '''

#Accessing of Tuples
#Tuples are immutable, and usually, they contain a sequence of heterogeneous elements 
#that are accessed via unpacking or indexing (or even by attribute in the case of named
# tuples). Lists are mutable, and their elements are usually homogeneous and are 
#accessed by iterating over the list.
#Note: In unpacking of tuple number of variables on the left-hand side should be equal to a number of values in given tuple a.
 
#Accessing Tuple with Indexing
Tuple1 = tuple("Geeks")
print("\nFirst element of Tuple: ")
print(Tuple1[1])
 
 
#Tuple unpacking
Tuple1 = ("Geeks", "For", "Geeks")
 
#This line unpack values of Tuple1
a, b, c = Tuple1
print("\nValues after unpacking: ")
print(a)
print(b)
print(c)
'''
Output: 
First element of Tuple:
e

Values after unpacking:
Geeks
For
Geeks
'''

#Concatenation of Tuples
#Concatenation of tuple is the process of joining two or more Tuples. Concatenation is done by the use of + operator. Concatenation of tuples is done always from the end of the original tuple. Other arithmetic operations do not apply on Tuples. 
#Note- Only the same datatypes can be combined with concatenation, an error arises if a list and a tuple are combined. 
 
# Concatenation of tuples
Tuple1 = (0, 1, 2, 3)
Tuple2 = ('Geeks', 'For', 'Geeks')
 
Tuple3 = Tuple1 + Tuple2
 
# Printing first Tuple
print("Tuple 1: ")
print(Tuple1)
 
# Printing Second Tuple
print("\nTuple2: ")
print(Tuple2)
 
# Printing Final Tuple
print("\nTuples after Concatenation: ")
print(Tuple3)

'''
Output: 

Tuple 1: 
(0, 1, 2, 3)

Tuple2: 
('Geeks', 'For', 'Geeks')

Tuples after Concatenation: 
(0, 1, 2, 3, 'Geeks', 'For', 'Geeks')
 '''

#Slicing of Tuple
#Slicing of a Tuple is done to fetch a specific range or slice of sub-elements from a Tuple. Slicing can also be done to lists and arrays. Indexing in a list results to fetching a single element whereas Slicing allows to fetch a set of elements. 
#Note- Negative Increment values can also be used to reverse the sequence of Tuples 
 
# Slicing of a Tuple with Numbers
Tuple1 = tuple('GEEKSFORGEEKS')
 
# Removing First element
print("Removal of First Element: ")
print(Tuple1[1:])
 
# Reversing the Tuple
print("\nTuple after sequence of Element is reversed: ")
print(Tuple1[::-1])
 
# Printing elements of a Range
print("\nPrinting elements between Range 4-9: ")
print(Tuple1[4:9])
'''
Output: 

Removal of First Element: 
('E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S')

Tuple after sequence of Element is reversed: 
('S', 'K', 'E', 'E', 'G', 'R', 'O', 'F', 'S', 'K', 'E', 'E', 'G')

Printing elements between Range 4-9: 
('S', 'F', 'O', 'R', 'G')
 '''

#Deleting a Tuple
#Tuples are immutable and hence they do not allow deletion of a part of it. The entire tuple gets deleted by the use of del() method. 
#Note- Printing of Tuple after deletion results in an Error. 
 
# Deleting a Tuple
 
Tuple1 = (0, 1, 2, 3, 4)
del Tuple1
 
#print(Tuple1)
'''
error:
Traceback (most recent call last): 
File /home/efa50fd0709dec08434191f32275928a.py, line 7, in 
print(Tuple1) 
NameError: name Tuple1 is not defined
'''
#-----------------------------------------------------------------------------------
# Boolean
# Booleans are data type with one of the two built-in values, True or False. It is denoted by the class bool.
# Python program to demonstrate boolean type 
   
print(type(True)) 
print(1>2)
print('a'=='a')
'''
Output:

<class 'bool'>
False
True
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Set
# In Python, Set is an unordered collection of data type that is iterable, mutable and has no duplicate elements. The order of elements in a set is undefined though it may consist of various elements. Sets can be created by using the built-in set() function with an iterable object or a sequence by placing the sequence inside curly braces {}, separated by comma.
# Python program to demonstrate Creation of Set in Python  
     
# Creating a Set  
set1 = set()  
 
# Creating a Set of String  
set1 = set("GeeksForGeeks") 
print(set1)  
   
# Creating a Set of List  
set1 = set(["Geeks", "For", "Geeks"])
print(set1)  
'''
Output:

{'o', 'r', 'k', 'G', 'e', 's', 'F'}
{'Geeks', 'For'}
'''
# Adding elements: Using add() and update()
# Python program to demonstrate Addition of elements in a Set  
  
set1 = set()
     
# Adding to the Set using add() 
set1.add(8)
set1.add((6, 7))
print(set1)  
   
# Additio to the Set using Update()   
set1.update([10, 11])
print(set1) 
'''
Output:

{8, (6, 7)}
{8, 10, 11, (6, 7)}
'''
# Accessing a Set: One can loop through the set items using a for loop as set items cannot be accessed by referring to an index.
# Python program to demonstrate Accessing of elements in a set  
     
# Creating a set  
set1 = set(["Geeks", "For", "Geeks"])  
 
# Accessing using for loop
for i in set1:  
    print(i)
'''
Output:

Geeks For
''' 

# Removing elements from a set: Using remove(), discard(), pop() and clear()
# Python program to demonstrate Deletion of elements in a Set  
 
set1 = set([1, 2, 3, 4, 5, 6,   
            7, 8, 9, 10, 11, 12])  
 
# using Remove() method  
set1.remove(5)  
set1.remove(6)
print(set1)  
 
# using Discard() method  
set1.discard(8)  
set1.discard(9)
print(set1)  
 
# Set using the pop() method  
set1.pop()
print(set1)  
 
# Set using clear() method  
set1.clear()
print(set1) 
'''
Output:

{1, 2, 3, 4, 7, 8, 9, 10, 11, 12}
{1, 2, 3, 4, 7, 10, 11, 12}
{2, 3, 4, 7, 10, 11, 12}
set()
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Dictionary
# Dictionary in Python is an unordered collection of data values, used to store data values like a map. Dictionary holds key:value pair. Each key-value pair in a Dictionary is separated by a colon :, whereas each key is separated by a comma. A Dictionary can be created by placing a sequence of elements within curly {} braces, separated by comma.
# Creating an empty Dictionary  
Dict = {}
print(Dict)  
 
# with Integer Keys  
Dict = {1: 'Geeks', 2: 'For', 3: 'Geeks'}
print(Dict)  
 
# with Mixed keys  
Dict = {'Name': 'Geeks', 1: [1, 2, 3, 4]}
print(Dict) 
'''
Output:

{}
{1: 'Geeks', 2: 'For', 3: 'Geeks'}
{1: [1, 2, 3, 4], 'Name': 'Geeks'}
'''

#Nested-Dictionary
# Creating a Nested Dictionary  
# as shown in the below image 
Dict = {1: 'Geeks', 2: 'For',  
        3:{'A' : 'Welcome', 'B' : 'To', 'C' : 'Geeks'}} 
   
print(Dict)  
'''
Output:

{1: 'Geeks', 2: 'For', 3: {'A': 'Welcome', 'B': 'To', 'C': 'Geeks'}}
'''

# Adding elements to a Dictionary: One value at a time can be added to a Dictionary by defining value along with the key e.g. Dict[Key] = Value.
# Creating an empty Dictionary 
Dict = {}
   
# Adding elements one at a time 
Dict[0] = 'Geeks'
Dict[2] = 'For'
Dict[3] = 1
print(Dict) 
 
   
# Updating existing Key's Value 
Dict[2] = 'Welcome'
print(Dict) 
'''
Output:

{0: 'Geeks', 2: 'For', 3: 1}
{0: 'Geeks', 2: 'Welcome', 3: 1}
'''

# Accessing elements from a Dictionary: In order to access the items of a dictionary refer to its key name or use get() method.
# Python program to demonstrate accessing an element from a Dictionary   
     
# Creating a Dictionary   
Dict = {1: 'Geeks', 'name': 'For', 3: 'Geeks'}  
     
# accessing a element using key
print(Dict['name'])  
   
# accessing a element using get()
print(Dict.get(3)) 
'''
Output:

For
Geeks
'''
# Removing Elements from Dictionary: Using pop() and popitem()
# Initial Dictionary  
Dict = { 5 : 'Welcome', 6 : 'To', 7 : 'Geeks',  
        'A' : {1 : 'Geeks', 2 : 'For', 3 : 'Geeks'},
       }  
     
# using pop()  
Dict.pop(5) 
print(Dict)  
 
# using popitem()  
Dict.popitem() 
print(Dict)  

'''
Output:

{'A': {1: 'Geeks', 2: 'For', 3: 'Geeks'}, 6: 'To', 7: 'Geeks'}
{6: 'To', 7: 'Geeks'}
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Decision Making
# Decision Making in programming is similar to decision making in real life. A programming language uses control statements to control the flow of execution of the program based on certain conditions. These are used to cause the flow of execution to advance and branch based on changes to the state of a program.

# Decision-making statements in Python
#    if statement
#    if..else statements
#    nested if statements
#    if-elif ladder

#Example 1: To demonstrate if and if-else
# Python program to demonstrate
# decision making
 
a = 10
b = 15
 
# if to check even number
if a % 2 == 0:
    print("Even Number")
     
# if-else to check even or odd
if b % 2 == 0:
    print("Even Number")
else:
    print("Odd Number")
'''
Output:

Even Number
Odd Number
'''

# Example 2: To demonstrate nested-if and if-elif
# Python program to demonstrate
# decision making
 
a = 10
 
# Nested if to check whether a 
# number is divisible by both 2 and 5
if a % 2 == 0:
    if a % 5 == 0:
        print("Number is divisible by both 2 and 5")
         
# is-elif
if (a == 11): 
    print ("a is 11") 
elif (a == 10): 
    print ("a is 10")
else: 
    print ("a is not present")
'''
Output:

Number is divisible by both 2 and 5
a is 10
'''
#-----------------------------------------------------------------------------------------------------------------------------------------------

# Control flow (Loops)
# Loops in programming come into use when we need to repeatedly execute a block of statements. For example: Suppose we want to print 'Hello World' 10 times. 
# This can be done with the help of loops. The loops in Python are:

# Python program to illustrate  
# while and while-else loop
i = 0
while (i < 3):      
    i = i + 1
    print("Hello Geek")  
   
# checks if list still 
# contains any element  
a = [1, 2, 3, 4] 
while a: 
    print(a.pop()) 
   
i = 10
while i < 12:  
    i += 1
    print(i)  
    break
else: # Not executed as there is a break  
    print("No Break") 
'''
Output:

Hello Geek
Hello Geek
Hello Geek
4
3
2
1
11
'''
# For and for-else loop

# for-loop-python
# Python program to illustrate  
# Iterating over a list  
print("List Iteration")  
l = ["geeks", "for", "geeks"]  
for i in l:  
    print(i) 
     
# Iterating over a String  
print("\nString Iteration")      
s = "Geeks"
for i in s :  
    print(i)  
     
print("\nFor-else loop")
for i in s:  
    print(i)  
else: # Executed because no break in for  
    print("No Break\n")  
   
for i in s:  
    print(i)  
    break
else: # Not executed as there is a break  
    print("No Break")  
'''
Output:

List Iteration
geeks
for
geeks

String Iteration
G
e
e
k
s

For-else loop
G
e
e
k
s
No Break

G
'''
#-----------------------------------------------------------------------------------------------------------------------------------------------

# Loop control statements
# Loop control statements change execution from its normal sequence. Following are the loop control statements provided by Python:
# Break: Break statement in Python is used to bring the control out of the loop when some external condition is triggered.
# Continue: Continue statement is opposite to that of break statement, instead of terminating the loop, it forces to execute the next iteration of the loop.
# Pass: Pass statement is used to write empty loops. Pass is also used for empty control statement, function and classes.

# Python program to demonstrate break, continue and pass 
   
s = 'geeksforgeeks'
 
for letter in s: 
    if letter == 'e' or letter == 's': 
        break
    print(letter)
print()
 
for letter in s: 
    if letter == 'e' or letter == 's': 
        continue
    print(letter)
print()    
 
for letter in s: 
    if letter == 'e' or letter == 's': 
        pass
    print(letter)
'''
Output:

g 
g k f o r g k 
g e e k s f o r g e e k s 
'''
#-----------------------------------------------------------------------------------------------------------------------------------------------

# Functions
# Functions are generally the block of codes or statements in a program that gives the user the ability to reuse the same code which ultimately saves the excessive use of memory, acts as a time saver and more importantly, provides better readability of the code. So basically, a function is a collection of statements that perform some specific task and return the result to the caller. A function can also perform some specific task without returning anything. In Python, def keyword is used to create functions.
# Python program to demonstrate
# functions
 
 
# Defining functions
def ask_user():
    print("Hello Geeks")
 
# Function that returns sum
# of first 10 numbers
def my_func():
    a = 0
    for i in range(1, 11):
        a = a + i
    return a
     
# Calling functions
ask_user()
res = my_func()
print(res)
'''
Output:

Hello Geeks
55
'''


# Function with arguments
# Default arguments: A default argument is a parameter that assumes a default value if a value is not provided in the function call for that argument.
# Python program to demonstrate default arguments 
     
     
def myFun(x, y = 50): 
   print("x: ", x) 
   print("y: ", y) 
       
# Driver code
myFun(10)

'''
Output:

('x: ', 10)
('y: ', 50)
'''

# Keyword arguments: The idea is to allow caller to specify argument name with values so that caller does not need to remember order of parameters.
# Python program to demonstrate Keyword Arguments 
def student(firstname, lastname):  
     print(firstname, lastname)  
     
     
# Keyword arguments                   
student(firstname ='Geeks', lastname ='Practice')     
student(lastname ='Practice', firstname ='Geeks') 

'''
Output:

('Geeks', 'Practice')
('Geeks', 'Practice')
'''

# Variable length arguments: In Python a function can also have variable number of arguments. This can be used in the case when we do not know in advance the number of arguments that will be passed into a function.
# Python program to demonstrate
# variable length arguments
 
 
# variable arguments
def myFun1(*argv):  
    for arg in argv:  
        print(arg) 
         
# variable keyword arguments
def myFun2(**kwargs):
    for key, value in kwargs.items(): 
        print ("% s == % s" %(key, value)) 
   
# Driver code 
myFun1('Hello', 'Welcome', 'to', 'GeeksforGeeks')
print()
myFun2(first ='Geeks', mid ='for', last ='Geeks')
'''
Output:

Hello Welcome to GeeksforGeeks 
first == Geeks
last == Geeks
mid == for
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Lambda functions
# In Python, the lambda/anonymous function means that a function is without a name. The lambda keyword is used to create anonymous functions. Lambda function can have any number of arguments but has only one expression.
# Python code to demonstrate   
# labmda function  
 
# Cube using lambda
cube = lambda x: x * x*x  
print(cube(7))
 
# List comprehension using lambda
a = [(lambda x: x * 2)(x) for x in range(5)]
print(a)
'''
Output:

343
[0, 2, 4, 6, 8]
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Object Oriented Programming
# Object-oriented programming aims to implement real-world entities like inheritance, hiding, polymorphism, etc in programming. 
# The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function

# Classes and Objects
# Class creates a user-defined data structure, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object.
# An Object is an instance of a Class. A class is like a blueprint while an instance is a copy of the class with actual values.
# Python program to demonstrate classes and objects
   
class Dog:  
       
    # A simple class attribute
    attr1 = "mamal"
    attr2 = "dog"
   
    # A sample method   
    def fun(self):  
        print("I'm a", self.attr1) 
        print("I'm a", self.attr2) 
   
# Driver code 
# Object instantiation 
Rodger = Dog() 
   
# Accessing class attributes 
# and method through objects 
print(Rodger.attr1) 
Rodger.fun()
'''
Output:

mamal
I'm a mamal
I'm a dog
'''
#-----------------------------------------------------------------------------------------------------------------------------------------------

# The self
# self represents the instance of the class. By using the self keyword we can access the attributes and methods of the class in python. It binds the attributes with the given arguments.
# Note: For more information, refer self in Python class.
# Constructors and Destructor

# Constructors: Constructors are generally used for instantiating an object.The task of constructors is to initialize(assign values) to the data members of the class when an object of class is created. In Python the __init__() method is called the constructor and is always called when an object is created. There can be two types of constructors:
# Default constructor: The constructor which is called implicilty and do not accept any argument.
# Parameterized constructor:Constructor which is called explicitly with parameters is known as parameterized constructor.

# Python program to demonstrate constructors
 
 
class Addition:
    # parameterized constructor 
    def __init__(self, f, s): 
        self.first = f 
        self.second = s
   
    def calculate(self):
        print(self.first + self.second)
   
# Invoking parameterized constructor
obj = Addition(1000, 2000) 
   
# perform Addition 
obj.calculate() 

'''
Output:

3000
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------
# Destructors: Destructors are called when an object gets destroyed. The __del__() method is a known as a destructor method in Python. It is called when all references to the object have been deleted i.e when an object is garbage collected.
# Python program to illustrate destructor 
class Employee: 
   
    # Initializing 
    def __init__(self): 
        print('Employee created.') 
   
    # Deleting (Calling destructor) 
    def __del__(self): 
        print('Destructor called, Employee deleted.') 
   
obj = Employee() 
del obj 

'''
Output:

Employee created.
Destructor called, Employee deleted.
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Inheritance
# Inheritance is the ability of any class to extract and use features of other classes. It is the process by which new classes called the derived classes are created from existing classes called Base classes.
# A Python program to demonstrate inheritance  
   
 
class Person(): 
       
    # Constructor 
    def __init__(self, name): 
        self.name = name 
   
    # To get name 
    def getName(self): 
        return self.name 
   
    # To check if this person is employee 
    def isEmployee(self): 
        return False
   
   
# Inherited or Sub class (Note Person in bracket) 
class Employee(Person): 
   
    # Here we return true 
    def isEmployee(self): 
        return True
   
# Driver code 
emp = Person("Geek1")  # An Object of Person 
print(emp.getName(), emp.isEmployee()) 
   
emp = Employee("Geek2") # An Object of Employee 
print(emp.getName(), emp.isEmployee())

'''
Output:

Geek1 False
Geek2 True
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Encapsulation
# Encapsulation describes the idea of wrapping data and the methods that work on data within one unit. This puts restrictions on accessing variables and methods directly and can prevent the accidental modification of data.
# Python program to demonstrate encapsulation 
   
# Creating a Base class 
class Base: 
    def __init__(self): 
        self.a = "GeeksforGeeks"
        self.__c = "GeeksforGeeks"
   
# Creating a derived class 
class Derived(Base): 
    def __init__(self): 
           
        # Calling constructor of 
        # Base class
        Base.__init__(self)  
        print("Calling private member of base class: ") 
        print(self.__a) 
# Driver code 
#obj = Derived()

'''
Output:

Traceback (most recent call last):
  File "/home/5a605c59b5b88751d2b93dd5f932dbd5.py", line 20, in 
    obj = Derived()
  File "/home/5a605c59b5b88751d2b93dd5f932dbd5.py", line 18, in __init__
    print(self.__a) 
AttributeError: 'Derived' object has no attribute '_Derived__a'
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------

# Polymorphism
# Polymorphism refers to the ability of OOPs programming languages to differentiate between entities with the same name efficiently. This is done by Python with the help of the signature of these entities.
# Python program to demonstrate Polymorphism
 
 
class A():
    def show(self):
        print("Inside A")
         
class B():
    def show(self):
        print("Inside B")
         
# Driver's code
a = A()
a.show()
b = B()
b.show()

'''
Output:

Inside A
Inside B
'''

#-----------------------------------------------------------------------------------------------------------------------------------------------
# File Handling

"""
Difference:
List	                       Set	                                     Tuple
Mutable	                       Set is Mutable							 Immutable
Ordered collection of items	   Unordered collection of items	         Ordered collection of items
Items in list can be replaced  Items in set cannot be changed/replaced	 Items in tuple cannot be changed or replaced
or changed


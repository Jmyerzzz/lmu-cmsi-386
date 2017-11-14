# Problem 1
Address of A[0][0]: 0x102c550c0

Address of A[3][7]: 0x102c551e8

There are 296 bytes in between each address. Each memory address is 8 bytes and A[3][7] is 37 address away from A[0][0]. 8*37=296

# Problem 2
1. This is an array of n pointers to doubles.
2. This is a pointer to an array of n doubles.
3. This is an array of n pointers to functions returning doubles.
4. This is a function returning a pointer to array of n doubles.


# Problem 3
F is a **[** function passing (a pointer to a [function passing (a double and an array of doubles) returning a double] and a double) returning a pointer **]** to a [function passing (a double and an arbitrary number of arguments) returning a double].

# Problem 4
The b field in the derived class will hide the b field in the base class, not override it. Both fields are still accessible; however, it is not good practice to have fields with the same name. To access the field in the derived class obj_name.b will return that value. To access the b field in the base class obj_name.Base::b will return that value.


# Problem 5
This program outputs:
>2

>5

>2

In main(), when g() is called the local x variable is set to 5. Then f() is called from inside g(), f() is outside the scope of g() and so return the global x variable. The final line also uses the global x variable. If C++ used dynamic scoping then the program would output:
>5

>5

>2


# Problem 6
Raw array: void shuffle(int * arr_p, int arr_length)

Std::array: void shuffle(array<auto, length>)

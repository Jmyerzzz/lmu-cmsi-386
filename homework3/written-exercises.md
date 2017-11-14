# 1
Address of A[0][0]: 0x102c550c0
Address of A[3][7]: 0x102c551e8
There are 296 bytes in between each address. Each memory address is 8 bytes and A[3][7] is 37 address away from A[0][0]. 8*37=296

# 2
This is an array of n pointers to doubles.
This is a pointer to an array of n doubles.
This is an array of n pointers to functions returning doubles.
This is a function returning a pointer to array of n doubles.


# 3


# 4
The b field in the derived class will hide the b field in the base class, not override it. Both fields are still accessible; however, it is not good practice. To access the field in the derived class obj_name.b will return that value. To access the b field in the base class obj_name.Base::b will return that value.


# 5
This program outputs:
2
5
2
In main(), when g() is called the local x variable is set to 5. Then f() is called from inside g(), f() is outside the scope of g() and so return the global x variable. The final line also uses the global x variable. If C++ used dynamic scoping then the program would output:
5
5
2


# 6

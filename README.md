# Understand_The_Multi_Dimensional_Array
다차원배열의 특징 및, 포인터 주소 연산, 배열과의 관계 파악을 위해 여러가지를 연습해보자.

<h4>참고: <a href = "https://stackoverflow.com/questions/2003745/pointer-address-in-a-c-multidimensional-array">pointer-address-in-a-c-multidimensional-array</a></h4><hr>

<p>
When an array expression appears in most contexts, its type is implicitly converted from "N-element array of T" to "pointer to T", and its value is set to point to the first element in the array. The exceptions to this rule are when the array expression is an operand of either the sizeof or address-of (&) operators, or when the array is a string literal being used as an initializer in a declaration.

Thus, the expression zippo "decays" from type int [4][2] (4-element array of 2-element arrays of int) to int (*)[2] (pointer to 2-element array of int). Similarly, the type of zippo[0] is int [2], which is implicitly converted to int *.
</p>

<pre>
Given the declaration int zippo[4][2], the following table shows the types of various array expressions involving zippo and any implicit conversions:

Expression    Type            Implicitly converted to  Equivalent expression
----------    ----            -----------------------  ---------------------
zippo         int [4][2]      int (*)[2]               
&zippo        int (*)[4][2]       
*zippo        int [2]         int *                    zippo[0]
zippo[i]      int [2]         int *
&zippo[i]     int (*)[2]                               
*zippo[i]     int                                      zippo[i][0]
zippo[i][j]   int
&zippo[i][j]  int *
*zippo[i][j]  invalid
</pre>
<hr>
<p>
Note that zippo, &zippo, *zippo, zippo[0], &zippo[0], and &zippo[0][0] all have the same value; they all point to the base of the array (the address of the array is the same as the address of the first element of the array). The types of the various expressions all differ, though.
</p>

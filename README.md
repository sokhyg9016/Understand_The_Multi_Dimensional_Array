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

<h3>Result</h3>
<hr>

<p>zippo[4][2] = {0,};</p>
<pre>
0x0019FEDC  00 00 00 00  ....
0x0019FEE0  00 00 00 00  ....
0x0019FEE4  00 00 00 00  ....
0x0019FEE8  00 00 00 00  ....
0x0019FEEC  00 00 00 00  ....
0x0019FEF0  00 00 00 00  ....
0x0019FEF4  00 00 00 00  ....
0x0019FEF8  00 00 00 00  ....
<hr>
<div style = "font-size: 0.8em; padding:0 margin:0;">
zippo         : 0019FEDC
zippo + 1     : 0019FEE4
<br>
&zippo        : 0019FEDC
&zippo + 1    : 0019FEFC
<br>
*zippo        : 0019FEDC
*zippo + 1    : 0019FEE0
<br>
zippo[0]      : 0019FEDC
zippo[0] + 1  : 0019FEE0
<br>
&zippo[0]     : 0019FEDC
&zippo[0] + 1 : 0019FEE4
<br>
*zippo[0]     : 0
*zippo[0] + 1 : 1
<br>
zippo[0][0]     : 0
zippo[0][0] + 1 : 1
<br>
&zippo[0][0]     : 0019FEDC
&zippo[0][0] + 1: 0019FEE0
</div>

</pre>
<br>

<img src = "http://cslab2.kku.ac.kr/~201721210/pointer_study.JPG">


<p>
In C, when the array notation is used for a function parameter, it is automatically transformed into a pointer declaration, so declaring parameter as int* array and int array[] are equivalent. I tend to use second one because it is more clear that function expects an array as an argument.
</p>
<p><b>
      C에서 배열 표기법이 함수 매개변수에 사용되면 포인터 선언으로 자동 변환되므로 매개변수를 int* 배열과 int 어레이[]로 선언하는 것은 동등하다.       <br>함수가 인수로 배열을 기대하는 것이 더 명확하기 때문에 나는 두번째 것을 사용하는 경향이 있다.
</b></p>
<hr>
<a href = "https://softwareengineering.stackexchange.com/questions/269648/int-vs-int-n-vs-int-n-in-functions-parameters-which-one-do-you-think-i">참조: int * vs int [N] vs int (*)[N] in functions parameters. Which one do you think is better?</a>





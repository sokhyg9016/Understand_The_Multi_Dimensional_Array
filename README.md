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
<pre>
In C, when the array notation is used for a function parameter, it is automatically transformed into a pointer declaration, so declaring parameter as int* array and int array[] are equivalent.
</pre>
</p>
<p><b>
      C에서 배열 표기법이 함수 매개변수에 사용되면 포인터 선언으로 자동 변환되므로 매개변수를 int* 배열과 int[]로 선언하는 것은 동등하다.      
</b></p>
<hr>
<h4>참조</h4>
<a href = "https://softwareengineering.stackexchange.com/questions/269648/int-vs-int-n-vs-int-n-in-functions-parameters-which-one-do-you-think-i">int * vs int [N] vs int (*)[N] in functions parameters. Which one do you think is better?</a><br>
<a href = "https://stackoverflow.com/questions/27878583/does-int-decay-into-int-in-a-function-parameter#comment44159110_27878630">Does “int (*)[]” decay into “int **” in a function parameter?</a>

<h3>정리</h3>
<ol>
      <li><b>C에서 int[]은 함수 매개변수에서 사용되면 포인터 선언으로 자동 변환되므로 매개변수를 int* 배열과 int[]로 선언하는 것은 동등하다.</b></li>
      <li>int (*a)[] 는 int **a로 변환될 수 없다. int(*)[]는 int형 배열의 주소값을 저장하는 포인터이고, int**a는 단순히 int* 타입의 주소를 저 장하기 때문이다. </li>
      <li>즉 int (*a)[]는 int arr[5]; 에서 arr의 주소를, int** a는 int*p에서 p의 주소를 저장한다.</li>
      <li>이때 당연히 arr와 p의 데이터 타입은 다르다. <b>&arr는 int(*)[5], &p는 int**이다.</b></li>
      <li>int zippo[4][2]에서 <b>zippo</b>는 type이 int[4][2]이며 이는 암시적으로 <b>'int(*)[2]'</b>로 변경될 수 있다.</li>
      <li><b>'주소 + 정수'</b>연산에서 정수는 해당 주소의 타입에 영향을 받아 상대적인 메모리상의 거리를 의미한다.</li>
      <li>만약 포인터, 예를 들어 'zippo + 1'이라면 <b>'zippo의 주소 + (sizeof(*zippo)*1)bytes'</b>만큼 이동함을 의미한다.</li>
      <li>이는 즉, <b>'zippo의 주소 + (sizeof(*int(*)[2])*1)bytes' = zippo의 주소 + 8bytes</b>만큼 이동한다는 뜻이다.</li>
      <li>int(*)[2] = zippo를 가리킬수 있고, 이때 이 배열 포인터를 한번 역참조하면 int[2]의 첫번째 주소 값으로 이동할 수 있다.</li> 
      <li>int(*)[2]의 주소 값의 타입은 <b>int(**)[2]</b>가 된다. (Ex. int(**zippo_ptr_ptr)[2] = &zippo_ptr;)</li>
</ol>

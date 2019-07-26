# Understand Multi Dimensional Array
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
<h3><b>In C, when the array notation is used for a function parameter,</b></h3>
it is automatically transformed into a pointer declaration, 
so declaring parameter as int* array and int array[] are equivalent.
</pre>
</p>
<p>
      <b>C에서 배열 표기법이 함수 매개변수에 사용되면</b><br>
      포인터 선언으로 자동 변환되므로 매개변수를 int* 배열과 int[]로 선언하는 것은 동등하다.
</p>
<p>
      
      When passing an array as a parameter, this 
      
      void arraytest(int a[]) 
      {
            ... 
      }
      
      means exactly the same as 
      
      void arraytest(int *a)
      {
            ...
      }
      
</p>
<br>
<p>
"..So, in summary, array names in a C program are (in most cases) converted to pointers. One exception is when we use the sizeof operator on an array. If a was converted to a pointer in this context, sizeof a would give the size of a pointer and not of the actual array, which would be rather useless, so in that case a means the array itself."
</p>
</p>
<p>
      <b>따라서 요약하면, C 프로그램의 배열 이름은 (대부분의 경우) 포인터로 변환된다. 한 가지 예외는 어레이에서 연산자 크기를 사용하는 것이다. 이 맥락에서 a가 포인터로 변환된 경우 a의 크기는 실제 배열이 아닌 포인터 크기를 제공하므로 오히려 쓸모가 없으므로 a는 배열 자체를 의미한다.</b>
</p>
<br>

<p>
      An array object name, or more generally any array expression, is implicitly <b>“converted”</b> to a pointer whenever it’s used in an expression — unless it is either
<ul>
      <li>The operand of the unary sizeof operator; or</li>
      <li>The operand of the unary & (address-of) operator; or</li>
      <li>A string literal in an initializer used to initialize an array object (possibly a sub-object of something else).</li>
</ul>

> This isn’t a run-time conversion; it’s more of a compile time adjustment.) The resulting pointer value is the address of the initial (0th) element of the array object.
</p>
</p>
<p>
      
      이것은 런타임 변환이 아니라 컴파일 타입의 조정에 가깝다. 포인터 값은 배열 요소의 1번째 요소의 주소(== &arr[0])입니다.

</p>
<br>
<hr>
<h3>참조 - K. N. KING - C PROGRAMMING A Modern Approach (p.266, p.272)
<hr>
<p>
      An array object name, or more generally any array expression, is implicitly <b>“converted”</b> to a pointer whenever it’s used in an expression — unless it is either
<ul>
      <li>The operand of the unary sizeof operator; or</li>
      <li>The operand of the unary & (address-of) operator; or</li>
      <li>A string literal in an initializer used to initialize an array object (possibly a sub-object of something else).</li>
</ul>

> This isn’t a run-time conversion; it’s more of a compile time adjustment.) The resulting pointer value is the address of the initial (0th) element of the array object.
</p>
</p>
<p>
      
      이것은 런타임 변환이 아니라 컴파일 타입의 조정에 가깝다. 포인터 값은 배열 요소의 1번째 요소의 주소(== &arr[0])입니다.

</p>
<br>
<hr>
<h3>참조</h3>
<hr>
<ul>
<li><a href = "https://softwareengineering.stackexchange.com/questions/269648/int-vs-int-n-vs-int-n-in-functions-parameters-which-one-do-you-think-i">int * vs int [N] vs int (*)[N] in functions parameters. Which one do you think is better?</a></li>
<li><a href = "https://stackoverflow.com/questions/27878583/does-int-decay-into-int-in-a-function-parameter#comment44159110_27878630">Does “int (*)[]” decay into “int **” in a function parameter?</a></li>
<li><a href = "https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer">Is an array name a pointer?</a></li>
<li><a href = "http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS9919998334">포인터와 배열의 애증 관계</a></li>
<li><a href = "https://www.quora.com/Do-C-compilers-gcc-implicitly-convert-arrays-to-pointer">Do C compilers (gcc) implicitly convert arrays to pointer?</a></li>
<li><a href = "https://yeogue.tistory.com/m/24">[정보/프로그래밍 갤러리]아까 나왔던 배열 얘기 설명해준다 - KaBiS</a></li>
</ul>
<hr>
<h3>정리</h3>
<hr>
<p>

<p>
다음과 같은 코드를 살펴보겠습니다.

      int *p;
      int array[3];
      
      array[0] = 0;
      array[1] = 1;
      array[2] = 2;

      p = array;
      p = &array[0];
</p>

여기서 마지막 두 줄이 중요합니다. p = array; 와 같이 사용할 수 있습니다. 이때, C에서는 array를 포인터로 변환합니다. 따라서, 실제 의미는 p = &array[0]; 과 같습니다.
<br>
<br>
자동 변환해준다고 해서 array를 "배열의 첫 번째를 나타내는 포인터"라고 설명하는 것은 적절하지 않습니다.
</p>
<p>
    C 언어에서 사용되는 식 안에서는 배열을 나타내는 array는 []이 있든, 없든 포인터로만 해석됩니다. array[2]에서 array는 포인터로 읽히며, 결국, *(array + 2)로 해석됩니다. []만 붙으면 배열이다라고 얘기하는 것은 설명하는 입장에서는 쉽지만 정확한 것은 아닙니다.
<br><br>
따라서, 다음은 모두 같은 표현입니다.
<br>
      
      array[2];
      *(array + 2 );
      p[2];
      *(p + 2 );
      
gcc 4.x에서는 gcc -std=c99 -ansi -Wall로 컴파일하고, gcc 3.x에서는 gcc -std=c99 -Wall로 컴파일하면 됩니다. 식 안에서 array를 평가할 때는 포인터로 해석한다는 것에 주의해야 합니다.
</p>
<hr>
<br>
<p>
함수 안에서 배열을 선언할 때는 다음과 같습니다.

      char name[] = "Hello, World";
</p>

초기화를 함께 하는 선언의 경우에는 맞는 표현입니다. 컴파일시에 할당되는 크기를 알 수 있습니다. 이런 종류를 <b><u>complete array type</u></b>이라 합니다.
<br>

      char name[];
      scanf( "%s", name );

<br>
이와 같은 표현을 접할 때가 있습니다. 두 줄 모두 잘못된 코드입니다. 메모리 할당도 안했고, 입력받을 수 있는 최대 문자열 길이도 지정하지 않았습니다. "%10s"와 같은 표현을 사용할 수도 있고, sscanf() 등을 사용할 수도 있습니다.
</p>
<p>
      문제의 char name[]을 살펴보겠습니다. 이것은 많은 분들이 배열로 생각하는데, 이것은 <b>포인터</b>입니다. 선언은 배열이지만, C에서는 이 동작에 대해 정의되어 있지 않습니다. 대부분의 컴파일러는 이것을 포인터로 처리하고 있습니다. char name[]과 같이 사용하는 것을 <b><u>incomplete array type</u></b>이라고 하며, 커널 소스에서도 너무 많이 사용되었습니다. 현재, gcc 3.3.6 이상의 버전과 gcc 4.x에서는 incomplete array type을 허용하지 않고 있습니다.
</p>
<br>
 
      error: array type has incomplete element type

<hr>
<p>출처: <a href = "http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS9919998334">http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS9919998334</a>
</p>
<hr>
<h4>"포인터 연산"</h4>
<hr>
<ol>
      <li><b>'주소 + 정수'</b>연산에서 정수는 해당 주소의 타입에 영향을 받아 상대적인 메모리상의 거리를 의미한다.</li>
      <li>int형 포인터를 대상으로 n 증가 -> n * sizeof(int)의 크기 만큼 증가</li>
      <li>double 형 포인터를 대상으로 n 증가 -> n * sizeof(double)의 크기 만큼 증가</li>
      <li><b>TYPE형 포인터를 대상으로 n의 크기만큼 값을 증가 및 감소 시, n * sizeof(TYPE)의 크기마늠 주소 값이 증가 및 감소한다.</b></li>
      <li>만약 포인터, 예를 들어 'zippo + 1'이라면 <b>'zippo의 주소 + (sizeof(*zippo)*1)bytes'</b>만큼 이동함을 의미한다.</li>
      <li>이는 즉, <b>'zippo의 주소 + (sizeof(*int(*)[2])*1)bytes' = zippo의 주소 + 8bytes</b>만큼 이동한다는 뜻이다.</li>
</ol>
<br>
<hr>
<h4>"배열과 포인터"</h4>
<hr>
<ol>
      <li>배열 이름과 포인터는 다르다. 다만 배열 이름이 몇몇 상황에서 포인터로 암시적인 형 변환(implicit type conversion)을 겪을 뿐이다.
            이러한 변환을 <b>붕괴(decay)</b>라고 한다.</li>
      <li>배열 이름 자체에 <b>sizeof연산자를 사용</b>하거나 , <b>배열 이름 앞에 & 연산자를 붙여 주소를 취할 때</b>는 붕괴(decay)가 일어나지 않는다.
            &nbsp;<b>웬만한 경우에는 붕괴가 일어난다.</b></li>
      <li><b>C에서 int[]은 함수 매개변수에서 사용되면 포인터 선언으로 자동 변환되므로 매개변수를 int* 배열과 int[]로 선언하는 것은 동등하다.</b></li>
      <li>배열명은 배열 생성부터 상수값으로 고정된다.</li>
      <li>배열명이 배열의 시작주소값을 상수 값으로 갖고 변경할 수 없다. 단, 그 배열의 주소에 들어있는 값을 변경하는 것은 가능하다.</li>
      <li><b>배열 이름은 포인터와 비슷하지만 상수적 특성을 지닌다. 또한 대부분의 컴파일러에서 배열을 포인터로 자동 변환해주는 일종의 규칙을 가지고 있다.</b></li>
      <li>int (*a)[] 는 int **a로 변환될 수 없다. int(*)[]는 int형 배열의 주소값을 저장하는 포인터이고, int**a는 단순히 int* 타입의 주소를 저 장하기 때문이다. </li>
      <li>즉 int (*a)[]는 int arr[5]; 에서 arr의 주소를, int** a는 int*p에서 p의 주소를 저장한다.</li>
      <li>이때 당연히 arr와 p의 데이터 타입은 다르다. <b>&arr는 int(*)[5], &p는 int**이다.</b></li>
      <li>int zippo[4][2]에서 <b>zippo</b>는 type이 int[4][2]이며 이는 암시적으로 <b>'int(*)[2]'</b>로 변경될 수 있다.</li>
      <li>int(*)[2] = zippo를 가리킬수 있고, 이때 이 배열 포인터를 한번 역참조하면 int[2]의 첫번째 주소 값으로 이동할 수 있다.</li> 
      <li>int(*)[2]의 주소 값의 타입은 <b>int(**)[2]</b>가 된다. (Ex. int(**zippo_ptr_ptr)[2] = &zippo_ptr;)</li>
</ol>

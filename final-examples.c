#include <stdio.h>
// text-book https://staff.emu.edu.tr/marifiguler/en/Documents/Kumar_Agrawal_C.pdf
// fellow friend https://pythontutor.com/visualize.html#mode=edit

//-----------------------------------------------------------------
//QUESTION 1-A
// understood
void q1_a(){
    int array[] = {1,2,4,5,4,0,3};
	int *p, sum=0;
	p = array+1; // pointer points to '2' element on the index 1
	while(*++p) // won't work if *++p == 0
	{
		sum += *p;
		printf("%d\n",sum);
	}
    /* 
        sum += 4 + 5 + 4
        sum = 17
    
        for the steps check thee link:
            https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20%20%20int%20array%5B%5D%20%3D%20%7B1,2,4,5,4,0,3%7D%3B%0A%20%20%20%20int%20*p,%20sum%3D0%3B%0A%20%20%20%20p%20%3D%20array%2B1%3B%20//%20pointer%20points%20to%20'2'%20element%20on%20the%20index%201%0A%20%20%20%20while%28*%2B%2Bp%29%20//%20won't%20work%20if%20*%2B%2Bp%20%3D%3D%200%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20sum%20%2B%3D%20*p%3B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%5Cn%22,sum%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20//%20sum%20%2B%3D%204%20%2B%205%20%2B%204%0A%20%20%20%20//%20sum%20%3D%2017%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    */
}
//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-B
int f(int i, int *b)
{
	i = i + 1;
	if (*b-1)
		return *++b;
	else 
		return *b++;
}

void q1_b()
{
	int i, a[]={1, 2, 1};
	for(i=0; i<3; i++)
		printf("%d %d\n", i, f(i, a+i));
	
}

/*
    first iteration i = 0, i became 1 in the function
    pointer points to first element of the array which is 1
    since 1 - 1 = 0 => returns 1 after return pointer points to next element 

    second iteration i = 1, i became 2 in the function
    pointer points to second element of the array which is 2
    since 2 - 1 = 1 => returns 1 which is the third element because of ++b operation

    third iteration i = 2, i became 3 in the function 
    pointer points to the third element of the array which is 1
    since 1 - 1 = 0 => returns 1 after return pointer points to null 

    for steps of this code check:
    https://pythontutor.com/render.html#code=int%20f%28int%20i,%20int%20*b%29%0A%7B%0A%20%20%20%20i%20%3D%20i%20%2B%201%3B%0A%20%20%20%20if%20%28*b-1%29%0A%20%20%20%20%20%20%20%20return%20*%2B%2Bb%3B%0A%20%20%20%20else%20%0A%20%20%20%20%20%20%20%20return%20*b%2B%2B%3B%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20%20%20int%20i,%20a%5B%5D%3D%7B1,%202,%201%7D%3B%0A%20%20%20%20for%28i%3D0%3B%20i%3C3%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%25d%5Cn%22,%20i,%20f%28i,%20a%2Bi%29%29%3B%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20return%200%3B%0A%20%20%20%20%0A%7D&cumulative=false&curInstr=25&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

*/

//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-C
// understood
#define SIZE 7
void fun1(int [], int);

void q1_c(){ 
    int i; 
    int array1[SIZE] = {2, 3, 4, 5, 6};
    fun1(array1, array1[2]);

    for (i = 0; i<SIZE; i++)
      printf("%d\n", array1[i]);
}

void fun1(int array1[], int len){ 
    int i;
    for (i = 0; i<len; i++)
        array1[i] += 10; // adds 10 to all elements 
        array1[len-1] += 20; 
        // since if for loop has no curly paranthesis it only takes the first argument after itself
        // so adding 10 is all this for loop do on the other hand it adds 20 one time to the element before the last 
}
/*
    for the steps check thee link:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0A%23define%20SIZE%207%0Avoid%20fun1%28int%20%5B%5D,%20int%29%3B%0A%0Aint%20main%28%29%7B%20%0A%20%20%20%20int%20i%3B%20%0A%20%20%20%20int%20array1%5BSIZE%5D%20%3D%20%7B2,%203,%204,%205,%206%7D%3B%0A%20%20%20%20fun1%28array1,%20array1%5B2%5D%29%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%3CSIZE%3B%20i%2B%2B%29%0A%20%20%20%20%20%20printf%28%22%25d%5Cn%22,%20array1%5Bi%5D%29%3B%0A%20%20%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20fun1%28int%20array1%5B%5D,%20int%20len%29%7B%20%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%3Clen%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20array1%5Bi%5D%20%2B%3D%2010%3B%0A%20%20%20%20%20%20%20%20array1%5Blen-1%5D%20%2B%3D%2020%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
*/

//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-D
// understood
void fun_d(int *p, int x){
 *p += 5;
  x += 5;
}

void q1_d(){
    int a = 4, b = 6;

    fun_d(&a, b); 
    // we directly sent the pointer of a on the other hand b will be copied to be used in the function
    // that's why value of a will be changed to 9 b will become 11 in the function fun_d but will be same in the main function
    // output will become a = 9, b = 6
    printf("a = %d b = %d\n", a, b);
}

/*
    for the steps check thee link:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0Avoid%20fun_d%28int%20*p,%20int%20x%29%7B%0A%20*p%20%2B%3D%205%3B%0A%20%20x%20%2B%3D%205%3B%0A%7D%0A%0Aint%20main%28%29%7B%0A%20%20%20%20int%20a%20%3D%204,%20b%20%3D%206%3B%0A%0A%20%20%20%20fun_d%28%26a,%20b%29%3B%0A%0A%20%20%20%20printf%28%22a%20%3D%20%25d%20b%20%3D%20%25d%5Cn%22,%20a,%20b%29%3B%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=10&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
*/

//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-E
void q1_e(){
    int k, *p, v[] = {2, 5, 3, 4, 6};

    p = v + 2; // pointer points to index 2 which is 3 
    *p = 7; // changes 3 to 7 new list {2, 5, 7, 4, 6}
    p[2] = 9; // changes 6 to 9 {2, 5, 7, 4, 9}
    p[-1] = 11; // changes 5 to 11 {2, 11, 7, 4, 9}
    v[0] = p[1] + 14; // changes 2 to 18 {18, 11, 7, 4, 9}
    *(v+3) = *p + 3; // changes 4 to 10 {18, 11, 7, 10, 9}
    for(k = 0; k <= 4; k++) printf("%d  ", v[k]);
}

/*
    for the steps:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%7B%0A%20%20%20%20int%20k,%20*p,%20v%5B%5D%20%3D%20%7B2,%205,%203,%204,%206%7D%3B%0A%0A%20%20%20%20p%20%3D%20v%20%2B%202%3B%0A%20%20%20%20*p%20%3D%207%3B%0A%20%20%20%20p%5B2%5D%20%3D%209%3B%0A%20%20%20%20p%5B-1%5D%20%3D%2011%3B%0A%20%20%20%20v%5B0%5D%20%3D%20p%5B1%5D%20%2B%2014%3B%0A%20%20%20%20*%28v%2B3%29%20%3D%20*p%20%2B%203%3B%0A%20%20%20%20for%28k%20%3D%200%3B%20k%20%3C%3D%204%3B%20k%2B%2B%29%20printf%28%22%25d%20%20%22,%20v%5Bk%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
*/

//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-F
void q1_f(){
    int x, *p, v[] = {2, 5, 3, 4, 6};

    p = v; // pointer points to the first element of the array which is 2 
    x = ++*p + 9; // 2 + 1 = 3; 9 + 3 = 12; x became 12 (changes 2 to 3)
    printf("%d\n", x); // prints 12 
    
    x = *p++ + 9; // p is 3; 9 + 3 = 12 (pointer points to 5)
    printf("%d\n", x); // prints 12 

    printf("%d  %d\n", p[2], v[0]);
    
}

/*
    for the steps:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%7B%0A%20%20%20%20int%20x,%20*p,%20v%5B%5D%20%3D%20%7B2,%205,%203,%204,%206%7D%3B%0A%0A%20%20%20%20p%20%3D%20v%3B%0A%20%20%20%20x%20%3D%20%2B%2B*p%20%2B%209%3B%0A%20%20%20%20printf%28%22%25d%5Cn%22,%20x%29%3B%0A%20%20%20%20%0A%20%20%20%20x%20%3D%20*p%2B%2B%20%2B%209%3B%0A%20%20%20%20printf%28%22%25d%5Cn%22,%20x%29%3B%0A%0A%20%20%20%20printf%28%22%25d%20%20%25d%5Cn%22,%20p%5B2%5D,%20v%5B0%5D%29%3B%0A%20%20%20%20%0A%7D&cumulative=false&curInstr=8&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
*/

//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-G
void q1_g(){
    int x[5] = {0};
    int j, k;
    for(j=1; j < 5; j++) // j = 5 
    for(k=1; k < 5; k++) x[k] += j/k; // 
    for(j=0; j < 5; j++)
        printf("x[%d] = %d\n", j, x[j]);
}
/*
    for the steps:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%7B%0A%20%20%20%20int%20x%5B5%5D%20%3D%20%7B0%7D%3B%0A%20%20%20%20int%20j,%20k%3B%0A%20%20%20%20for%28j%3D1%3B%20j%20%3C%205%3B%20j%2B%2B%29%0A%20%20%20%20for%28k%3D1%3B%20k%20%3C%205%3B%20k%2B%2B%29%20x%5Bk%5D%20%2B%3D%20j/k%3B%0A%20%20%20%20for%28j%3D0%3B%20j%20%3C%205%3B%20j%2B%2B%29%0A%20%20%20%20%20%20%20%20printf%28%22x%5B%25d%5D%20%3D%20%25d%5Cn%22,%20j,%20x%5Bj%5D%29%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    
    to have a better understanding:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0Aint%20main%28%29%7B%0A%20%20%20%20int%20x%5B5%5D%20%3D%20%7B0%7D%3B%0A%20%20%20%20int%20j,%20k%3B%0A%20%20%20%20for%28j%3D1%3B%20j%20%3C%205%3B%20j%2B%2B%29%20//%20j%20%3D%205%20%0A%20%20%20%20for%28k%3D1%3B%20k%20%3C%205%3B%20k%2B%2B%29%20%0A%20%20%20%20%20%20x%5Bk%5D%20%2B%3D%20j/k%3B%20//%20%0A%20%20%20%20%0A%7D&cumulative=false&curInstr=32&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
*/

//-----------------------------------------------------------------


//-----------------------------------------------------------------
//QUESTION 1-H
// understood
void fun_h(int *p, int size){
    int k;
    for(k=0; k<size; k++) p[k] += k+10;
    //              p[k]
    // 0 + 10         3
    // 1 + 10         4
    // 2 + 10         5
}
 
void q1_h(){
    int k, v[] = {2, 5, 3, 4, 6, 9};
    fun_h(v+2, 3); // given the {3,4,6,9}
    for(k=0; k<= 5; k++) printf("%d  ", v[k]);
    // 2,5,13,15,18,9
}
/*
    for the steps:
    https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0Avoid%20fun_h%28int%20*p,%20int%20size%29%7B%0A%20%20%20%20int%20k%3B%0A%20%20%20%20for%28k%3D0%3B%20k%3Csize%3B%20k%2B%2B%29%20p%5Bk%5D%20%2B%3D%20k%2B10%3B%0A%7D%0A%20%0Aint%20main%28%29%7B%0A%20%20%20%20int%20k,%20v%5B%5D%20%3D%20%7B2,%205,%203,%204,%206,%209%7D%3B%0A%20%20%20%20fun_h%28v%2B2,%203%29%3B%0A%20%20%20%20for%28k%3D0%3B%20k%3C%3D%205%3B%20k%2B%2B%29%20printf%28%22%25d%20%20%22,%20v%5Bk%5D%29%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
*/

//-----------------------------------------------------------------
//MAIN FUNCTION
int main()
{
 	q1_b();
	return 0;
}



#include <stdio.h>
// solved the lab questions 
//-----------------------------------------------------------------------------

// TASK1 A
void task1_a(){
  int a[] = {13, 9, 11, 7, 3, 16, 2, 17};
  int  k, *pa;
  pa = a + 1;
  for(k=0; *(pa+k)-2; k++)
    printf("pa = %d,  k = %d,  *(pa+k) = %d, *(pa+k)-2 = %d\n", *pa, k, *(pa+k), *(pa+k)-2);

  /*
    for loop => for(exp1, exp2, exp3)
    for loop executes until exp2 becomes 0


    so in this code first we initalize pa to 9 which is in the first index of array
    then everytime k increments we move to next element of the array
    *(pa+k)         pa                  k         *(pa+k)-2
    9               1st index           0         7
    11              2nd index           1         9
    7               3rd index           2         5
    3               4th index           3         1
    16              5th index           4         14
    2               6th index           5         0

    since *(pa+k)-2 becames 0 for loop stops the execution
  */
}

//-----------------------------------------------------------------------------
// TASK1 B
void task1_b(){
  void fun1(int *);
  int k;
  int a[] = {9, 11, 7, 3, 16};
  fun1(a + 2); // in this part we send [7, 3, 16] array to the fun function
  for(k=0; k<5; k++) printf("%d  ", a[k]);
}

void fun1(int *p)
 {  
  // p[3] = [7,3,16]
  p[-1] = p[p[-2] ? 2: 1]; // p[-2] = 16 since p[-2] != 0 expression becomes p[-1] = p[2] which doesnt change anything
  p[0] *= 2; // p[0] = 2*7 => p[0] = 14
  p[1] = 44; // p[1] = 3 => p[1] = 44
  p[2] = p[-1] + 1; // p[2] = p[-1] = 16 => p[2] = 17

  /*
  After that function new p became 
  p[3] = [14, 44, 17]
  */
}

//-----------------------------------------------------------------------------
// TASK1 C
double g(double u){
  
  return u < 0 ? u - 1 : u + 1; // since 5.2 > 0 will return 5.2+1 = 6.2
  
}

void f(double *px){
  *px += g(*px); // sent 5.2 to g function result will be added to 5.2
  // output of function g is 6.2 
  // 6.2 + 5.2 = 11.4 
}

void task1_c(){
  double y = 5.2;
  f(&y); // sent 5.2 to the function f 
  printf("\n %4.1f" , y); // output is 11.2
}

//-----------------------------------------------------------------------------
// TASK1 D
void task1_d(){
  int *ptr;
  int array[4] = {1, 2, 3, 4};
  for(ptr=array+3; ptr >= array; ptr--)
    printf("%d   ",  *ptr);
  /*
    ptr points to last element of the array
    and for loop iterates backwards from last item to first item
    then output became 
    4 3 2 1 
  */
}

void fun2(int *p)
{
  int i;
  i = 1;
  while( i < 10){
    *p = i; 
    i *=  3;
    p++;
  }

  // while loop iterates over the elements of p
  // before iteration array was [9, 4, 6, 5, 7]
  // after iteration array => [1, 3, 9, 5 ,7] 
}

//-----------------------------------------------------------------------------
// TASK1 E
void task1_e(){
  int a[] = {8, 2, 9, 4, 6, 5, 7};
  int i;
  fun2(a+2); // send the array [9, 4, 6, 5, 7]
  for(i=0; i < 7; i += 2)
  printf("%d  ", a[i]);

  // new array after passing to function => [8, 2, 1, 3, 9, 5 ,7] 
  // output is => 8, 1, 9, 7
}

//-----------------------------------------------------------------------------
//TASKC 2 SWAPPING WITH POINTERS

void swap_by_ptr(int *fst_num, int *scd_num){
  printf("Before swapping fst_num = %d, scd_num = %d\n", *fst_num, *scd_num);
  int tmp;
  tmp = *fst_num;
  *fst_num = *scd_num;
  *scd_num = tmp;
  printf("After swapping fst_num = %d, scd_num = %d\n", *fst_num, *scd_num);
}

//-----------------------------------------------------------------------------
//TASKC 3 MAX-MIN ELEMS

void maxMinElems(int *arr){
  // here is an example code 
  // https://notesformsc.org/c-find-max-min-pointers/
}

//-----------------------------------------------------------------------------
// MAIN FUNCTION

int main(){
  int a = 5, b = 7;
  swap_by_ptr(&a, &b);
  return 0;
}


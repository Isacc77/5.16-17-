#include <stdio.h>

void test1(){
  int n = 10;
  int m = 30;
  int *p = &n;
  
  printf("%d %d\n", *p,n);
  *p = 20;//ok?
  printf("%d %d\n", *p,n);
  printf("%p %p\n", p, &n);
  p = &m; //ok?
  printf("%p %p\n", p, &m);
  printf("%d %d\n", *p, n);  
  printf("%p %p\n", p, &n);
  /*
  n   &n
  m   &m
 *p    p
    */
}

void test2(){
  //代码2
  int n = 10;
  int m = 20;

 //p的值可修改，但p指向的变量值不可修改
  const int *p = &n;
  // *p = 20;//ok?

  p = &m; //ok?
  // printf("%d %d\n", *p,n);
}

void test3() {
  int n = 10;
  int m = 20;
  //p的值不可修改，但p指向的变量值可修改
  int *const p = &n;
  *p = 20; //ok?
  // p = &m; //ok?
}
/*
A.int *const p与int const *p等价
错误
int *const p 是p值不能改变，p指针指向的变量可以改变 
int const *p 是p值可以改变，p指针指向的变量不可以改变 

B.const int *p与int *const p等价
错误
const int *p 是p值可以改变，p指针指向的变量不可以改变 
int *const p 是p值不能改变，p指针指向的变量可以改变 

C.const int *p与int const *p等价
正确
both are p值可以改变，p指针指向的变量不可以改变 

D.int *p[10]与int (*p)[10]等价

总结 
const 放在*左边，p值可以改变，p指针指向的变量不可以改变 
int const *p 
const int *p

const 放在*右边，是p值不能改变，p指针指向的变量可以改变
int *const p
*/

// void test4() {
//   int n = 10;
//   int m = 20;
//  const int *p = &n;
//   *p = 20; //ok?
//   p = &m; //ok?
// }

// void test5() {
//   int n = 10;
//   int m = 20;

//   int const *p = &n;
//   *p = 20; 
//   p = &m; 
// }



int main(){

//测试无cosnt的
test1();
//测试const放在*的左边
test2();
//测试const放在*的右边
test3();
return 0;


}
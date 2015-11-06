#include<stdio.h>
#include<stdlib.h>
int fac(int n, int accumulate){
  if(n == 1){
    return accumulate;
  }
  return fac(n - 1, n * accumulate);

}
int main(){
  char input[80] = {0};
  while(fgets(input, 80, stdin)){
    printf("%d\n", fac(strtol(input, NULL, 10), 1));
  }
  return 0;
}

#include "union.h"


void union_test(){
  union Dato v;
  v.intero = 10;
  printf( "Intero: %d\n"  , v.intero ) ;
  v.decimale = 3.14;
  printf( "Decimale: %f\n", v.decimale ) ;
  v.carattere = 'A';
  printf( "Carattere: %c\n", v.carattere ) ;
}

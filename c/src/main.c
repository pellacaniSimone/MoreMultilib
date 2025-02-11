#include <stdio.h> // printf
#include <stdlib.h> // free malloc
#include <string.h>

// basic
#include "basic/var.h"
#include "basic/files.h"
#include "basic/variadic.h"
#include "basic/datetime.h"
#include "basic/union.h"


// advanced
#include "advanced/basic_object.h"
#include "advanced/mt_data_race.h"

// design pattern creational
#include "dp/creational/singleton.h"
#include "dp/creational/factory.h"
#include "dp/creational/union_singleton.h"


void handle_test_visibility() {
  printf("variabili locali %d, globali %d e statiche %d \n",
  globaleFun(), GLOBALE_VAR , staticFun());
}


void run_all_tests() {
  handle_test_visibility()  ;
  files_handling();
  variadic_test();
  timedate_handling();
  union_test();
  metaobject();
  test_singleton();
  union_singleton();
  factory_example();
  grandi_numeri_mt_rc(); 
}


int main(int n, char** args) {
  if (n > 1 && args[1] != NULL){
    printf("\n");
    // basic
    if ( strcmp(args[1], "test_visibilita_variabili") == 0) { handle_test_visibility()  ;  }
    if ( strcmp(args[1], "files_handling") == 0 ) { files_handling(); }
    if ( strcmp(args[1], "variadic_example") == 0 ) { variadic_test(); }
    if ( strcmp(args[1], "timedate_handling") == 0 ) {  timedate_handling();   }
    if ( strcmp(args[1], "union_test") == 0 ) {  union_test();   }
    // advanced
    if ( strcmp(args[1], "basic_class_example") == 0 ) {  metaobject();   }
    if ( strcmp(args[1], "test_singleton") == 0 ) { test_singleton();  }
    if ( strcmp(args[1], "union_singleton") == 0 ) { union_singleton(); }
    // design pattern
    if ( strcmp(args[1], "factory_example") == 0 ) { factory_example(); }
    if ( strcmp(args[1], "multithread_data_race") == 0 ) { grandi_numeri_mt_rc(); }
    if ( strcmp(args[1], "all") == 0 ) { run_all_tests() ;} // no input or mem test
    if ( args[1] == NULL ) { printf("Unsupported test\n"); }
  }

  printf("\n");
  return 0;
}

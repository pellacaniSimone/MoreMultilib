#include <iostream>   // for I/O operations

using namespace std;

// basic
#include "basic/var.h"
#include "basic/files.h"
#include "basic/variadic.h"
#include "basic/datetime.h"
#include "basic/union.h"

// advanced
#include "advanced/basic_namespace.h"
#include "advanced/basic_object.h"
#include "advanced/object_namespace.h"
#include "advanced/multiple_inheritance.h"
#include "advanced/template_class.h"
#include "advanced/template_inheritance.h"
#include "advanced/mro.h"

// design pattern
#include "dp/creational/union_singleton.h"
#include "dp/creational/factory.h"

void handle_test_visibility() {
  printf("variabili locali %d, globali %d e statiche %d \n",
  globaleFun(), GLOBALE_VAR , staticFun());
  test_visibilita();
}


void run_all_tests() {
  handle_test_visibility();
  files_handling();
  variadic_test();
  timedate_handling();
  union_test();
  namespace_example();
  basic_class_example();
  classes_namespace_example();
  advanced_class_example();
  template_example();
  inheritance_template_example();
  mro_example();
  union_singleton();
  factory_example();
}

#include <cstring>
int main(int n, char** args) {
  if (n > 1 && args[1] != NULL){
    printf("\n");
    // basic
    if ( strcmp(args[1], "test_visibilita_variabili") == 0) {  handle_test_visibility() ; }
    if ( strcmp(args[1], "files_handling") == 0 ) { files_handling(); }
    if ( strcmp(args[1], "variadic_example") == 0 ) { variadic_test(); }
    if ( strcmp(args[1], "timedate_handling") == 0 ) { timedate_handling(); }
    if ( strcmp(args[1], "union_test") == 0 ) { union_test(); }
    // advanced
    if ( strcmp(args[1], "namespace_example") == 0 ) { namespace_example(); }
    if ( strcmp(args[1], "basic_class_example") == 0 ) { basic_class_example(); }
    if ( strcmp(args[1], "classes_namespace_example") == 0 ) { classes_namespace_example(); }
    if ( strcmp(args[1], "multiple_inheritance") == 0 ) { advanced_class_example(); }
    if ( strcmp(args[1], "template_example") == 0 ) { template_example(); }
    if ( strcmp(args[1], "inheritance_template_example") == 0 ) { inheritance_template_example(); }
    if ( strcmp(args[1], "mro_example") == 0 ) { mro_example(); }
    // design pattern
    if ( strcmp(args[1], "union_singleton") == 0 ) { union_singleton(); }
    if ( strcmp(args[1], "factory_example") == 0 ) { factory_example(); }
    
    // all
    if ( strcmp(args[1], "all") == 0 ) { run_all_tests() ;} // no input or mem test
    if ( args[1] == NULL ) { printf("Unsupported test\n"); }
  }
  printf("\n");
  return 0;
}

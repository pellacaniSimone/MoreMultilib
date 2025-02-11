mod basic {
  pub mod var;
  pub mod files;
  pub mod variadic;
  pub mod datetime;
  pub mod union;
}
use basic::{var,files,variadic,datetime,union};

mod advanced {
  pub mod basic_namespace;
  pub mod basic_object;
  pub mod multiple_inheritance;
  pub mod template_class;
  pub mod template_inheritance;
  pub mod mro;
  pub mod mt_data_race;
}
use advanced::{basic_namespace,basic_object,multiple_inheritance,
  template_class,template_inheritance,mro,mt_data_race};


mod dp {
  pub mod creational {
    pub mod singleton;
    pub mod mt_singleton;
    pub mod union_singleton;
    pub mod mt_union_singleton;
    pub mod factory;
  }
  pub mod structural {
    pub mod decorator;
  }
}

use dp::creational::{
    singleton,
    mt_singleton,
    union_singleton,
    mt_union_singleton,
    factory,
};
use dp::structural::{decorator};

use std::thread;


fn handle_test_visibility() {
  println!("variabili locali {}, globali {} e statiche {}",
    var::globale_fun(), var::GLOBALE_VAR, var::statiche())
}



fn run_all_tests() {
  // basic
  handle_test_visibility();
  files::files_handling();
  variadic::variadic_test();
  datetime::timedate_handling();
  union::union_test();
  // advanced
  basic_namespace::namespace_test();
  basic_object::metaobject();
  multiple_inheritance::test_oopr();
  template_class::template_example();
  template_inheritance::inheritance_template_example();
  mro::mro_example();
  mt_data_race::multithread_data_race();
  // dp
  singleton::test_singleton();
  mt_singleton::test_mt_singleton();
  union_singleton::union_singleton();
  mt_union_singleton::mt_union_singleton();
  factory::factory_example();
  decorator::decorators_example();
}


//---------------------------------------------------------------------------------------
// Main
//---------------------------------
fn main() {
  // Recupera gli argomenti della riga di comando in un vettore
  let args: Vec<String> = std::env::args().collect();

  if args.len() > 1 {
    match args[1].as_str() {
      // basic
      "test_visibilita_variabili" => handle_test_visibility() ,
      "files_handling" => thread::spawn(files::files_handling).join().unwrap(),
      "variadic_example" => variadic::variadic_test(),
      "timedate_handling" => thread::spawn(datetime::timedate_handling).join().unwrap(),
      "union_test" => thread::spawn(union::union_test).join().unwrap(),

      // advanced
      "namespace_test" => thread::spawn(basic_namespace::namespace_test).join().unwrap(),
      "basic_class_example" => thread::spawn(basic_object::metaobject).join().unwrap(),
      "multiple_inheritance" => thread::spawn(multiple_inheritance::test_oopr).join().unwrap(),
      "template_example" => thread::spawn(template_class::template_example).join().unwrap(),
      "inheritance_template_example" => thread::spawn(template_inheritance::inheritance_template_example).join().unwrap(),
      "mro_example" => thread::spawn(mro::mro_example).join().unwrap(),
      "multithread_data_race" => thread::spawn(mt_data_race::multithread_data_race).join().unwrap(),
      // dp
      "test_singleton" => thread::spawn(singleton::test_singleton).join().unwrap(),
      "test_mt_singleton" => thread::spawn(mt_singleton::test_mt_singleton).join().unwrap(),
      "union_singleton" => thread::spawn(union_singleton::union_singleton).join().unwrap(),
      "mt_union_singleton" => thread::spawn(mt_union_singleton::mt_union_singleton).join().unwrap(),
      "factory_example" => thread::spawn(factory::factory_example).join().unwrap(),
      "decorators_example" => thread::spawn(decorator::decorators_example).join().unwrap(),

      // all
      "all" => thread::spawn(run_all_tests).join().unwrap(),
      _ => println!("Unsupported test"),
    }
  }
}

use std::sync::{Mutex, OnceLock};
use std::any::{Any, TypeId};

union MyUnion { // definisce una union per i vari tipi di dato
  int: i32,
  float: f32,
  character: char,
}

struct SSingleton {
  data: Mutex<(MyUnion, TypeId)>,
}

static UINSTANCE: OnceLock<SSingleton> = OnceLock::new();

impl SSingleton {

  fn instance() -> &'static SSingleton {
    UINSTANCE.get_or_init(|| SSingleton {
      data: Mutex::new((MyUnion { int: 0 }, TypeId::of::<i32>())),
    })
  }


  fn set_value<T: Any + 'static>(value: &T) {
    let instance = Self::instance();
    let mut lock = instance.data.lock().unwrap();
    let value: &dyn Any = value;
    if let Some(int_val) = value.downcast_ref::<i32>() {
      lock.0.int = *int_val;
      lock.1 = TypeId::of::<i32>();
    } else if let Some(float_val) = value.downcast_ref::<f32>() {
      lock.0.float = *float_val;
      lock.1 = TypeId::of::<f32>();
    } else if let Some(char_val) = value.downcast_ref::<char>() {
      lock.0.character = *char_val;
      lock.1 = TypeId::of::<char>();
    } else {
      panic!("tipo non supportato");
    }
  }


  fn print_value() {
    let instance = Self::instance();
    let lock = instance.data.lock().unwrap();
    match lock.1 {
      tid if tid == TypeId::of::<i32>() => {
        println!("Valore intero: {}", unsafe { lock.0.int });
      }
      tid if tid == TypeId::of::<f32>() => {
        println!("Valore float: {:.2}", unsafe { lock.0.float });
      }
      tid if tid == TypeId::of::<char>() => {
        println!("Valore char: {}", unsafe { lock.0.character });
      }
      _ => println!("Tipo sconosciuto"),
    }
  }
}

pub fn union_singleton() {
  SSingleton::set_value(&42);
  SSingleton::print_value();

  SSingleton::set_value(&3.14f32);
  SSingleton::print_value();

  SSingleton::set_value(&'A');
  SSingleton::print_value();
}

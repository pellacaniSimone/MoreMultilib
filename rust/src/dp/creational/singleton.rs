use std::sync::{Mutex, OnceLock};

struct Singleton {
  valore: Mutex<i32>,
}

static INSTANCE: OnceLock<Singleton> = OnceLock::new();

impl Singleton {
  fn get_instance() -> &'static Singleton {
    INSTANCE.get_or_init(|| Singleton {
      valore: Mutex::new(0),
    })
  }

  fn set_valore(new_val: i32) {
    let instance = Self::get_instance();
    let mut valore = instance.valore.lock().unwrap();
    *valore = new_val;
  }

  fn get_valore() -> i32 {
    let instance = Self::get_instance();
    *instance.valore.lock().unwrap()
  }
}

pub fn test_singleton() {
  let s1 = Singleton::get_instance();
  Singleton::set_valore(42);

  let s2 = Singleton::get_instance();
  println!("Valore di s2: {}", Singleton::get_valore()); // Deve stampare 42

  if std::ptr::eq(s1, s2) {
    println!("s1 e s2 puntano alla stessa istanza");
  }
}

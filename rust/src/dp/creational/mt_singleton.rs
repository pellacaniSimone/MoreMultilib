use std::sync::{ Mutex, OnceLock};
use std::thread;


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

pub fn test_mt_singleton() {
  let mut handles = vec![];

  for i in 0..10 {
    let handle = thread::spawn(move || {
      Singleton::set_valore(i); 
      println!("Thread {}: {}", i, Singleton::get_valore()); 
    });
    handles.push(handle);
  }

  for handle in handles {
    handle.join().unwrap(); // join
  }
}
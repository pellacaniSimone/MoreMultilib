use std::sync::{ Mutex, OnceLock};
use std::thread;

use std::any::{Any, TypeId};

//---------------------------------------------------------------------------------------
// Union Singleton
//---------------------------------
union MyUnion { // Define a union to store different types of data (i32, f32, char)
  int: i32,
  float: f32,
  character: char,
}

// Define a singleton struct to hold the union and its type information
struct SSingleton {
  data: Mutex<(MyUnion, TypeId)>,
}

// Declare a static variable for the singleton instance, initialized lazily using OnceLock
static UINSTANCE: OnceLock<SSingleton> = OnceLock::new();

// Implement methods for the SSingleton struct
impl SSingleton {
    // Method to get the singleton instance
    fn instance() -> &'static SSingleton {
      UINSTANCE.get_or_init(|| SSingleton {
        // Initialize the singleton with a default value (int: 0) and its TypeId
        data: Mutex::new((MyUnion { int: 0 }, TypeId::of::<i32>())),
      })
    }

    // Method to set a value in the singleton
    fn set_value<T: Any + 'static>(value: &T) {
      let instance = Self::instance();  // Get the singleton instance
      let mut lock = instance.data.lock().unwrap(); // Lock the Mutex for thread-safe access

      let value: &dyn Any = value; // Cast the input value to a dynamic Any type

      // Check the type of the input value and update the union and TypeId accordingly
      if let Some(int_val) = value.downcast_ref::<i32>() {
        lock.0.int = *int_val; // Update the union with the integer value
        lock.1 = TypeId::of::<i32>(); // Update the TypeId to i32
      } else if let Some(float_val) = value.downcast_ref::<f32>() {
        lock.0.float = *float_val;
        lock.1 = TypeId::of::<f32>();
      } else if let Some(char_val) = value.downcast_ref::<char>() {
        lock.0.character = *char_val;
        lock.1 = TypeId::of::<char>();
      } else {
        panic!("Tipo non supportato"); // Panic if the type is not supported, use raise if exixt
      }
    }

    // Method to print the current value stored in the singleton
    fn print_value() {
      let instance = Self::instance(); // Get the singleton instance
      let lock = instance.data.lock().unwrap(); // Lock the Mutex for thread-safe access

      // Match on the TypeId to determine the type of the stored value
      match lock.1 {
        tid if tid == TypeId::of::<i32>() => {
          println!("Valore intero: {}", unsafe { lock.0.int }); // Print the integer value (using unsafe to access the union field)
        }
        tid if tid == TypeId::of::<f32>() => {
          println!("Valore float: {:.2}", unsafe { lock.0.float });
        }
        tid if tid == TypeId::of::<char>() => {
          println!("Valore char: {}", unsafe { lock.0.character });
        }
        _ => println!("Tipo sconosciuto"),  // Handle unknown types
    }
    }
}

pub fn mt_union_singleton() {
    let mut handles = vec![];

    handles.push(thread::spawn(|| {
      SSingleton::set_value(&42); // Set the singleton value to an integer
      SSingleton::print_value(); // Print the current value
    }));

    handles.push(thread::spawn(|| {
      SSingleton::set_value(&3.14f32); // Set the singleton value to a float
      SSingleton::print_value(); // Print the current value
    }));

    handles.push(thread::spawn(|| {
      SSingleton::set_value(&'A'); // Set the singleton value to a char
      SSingleton::print_value(); // Print the current value
    }));

    for handle in handles {
      handle.join().unwrap();
    }
}
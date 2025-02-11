

struct Counter { value: i32, }

impl Counter {
  // override costruttore
  fn new(offset: i32) -> Self { Self { value: offset } }
  fn increment(&mut self) { self.value += 1; }
  fn print(&self) { println!("Counter value print: {}", self.value); }
}

use std::fmt;
impl fmt::Display for Counter {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
    write!(f, "Counter value display: {}", self.value)
  }
}

pub fn metaobject() {
  let mut c = Counter::new(0);
  c.print();
  c.increment();
  c.print();
  println!("{}", c); // using display
}
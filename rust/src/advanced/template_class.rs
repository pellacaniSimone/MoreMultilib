
// come una Union
struct Container<T> { value: T, }

impl<T> Container<T> {
  fn new(value: T) -> Self { Container { value }  }
  fn set_value(&mut self, value: T) { self.value = value;  }
  fn get_value(&self) -> &T { &self.value }
}

pub fn template_example() {

  let mut p = Container::new(0);
  p.set_value(42);
  println!("Int value: {}", p.get_value());

  let p = Container::new(3.14);
  println!("Float value: {}", p.get_value());

  let p = Container::new("Hello World!");
  println!("String value: {}", p.get_value());
}

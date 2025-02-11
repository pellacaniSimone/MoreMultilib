
struct Pair<T, U> { first: T,  second: U, }
impl<T, U> Pair<T, U> {
  fn new(first: T, second: U) -> Self { Pair { first, second }  }
  fn set_value(&mut self, first: T, second: U) { self.first = first; self.second = second;  }
  fn get_first(&self) -> &T { &self.first  }
  fn get_second(&self) -> &U {  &self.second  }
}

// if we rename "pair:" with "super:" syntax is more devFriendly
struct LabeledPair<T, U> { pair: Pair<T, U>, label: String, }
impl<T, U> LabeledPair<T, U> {
  fn new(first: T, second: U, label: String) -> Self {
    LabeledPair { pair: Pair::new(first, second), label }
  }
  // ridefinizione obbligatoria getter oppure chiamata puntuale p.pair.get_second()
  fn get_first(&self) -> &T { self.pair.get_first()  }
  fn get_second(&self) -> &U {  self.pair.get_second()  }
  fn stampa_label(&self) { println!("Label: {}", self.label); }
}

pub fn inheritance_template_example() {
  let mut p = Pair::new(0.0, 0.0);
  p.set_value(10.0, 20.5);
  println!("First: {}, Second: {}", p.get_first(), p.get_second());

  // p.pair.get_second() return the same
  let p = LabeledPair::new(30, 40.5, "Example Label".to_string());
  println!("First: {}, Second: {}", p.get_first(), p.get_second()); 
  p.stampa_label();
}




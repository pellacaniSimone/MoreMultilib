// rust use traits hierarchy instead class hierarchy
trait TraitA { fn method(&self); }

trait TraitB: TraitA {
  fn method(&self) {
    println!("TraitB di B L1");
    TraitA::method(self);
  }
}

trait TraitC: TraitA {
  fn method(&self) {
    println!("TraitC di C L1");
    TraitA::method(self);
  }
}

struct A;
impl TraitA for A {
  fn method(&self) { println!("TraitA di A L0");  }
}

impl TraitB for A {}  // use default implementation
impl TraitC for A {}  

impl A {
  fn method(&self) {
    println!("Metodo di A L2");
    TraitB::method(self);
    TraitC::method(self); 
  }
}

pub fn mro_example() {
  let my_instance = A;
  my_instance.method();
}
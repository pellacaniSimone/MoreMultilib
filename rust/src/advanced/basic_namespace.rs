
// in rust tutto è privarto per impostazione predefinita,
// per rendere visdibile all'esterno serve la keywork pub

mod math_operations {
  pub mod algebra {
    pub fn somma(a: f32, b: f32) -> f32 { a + b }
    pub fn sottrazione(a: f32, b: f32) -> f32 { a - b }
  } // both syntax permitted and nested namespeces
  pub fn moltiplicazione(a: f32, b: f32) -> f32 { a * b }
  pub fn divisione(a: f32, b: f32) -> f32 { if b==0.0 {0.0} else {a/b}  }
}




pub fn namespace_test() {
  let x = 10.5; let y = 2.5;
  
  println!("Somma: {}", math_operations::algebra::somma(x, y));
  println!("Sottrazione: {}", math_operations::algebra::sottrazione(x, y));
  println!("Moltiplicazione: {}", math_operations::moltiplicazione(x, y));
  println!("Divisione: {}", math_operations::divisione(x, y));
}
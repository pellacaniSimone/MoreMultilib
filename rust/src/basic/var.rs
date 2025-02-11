
pub static GLOBALE_VAR: i32 = 6;

pub fn globale_fun() -> i32 {
  let local_var = 6;
  // GLOBALE_VAR = local_var; // non assegnabile by design
  let x = 6;
  x + GLOBALE_VAR + local_var // Ritorna la somma di `x` e `y`
}

pub fn statiche() -> i32 {
  const INC: i32 = 100000;
  INC // costante
}
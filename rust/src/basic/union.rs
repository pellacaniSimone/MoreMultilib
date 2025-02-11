
union Valore {
  intero: i32,
  decimale: f32,
  carattere: char,
}

pub fn union_test() {
  let mut v = Valore { intero: 10 }; //  del campo `intero`.
  unsafe { // scrivere i campi della `union` richiede un blocco `unsafe`
    println!("Intero: {}", v.intero);
    v.decimale = 3.14;
    println!("Decimale: {}", v.decimale);
    v.carattere = 'A';
    println!("Carattere: {}", v.carattere);
  }
}

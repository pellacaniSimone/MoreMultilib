// in rust i decoratori si chiamano Macro e sono usanti in libreria standard per implementare 
// traits polimorfici in automatico per una struct, come in questo caso di esepio

#[derive(Debug)] 
struct Persona<'a> {
    nome: &'a str,
    eta: u8,
}

pub fn decorators_example() {
    let p = Persona { nome: "Alice", eta: 30 };
    println!("Stampa di debug");
    println!("{:?}", p); // Output: Persona { nome: "Alice", eta: 30 }
    println!("Stampa normale");
    println!("Nome: {} - età : {}" , p.nome , p.eta);
}
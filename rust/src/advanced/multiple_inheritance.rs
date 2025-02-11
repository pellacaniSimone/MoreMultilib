// polimethod
trait Muovi { fn move_it(&self) -> String; }

struct VeicoloGenerico { alert: String, }
impl VeicoloGenerico {
  fn new(message: &str) -> Self {
    if !message.is_empty() { Self { alert: message.to_string(),  }  } 
    else { Self { alert: "Non raggiungibile, errore\n".to_string(), }}
  }
  fn get_alert(&self) -> String { self.alert.clone() }
}
impl Muovi for VeicoloGenerico {   // metodo polimorfico (trait)
  fn move_it(&self) -> String { 
    self.get_alert()
  } 
}

struct Auto { tipo: VeicoloGenerico }
impl Auto {
  fn new(message: &str) -> Self {
    Self {  tipo: VeicoloGenerico::new(message), }
  }
  fn get_message(&self) -> String{ "Guida su strada".to_string() } // self instance method
}
impl Muovi for Auto { // metodo polimorfico (trait)
  fn move_it(&self) -> String {
    format!("{}\n{}\n", self.tipo.get_alert() , self.get_message() )
  }
}

struct Barca { tipo: VeicoloGenerico }
impl Barca {
  fn new(message: &str) -> Self {
    Self { tipo: VeicoloGenerico::new(message)   }
  }
  fn get_message(&self) -> String{ "Naviga sull'acqua".to_string() }
}
impl Muovi for Barca {
  fn move_it(&self) -> String {
    format!("{}\n{}\n", self.tipo.get_alert() , self.get_message() )
  }
}

struct AutoAnfibia { auto: Auto, barca: Barca,}
impl AutoAnfibia {
  fn new(message: &str) -> Self {
    Self {
      auto: Auto::new(message),
      barca: Barca::new(message),
    }
  }
}

impl Muovi for AutoAnfibia {
  fn move_it(&self) -> String {
    format!(
      "{}\n{}\n{}\n",
      self.auto.tipo.get_alert(),
      self.auto.get_message(),
      self.barca.get_message()
    )
  }
}

// call polimorfica dynamic dispatch
fn make_move_it(veicolo: &dyn Muovi) { println!("{}", veicolo.move_it()); }

pub fn test_oopr() {
  let generic_veicle = VeicoloGenerico::new("");
  let automobile = Auto::new("Veicolo Auto da ora");
  let barca = Barca::new("Veicolo Barca da ora");
  let auto_anfibia = AutoAnfibia::new("Veicolo Anfibio da ora");

  make_move_it(&generic_veicle);
  make_move_it(&automobile);
  make_move_it(&barca);
  make_move_it(&auto_anfibia);

}

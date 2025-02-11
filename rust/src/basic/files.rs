use std::sync::Mutex;
use std::io::{Write, Read};
//---------------------------------------------------------------------------------------
// Gestione concorrenza per input e file
//---------------------------------

//static INPUT_LOCK: Mutex<()> = Mutex::new(());
static FILES_LOCK: Mutex<()> = Mutex::new(());


//---------------------------------------------------------------------------------------
// Gestione file
//---------------------------------

use std::fs::File;
fn crea_file_vuoto() {
  let _lock = FILES_LOCK.lock().unwrap();
  let _ = File::create("filename.txt").expect("Unable to create file");
}

fn scrivi_su_un_file_nuovo() {
  let _lock = FILES_LOCK.lock().unwrap();
  let mut fptr = File::create("filename2.txt").expect("Unable to create file");
  write!(fptr, "Some text").expect("Unable to write data");
}

fn leggi_file_e_stampa() {
  let _lock = FILES_LOCK.lock().unwrap();
  let mut fptr = File::open("filename2.txt").expect("Unable to open file");
  let mut stringa = String::new();
  while fptr.read_to_string(&mut stringa).expect("Unable to read file") > 0 {
    print!("{}", stringa);
  }
  println!(); // Aggiunge una nuova riga
}

pub fn files_handling() {
  crea_file_vuoto();
  scrivi_su_un_file_nuovo();
  leggi_file_e_stampa();
}
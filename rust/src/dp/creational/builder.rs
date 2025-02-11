use std::fmt::Write;

pub trait FormBuilder {
  fn add_title(&mut self, title: &str);
  fn add_label(&mut self, text: &str, row: i32, col: i32, target: &str);
  fn add_entry(&mut self, variable: &str, row: i32, col: i32, kind: &str);
  fn add_button(&mut self, text: &str, row: i32, col: i32);
  fn form(&self) -> String;
}

pub struct HtmlFormBuilder {
  title: String,
  items: Vec<String>,
}

impl HtmlFormBuilder {
  pub fn new() -> Self {
    Self {
      title: String::new(),
      items: Vec::new(),
    }
  }
}

impl FormBuilder for HtmlFormBuilder {
  fn add_title(&mut self, title: &str) {
    self.title = title.to_string();
  }

  fn add_label(&mut self, text: &str, _row: i32, _col: i32, target: &str) {
    self.items.push(format!("<label for=\"{}\">{}</label>", target, text));
  }

  fn add_entry(&mut self, variable: &str, _row: i32, _col: i32, kind: &str) {
    self.items.push(format!("<input name=\"{}\" type=\"{}\">", variable, kind));
  }

  fn add_button(&mut self, text: &str, _row: i32, _col: i32) {
    self.items.push(format!("<button>{}</button>", text));
  }

  fn form(&self) -> String {
    let mut form = String::new();
    write!(
      form,
      "<html><head><title>{}</title></head><body><form>",
      self.title
    )
    .unwrap();
    
    for item in &self.items {
      write!(form, "{}\n", item).unwrap();
    }
    
    write!(form, "</form></body></html>").unwrap();
    form
  }
}

pub struct DialogFormBuilder {
  title: String,
  fields: Vec<String>,
  buttons: Vec<String>,
}

impl DialogFormBuilder {
  pub fn new() -> Self {
    Self {
      title: String::new(),
      fields: Vec::new(),
      buttons: Vec::new(),
    }
  }
}

impl FormBuilder for DialogFormBuilder {
  fn add_title(&mut self, title: &str) {
    self.title = title.to_string();
  }

  fn add_label(&mut self, _text: &str, _row: i32, _col: i32, _target: &str) {
    // Dialog handles labels directly in widgets
  }

  fn add_entry(&mut self, variable: &str, _row: i32, _col: i32, kind: &str) {
    let password_flag = if kind == "password" { "--insecure" } else { "" };
    self.fields.push(format!(
      "$DIALOG --title \"{}\" --clear \\\n  --inputbox \"{}:\" 8 40 {} 2> {}.txt",
      self.title, variable, password_flag, variable
    ));
  }

  fn add_button(&mut self, text: &str, _row: i32, _col: i32) {
    match text.to_lowercase().as_str() {
      "login" => self.buttons.push("echo \"Login pressed, processing...\"".to_string()),
      "cancel" => self.buttons.push("echo \"Cancel pressed, exiting...\" && exit 1".to_string()),
      _ => {}
    }
  }

  fn form(&self) -> String {
    let mut script = String::from("#!/bin/bash\nDIALOG=${DIALOG=dialog}\n\n");
    
    for field in &self.fields {
      write!(script, "{}\n\n", field).unwrap();
    }
    
    write!(
      script,
      "choices=$(\n$DIALOG --title \"{}\" --clear \\\n  --yesno \"Do you want to proceed?\" 8 40\n)\n\n",
      self.title
    )
    .unwrap();
    
    write!(script, "case $? in\n  0)\n  echo \"Yes chosen.\"\n").unwrap();
    
    for button in &self.buttons {
      write!(script, "  {}\n", button).unwrap();
    }
    
    write!(
      script,
      "  ;;\n  1)\n  echo \"No chosen, exiting...\"; exit 1;;\n  255)\n  echo \"ESC pressed, exiting...\"; exit 1;;\nesac\n"
    )
    .unwrap();
    
    script
  }
}

pub fn create_login_form(builder: &mut dyn FormBuilder) -> String {
  builder.add_title("Login");
  builder.add_label("Username", 0, 0, "username");
  builder.add_entry("username", 0, 1, "text");
  builder.add_label("Password", 1, 0, "password");
  builder.add_entry("password", 1, 1, "password");
  builder.add_button("Login", 2, 0);
  builder.add_button("Cancel", 2, 1);
  builder.form()
}

pub struct TestBuilder;

impl TestBuilder {
  pub fn run() {
    let mut html_builder = HtmlFormBuilder::new();
    let mut dialog_builder = DialogFormBuilder::new();
    
    println!("HTML Form generated:");
    println!("{}", create_login_form(&mut html_builder));
    println!("\nDialog Form generated:");
    println!("{}", create_login_form(&mut dialog_builder));
  }
} 
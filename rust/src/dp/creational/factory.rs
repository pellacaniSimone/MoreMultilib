
use std::thread;

//---------------------------------------------------------------------------------------
// Factory
//---------------------------------
trait Shape {
  fn draw(&self);
}

struct Circle ;

impl Shape for Circle {
  fn draw(&self) {
    // Logica per disegnare un cerchio.
    println!("Drawing an empty Circle");
    let dim : i32= 10;
    let radius: f32 = dim as f32 / 2.0;
    let center: f32 = radius - 0.5;
    let border_thickness :f32 = 0.5;

    for i in 0..dim {
      for j in 0..dim {
        let dist = ((i as f32 - center).powi(2) + (j as f32 - center).powi(2)).sqrt();
        if dist >= radius - border_thickness && dist <= radius + border_thickness {
          print!(" #");
        } else {
          print!("  ");
        }
      }
      println!();
    }
  }
}

struct Square ;

impl Shape for Square {
  fn draw(&self) {
    println!("Drawing a empty Square");
    let dim = 10;
    for i in 0..dim {
      for j in 0..dim {
        if i == 0 || i == dim - 1 || j == 0 || j == dim - 1 {
          print!(" #");
        } else {
          print!("  ");
        }
      }
      println!();
    }
  }
}

// Factory per creare istanze di forme basate su una stringa.
fn shape_factory(shape_type: &str) -> Option<Box<dyn Shape>> {
  match shape_type {
    "circle" => Some(Box::new(Circle {  })), // Crea un cerchio con raggio 5.
    "square" => Some(Box::new(Square {  })), // Crea un quadrato con lato 10.
    _ => {
      println!("Tipo di forma non supportato.");
      None // return usupported
    }
  }
}

fn mt_factory_example() {
  // unused mt example
  let mut handles = vec![];
  handles.push(thread::spawn(|| {
    if let Some(shape) = shape_factory("circle") {
      shape.draw();
    }
  }));

  handles.push(thread::spawn(|| {
    if let Some(shape) = shape_factory("square") {
      shape.draw();
    }
  }));

  for handle in handles {
    handle.join().unwrap();
  }
}

pub fn factory_example() {
  // None return unsupported
  match shape_factory("circle") {
    Some(shape) => shape.draw(),
    None => println!("Shape not created"),
  }

  match shape_factory("square") {
    Some(shape) => shape.draw(),
    None => {
      println!("Shape not created");
      mt_factory_example()
    },
  }
}




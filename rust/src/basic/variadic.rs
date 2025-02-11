
fn variadic_sum(args: &[i32]) -> i32 {
  args.iter().sum()
}

fn variadic_avg(args: &[i32]) -> f32 {
  if args.is_empty() { 0.0 }
  else { args.iter().sum::<i32>() as f32 / args.len() as f32 }
}

pub fn variadic_test() {
  println!("Sum: {}", variadic_sum(&[3, 1, 2, 3]));
  println!("AVG: {:.2}", variadic_avg(&[5, 1, 2, 3, 4, 5]));
}
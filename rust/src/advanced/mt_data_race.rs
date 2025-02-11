use std::sync::Mutex;
use std::thread;
use std::time::Duration;

//---------------------------------------------------------------------------------------
// Multithread data race
//---------------------------------

static mut UNSAFE_COUNTER: i32 = 0;
static SAFE_COUNTER: Mutex<i32> = Mutex::new(0);

fn random_integer() -> u32 {
  let x = Box::new(0u32);
  let address = &*x as *const u32 as usize;
  address as u32
}

fn increment_safe(increment:i32) {
  thread::sleep(Duration::from_millis(50));
  let mut counter = SAFE_COUNTER.lock().unwrap();
  *counter += increment;
}

fn increment_unsafe(increment:i32) {
  thread::sleep(Duration::from_millis(50));
  unsafe {
    UNSAFE_COUNTER += increment;
  }
}

fn data_race_example() -> bool {
  // Reset dei contatori
  unsafe { UNSAFE_COUNTER = 0; }
  *SAFE_COUNTER.lock().unwrap() = 0;

  let max = 40; // double number of cores
  let mut handles = vec![];
  for _ in 0..max {
    let handle = thread::spawn(|| {
      let base = (random_integer() % 11) as i32; // 0..10
      let increment :i32 = base - 5; // -5..5
      increment_unsafe(increment);
      increment_safe(increment);
    });
    handles.push(handle);
  }

  for handle in handles { handle.join().unwrap();  }

  let safe_total = *SAFE_COUNTER.lock().unwrap();
  let unsafe_total = unsafe { UNSAFE_COUNTER };
  safe_total == unsafe_total
}

fn run_experiment() {
  let mut discrepancies = 0;
  let experiments=100;
  for _ in 0..experiments {
    if !data_race_example() { discrepancies += 1; }
  }
  println!("Discrepanze rilevate: {}/{}", discrepancies,experiments);
}

pub fn multithread_data_race() {
  run_experiment();
}

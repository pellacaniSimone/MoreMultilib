use std::time::{SystemTime, UNIX_EPOCH};

pub fn timedate_handling() {
  let now = SystemTime::now();
  let duration = now.duration_since(UNIX_EPOCH).expect("Time went backwards"); // seconds from time 0
  let secs = duration.as_secs(); 
  let tm = secs / 86400; // days from 0

  // actual 
  let days = tm % 365; 
  let years = tm / 365; 
  let hours = (secs % 86400) / 3600; 
  let minutes = (secs % 3600) / 60; 
  let seconds = secs % 60;
  
  println!("Data corrente: {}-{:02}-{:02}", days, (days % 12) + 1, years + 1970);

  let hours_remaining = 23 - hours;
  let minutes_remaining = 59 - minutes;
  let seconds_remaining = 59 - seconds;

  println!("Ore mancanti alla mezzanotte: {} ore, {} minuti e {} secondi.\n", 
           hours_remaining, minutes_remaining, seconds_remaining);
}

from datetime import datetime, timedelta

class TimeDateHandling:
  def __init__(self):
    self.current_time = datetime.now()

  def print_current_datetime(self):
    print("Data e ora corrente:", self.current_time.strftime("%Y-%m-%d %H:%M:%S"))

  def time_until_midnight(self):
    midnight = (self.current_time + timedelta(days=1)).replace(hour=0, minute=0, second=0, microsecond=0)
    time_left = midnight - self.current_time
    hours_left = time_left.seconds // 3600
    minutes_left = (time_left.seconds // 60) % 60
    seconds_left = time_left.seconds % 60
    print(f"Ore mancanti alla mezzanotte: {hours_left} ore, {minutes_left} minuti e {seconds_left} secondi.")

class TestTimeDate:
  @classmethod
  def run(cls):
    d = TimeDateHandling()
    d.print_current_datetime()
    d.time_until_midnight()
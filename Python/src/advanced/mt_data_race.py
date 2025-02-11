
import threading
import time
import random

# Liste globali condivise, funziona anche con variabili
safe_list = []
unsafe_list = []
# Lock per proteggere la lista sicura
safe_list_lock = threading.Lock()

def unsafe_increment(increment):
  global unsafe_list
  if unsafe_list:
    last = unsafe_list[-1]
    time.sleep(random.uniform(0.0001, 0.001))  # Ritardo artificiale
    unsafe_list.append(last + increment)
  else:
    time.sleep(random.uniform(0.0001, 0.001))  # Ritardo artificiale
    unsafe_list.append(increment)

def safe_increment(increment):
  global safe_list
  with safe_list_lock:
    if safe_list:
      last = safe_list[-1]
      time.sleep(random.uniform(0.0001, 0.001))  # Ritardo artificiale
      safe_list.append(last + increment)
    else:
      time.sleep(random.uniform(0.0001, 0.001))  # Ritardo artificiale
      safe_list.append(increment)

def data_race_example(verbose=False):
  global safe_list, unsafe_list
  safe_list = []  # Svuota liste
  unsafe_list = []  # Svuota liste
  num_threads = 100  # Numero di thread
  threads = []

  #  parte unsafe
  for i in range(0,num_threads): # == (num_threads)
    increment = random.randint(-5, 5)  # Incremento casuale
    thread0 = threading.Thread(target=unsafe_increment, args=(increment,))
    thread1 = threading.Thread(target=safe_increment, args=(increment,))
    threads.append(thread0)
    threads.append(thread1)
    thread0.start()
    thread1.start()


  for thread in threads:
    thread.join()

  if verbose:
    print(f"Valore finale del contatore sicuro: {sum(safe_list)}")
    print(f"Valore finale del contatore non sicuro: {sum(unsafe_list)}")
    print(f"I due contatori sono uguali? {sum(safe_list) == sum(unsafe_list)}")
    
  return sum(safe_list) == sum(unsafe_list)


def grandi_numeri_mt_rc():
  tot = 0
  tgn = 100
  for _ in range(0,tgn):
    if not data_race_example():
      tot += 1
  print(f"I due contatori sono risultati diversi {tot} volte su {tgn}")

class TestDataRace:
  @classmethod
  def run(cls):
    grandi_numeri_mt_rc()
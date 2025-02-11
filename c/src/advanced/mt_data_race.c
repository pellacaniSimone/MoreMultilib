#include "mt_data_race.h"

int safe_counter = 0;
int unsafe_counter = 0;

pthread_mutex_t safe_counter_mutex = PTHREAD_MUTEX_INITIALIZER;

static void* unsafe_increment(void* arg) {
  int increment = *((int*)arg);
  sleep(rand() % 3 * 0.001);  // delay artificiale
  unsafe_counter += increment;
  return NULL;
}

static void* safe_increment(void* arg) {
  int increment = *((int*)arg);
  sleep(rand() % 3 * 0.001);  // delay artificiale
  pthread_mutex_lock(&safe_counter_mutex);
  safe_counter += increment;
  pthread_mutex_unlock(&safe_counter_mutex);
  return NULL;
}

void data_race_example(int verbose) {
  safe_counter = 0;  // reset il contatore sicuro
  unsafe_counter = 0;  // reset il contatore non sicuro

  int num_threads = 100;  // numero di thread
  pthread_t threads[num_threads * 2];
  int increments[num_threads * 2];

  srand(time(NULL));

  // crea e avvia i thread
  for (int i = 0; i < num_threads; i++) {
    increments[i] = rand() % 11 - 5;  // incremento casuale tra -5 e 5 unsafe
    pthread_create(&threads[i], NULL, unsafe_increment, &increments[i]);

    increments[num_threads + i] = rand() % 11 - 5;  // incremento casuale tra -5 e 5 safe
    pthread_create(&threads[num_threads + i], NULL, safe_increment, &increments[num_threads + i]);
  }

  for (int i = 0; i < num_threads * 2; i++)
    pthread_join(threads[i], NULL);

  if (verbose) {
    printf("Valore finale del contatore sicuro: %d\n", safe_counter);
    printf("Valore finale del contatore non sicuro: %d\n", unsafe_counter);
    printf("I due contatori sono uguali? %s\n", safe_counter == unsafe_counter ? "Sì" : "No");
  }
}


void grandi_numeri_mt_rc() {
  int tot = 0;
  int tgn = 100;
  for (int i = 0; i < tgn; i++) {
    data_race_example(0);
    if (safe_counter != unsafe_counter) 
      tot++;
  }
  printf("I due contatori sono risultati diversi %d volte su %d\n", tot, tgn);
}

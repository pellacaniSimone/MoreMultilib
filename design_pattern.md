Ecco una tabella riassuntiva dei **23 design pattern** classici del libro *"Design Patterns: Elements of Reusable Object-Oriented Software"* (Gang of Four), organizzati per categoria, con una breve spiegazione:

---

### **Design Pattern Classici (GoF)**
| **Categoria**       | **Nome**                 | **Spiegazione Breve**                                                                 |
|----------------------|--------------------------|---------------------------------------------------------------------------------------|
| **Creazionali**      | **Abstract Factory**     | Crea famiglie di oggetti correlati senza specificare le classi concrete.              |
|                      | **Builder**              | Separa la costruzione di un oggetto complesso dalla sua rappresentazione.             |
|                      | **Factory Method**       | Definisce un'interfaccia per creare un oggetto, ma lascia alle sottoclassi la scelta. |
|                      | **Prototype**            | Crea nuovi oggetti clonando un prototipo esistente.                                   |
|                      | **Singleton**            | Garantisce che una classe abbia una sola istanza e fornisce un accesso globale.       |
| **Strutturali**      | **Adapter**              | Adatta l'interfaccia di una classe a un'altra interfaccia attesa dal client.          |
|                      | **Bridge**               | Separa un’astrazione dalla sua implementazione, permettendo cambiamenti indipendenti. |
|                      | **Composite**            | Compone oggetti in strutture ad albero per rappresentare gerarchie parte-intero.      |
|                      | **Decorator**            | Aggiunge responsabilità dinamiche a un oggetto in modo flessibile.                    |
|                      | **Facade**               | Fornisce un'interfaccia semplificata a un sottosistema complesso.                     |
|                      | **Flyweight**            | Condivide oggetti per ridurre l'uso di memoria in contesti con molti oggetti simili.  |
|                      | **Proxy**                | Fornisce un sostituto o un segnaposto per un altro oggetto per controllarne l'accesso.|
| **Comportamentali**  | **Chain of Responsibility** | Passa una richiesta lungo una catena di gestori finché uno non la elabora.           |
|                      | **Command**              | Incapsula una richiesta come un oggetto, permettendo operazioni come undo/redo.       |
|                      | **Interpreter**          | Definisce una rappresentazione grammaticale e un interprete per un linguaggio.        |
|                      | **Iterator**             | Fornisce un modo per accedere sequenzialmente agli elementi di una collezione.        |
|                      | **Mediator**             | Centralizza la comunicazione complessa tra oggetti, riducendo gli accoppiamenti.      |
|                      | **Memento**              | Salva e ripristina lo stato interno di un oggetto senza violarne l'incapsulamento.    |
|                      | **Observer**             | Notifica automaticamente gli oggetti "osservatori" di cambiamenti in un soggetto.     |
|                      | **State**                | Permette a un oggetto di modificare il suo comportamento al cambiare del suo stato.   |
|                      | **Strategy**             | Definisce una famiglia di algoritmi, rendendoli intercambiabili.                      |
|                      | **Template Method**      | Definisce lo scheletro di un algoritmo, differendo alcuni passi alle sottoclassi.     |
|                      | **Visitor**              | Aggiunge operazioni a oggetti senza modificarne le classi.                           |

---

### **Altri Pattern Comuni (Non GoF)**
| **Nome**               | **Spiegazione Breve**                                                                 |
|------------------------|---------------------------------------------------------------------------------------|
| **Model-View-Controller (MVC)** | Separa logica di business (Model), interfaccia utente (View) e controllo (Controller).|
| **Dependency Injection** | Inietta dipendenze esterne in un oggetto invece che crearle internamente.            |
| **Repository**          | Astrae l'accesso ai dati, separando la logica di dominio dallo strato di persistenza.|
| **Service Locator**     | Centralizza l'accesso a servizi condivisi in un'applicazione.                        |

---

### Note:
- I pattern **GoF** sono i 23 descritti nel libro fondazionale del 1994.
- Altri pattern (es. MVC, Dependency Injection) sono stati identificati successivamente e sono ampiamente utilizzati in contesti specifici (es. architetture software, testing).
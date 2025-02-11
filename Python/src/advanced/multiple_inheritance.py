
class VeicoloGenerico:
  __secret="sono un segreto" # incapsulamento
  def muovi(self):
    print("Non raggiungibile, errore")
  @property
  def secret(self):
    return self.__secret
  @secret.setter
  def secret(self, value):
    self.__secret = value
  @secret.deleter
  def secret(self):
    del self.__secret


class Auto(VeicoloGenerico):
  def muovi(self):
    print("Veicolo Auto da ora")
  def guida(self):
    self.muovi()
    print("Guida su strada")


class Barca(VeicoloGenerico):
  def muovi(self):
    print("Veicolo Barca da ora")
  def naviga(self):
    self.muovi()
    print("Naviga sull'acqua")


class AmphibiousCar(Auto, Barca):
  __more_secret="sono un segreto senza getter, variabile di classe" # incapsulamento
  def __init__(self):
    Auto.__init__(self)
    Barca.__init__(self)
    self.__more_secret="""
    sono un segreto senza getter, ora variabile di istanza
    non più variabile di classe senza getter quindi solo
    ora vengo aggiunta al dizionario di classe
    """ # incapsulamento
  def muovi(self):
    print("Veicolo anfibio in movimento da ora")


class TestVeicoli:
  @classmethod
  def run(cls):
    print("--- Test property ---")
    gv=VeicoloGenerico()
    print(gv.secret)
    gv.secret="sono un segreto nuovo"
    print(gv.secret)
    print("--- Test AmphibiousCar ---")
    boat = Barca()
    car = Auto()
    amphibious = AmphibiousCar()
    car.guida()  
    boat.naviga()     
    amphibious.muovi()    
    amphibious.naviga()   
    amphibious.guida()   
    print(amphibious.__dict__['_AmphibiousCar__more_secret']) # accesso come variabile di istanza
    print("--- Test polimorfismo ---")
    veicoli = [Barca(), Auto(), AmphibiousCar()]
    for veicolo in veicoli:
      veicolo.muovi()  # Chiamata polimorfica
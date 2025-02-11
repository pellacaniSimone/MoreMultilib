
import argparse
class Frontend:
  def __init__(self):
    self.parser = argparse.ArgumentParser( prog='MoreMultilib',
      description="Classe Frontend per parsing degli input",
      epilog='Obbligatorio un argomento'
    )
    self.parser.add_argument("argomento1", help="Primo argomento posizionale obbligatorio")

  def parse(self):
    return self.parser.parse_args()

# basic
from basic.var import ClasseDerivataEp1
from basic.files import filesHandling
from basic.variadic import SumCalculator
from basic.datetime import TestTimeDate
from basic.union import TestUnion

# advanced
# in python i gli spazi dei nomi si affrontano con la modularità dei file e gli import
from advanced.basic_object import Studente
from advanced.multiple_inheritance import TestVeicoli
from advanced.template_class import TestGenerics
from advanced.template_inheritance import TestGenericsInheritance
from advanced.mro import TestMRO
from advanced.mt_data_race import TestDataRace

# dp creational
from dp.creational.singleton import TestSingleton
from dp.creational.borg import TestBorg
from dp.creational.factory import TestShapeFactory
# dp structural
from dp.structural.decorator import TestDecorators

""" -------------------------------------------------
  test
    -------------------------------------------------
"""


class TestAll:
  @staticmethod
  def run():
    ClasseDerivataEp1.run()
    filesHandling.run()
    SumCalculator.run()
    TestTimeDate.run()
    TestUnion.run()
    # advanced
    Studente.run()
    TestVeicoli.run()
    TestGenerics.run()
    TestGenericsInheritance.run()
    TestMRO.run()
    TestDataRace.run()
    # dp
    TestSingleton.run()
    TestBorg.run()
    TestShapeFactory.run()
    TestDecorators.run()



""" -------------------------------------------------
  main
    -------------------------------------------------
"""

if __name__ == "__main__":
  frontend = Frontend()
  args = frontend.parse()
  # basic
  if args.argomento1 == "test_visibilita_variabili":
    ClasseDerivataEp1.run()
  elif args.argomento1 == "files_handling":
    filesHandling.run()
  elif args.argomento1 == "variadic_example":
    SumCalculator.run()
  elif args.argomento1 == "timedate_handling":
    TestTimeDate.run()
  elif args.argomento1 == "union_test":
    TestUnion.run()
  # advanced
  elif args.argomento1 == "basic_class_example":
    Studente.run()
  elif args.argomento1 == "advanced_class_example":
    TestVeicoli.run()
  elif args.argomento1 == "template_example":
    TestGenerics.run()
  elif args.argomento1 == "template_inheritance":
    TestGenericsInheritance.run()
  elif args.argomento1 == "mro_example":
    TestMRO.run()
  elif args.argomento1 == "multithread_data_race":
    TestDataRace.run()
  # dp
  elif args.argomento1 == "test_singleton": 
    TestSingleton.run()
  elif args.argomento1 == "test_borg": 
    TestBorg.run()
  elif args.argomento1 == "factory_example":
    TestShapeFactory.run()
  elif args.argomento1 == "test_decorators":
    TestDecorators.run()
  elif args.argomento1 == "all":
    TestAll.run()
  else:
    print("Unsupported test")



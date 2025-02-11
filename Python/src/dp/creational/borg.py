
class Singleton:
  """The Borg Queen"""
  _shared_state = {}
  def __init__(self):
     self.__dict__ = self._shared_state


class Borg(Singleton):
  data=None 
  def __init__(self):
     super().__init__()


class Agent:
  """b= entrambi, s=condivisa, l=locale"""
  local_data=None
  def __init__(self, val=None, sync='b'):
    self.shared=Borg()
    if sync == 'b':
      self.shared.data = val
      self.local_data = val
    elif sync == 'l':
      self.local_data = val
    elif sync == 's':
      self.shared.data = val
  def __str__(self):
    return f"Local: {self.local_data}, SharedBorg: {self.shared.data}"


class TestBorg:
  @classmethod
  def run(cls):
    print("Test 1: Condivisione stato base")
    a1 = Agent(10, 'b') # entrambi gli stati
    print(a1)  # Local: 10, SharedBorg: 10
    a2 = Agent(20, 's') # solo memoria condivisa
    print(a2)  # Local: None, SharedBorg:20 
    a3 = Agent(30, 'l') # solo memoria locale
    print(a3)  # Local: 30, SharedBorg:20
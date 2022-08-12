"""
策略模式
描述：定义一系列的算法，把它们一个个封装起来，并且使它们可相互替换。本模式使得算法可独立于使用它的客户而变化。

角色：
    * 抽象策略(Strategy)
    * 具体策略(ConcreteStrategy)
    * 上下文(Context)

优点：
    * 定义了一系列可重用的算法和行为
    * 消除了一些条件语句
    * 可以提供相同行为的不同实现

缺点：
    * 客户必须了解不同的策略
"""
from abc import ABCMeta, abstractmethod


class Strategy(metaclass=ABCMeta):
    @abstractmethod
    def execute(self, data):
        pass



class FastStrategy(Strategy):
    def execute(self, data):
        print(f"用较快的策略处理:{data}")



class SlowStrategy(Strategy):
    def execute(self, data):
        print(f"用较慢的策略处理:{data}")



class Context:
    def __init__(self, strategy=None, data=None) -> None:
        self.strategy = strategy
        self.data = data

    def set_strategy(self, strategy):
        self.strategy = strategy

    def do_strategy(self):
        self.strategy.execute(self.data)



# client
def main():
    data = "[...]"
    s1 = FastStrategy()
    s2 = SlowStrategy()
    content = Context(s1, data)
    content.do_strategy()
    content.set_strategy(s2)
    content.do_strategy()


if __name__ == "__main__":
    main()
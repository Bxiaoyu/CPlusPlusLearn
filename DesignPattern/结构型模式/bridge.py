"""
桥模式
描述：将一个事物的两个维度分离，使其都可以独立的变化

角色：
    * 抽象(Abstraction)
    * 细化抽象(RefinedAbstraction)
    * 实现者(Implementor)
    * 具体实现者(ConcreteImplementor)

适用场景：
    * 当事物有两个维度上的表现，两个维度都可能扩展时

优点:
    * 抽象和实现相分离
    * 优秀的扩展能力

"""
from abc import ABCMeta, abstractmethod


class Shape(metaclass=ABCMeta):
    def __init__(self, color) -> None:
        self.color = color

    @abstractmethod
    def draw(self):
        pass


class Color(metaclass=ABCMeta):
    @abstractmethod
    def paint(self, shape):
        pass


class Rectangle(Shape):
    name = "长方形"
    def draw(self):
        # 长方形逻辑
        self.color.paint(self)


class Circle(Shape):
    name = "圆形"
    def draw(self):
        # 圆形逻辑
        self.color.paint(self)


class Red(Color):
    def paint(self, shape):
        print(f"红色的{shape.name}")


class Green(Color):
    def paint(self, shape):
        print(f"绿色的{shape.name}")


def main():
    rec = Rectangle(Red())
    rec.draw()

    cir = Circle(Green())
    cir.draw()


if __name__ == "__main__":
    main()

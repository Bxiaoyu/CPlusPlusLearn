"""
建造者模式
描述：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
角色：
    * 抽象建造者(Builder)
    * 具体建造者(Concrete Builder)
    * 指挥者(Director)
    * 产品(Product)

优点：
    * 每个具体产品都对应一个具体工厂类，不需要修改工厂类代码
    * 隐藏了对象创建的实现细节
缺点：
    * 每增加一个具体产品类，就必须增加一个相应的具体工厂类
"""
from abc import ABCMeta, abstractmethod
from msilib.schema import SelfReg


class Player:
    def __init__(self, face, body, arm, leg) -> None:
        self.face = face
        self.body = body
        self.arm = arm
        self.leg = leg

    def __str__(self) -> str:
        return f"{self.face}, {self.body}, {self.arm}, {self.leg}"


class PlayerBuilder(metaclass=ABCMeta):
    @abstractmethod
    def build_face(self):
        pass

    @abstractmethod
    def build_body(self):
        pass

    @abstractmethod
    def build_arm(self):
        pass

    @abstractmethod
    def build_leg(self):
        pass


class SexyGirlBuilder(PlayerBuilder):
    def __init__(self) -> None:
        super().__init__()
        self.player = Player()
    
    def build_face(self):
        self.player.face = "酷酷的脸"
    
    def build_body(self):
        self.player.body = "苗条"

    def build_arm(self):
        self.player.arm = "漂亮胳膊"

    def build_leg(self):
        self.player.leg = "大长腿"


class MonsterBuilder(PlayerBuilder):
    def __init__(self) -> None:
        super().__init__()
        self.player = Player()
    
    def build_face(self):
        self.player.face = "恐怖的脸"
    
    def build_body(self):
        self.player.body = "怪兽身材"

    def build_arm(self):
        self.player.arm = "长毛的胳膊"

    def build_leg(self):
        self.player.leg = "长毛的腿"
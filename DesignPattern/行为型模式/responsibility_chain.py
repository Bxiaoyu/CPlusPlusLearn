"""
责任链模式
描述：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连城一条链，
     并沿着这条链传递该请求，直到有一个对象处理它为止。

角色：
    * 抽象处理者(Handler)
    * 具体处理者(ConcreteHandler)
    * 客户端(Client)

应用场景：
    * 有多个对象可以处理一个请求，哪个对象处理由运行时决定
    * 在不明确接收者的情况下，向多个对象中的一个提交一个请求

优点:
    * 降低耦合度：一个对象无需知道是其它哪一个对象处理其请求

"""
from abc import ABCMeta, abstractmethod


# 抽象处理类
class Handler(metaclass=ABCMeta):
    @abstractmethod
    def handle_leave(self, day):
        pass


# 具体处理类
class GeneralManager(Handler):
    def handle_leave(self, day):
        if day <= 10:
            print(f"总经理准假{day}天")
        else:
            print("假期过长，不允批准")


class DepartmentManager(Handler):
    def __init__(self) -> None:
        super().__init__()
        self.next = GeneralManager()

    def handle_leave(self, day):
        if day <= 5:
            print(f"部门主管准假{day}天")
        else:
            print("请交总经理处理")
            self.next.handle_leave(day)


class ProjectDirector(Handler):
    def __init__(self) -> None:
        super().__init__()
        self.next = DepartmentManager()

    def handle_leave(self, day):
        if day <= 1:
            print(f"项目主管准假{day}天")
        else:
            print(f"请交部门主管处理")
            self.next.handle_leave(day)


def main():
    day = 4
    h = ProjectDirector()
    h.handle_leave(day)



if __name__ == "__main__":
    main()

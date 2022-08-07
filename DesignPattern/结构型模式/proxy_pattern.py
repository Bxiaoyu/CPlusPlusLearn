"""
代理模式
描述：为其它对象提供一种代理以控制对这个对象的访问

角色：
    * 抽象实体(Subject)
    * 实体(RealSubject)
    * 代理(Proxy)

应用场景：
    * 远程代理：为远程的对象提供代理
    * 虚代理：根据需要创建很大的对象
    * 保护代理：控制对原始对象的访问，用于对象有不同访问权限时

优点:
    * 远程代理：可以隐藏对象位于远程地址空间的事实
    * 虚代理：可以进行优化，例如根据要求创建对象
    * 保护代理：允许在访问一个对象时有一些附加的内务处理

"""
from abc import ABCMeta, abstractmethod


class Subject(metaclass=ABCMeta):
    @abstractmethod
    def get_content(self):
        pass

    @abstractmethod
    def set_content(self, content):
        pass


class RealSubject(Subject):
    def __init__(self, filename) -> None:
        super().__init__()
        self.filename = filename
        # 读取文件内容
        f = open(self.filename, 'r', encoding='utf-8')
        self.content = f.read()
        f.close()

    def get_content(self):
        return self.content

    def set_content(self, content):
        f = open(self.filename, 'w', encoding='utf-8')
        f.write(content)
        f.close()


class VirtualProxy(Subject):
    def __init__(self, filename) -> None:
        super().__init__()
        self.filename = filename
        self.subj = None

    def get_content(self):
        if not self.subj:
            self.subj = RealSubject(self.filename)
        return self.subj.get_content()

    def set_content(self, content):
        if not self.subj:
            self.subj = RealSubject(self.filename)
        self.subj.set_content(content)


class ProtectedProxy(Subject):
    def __init__(self, filename) -> None:
        super().__init__()
        self.subj = RealSubject(filename)

    def get_content(self):
        return self.subj.get_content()

    def set_content(self, content):
        raise PermissionError("无写入权限")


def main():
    # v = VirtualProxy('test.txt')
    # print(v.get_content())
    p = ProtectedProxy('test.txt')
    print(p.get_content())
    p.set_content("abc")


if __name__ == "__main__":
    main()
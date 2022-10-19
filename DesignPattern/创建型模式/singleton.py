"""
单例模式
描述：保证一个类只有一个实例，并提供一个访问它的全局访问点
角色：
    * 单例(Singleton)
优点：
    * 对唯一实例的受控访问
    * 单例相当于全局变量，但防止了命名空间被污染
缺点：
    
"""
class Singleton:
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, "_instance"):
            cls._instance = super(Singleton, cls).__new__(cls)
        return cls._instance


class MyClass(Singleton):
    def __init__(self, a) -> None:
        super().__init__()
        self.a = a


def main():
    a = MyClass(10)
    b = MyClass(20)
    print(a.a)
    print(b.a)
    print(f"a_id:{id(a)}, b_id:{id(b)}")


if __name__ == "__main__":
    main()

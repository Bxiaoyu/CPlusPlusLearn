"""
简单工厂模式
描述：不直接向客户端暴露对象创建的实现细节，而是通过一个工厂类来负责创建产品类的实例
角色：
    * 工厂角色(Creator)
    * 抽象产品角色(Product)
    * 具体产品角色(Concrete Product)
优点：
    * 隐藏对象创建的实现细节
    * 客户端不需要修改代码
缺点：
    * 违反单一职责原则，将创建逻辑集中到一个工厂类里
    * 当添加新产品时，需要修改工厂类代码，违反了开闭原则
"""
from abc import ABCMeta, abstractmethod


# 抽象产品角色
class Payment(metaclass=ABCMeta):
    @abstractmethod
    def pay(self, money):
        pass


# 具体产品角色
class Alipay(Payment):
    def __init__(self, use_huabei=False) -> None:
        super().__init__()
        self.use_huabei = use_huabei

    def pay(self, money):
        if self.use_huabei:
            print(f"花呗支付{money}元.")
        else:
            print(f"支付宝支付{money}元.")
        

class WechatPay(Payment):
    def pay(self, money):
        print(f"微信支付{money}元.")


# 工厂角色
class PaymentFactory:
    def create_payment(self, method):
        if method == 'alipay':
            return Alipay()
        elif method == 'wechat':
            return WechatPay()
        elif method == 'huabei':
            return Alipay(use_huabei=True)
        else:
            raise TypeError(f"No such payment named {method}!")


def main():
    pf = PaymentFactory()
    p = pf.create_payment('wechat')
    p.pay(100)


if __name__ == "__main__":
    main()

"""
工厂方法模式
描述：定义一个用于创建对象的接口（工厂接口），让子类决定实例化哪一个产品类
角色：
    * 抽象工厂角色(Creator)
    * 具体工厂角色(Concrete Creator)
    * 抽象产品角色(Product)
    * 具体产品角色(Concrete Product)

优点：
    * 每个具体产品都对应一个具体工厂类，不需要修改工厂类代码
    * 隐藏了对象创建的实现细节
缺点：
    * 每增加一个具体产品类，就必须增加一个相应的具体工厂类
"""
from abc import ABCMeta, abstractmethod

# 抽象产品角色
class Payment(metaclass=ABCMeta):
    @abstractmethod
    def pay(self, money):
        pass

# 抽象工厂角色
class PaymentFactory(metaclass=ABCMeta):
    @abstractmethod
    def create_payment(self):
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


class BankPay(Payment):
    def pay(self, money):
        print(f"银行卡支付{money}元.")


# 具体工厂角色
class AlipayFactory(PaymentFactory):
    def create_payment(self):
        return Alipay()


class HuabeiFactory(PaymentFactory):
    def create_payment(self):
        return Alipay(use_huabei=True)


class WechatPayFactory(PaymentFactory):
    def create_payment(self):
        return WechatPay()


class BankPayFactory(PaymentFactory):
    def create_payment(self):
        return BankPay()


def main():
    pf = WechatPayFactory()
    p = pf.create_payment()
    p.pay(100)


if __name__ == "__main__":
    main()
"""
适配器模式
描述：将一个类的接口转换成客户希望的另一个接口。适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

两种实现方式：
    * 类适配器：使用多继承
    * 对象适配器：使用组合

角色：
    * 目标接口(Target)
    * 待适配的类(Adaptee)
    * 适配器(Adapter)

适用场景：
    * 想使用一个已经存在的类，而它的接口不符合你的要求
    * (对象适配器)想使用一些已经存在的子类，但不可能对每一个都进行子类化以匹配它的接口，对象适配器可以适配它的父类接口

"""
from abc import ABCMeta, abstractmethod

# 抽象接口类(目标接口)
class Payment(metaclass=ABCMeta):
    @abstractmethod
    def pay(self, money):
        pass


class Alipay(Payment):
    def pay(self, money):
        print(f"支付宝支付{money}元.")


class WechatPay(Payment):
    def pay(self, money):
        print(f"微信支付{money}元.")

#--------------------------------------------
# 待适配的类，支付接口与前几个不一样，如何组合？
class BankPay:
    def cost(self, money):
        print(f"银联支付{money}元.")


class ApplePay:
    def cost(self, moeny):
        print(f"苹果支付{moeny}元.")
#--------------------------------------------


#---------类适配器--------
class NewBankPay(Payment, BankPay):
    def pay(self, money):
        self.cost(money)


#---------对象适配器--------
class PaymentAdapter(Payment):
    def __init__(self, payment) -> None:
        super().__init__()
        self.payment = payment

    def pay(self, money):
        self.payment.cost(money)


def main():
    # p = NewBankPay()
    # p.pay(100)
    pr = PaymentAdapter(BankPay())
    pr.pay(100)


if __name__ == "__main__":
    main()

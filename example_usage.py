# Import necessary classes from lob.py
from lob import LimitOrderBook, Order

def main():
    # 创建一个限价订单簿实例
    lob = LimitOrderBook()

    # 创建一些订单
    order1 = Order(uid=1, is_bid=True, size=10, price=100)
    order2 = Order(uid=2, is_bid=True, size=5, price=105)
    order3 = Order(uid=3, is_bid=False, size=8, price=110)
    order4 = Order(uid=4, is_bid=False, size=12, price=95)

    # 添加订单到订单簿
    lob.process(order1)
    lob.process(order2)
    lob.process(order3)
    lob.process(order4)

    # 打印当前订单簿状态
    print("Initial Order Book Levels:")
    print(lob.levels())

    # 更新订单
    order1.size = 15
    lob.process(order1)

    # 打印更新后的订单簿状态
    print("\nOrder Book Levels after updating order1:")
    print(lob.levels())

    # 移除订单
    lob.remove(order2)

    # 打印移除订单后的订单簿状态
    print("\nOrder Book Levels after removing order2:")
    print(lob.levels())

if __name__ == "__main__":
    main()
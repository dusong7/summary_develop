动机(Motivation)
---------
在某些情况下我们可能会"过度地使用继承来扩展对象的功能"，由于继承为类型引入的静态特质，是的这种扩展方式缺乏灵活性；并且随着子类的增多（扩展功能的增多），各类子类的组合（拓展功能的组合）会导致更多子类的膨胀。

如何使“对象功能的拓展”能够根据需要来动态地实现？同时避免“拓展功能的增多”带来的子类膨胀问题？从而使得任何“功能拓展变化”所导致的影响降为最低?


模式定义
---------
动态（组合）地给一个对象增加一些额外的职责。就增加功能而言，Decorator模式比生成子类（继承）更为灵活（消除重复代码&减少子类个数）


要点总结
---------
通过采用组合而非继承的手法，Decorator模式实现了在运行时动态拓展对象功能的能力，而且可以根据需要拓展多个功能。避免了使用继承带来的“灵活性差”和“多子类衍生问题”

Decorator类在接口上表现为is-a Component的继承关系，即Decorator类继承了Component类所具有的接口。但在实现上有表现为has-a Component的组合关系，即Decorator类又使用了另外一个Component类

Decorator模式的目的并非解决“多子类衍生的多继承”问题，Decorator模式引用的要点在于解决“主体类在多个方向上的扩展功能”————是为“装饰”的含义


## 装饰者模式：
![Image text](https://github.com/Dylanin1999/Design-Pattern/blob/master/Decorator%EF%BC%88%E8%A3%85%E9%A5%B0%E6%A8%A1%E5%BC%8F%EF%BC%89/img/Decorator.png)


## 普通写法：
![Image text](https://github.com/Dylanin1999/Design-Pattern/blob/master/Decorator%EF%BC%88%E8%A3%85%E9%A5%B0%E6%A8%A1%E5%BC%8F%EF%BC%89/img/Normal.png)

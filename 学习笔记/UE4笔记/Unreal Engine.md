# Unreal Engine

## 1、蓝图基础

> 主要介绍蓝图的概念和使用，事件和变量的知识略过



### 1.1、什么是蓝图[Blueprint]？

> 介绍蓝图概念

* 可以把蓝图看作是内容的**容器**
  * 它可以容纳组件（Components）
  * 它可以保存脚本
  * 它可以保存数据
* 编译的**面向对象**可视化脚本语言
  * 绑定到UE4现有的框架类层次结构中
* 完全**嵌入**UE4中
* 通过将**节点和连接**串在一起并立即查看结果来工作，迭代开发很快
* 蓝图类型
  * <font color=red>关卡蓝图</font> - 每个关卡只有一个，不利于复用
  * <font color=red>蓝图类</font> - 多个（模块化）
* 蓝图与C++
  * 蓝图是基于C++代码构建的
  * 可以在C++中打开/编辑蓝图
  * 蓝图和C++可以一起配合使用



### 1.2 、流程控制

> 主要介绍几个比较常用的流程控制节点



* **Branch（分支）**

  * ![Branch](./image/Branch.png)

    

* **Delay（延迟，可用于计时）**

  * ![Delay](./image/Delay.png)

    

* **Retriggerable Delay（可触发延迟）**

  * ![Retriggerable Delay](./image/RetriggerableDelay.png)

    

* **Do Once（执行一次）**

  * ![DoOnce](./image/DoOnce.png)

    

* **Do N（执行多次）**

  * ![DoN](./image/DoN.png)

    

* **DoOnce MultiInput（一次执行多个输入/输出）**

  * ![DoOnceMultiInput](./image/DoOnceMultiInput.png)

    

* **Flip Flop（翻转，动作1和2交替）**

  * ![FlipFlop](./image/FlipFlop.png)

    

* **Gate（门，开关）**

  * ![Gate](./image/Gate.png)

    

* **MultiGate（多门，一个动作触发不同内容）**

  * ![MultiGate](./image/MultiGate.png)

    

* **Sequence（序列，多个动作可以同时执行）**

  * ![Sequence](./image/Sequence.png)



### 1.3、坐标系

> 主要了解UE4世界坐标系和局部坐标系



#### 1.3.1、游戏开发中的坐标系

在3D游戏开发中，用的是笛卡尔三维坐标系，由于历史原因（没有统一标准）包含两种三维的坐标系：***左手坐标系***和***右手坐标系***。

如何理解左手坐标系和右手坐标系呢？

![Coordinate_left_and_right](./image/coordinateRule.png)



![CoordinateRule](./image/coordinateRule2.png)



#### 1.3.2、UE4的坐标系

在UE4中的所用的坐标系（世界坐标系和局部坐标系）都为***左手坐标系***。 而OpenGL和建模软件3DsMax用的是右手坐标系，需要转换。

**UE4坐标轴旋转轴（Rotation）说明：**

* Pitch是围绕Y轴旋转，也叫做俯仰角
* Yaw是围绕Z轴旋转，也叫偏航角
* Roll是围绕X轴旋转，也叫翻滚角

图示如下：

![Rotation](./image/coordinate.png)



UE4蓝图中的Rotation顺序三个依次为：roll、pitch、yaw。

* ![BlueprintRoll](./image/BlueprintRoll.png)
* ![BlueprintPitch](./image/BlueprintPitch.png)
* ![BlueprintYaw](./image/BlueprintYaw.png)



UE4的C++接口中，FRotator的顺序则依次为：pitch、yaw、roll，这点需要注意。

* ![CPlusPlusRotator](./image/CPlusPlusRotator.png)

* ![CPlusPlusRotator](./image/CPlusPlusRotator2.png)



#### 1.3.3、UE4中坐标系之间的关系

在UE4中，要了解ActorLocation和Mesh的WorldLocation以及RelativeLocation这三种设置的区别。

首先必须了解两个概念，一个是坐标系概念，一个是层级关系。

* 坐标系

![Coordinate](./image/Coordinate2.png)

* 层级关系

![Coordinate](./image/Coordinate3.png)





## 2、UE4的C++编程基础

> 主要记录UE4在C++编程中的比较常用的几个点。

### 2.1、UE4反射用到的宏

主要介绍两个反射宏：***UPROPERTY*** 和 ***UFUNCTION***。具体的使用和参数之类的参考官方文档：[UE4官方文档]([属性 | 虚幻引擎文档 (unrealengine.com)](https://docs.unrealengine.com/4.27/zh-CN/ProgrammingAndScripting/GameplayArchitecture/Properties/))，在宏中可以加入**属性说明符**、**元数据说明符（meta=(...)）**、**分类说明符（Category="AAA"）**等。

* **UPROPERTY**属性宏参数：
  * EditAnywhere：在编辑中可见，且可编辑；
  * EditDefaultsOnly：只在类默认设置中可见；
  * EditInstanceOnly：可通过属性窗口进行编辑，但只能在实例上进行，不能在原型上进行；
  * VisibleAnywhere：在编辑中可见，但不能编辑；
  * BlueprintReadOnly：蓝图只读；
  * BlueprintReadWrite：蓝图可读可写。
* **UFUNTION**函数宏参数:
  * BlueprintCallable：此函数可在蓝图或关卡蓝图图表中执行；
  * BlueprintPure：此函数不对拥有它的对象产生任何影响，可在蓝图或关卡蓝图图表中执行；
  * BlueprintImplementableEvent：需要在蓝图里面重载；
  * BlueprintNativeEvent：此函数旨在被蓝图覆盖掉，但是也具有默认原生实现。用于声明名称与主函数相同的附加函数，单数末尾添加了Implementation，是写入代码的位置，如果未找到任何蓝图覆盖，该自动生成的代码将调用Implementation方法。
  * CallInEditor：可通过细节（Details）面板中的按钮在编辑器中的选定实例上调用此函数。

代码示例：

![Property](./image/UProperty.png)





### 2.2、UE4如何定义枚举和结构体

UE4中定义枚举和结构体大体上和C++是一样的，只是要和蓝图交互的话有些不一样，要增加额外的关键字。



命名规则：

* Axxx：继承自AActor
* Uxxx：继承自UObject
* Fxxx：原生C++
* Exxx：枚举
* Ixxx：接口
* Sxxx：slate



代码示例：

```c++
// 定义枚举类，此写法是C++11的写法
UENUM(BlueprintType)  // 暴露给蓝图
enum class UColorType: uint8
{
	RED,
	GREEN,
	BLUE
};

// 定义结构体
USTRUCT(BlueprintType)  // 暴露给蓝图
struct FTestStruct  
{
	GENERATED_USTRUCT_BODY()  // 增加反射宏
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 num;
};
```





### 2.3、浅析什么是UObject

UObject，它是所有引擎层面、游戏层面对象的基类，为序列化，网络同步，反射，蓝图，等提供了广泛的支持。

重要的功能介绍：

* **反射**：所谓反射，抽象的来说就是程序在运行时动态获取对象信息以及调用对象方法的能力，原生C++不支持反射，  UE4中，UE4反射的功能意义之一就是支持蓝图和C++的交互功能。如UCLASS()、UPROPERTY()、UFUNCTION()等就是应用体现；
* **垃圾回收**（GC）：对对象生命周期的管理，对内存堆中已经死亡的或者长时间没有使用的对象进行清除和回收，有很多垃圾回收算法。原生C++不支持垃圾回收，需要开发人员自行管理；
* **序列化**：将对象的状态信息转换为可以存储或传输的形式的过程；
  * 序列化：把对象转换为字节序列的过程称为对象的序列化
  * 反序列化：把字节序列恢复为对象的过程称为对象的反序列化
* **CDO**（class default object）类默认对象 ：
  * 主要作用就是用于为类提供默认值，例如我们在编辑器中编辑的蓝图类的属性就是保存在该蓝图类的 CDO 中，且在构造此蓝图类的实例时会以其 CDO 作为默认的模板对象来初始化蓝图类实例的属性；
  * CDO 对象是具有稳定的网络路径的，可由网络同步其引用，这使得我们在同步一个 UObject 对象的属性时，仅需同步和 CDO 中不同的属性即可。同样的道理在序列化时也只需保存和 CDO 中不同的差异属性即可。

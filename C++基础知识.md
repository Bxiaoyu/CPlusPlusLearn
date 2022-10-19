# C++基础知识

## 1.指针

### 1.1 指针的基本概念

**指针的作用：**可以通过指针间接访问内存

* 内存编号是从0开始记录的，一般用十六进制数字表示
* 可以利用指针变量保存地址

### 1.2 指针变量的定义和使用

指针变量定义语法：**数据类型 * 变量名**

示例：

```c++
// 指针定义
void define_pointer()
{
	int a = 10; // 定义整形变量a
	int* p = &a; // 定义指针p，记录变量a的地址

	cout << "a的地址：" << &a << endl;
	cout << "指针p为：" << p << endl;

	// 使用指针
	// 指针前加 * 代表解引用，找到指针指向的内存中的数据
	cout << "*p=" << *p << endl;

	*p = 20;
	cout << "a=" << a << endl;
	cout << "*p=" << *p << endl;
}

结果为：
a的地址：007FFD94
指针p为：007FFD94
*p=10
a=20
*p=20
```

### 1.3 指针所占内存空间

指针所占空间的大小取决于操作系统：

* 在32位操作系统下，指针是占4个字节大小，不论是什么数据类型
* 在64位操作系统下，指针是占8个字节大小，不论是什么数据类型

示例：

```c++
// 指针所占空间大小
void pointer_size()
{
	cout << "sizeof(int*) = " << sizeof(int*) << endl;
	cout << "sizeof(float*) = " << sizeof(float*) << endl;
	cout << "sizeof(double*) = " << sizeof(double*) << endl;
	cout << "sizeof(char*) = " << sizeof(char*) << endl;
	cout << "sizeof(string*) = " << sizeof(string*) << endl;
}

结果：
sizeof(int*) = 4
sizeof(float*) = 4
sizeof(double*) = 4
sizeof(char*) = 4
sizeof(string*) = 4
```

### 1.4 空指针和野指针

#### 1.4.1 空指针

**空指针：**指针变量指向内存中编号为0的空间

**用途：**初始化指针变量

**注意：**空指针指向的内存是不可访问的

示例：

```c++
// 空指针
void empty_pointer()
{
	// 1.空指针用于初始化指针变量
	int *p = nullptr;
    cout << *p << endl; // 错误，执行会出错

	// 2.空指针不可以进行访问
	// 0~255之间的内存编号是系统占用的，因此不可以访问
	*p = 100; // 错误，执行会出错
}
```

#### 1.4.2 野指针

**野指针：**指针变量指向非法的内存空间

示例：

```c++
// 野指针
void wild_pointer()
{
	// 野指针
	// 在程序中要避免这种情况
	int *p = (int*)0x1100; // 随便指向一个地址
	cout << *p << endl; // 访问野指针报错
}
```

### 1.5 const修饰指针

const修饰指针有三种情况：

* const 修饰指针 --- 常量指针
* const 修饰常量 --- 指针常量
* const 既修饰指针，又修饰常量

#### 1.5.1 const 修饰指针---常量指针

**含义：**指针的指向可以更改，但是指针指向的值不能更改

示例：

```c++
// const 和 指针
void const_and_pointer()
{
	int a = 10;
	int b = 10;
	// 1.const 修饰指针，常量指针
	// 指针指向可以更改，指针指向的值不能改
	const int* p = &a;
	p = &b; // 正确
	//*p = 20; // 错误
}
```

#### 1.5.2 const 修饰常量---指针常量

**含义：**指针指向不可以更改，但是指针指向的值可以更改

示例：

```c++
// const 和 指针
void const_and_pointer()
{
	int a = 10;
	int b = 10;

	// 2.const修饰常量，指针常量
	// 指针的指向不可以改，指针指向的值可以改
	int* const p1 = &a;
	*p1 = 20; // 正确
	//p1 = &b; // 错误
}
```

#### 1.5.3 const 既修饰指针又修饰常量

**含义：**指针的指向和指针指向的值 都不可以改

示例：

```c++
// const 和 指针
void const_and_pointer()
{
	int a = 10;
	int b = 10;

	// 3.const修饰指针和常量
	// 指针的指向和指针指向的值 都不可以改
	const int* const p2 = &a;
	//p2 = &b;  // 错误
	//*p2 = 20; // 错误
}
```

### 1.6 指针和数组

**作用：**利用指针访问数组元素

示例：

```c++
// 指针和数组
void pointer_and_array()
{
	int arr[5] = { 1,2,3,4,5 };
	// 利用指针访问数组
	int *p = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << *p << endl;
		p++; // 指针偏移
	}
}

结果：
1
2
3
4
5
```

### 1.7 指针和函数

**作用：**利用指针做函数参数，可以修改实参的值



示例：

```c++
// 值传递
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    swap1(a, b); // 值传递不会改变实参
    cout << "swap1 after: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    swap2(&a, &b); // 地址传递会改变实参
    cout << "swap2 after:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    return 0;
}

结果：
swap1 after:
a = 10
b = 20
swap2 after:
a = 20
b = 10
```

### 1.8 指针，数组，函数

**案例描述：**封装一个函数，利用冒泡排序，实现对整形数组的升序排序



示例：

```c++
// 冒泡排序
void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// 打印
void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int arr[5] = { 10,2,1,25,0 };
	bubble_sort(arr, 5);
	printArray(arr, 5);
	return 0;
}

结果：
0
1
2
10
25
```



## 2.结构体

### 2.1 结构体基本概念

结构体属于用户<font color=gold>自定义数据类型</font>，允许用户存储不同的数据类型



### 2.2 结构体的定义和使用

**语法：**`struct 结构体名 {结构体成员列表};`



通过结构体创建变量的三种方式：(struct 关键字可以省略)

* struct 结构体名 变量名
* struct 结构体名 变量名 = {成员1值，成员2值...}
* 定义结构体时顺便创建变量（不是很建议使用）

示例：

```c++
// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
}s3; // 顺便创建结构体变量

int main()
{
	// 1.struct 结构体名 变量名
	struct Student s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 92;
    // 2.struct 结构体名 变量名 = { 成员1值，成员2值... }
	struct Student s2 = { 18, 95, "李四" };
	// 3.定义结构体时顺便创建变量
	s3.name = "王五";
	s3.age = 19;
	s3.score = 90;
}
```

### 2.3 结构体数组

**作用：**将自定义的结构体放入到数组中方便维护

**语法：**`struct 结构体名 数组名[元素个数] = {{}，{}，...{}}`

示例：

```c++
// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
};

int main()
{
	// 创建结构体数组
	struct Student stuArr[3] = {
		{18, 90, "张三"},
		{19, 95, "李四"},
		{20, 93, "王五"}
	};

	// 更改数组中的元素值
	stuArr[2].name = "赵六";

	// 遍历结构体数组
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << stuArr[i].name << " 年龄：" << stuArr[i].age << "分数：" << stuArr[i].score << endl;
	}
	return 0;
}

结果：
姓名：张三 年龄：18分数：90
姓名：李四 年龄：19分数：95
姓名：赵六 年龄：20分数：93
```

### 2.4 结构体指针

**作用：**通过指针访问结构体中的成员

* 利用操作符`->`可以通过结构体指针访问结构体属性

示例：

```c++
// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
};

int main()
{
	// 创建结构体指针
	struct Student* stu = new struct Student(); // 指针一定要初始化，否则会出问题
	stu->name = "张三";
	stu->age = 18;
	stu->score = 96;

	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;

	delete stu;
	return 0;
}

结果：
    姓名：张三 年龄：18 分数：96
```

### 2.5 结构体嵌套结构体

**作用：**结构体中的成员可以是另一个结构体



示例：

```c++
// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
}; // 顺便创建结构体变量

// 教师结构体
struct Teacher {
	// 教师编号
	int id;
	// 教师年龄
	int age;
	// 教师姓名
	string name;
	// 学生信息
	struct Student stu;
};

int main()
{
	// 创建老师
	Teacher t;
	t.name = "老王";
	t.id = 501;
	t.age = 38;
	t.stu.name = "小张";
	t.stu.age = 20;
	t.stu.score = 95;
	return 0;
}
```

### 2.6 结构体做函数参数

**作用：**将结构体作为参数向函数中传递

传递方式（两种）：

* 值传递（实参不会被改变，但效率较低）
* 地址传递（实参可以被改变，效率高，但是有隐患）

```c++
// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
}; // 顺便创建结构体变量

// 打印信息（值传递）
void printInfo(Student s)
{
	cout << "值传递" << endl;
	cout << "姓名\t年龄\t分数" << endl;
	cout << s.name << "\t" << s.age << "\t" << s.score << endl;
}

// 打印消息（地址传递，实参会发生改变）
void printInfo2(Student* s)
{
	cout << "地址传递" << endl;
	cout << "姓名\t年龄\t分数" << endl;
	cout << s->name << "\t" << s->age << "\t" << s->score << endl;
}

int main()
{
	// 创建学生信息
	Student s{ 18, 95, "张三" };
	printInfo(s);
	cout << endl;
	printInfo2(&s);
	return 0;
}

结果：
值传递
姓名    年龄    分数
张三    18      95

地址传递
姓名    年龄    分数
张三    18      95
```

### 2.7 结构体中 const 使用场景

**作用：**用const防止误操作



示例：

```c++
// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
}; // 顺便创建结构体变量

// 打印消息（地址传递，加const防止实参被修改）
void printInfo2(const Student* s)
{
	s->age = 100; // 错误
	cout << "地址传递" << endl;
	cout << "姓名\t年龄\t分数" << endl;
	cout << s->name << "\t" << s->age << "\t" << s->score << endl;
}

int main()
{
	// 创建学生信息
	Student s{ 18, 95, "张三" };
	printInfo(s);
	cout << endl;
	printInfo2(&s);
	return 0;
}
```


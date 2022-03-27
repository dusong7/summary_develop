/*		
单例模式:
	动机:在软件系统中，经常有这样的一些特殊的类，必须保证他们在系统中只存在一个实例，
		 这样才能保证他们的逻辑正确性，以及良好的效率
	如何绕开常规的构造器，提供一种机制来保证一个类只有一个实例？
	(我们不能单单说,我们(类设计者)告诉用户(类使用者)，你就只能实例化一个对象，不要弄多了)
	这应该是类设计者的责任，而不是使用者的责任
	
	模式定义:保证一个类仅有一个实例，并提供一个该实例的全局访问点

	实现版本:
		1、懒汉模式：顾名思义，非常“懒”，懒汉模式不会迫切需要单例模式，只有在第一次需要
					 该单例实例对象的时候才会生成该单例实例对象，之后再获得该单例实例时，
					 该单例实例就是第一次获取时所产生的并返回的静态变量。
					 但是，懒汉模式的问题在于，会导致在多线程的情况下，代码变得不安全
				①、单线程版本   --在多线程下是不安全的
				②、多线程版本   --多线程单独加锁模式，有效简单但消耗大
				③、多线程双检查锁优化版本   --在多线程下的双检查模式，有效的优化了加锁的时机。
				    在除初次生成实例外，此后的所有调用获取单例都不需要加锁,但是会由于指令层面的reorder
					导致，双检查锁的失效。
				④、C++11版本之后的跨版本实现（volatile） --在这种方法下，代码在指令层面不会被reorder，
				    这样就解决了双检查锁失效的问题


		2、饿汉模式：特点，空间换时间，在单例类定义的时候就进行实例化，饿汉模式的优点在于，
					 他是线程安全的。


	要点总结:
		1、Singleton模式中的实例构造器可以设置为protected以允许子类派生
		2、Singleton模式一般不要支持拷贝构造函数和Clone接口，因为这有可能导致多个对象实例，
		   与Singleton模式的初衷违背
		3、如何实现多线程环境下安全的Singleton? 注意对双检查锁的正确实现

*/


#include <iostream>
#include <mutex>
#include <atomic>

class Singleton
{
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};


//线程非安全版本 (普通懒汉模式)
Singleton* Singleton::getInstance()
{
	if (m_instance==nullptr)
	{
		m_instance = new Singleton();
	}
	return m_instance;
}

//线程安全版本，但锁的代价过高 (线程安全的懒汉模式)
Singleton* Singleton::getInstance()
{
	std::mutex lock;
	lock.lock();
	if (m_instance == nullptr)
	{
		m_instance = new Singleton();
	}
	lock.unlock();
	return m_instance;
}

//双检查锁，但是由于内存的读写reorder不安全 (双检查锁的懒汉模式)

/*reorder 问题：再指令层面，代码的调用顺序并不一定是按照我们代码编写的顺序执行，这样就有可能导致
双检查锁的失效*/
/*我们假定的顺序 ：先分配内存，然后执行构造器，然后将地址赋值给m_instance
可能的顺序：先分配内存，然后将地址赋值给m_instance，然后执行构造器  （优化结果）
这样导致的结果就是：在地址被复制给m_instance后，m_instance!=nullptr了，
但是此时，constructor还没有被执行*/

Singleton* Singleton::getInstance() 
{
	if (m_instance==nullptr)
	{
		std::mutex lock;
		lock.lock();
		if (m_instance == nullptr)
		{
			m_instance = new Singleton();
		}
		lock.unlock();
 	}
	return m_instance;
} 

//C++11版本之后的跨版本实现（volatile）

class SingletonCPP
{
private:
	SingletonCPP();
	SingletonCPP(const SingletonCPP& other);
public:
	static SingletonCPP* getInstance();
	static std::atomic<SingletonCPP*> m_instance;
	static std::mutex m_mutex;
};


SingletonCPP* SingletonCPP::getInstance()
{
	SingletonCPP* tmp = m_instance.load(std::memory_order_relaxed);
	std::_Atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	if (tmp==nullptr)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp==nullptr)
		{
			tmp = new SingletonCPP;
			std::_Atomic_thread_fence(std::memory_order_release);//释放内存fence
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}


//饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance();

private:
	static Singleton* m_instance;
	Singleton();
};

Singleton* Singleton::m_instance = new Singleton;
Singleton* Singleton::GetInstance()
{
	return m_instance;
}
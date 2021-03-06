
# MarsTech Dependency Injection
 - [Installation](#installation)
	 - [Configuration](#configuration)
 - [MDI Factory](#mdi-factory)
	 - [MSV_FACTORY_START](#msv_factory_start)
	 - [MSV_FACTORY_GET_n](#msv_factory_get_n)
	 - [MSV_FACTORY_GET_WITH_NAMESPACE_n](#msv_factory_get_with_namespace_n)
	 - [MSV_FACTORY_END](#msv_factory_end)
 - [MDI Injector](#mdi-injector)
 - [Usage Example](#usage-example)
 - [Source code documentation](#source-code-documentation)
 - [License](#license)

MarsTech Dependency Injection (MDI) is a C++ project to make dependency injection easier. There is a set of macros to define [dependency injection factories](#mdi-factory) and a set of macros to define [dependency injection injectors](#mdi-injector).
What is dependency injection good for? The primary usage is for (unit) tests. You can easy mock interface and inject them in (unit) tests.
If you want use this library effectivelly, you should at least know some basics of:
 - C++ Interfaces
 - C++ Dependency Injection
 - C++ (Unit) Testing

## Installation
MDI is header only project/library - there is no static or dynamic library. You can download repository and include header file mdi.h (or one of MdiFactory.h and MdiInjector.h if you need only one of them) to your project.

### Configuration
No configuration is needed - just include MDI header files to your project.

## MDI Factory
MDI factory is object which is injected to class (as pointer or smart pointer) and this object has GET methods to create (uses new (std::nothrow)) injected objects.
What is good for? You don't create required objects in your own class (method) implementation but you get them from MDI factory. Once you write (unit) tests you can easy inject mocked factory (must inherits from your original one) which creates mocks of required objects. 

**Examples:**
~~~cpp
#include "mdi/MdiFactory.h"

//-------------------Test class definitions-------------------

//example interface and its implementation (will be accessible by factory)
class ITestObject { public: virtual ~ITestObject() {  } };
class TestObject: public ITestObject
{
	public:
	TestObject(int x, int y)
	{
		//use or store x, y
	}
	virtual ~TestObject() {  }
};

//example interface and its implementation in namespace (will be accessible by factory)
namespace TestNamespace
{
	class ITestObject { public: virtual ~ITestObject() {  } };
	class TestObject: public ITestObject
	{
		public:
		TestObject()
		{
			
		}
		virtual ~TestObject() {  }
	};
}

//-------------------Factory usage-------------------

MSV_FACTORY_START(MyClassDpiFactory)
	MSV_FACTORY_GET_2(ITestObject, TestObject, int, int)
	MSV_FACTORY_GET_WITH_NAMESPACE_0(TestNamespace, ITestObject, TestNamespace::TestObject)
MSV_FACTORY_END

class MyClass
{
	MyClass(MyClassDpiFactory* pFactory = MyClassDpiFactory::GetMyClassDpiFactory()):
		m_spFactory(pFactory)
	{
		//you can use pFactory here (to get objects)
		//!!!!if you don't store pFactory to smart pointer, you have to delete manually (by delete)
		pFactory->GetITestObject(1, 2);
		pFactory->GetITestObject();
	}
	virtual ~MyClass() {  }
protected:
	//!!!don't use std::unique_ptr - you might have some issues in unit tests with it (std::shared_ptr is absolutelly ok and threre are no issues with it)
	std::shared_ptr<MyClassDpiFactory> m_spFactory;
};
~~~

### MSV_FACTORY_START
Each dependency injetion factory (generated by MDI) must starts by MSV_FACTORY_START. It defines MDI factory name and static method GET (to obtain your factory).

**Example:**
~~~cpp
#include "mdi/MdiFactory.h"

//create class MyClassDpiFactory
MSV_FACTORY_START(MyClassDpiFactory)

//generates:
class MyClassDpiFactory
{
public:
	virtual ~MyClassDpiFactory() {  }
	static std::shared_ptr<MyClassDpiFactory> Get()
	{ \
		return std::shared_ptr<MyClassDpiFactory> (new (std::nothrow) MyClassDpiFactory());
	} 
~~~

### MSV_FACTORY_GET_n
Defines GET method for interface and its implementation. Pass all defined arguments to created object. There are macros supported up to 10 parameters. If your class takes more then 10 arguments you should definitelly think about [MDI Injector](#mdi-injector)

**Example:**
~~~cpp
#include "mdi/MdiFactory.h"

//create class MyClassDpiFactory
MSV_FACTORY_GET_4(IMyClass, MyClass, int, double, int*, std::shared_ptr<int>)

//generates:
virtual std::shared_ptr<IMyClass> GetIMyClass(int arg1, double arg2, int* arg3, std::shared_ptr<int> arg4) const { return std::shared_ptr<IMyClass>(new (std::nothrow) MyClass(arg1, arg2, arg3, arg4)); }
~~~

### MSV_FACTORY_GET_WITH_NAMESPACE_n
Same as [MSV_FACTORY_GET_n](#msv_factory_get_n), but interface is in namespace.

**Example:**
~~~cpp
#include "mdi/MdiFactory.h"

//create class MyClassDpiFactory
MSV_FACTORY_GET_4(IfaceNamespace, IMyClass, ImplNamespace::MyClass, int, double, int*, std::shared_ptr<int>)

//generates:
virtual std::shared_ptr<IfaceNamespace::IMyClass> GetIMyClass(int arg1, double arg2, int* arg3, std::shared_ptr<int> arg4) { return std::shared_ptr<IfaceNamespace::IMyClass>(new (std::nothrow) ImplNamespace::MyClass(arg1, arg2, arg3, arg4)); }
~~~

### MSV_FACTORY_END
Each dependency injetion factory (generated by MDI) must ends by MSV_FACTORY_END. It ends factory definition.
**Example:**
~~~cpp
#include "mdi/MdiFactory.h"

//create class MyMyClassInjector
MSV_FACTORY_END

//generates:
};
~~~

## MDI Injector
MDI Injector is class which holds objects (data, pointers, etc.) required by developed class. Of course, you can pass all these objects to class as constructor parameters. But if you have more objects it can be confusing and MDI Injector can helpfull.
There is a set of macros to easy definition of your class injector. These macros can create injector with up to 15 parameters.

**Examples:**
~~~cpp
#include "mdi/MdiInjector.h"

//create class MyClassInjector
MSV_INJECTOR_4(MyClassInjector, int, m_int, double, m_double, int*, m_pInt, std::shared_ptr<int>, m_spInt);

//generates:
class MyClassInjector
{
public:
	virtual ~MyClassInjector() {  }
	MyClassInjector(int arg1, double arg2, int* arg3, std::shared_ptr<int> arg4):
		m_int(arg1), m_double(arg2), m_pInt(arg3), m_spInt(arg4)
	{}
	int m_int;
	double m_double;
	int* m_pInt;
	std::shared_ptr<int> m_spInt;
};
~~~
~~~cpp
//how to use MyClassInjector from previous example

class MyClass
{
public:
	virtual MyClass(std::share_ptr<MyClassInjector> spInjector):
		m_spInjector(spInjector)
	{
		//you can access injector data here
	}
	virtual ~MyClass() {  }
protected:
	//or you can store injector pointer and access its data in any method
	std::share_ptr<MyClassInjector> m_spInjector;
};
~~~

## Usage Example
There is also an [usage example](https://github.com/Mars2004/msys/tree/master/Example) which uses the most of [MarsTech](https://github.com/Mars2004) projects and libraries.
Its source codes and readme can be found at:
 - [https://github.com/Mars2004/msys/tree/master/Example](https://github.com/Mars2004/msys/tree/master/Example)

## Source code documentation
You can find generated source code documentation at [https://www.marstech.cz/projects/mdi/1.0.1/doc](https://www.marstech.cz/projects/mdi/1.0.1/doc).

## License
This project is released under GNU General Public License version 3. If you can not or do not want to accept GNU GPLv3 license and you would like to use this project under another license, please contact me on [info@marstech.cz](mailto:info@marstech.cz) or visit [www.marstech.cz](https://www.marstech.cz/en).

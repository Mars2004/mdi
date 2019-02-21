/**************************************************************************************************//**
* @defgroup		MDI MarsTech Dependency Injection
* @brief			MarsTech Dependency Injection macros
* @details		Contains implementation and all definitions of MarsTech Dependency Injection.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file		
* @brief			MarsTech Dependency Injection Factory
* @details		Contains implementation and all definitions of MarsTech Dependency Injection Factory.
* @author		Martin Svoboda
* @date			25.07.2018
* @copyright	GNU General Public License (GPLv3).
******************************************************************************************************/


/*
This file is part of MarsTech Dependency Injection.

MarsTech Dependency Injection is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MarsTech Promise Like Syntax is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar. If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef MARSTECH_DEPENDENCY_INJECTION_FACTORY_H
#define MARSTECH_DEPENDENCY_INJECTION_FACTORY_H


#ifndef MSV_INTERFACE_POINTER
#include <memory>

/**************************************************************************************************//**
* @def			MSV_INTERFACE_POINTER(msvIFaceName)
* @brief			Interface pointer type.
* @details		Defines type of pointer interface - classic pointer, shared_ptr, etc.
* @param[in]	msvIFaceName			The interface name.
* @note			For classic pointer define as: #define MSV_INTERFACE_POINTER(msvIFaceName) msvIFaceName*
* @note			See some of MSV_FACTORY_GET_n macros how to use this macro.
* @see			MSV_FACTORY_INNER_GET_BODY
******************************************************************************************************/
#define MSV_INTERFACE_POINTER(msvIFaceName) std::shared_ptr<msvIFaceName>

#ifndef MSV_INTERFACE_CREATE
/**************************************************************************************************//**
* @def			MSV_INTERFACE_CREATE(msvIFaceName, msvIFaceCreate)
* @brief			Interface create.
* @details		Defines how to create interface.
* @param[in]	msvIFaceName			The interface name.
* @param[in]	msvIFaceCreate			Create interface - allocation.
* @note			For classic pointer define as: #define MSV_INTERFACE_CREATE(msvIFaceName, msvIFaceCreate) msvIFaceCreate
* @note			See @ref MSV_FACTORY_INNER_GET_BODY how to use this macro.
* @see			MSV_FACTORY_INNER_GET_BODY
******************************************************************************************************/
#define MSV_INTERFACE_CREATE(msvIFaceName, msvIFaceCreate) std::shared_ptr<msvIFaceName>(msvIFaceCreate)
#endif // !MSV_INTERFACE_CREATE
#endif // !MSV_INTERFACE_POINTER


/**************************************************************************************************//**
* @def			MSV_FACTORY_START(msvFactoryName)
* @brief			Dependecy injection factory start.
* @details		Generates dependency injection factory class (class name, virtual destructor, static GET
*					method to create factory).
* @param[in]	msvFactoryName			The factory name (name of class which will be generated).
* @warning		Each dependency factory definition must starts with this macro.
* @note			Static GET method does not throw exceptions. If allocation/creation fails it returns nullptr.
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_START(msvFactoryName) \
class msvFactoryName \
{ \
public: \
	virtual ~msvFactoryName() {  } \
	static MSV_INTERFACE_POINTER(msvFactoryName) Get() \
	{ \
		return MSV_INTERFACE_CREATE(msvFactoryName, new (std::nothrow) msvFactoryName()); \
	} 

/**************************************************************************************************//**
* @def			MSV_FACTORY_END
* @brief			Dependecy injection factory end.
* @details		Generates dependency injection factory end of class.
* @warning		Each dependency factory definition must ends with this macro.
* @see			MSV_FACTORY_START
******************************************************************************************************/
#define MSV_FACTORY_END };

/**************************************************************************************************//**
* @def			MSV_FACTORY_INNER_GET_BODY(msvImplName, ...)
* @brief			Inner body of GET method.
* @details		Creates GET method body in MSV_FACTORY_GET and MSV_FACTORY_GET_WITH_NAMESPACE macros.
* @param[in]	msvImplName			The implementation name (name of class which will be created).
* @warning		Do not use this macro standalone. It is used as part of MSV_FACTORY_GET and MSV_FACTORY_GET_WITH_NAMESPACE macros.
* @see			MSV_INTERFACE_CREATE
******************************************************************************************************/
#define MSV_FACTORY_INNER_GET_BODY(msvImplName, ...) { return MSV_INTERFACE_CREATE(msvImplName, new (std::nothrow) msvImplName(__VA_ARGS__)); }

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_0(msvIFaceName, msvImplName)
* @brief			Factory GET method without parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without any parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_0 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_0(msvIFaceName, msvImplName) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName() const \
MSV_FACTORY_INNER_GET_BODY(msvImplName)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_0(msvIFaceNamespace, msvIFaceName, msvImplName)
* @brief			Factory GET WITH NAMESPACE method without parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without any parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_0 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_0(msvIFaceNamespace, msvIFaceName, msvImplName) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName() const \
MSV_FACTORY_INNER_GET_BODY(msvImplName)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_1(msvIFaceName, msvImplName, msvArg1)
* @brief			Factory GET method with 1 parameter.
* @details		Creates implementation of factory method Get<msvIFaceName> without 1 parameter.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_1 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_1(msvIFaceName, msvImplName, msvArg1) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_1(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1)
* @brief			Factory GET WITH NAMESPACE method with 1 parameter.
* @details		Creates implementation of factory method Get<msvIFaceName> with 1 parameter.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_1 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_1(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_2(msvIFaceName, msvImplName, msvArg1, msvArg2)
* @brief			Factory GET method with 2 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 2 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_2 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_2(msvIFaceName, msvImplName, msvArg1, msvArg2) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_2(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2)
* @brief			Factory GET WITH NAMESPACE method with 2 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 2 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_2 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_2(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_3(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3)
* @brief			Factory GET method with 3 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 3 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_3 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_3(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_3(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3)
* @brief			Factory GET WITH NAMESPACE method with 3 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 3 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_3 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_3(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_4(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4)
* @brief			Factory GET method with 4 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 4 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_4 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_4(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_4(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4)
* @brief			Factory GET WITH NAMESPACE method with 4 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 4 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_4 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_4(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_5(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5)
* @brief			Factory GET method with 5 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 5 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_5 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_5(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_5(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5)
* @brief			Factory GET WITH NAMESPACE method with 5 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 5 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_5 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_5(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_6(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6)
* @brief			Factory GET method with 6 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 6 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_6 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_6(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_6(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6)
* @brief			Factory GET WITH NAMESPACE method with 6 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 6 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_6 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_6(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_7(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7)
* @brief			Factory GET method with 7 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 7 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_7 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_7(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_7(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7)
* @brief			Factory GET WITH NAMESPACE method with 7 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 7 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_7 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_7(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_8(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8)
* @brief			Factory GET method with 8 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 8 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @param[in]	msvArg8					The type of the eight argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_8 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_8(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7, msvArg8 arg8) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_8(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8)
* @brief			Factory GET WITH NAMESPACE method with 8 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 8 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @param[in]	msvArg8					The type of the eight argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_8 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_8(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7, msvArg8 arg8) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_9(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9)
* @brief			Factory GET method with 9 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 9 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @param[in]	msvArg8					The type of the eight argument.
* @param[in]	msvArg9					The type of the ninth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_9 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_9(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7, msvArg8 arg8, msvArg9 arg9) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_9(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9)
* @brief			Factory GET WITH NAMESPACE method with 9 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 9 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @param[in]	msvArg8					The type of the eight argument.
* @param[in]	msvArg9					The type of the ninth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_9 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_9(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7, msvArg8 arg8, msvArg9 arg9) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_10(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9, msvArg10)
* @brief			Factory GET method with 10 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> without 10 parameters.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @param[in]	msvArg8					The type of the eight argument.
* @param[in]	msvArg9					The type of the ninth argument.
* @param[in]	msvArg10					The type of the tenth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is in namespace, use MSV_FACTORY_GET_WITH_NAMESPACE_10 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_10(msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9, msvArg10) virtual MSV_INTERFACE_POINTER(msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7, msvArg8 arg8, msvArg9 arg9, msvArg10 arg10) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)

/**************************************************************************************************//**
* @def			MSV_FACTORY_GET_WITH_NAMESPACE_10(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9, msvArg10)
* @brief			Factory GET WITH NAMESPACE method with 10 parameters.
* @details		Creates implementation of factory method Get<msvIFaceName> with 10 parameters.
* @param[in]	msvIFaceNamespace		The interface namespace name.
* @param[in]	msvIFaceName			The interface name (GET method will be Get<msvIFaceName>).
* @param[in]	msvImplName				The implementation name (class implementeting interface msvIFaceName).
* @param[in]	msvArg1					The type of the first argument.
* @param[in]	msvArg2					The type of the second argument.
* @param[in]	msvArg3					The type of the third argument.
* @param[in]	msvArg4					The type of the fourth argument.
* @param[in]	msvArg5					The type of the fifth argument.
* @param[in]	msvArg6					The type of the sixth argument.
* @param[in]	msvArg7					The type of the seventh argument.
* @param[in]	msvArg8					The type of the eight argument.
* @param[in]	msvArg9					The type of the ninth argument.
* @param[in]	msvArg10					The type of the tenth argument.
* @warning		Must be used between @ref MSV_FACTORY_START and MSV_FACTORY_END.
* @note			If your interface is not in namespace, use MSV_FACTORY_GET_10 macro.
* @see			MSV_FACTORY_START
* @see			MSV_FACTORY_END
******************************************************************************************************/
#define MSV_FACTORY_GET_WITH_NAMESPACE_10(msvIFaceNamespace, msvIFaceName, msvImplName, msvArg1, msvArg2, msvArg3, msvArg4, msvArg5, msvArg6, msvArg7, msvArg8, msvArg9, msvArg10) virtual MSV_INTERFACE_POINTER(msvIFaceNamespace##::msvIFaceName) Get##msvIFaceName(msvArg1 arg1, msvArg2 arg2, msvArg3 arg3, msvArg4 arg4, msvArg5 arg5, msvArg6 arg6, msvArg7 arg7, msvArg8 arg8, msvArg9 arg9, msvArg10 arg10) const \
MSV_FACTORY_INNER_GET_BODY(msvImplName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)


#endif // !MARSTECH_DEPENDENCY_INJECTION_FACTORY_H

/** @} */	//End of group MDI.

/**************************************************************************************************//**
* @defgroup		MDI MarsTech Dependency Injection
* @brief			MarsTech Dependency Injection macros
* @details		Contains implementation and all definitions of MarsTech Dependency Injection.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file		
* @brief			MarsTech Dependency Injection Injector
* @details		Contains implementation and all definitions of MarsTech Dependency Injection Injector.
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


#ifndef MARSTECH_DEPENDENCY_INJECTION_INJECTOR_H
#define MARSTECH_DEPENDENCY_INJECTION_INJECTOR_H


/**************************************************************************************************//**
* @def			MSV_INJECTOR_INNER_START(msvInjectorName)
* @brief			Inner code of MSV_INJECTOR macros.
* @details		Creates injector start (defines class and virtual destructor).
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @warning		Do not use this macro standalone. It is used as part of MSV_INJECTOR macros.
******************************************************************************************************/
#define MSV_INJECTOR_INNER_START(msvInjectorName) \
class msvInjectorName \
{ \
public: \
	virtual ~msvInjectorName() {  }


/**************************************************************************************************//**
* @def			MSV_INJECTOR_1(msvInjectorName, arg1Type, arg1Name)
* @brief			MDI Injector with 1 injected named member.
* @details		Creates MDI Ijector with 1 injected member. Member type followed by member name
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
******************************************************************************************************/
#define MSV_INJECTOR_1(msvInjectorName, arg1Type, arg1Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1): arg1Name(arg1) {} \
	arg1Type arg1Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_2(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name)
* @brief			MDI Injector with 2 injected named members.
* @details		Creates MDI Ijector with 2 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
******************************************************************************************************/
#define MSV_INJECTOR_2(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2): \
		arg1Name(arg1), arg2Name(arg2) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_3(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name)
* @brief			MDI Injector with 3 injected named members.
* @details		Creates MDI Ijector with 3 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
******************************************************************************************************/
#define MSV_INJECTOR_3(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_4(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name)
* @brief			MDI Injector with 4 injected named members.
* @details		Creates MDI Ijector with 4 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
******************************************************************************************************/
#define MSV_INJECTOR_4(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_5(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name)
* @brief			MDI Injector with 5 injected named members.
* @details		Creates MDI Ijector with 5 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
******************************************************************************************************/
#define MSV_INJECTOR_5(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_6(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name)
* @brief			MDI Injector with 6 injected named members.
* @details		Creates MDI Ijector with 6 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
******************************************************************************************************/
#define MSV_INJECTOR_6(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_7(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name)
* @brief			MDI Injector with 7 injected named members.
* @details		Creates MDI Ijector with 7 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
******************************************************************************************************/
#define MSV_INJECTOR_7(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_8(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name)
* @brief			MDI Injector with 8 injected named members.
* @details		Creates MDI Ijector with 8 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
******************************************************************************************************/
#define MSV_INJECTOR_8(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_9(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name)
* @brief			MDI Injector with 9 injected named members.
* @details		Creates MDI Ijector with 9 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
******************************************************************************************************/
#define MSV_INJECTOR_9(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_10(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name)
* @brief			MDI Injector with 10 injected named members.
* @details		Creates MDI Ijector with 10 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
* @param[in]	arg10Type				The type of the tenth argument.
* @param[in]	arg10Name				The name of the tenth argument.
******************************************************************************************************/
#define MSV_INJECTOR_10(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9, arg10Type arg10): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9), arg10Name(arg10) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
	arg10Type arg10Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_11(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name)
* @brief			MDI Injector with 11 injected named members.
* @details		Creates MDI Ijector with 11 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
* @param[in]	arg10Type				The type of the tenth argument.
* @param[in]	arg10Name				The name of the tenth argument.
* @param[in]	arg11Type				The type of the eleventh argument.
* @param[in]	arg11Name				The name of the eleventh argument.
******************************************************************************************************/
#define MSV_INJECTOR_11(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9, arg10Type arg10, arg11Type arg11): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9), arg10Name(arg10), arg11Name(arg11) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
	arg10Type arg10Name; \
	arg11Type arg11Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_12(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name)
* @brief			MDI Injector with 12 injected named members.
* @details		Creates MDI Ijector with 12 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
* @param[in]	arg10Type				The type of the tenth argument.
* @param[in]	arg10Name				The name of the tenth argument.
* @param[in]	arg11Type				The type of the eleventh argument.
* @param[in]	arg11Name				The name of the eleventh argument.
* @param[in]	arg12Type				The type of the twelfth argument.
* @param[in]	arg12Name				The name of the twelfth argument.
******************************************************************************************************/
#define MSV_INJECTOR_12(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9, arg10Type arg10, arg11Type arg11, arg12Type arg12): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9), arg10Name(arg10), arg11Name(arg11), arg12Name(arg12) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
	arg10Type arg10Name; \
	arg11Type arg11Name; \
	arg12Type arg12Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_13(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name, arg13Type, arg13Name)
* @brief			MDI Injector with 13 injected named members.
* @details		Creates MDI Ijector with 13 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
* @param[in]	arg10Type				The type of the tenth argument.
* @param[in]	arg10Name				The name of the tenth argument.
* @param[in]	arg11Type				The type of the eleventh argument.
* @param[in]	arg11Name				The name of the eleventh argument.
* @param[in]	arg12Type				The type of the twelfth argument.
* @param[in]	arg12Name				The name of the twelfth argument.
* @param[in]	arg13Type				The type of the thirteenth argument.
* @param[in]	arg13Name				The name of the thirteenth argument.
******************************************************************************************************/
#define MSV_INJECTOR_13(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name, arg13Type, arg13Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9, arg10Type arg10, arg11Type arg11, arg12Type arg12, arg13Type arg13): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9), arg10Name(arg10), arg11Name(arg11), arg12Name(arg12), arg13Name(arg13) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
	arg10Type arg10Name; \
	arg11Type arg11Name; \
	arg12Type arg12Name; \
	arg13Type arg13Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_14(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name, arg13Type, arg13Name, arg14Type, arg14Name)
* @brief			MDI Injector with 14 injected named members.
* @details		Creates MDI Ijector with 14 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
* @param[in]	arg10Type				The type of the tenth argument.
* @param[in]	arg10Name				The name of the tenth argument.
* @param[in]	arg11Type				The type of the eleventh argument.
* @param[in]	arg11Name				The name of the eleventh argument.
* @param[in]	arg12Type				The type of the twelfth argument.
* @param[in]	arg12Name				The name of the twelfth argument.
* @param[in]	arg13Type				The type of the thirteenth argument.
* @param[in]	arg13Name				The name of the thirteenth argument.
* @param[in]	arg14Type				The type of the fourteenth argument.
* @param[in]	arg14Name				The name of the fourteenth argument.
******************************************************************************************************/
#define MSV_INJECTOR_14(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name, arg13Type, arg13Name, arg14Type, arg14Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9, arg10Type arg10, arg11Type arg11, arg12Type arg12, arg13Type arg13, arg14Type arg14): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9), arg10Name(arg10), arg11Name(arg11), arg12Name(arg12), arg13Name(arg13), arg14Name(arg14) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
	arg10Type arg10Name; \
	arg11Type arg11Name; \
	arg12Type arg12Name; \
	arg13Type arg13Name; \
	arg14Type arg14Name; \
};

/**************************************************************************************************//**
* @def			MSV_INJECTOR_15(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name, arg13Type, arg13Name, arg14Type, arg14Name, arg15Type, arg15Name)
* @brief			MDI Injector with 15 injected named members.
* @details		Creates MDI Ijector with 15 injected members. Member types followed by member names
*					are expected.
* @param[in]	msvInjectorName		The MDI Injector name (class name).
* @param[in]	arg1Type					The type of the first argument.
* @param[in]	arg1Name					The name of the first argument.
* @param[in]	arg2Type					The type of the second argument.
* @param[in]	arg2Name					The name of the second argument.
* @param[in]	arg3Type					The type of the third argument.
* @param[in]	arg3Name					The name of the third argument.
* @param[in]	arg4Type					The type of the fourth argument.
* @param[in]	arg4Name					The name of the fourth argument.
* @param[in]	arg5Type					The type of the fifth argument.
* @param[in]	arg5Name					The name of the fifth argument.
* @param[in]	arg6Type					The type of the sixth argument.
* @param[in]	arg6Name					The name of the sixth argument.
* @param[in]	arg7Type					The type of the seventh argument.
* @param[in]	arg7Name					The name of the seventh argument.
* @param[in]	arg8Type					The type of the eight argument.
* @param[in]	arg8Name					The name of the eight argument.
* @param[in]	arg9Type					The type of the ninth argument.
* @param[in]	arg9Name					The name of the ninth argument.
* @param[in]	arg10Type				The type of the tenth argument.
* @param[in]	arg10Name				The name of the tenth argument.
* @param[in]	arg11Type				The type of the eleventh argument.
* @param[in]	arg11Name				The name of the eleventh argument.
* @param[in]	arg12Type				The type of the twelfth argument.
* @param[in]	arg12Name				The name of the twelfth argument.
* @param[in]	arg13Type				The type of the thirteenth argument.
* @param[in]	arg13Name				The name of the thirteenth argument.
* @param[in]	arg14Type				The type of the fourteenth argument.
* @param[in]	arg14Name				The name of the fourteenth argument.
* @param[in]	arg15Type				The type of the fifteenth argument.
* @param[in]	arg15Name				The name of the fifteenth argument.
******************************************************************************************************/
#define MSV_INJECTOR_15(msvInjectorName, arg1Type, arg1Name, arg2Type, arg2Name, arg3Type, arg3Name, arg4Type, arg4Name, arg5Type, arg5Name, arg6Type, arg6Name, arg7Type, arg7Name, arg8Type, arg8Name, arg9Type, arg9Name, arg10Type, arg10Name, arg11Type, arg11Name, arg12Type, arg12Name, arg13Type, arg13Name, arg14Type, arg14Name, arg15Type, arg15Name) \
MSV_INJECTOR_INNER_START(msvInjectorName) \
	msvInjectorName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4, arg5Type arg5, arg6Type arg6, arg7Type arg7, arg8Type arg8, arg9Type arg9, arg10Type arg10, arg11Type arg11, arg12Type arg12, arg13Type arg13, arg14Type arg14, arg15Type arg15): \
		arg1Name(arg1), arg2Name(arg2), arg3Name(arg3), arg4Name(arg4), arg5Name(arg5), arg6Name(arg6), arg7Name(arg7), arg8Name(arg8), arg9Name(arg9), arg10Name(arg10), arg11Name(arg11), arg12Name(arg12), arg13Name(arg13), arg14Name(arg14), arg15Name(arg15) \
	{} \
	arg1Type arg1Name; \
	arg2Type arg2Name; \
	arg3Type arg3Name; \
	arg4Type arg4Name; \
	arg5Type arg5Name; \
	arg6Type arg6Name; \
	arg7Type arg7Name; \
	arg8Type arg8Name; \
	arg9Type arg9Name; \
	arg10Type arg10Name; \
	arg11Type arg11Name; \
	arg12Type arg12Name; \
	arg13Type arg13Name; \
	arg14Type arg14Name; \
	arg15Type arg15Name; \
};


#endif // !MARSTECH_DEPENDENCY_INJECTION_INJECTOR_H

/** @} */	//End of group MDI.

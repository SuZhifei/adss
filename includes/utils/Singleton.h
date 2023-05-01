/******************************************************************************

* Copyright (c) 2022，宇通客车股份有限公司

* All rights reserved

* 编写者: 苏志飞

* 编写日期: 2022-05

* 简要描述:  Singleton（线程不安全）
			SingletonS（线程安全）
				
				Singleton(S)是用于定义单例模式的数据结构，可以使用它定义任意类型的
				唯一实例。

			注意：不可使用在两个库之间，否则不会保证是一个实例，可能会产生两个以上的实例
* 修改记录:

*****************************************************************************/
#pragma once
#include "Def.h"
#include <mutex>

namespace yutong{ namespace adss{

template<class T>
class YT_API Singleton
{
public:
	static T *GetInstance()
	{
		if(!t)	t = new T();
		return t;
	}

private:
	static T			*t;
};
template<class T> T *Singleton<T>::t = nullptr;

template<class T>
class SingletonS
{
public:
	static T *GetInstance()
	{
		//加一层判断，减少lock消耗
		if(!t)
		{
			lock.lock();
			if(!t)	t = new T();
			lock.unlock();
		}
		return t;
	}

private:
	static T					*t;
	static std::mutex			lock;
};
template<class T> T *SingletonS<T>::t = nullptr;
template<class T> std::mutex SingletonS<T>::lock;

}}

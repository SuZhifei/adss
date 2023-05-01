#pragma once
#include <vector>
#include <functional>
#include "Def.h"

namespace yutong{
namespace adss{

template<class ArgsT>
class YT_API Event
{
public:
	void addHandler(std::function<void(const ArgsT &args)> handler)
	{
		m_handlers.push_back(handler);
	}

	void removeHandler(std::function<void(const ArgsT &args)> handler)
	{
		for (auto iter = m_handlers.begin(); iter != m_handlers.end();)
		{
			if (iter->target_type() == handler.target_type())
			{
				iter = m_handlers.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void dispatch(const ArgsT &args)
	{
		for (int i = 0; i != m_handlers.size(); ++i)
			if (m_handlers[i])
				m_handlers[i](args);
	}

	void operator += (std::function<void(const ArgsT &args)> handler)
	{
		addHandler(handler);
	}

	void operator -=(std::function<void(const ArgsT &args)> handler)
	{
		remove(handler);
	}

private:
	std::vector<std::function<void(const ArgsT &)>>	m_handlers;
};

}}
#pragma once

#include <atomic>
#include <memory>
#include <chrono>
#include "utils/Def.h"

namespace yutong{
namespace adss{

using namespace std::chrono;
using TimeBase = std::chrono::steady_clock;
using TimePoint = TimeBase::time_point;
using TimeUnit = TimeBase::duration;

struct YT_API LoanBill
{
    using id_type = std::atomic_uint32_t::value_type;
    std::atomic_uint32_t m_instance;
    TimePoint m_expiration;
    std::atomic_flag m_spin;
    void lock()
    {
        while (m_spin.test_and_set(std::memory_order_acquire))
            ;
    }
    void unlock() { m_spin.clear(std::memory_order_release); }
    id_type get_instance() { return m_instance.load(); }
};

template<typename _Ty>
class YT_API LoanedPtr
{
public:
    using type = _Ty;
    using bill_type = LoanBill;
    using reference = type &;
    using pointer = type *;
    using owner = uintptr_t;
    using instance_type = typename bill_type::id_type;
    using this_type = LoanedPtr<type>;
    inline static owner LocalOwner = reinterpret_cast<owner>(nullptr);

public:
    LoanedPtr() = default;
    LoanedPtr(pointer ptr)
        : LoanedPtr(std::unique_ptr<type>(ptr))
    {
    }
    LoanedPtr(std::unique_ptr<type> &&ptr) : LoanedPtr(std::move(ptr), nullptr, LocalOwner)
    {
    }
    LoanedPtr(std::unique_ptr<type> &&ptr, std::unique_ptr<bill_type> &&bill,
              const owner &_owner = LocalOwner)
        : m_bill(std::move(bill)), m_ptr(std::move(ptr)), m_owner(_owner)
    {
    }
    LoanedPtr(LoanedPtr &&) = default;

    LoanedPtr(const LoanedPtr &) = delete;
    LoanedPtr &operator=(const LoanedPtr &) = delete;
    // 		void reset(const pointer& p = 0) noexcept
    // 		{
    // 			this_type(p).swap(*this);
    // 		}
    //
    // 		pointer release() noexcept
    // 		{
    // 			pointer tmp(m_ptr);  m_ptr = 0;  return tmp;
    // 		}

    reference operator*() const noexcept { return *get(); }

    pointer operator->() const noexcept { return get(); }

    pointer get() const noexcept { return m_ptr.get(); }

    bool operator!() const noexcept { return m_ptr == 0; }
    void swap(LoanedPtr &b) noexcept {}
    TimePoint postponed() noexcept { return TimeBase::now(); }

private:
    std::unique_ptr<bill_type> m_bill;
    std::unique_ptr<type> m_ptr;
    instance_type m_instance;
    owner m_owner;
};

}}

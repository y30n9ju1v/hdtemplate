// tuple.h
#pragma once

template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;
	T value;
	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value(v), base(args...) {}
	static constexpr std::size_t N = base::N + 1;
};

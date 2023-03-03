#pragma once
#ifndef _HELPER_H
#define _HELPER_H

#include <iostream>

bool equal(int c1, int c2)
{
	return c1 == c2;
}

bool equal(double c1, double c2)
{
	return std::abs(c1 - c2) < 1.0e-6;
}

template<typename T>
inline void mprint(T* c)
{
	std::cout << *c << " ";
}

#endif
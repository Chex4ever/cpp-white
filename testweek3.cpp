#include <iostream>
#include "src-week3/w3-1.hpp"
#include "src-week3/w3-2.hpp"
#include "src-week3/w3-3.hpp"
#include "src-week3/w3-4.hpp"
#include "src-week3/w3-5.hpp"
#include "src-week3/w3-6.hpp"
#include "src-week3/w3-7.hpp"
#include "src-week3/w3-8.hpp"

void testweek3() {
	std::clog << std::endl << "----------Starting test w3-1-----------------" << std::endl;
	RunTests3w1();
	std::clog << std::endl << "----------Starting test w3-2-----------------" << std::endl;
	RunTests3w2();
	std::clog << std::endl << "----------Starting test w3-3-----------------" << std::endl;
	RunTests3w3();
	std::clog << std::endl << "----------Starting test w3-4-----------------" << std::endl;
	RunTests3w4();
	std::clog << std::endl << "----------Starting test w3-5-----------------" << std::endl;
	RunTests3w5();
	std::clog << std::endl << "----------Starting test w3-6-----------------" << std::endl;
	RunTests3w6();
	std::clog << std::endl << "----------Starting test w3-7-----------------" << std::endl;
	RunTests3w7();
	std::clog << std::endl << "----------Starting test w3-8-----------------" << std::endl;
	RunTests3w8();

	std::clog << std::endl << std::endl << "To be continued..." << std::endl;
}
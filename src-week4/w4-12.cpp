/*
#### Задание по программированию: Работа с сервером времени ####

Вам дана функция *string AskTimeServer()*, про которую известно следующее:

* в процессе своей работы она обращается по сети к удалённому серверу, запрашивая текущее время;
* если обращение к серверу прошло успешно, функция возвращает текущее время в виде строки;
* если в процессе обращения к серверу возникла сетевая проблема, функция выбрасывает исключение
	*system_error*;
* функция может выбрасывать другие исключения, чтобы сообщить о других проблемах.

Используя функцию *AskTimeServer*, напишите класс *TimeServer* со следующим интерфейсом:
```objectivec
class TimeServer {
public:
  string GetCurrentTime();
private:
  string LastFetchedTime = "00:00:00";
};
```

Метод *GetCurrentTime* должен вести себя так:

* он должен вызвать функцию *AskTimeServer*, записать её результат в поле *LastFetchedTime*
	и вернуть значение этого поля;
* если *AskTimeServer* выбросила исключение *system_error*, метод *GetCurrentTime* должен
	его поймать и вернуть текущее значение поля *LastFetchedTime*. Таким образом мы скрываем
	от пользователя сетевые проблемы, возвращая значение, которое было получено при последнем
	успешном обращении к серверу;
* если *AskTimeServer* выбросила другое исключение, метод *GetCurrentTime* должен пробросить
	его дальше, потому что в рамках класса *TimeServer* мы не знаем, как обрабатывать проблемы,
	не связанные со сбоями сети.
*/

#include <string>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <system_error>
#include <thread>
#include "w4-11.hpp"
#include "rational.hpp"

std::string CurrentTime() {
	auto local_time = std::chrono::zoned_time{ std::chrono::current_zone(), floor<std::chrono::seconds>(std::chrono::system_clock::now()) }.get_local_time();
	auto today_time = std::chrono::hh_mm_ss{ local_time - floor<std::chrono::days>(local_time) };
	return std::format("{:%T}", today_time);
}

std::string AskTimeServer(int test = 0) {
	if (test == 0) {
		return CurrentTime();
	}
	else if (test == 1) {
		throw std::runtime_error("Some error.");
	}
	throw std::system_error(EAGAIN, std::system_category());
}

class TimeServer {
public:
	std::string GetCurrentTime(int test = 0) {
		try {
			LastFetchedTime = AskTimeServer(test);
			std::clog << "TimeServer:                 OK: "; //<< std::endl;
		}
		catch (const std::system_error& e) {
			std::clog << "TimeServer: Connection timeout! "; //<< std::endl;

		}

		return LastFetchedTime;
	}
private:
	std::string LastFetchedTime = "00:00:00";
};

void RunTests4w12() {
	TimeServer ts;
	for (int test : {0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 2})
	{
		try {
			std::cout << "Test " << test << ": ";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << ts.GetCurrentTime(test) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Main      : got exception " << e.what() << std::endl;
		}
	}
	std::cout << "  Easy!" << std::endl;

}
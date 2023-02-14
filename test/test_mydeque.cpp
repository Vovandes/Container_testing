#include "mydeque.hpp"

#include <gtest/gtest.h>

//	Реализовать не менее 10 - ти тестовых сценариев для каждого из контейнеров.Конкретные сценарии придумать самостоятельно, но проверять они должны основную функциональность контейнеров : -создание контейнера
//		+- вставка элементов в конец
//		+- вставка элементов в начало
//		+- вставка элементов в середину
//		+- удаление элементов из конца
//		+- удаление элементов из начала
//		+- удаление элементов из середины
//		+- получение элементов из контейнера
//		+- получение размера контейнера(фактическое количество элементов)
// 
//	++Дополнительное задание 1.
//		Реализовать unit - тест на копирование контейнера.Тест должен проверять, что после 
//		копирования одного объекта контейнера в другой содержимое обоих контейнеров одинаково
//	++Дополнительное задание 2.
//		Реализовать unit - тест на удаление контейнера.Тест должен проверять, что для всех 
//		элементов внутри контейнера был вызван деструктор во время уничтожения объекта контейнера.
//	++Дополнительное задание 3. 
//		Добавить unit - тест на перемещение контейнера(вызов перемещающего оператора присваивания).

TEST(Vector, Empty) {
	// Arrange
	mtd::deque<int> deque;

	// Act

	// Assert
	ASSERT_EQ(deque.size(), 0);
	ASSERT_TRUE(deque.empty());
}

TEST(Vector, PushBack) {
	// Arrange
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Assert
	ASSERT_EQ(deque.size(), count);
	ASSERT_FALSE(deque.empty());
}

TEST(Vector, PushFront) {
	// Arrange
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_front(i);
	}

	// Assert
	ASSERT_EQ(deque.size(), count);
	ASSERT_FALSE(deque.empty());
}

TEST(Vector, PopBack) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		deque.pop_back();
	}

	// Assert
	ASSERT_EQ(deque.size(), 0);
	ASSERT_TRUE(deque.empty());
}

TEST(Vector, PopFront) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		deque.pop_front();
	}

	// Assert
	ASSERT_EQ(deque.size(), 0);
	ASSERT_TRUE(deque.empty());
}

TEST(Vector, Insert) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	const std::size_t value{ 77 };
	std::size_t middle{ deque.size() / 2 };
	deque.insert(middle, value);

	// Assert
	ASSERT_EQ(deque.size(), count + 1);
	ASSERT_TRUE(deque[middle - 1] == value);
}

TEST(Vector, Erase) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	std::size_t middle{ deque.size() / 2 };
	deque.erase(middle);

	// Assert
	ASSERT_EQ(deque.size(), count - 1);
	ASSERT_FALSE(deque.empty());
}

TEST(Vector, OperatorAT) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	auto lambda = [&deque]() {
		std::string tmp;
		for (std::size_t i = 0; i < deque.size(); ++i) {
			tmp += std::to_string(deque.at(i));
		}
		return tmp == "0123456789" ? true : false;
	};

	// Assert
	ASSERT_EQ(deque.size(), count);
	ASSERT_TRUE(lambda());
}

TEST(Vector, Size) {
	// Arrange
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}
	// Act

	// Assert
	ASSERT_EQ(deque.size(), count);
	ASSERT_FALSE(deque.empty());
}

TEST(Vector, CopyCtor) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	auto deque2{ deque };

	// Assert
	ASSERT_EQ(deque.size(), deque2.size());
	ASSERT_TRUE(deque == deque2);
}

TEST(Vector, Dtor) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	deque.clear();

	// Assert
	ASSERT_EQ(deque.size(), 0);
	ASSERT_TRUE(deque.empty());
}

TEST(Vector, MoveCtor) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::deque<std::size_t> deque;
	for (std::size_t i = 0; i < count; ++i) {
		deque.push_back(i);
	}

	// Act
	auto deque2{ deque };
	auto deque3{ std::move(deque2) };

	// Assert
	ASSERT_EQ(deque2.size(), count);
	ASSERT_TRUE(deque3 == deque);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

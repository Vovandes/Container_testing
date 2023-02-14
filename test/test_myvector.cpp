#include "myvector.hpp"

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
	mtd::vector<int> vector;

	// Act
	
	// Assert
	ASSERT_EQ(vector.size(), 0);
	ASSERT_TRUE(vector.empty());
}

TEST(Vector, PushBack) {
	// Arrange
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Assert
	ASSERT_EQ(vector.size(), count);
	ASSERT_FALSE(vector.empty());
}

TEST(Vector, PushFront) {
	// Arrange
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_front(i);
	}

	// Assert
	ASSERT_EQ(vector.size(), count);
	ASSERT_FALSE(vector.empty());
}

TEST(Vector, PopBack) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		vector.pop_back();
	}

	// Assert
	ASSERT_EQ(vector.size(), 0);
	ASSERT_TRUE(vector.empty());
}

TEST(Vector, PopFront) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	for (std::size_t i = 0; i < count; ++i) {
		vector.pop_front();
	}

	// Assert
	ASSERT_EQ(vector.size(), 0);
	ASSERT_TRUE(vector.empty());
}

TEST(Vector, Insert) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	const std::size_t value{ 77 };
	std::size_t middle{ vector.size() / 2 };
	vector.insert(middle, value);

	// Assert
	ASSERT_EQ(vector.size(), count + 1);
	ASSERT_TRUE(vector[middle-1] == value);
}

TEST(Vector, Erase) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	std::size_t middle{ vector.size() / 2 };
	vector.erase(middle);

	// Assert
	ASSERT_EQ(vector.size(), count - 1);
	ASSERT_FALSE(vector.empty());
}

TEST(Vector, OperatorAT) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	auto lambda = [&vector]() {
		std::string tmp;
		for (std::size_t i = 0; i < vector.size(); ++i) {
			tmp += std::to_string(vector.at(i));
		}
		return tmp == "0123456789" ? true : false;
	};

	// Assert
	ASSERT_EQ(vector.size(), count);
	ASSERT_TRUE(lambda());
}

TEST(Vector, Size) {
	// Arrange
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}
	// Act

	// Assert
	ASSERT_EQ(vector.size(), count);
	ASSERT_FALSE(vector.empty());
}

TEST(Vector, CopyCtor) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	auto vector2{ vector };

	// Assert
	ASSERT_EQ(vector.size(), vector2.size());
	ASSERT_TRUE(vector == vector2);
}

TEST(Vector, Dtor) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	vector.clear();

	// Assert
	ASSERT_EQ(vector.size(), 0);
	ASSERT_TRUE(vector.empty());
}

TEST(Vector, MoveCtor) {
	// Arrange 
	const std::size_t count{ 10 };
	mtd::vector<std::size_t> vector;
	for (std::size_t i = 0; i < count; ++i) {
		vector.push_back(i);
	}

	// Act
	auto vector2{ vector };
	auto vector3{ std::move(vector2) };

	// Assert
	ASSERT_EQ(vector3.size(), count);
	ASSERT_TRUE(vector3 == vector);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//  В соответствии с вариантом задания разработать рекурсивную функцию для обработки динамического массива.	Определить порядковый номер минимального элемента.
#include <iostream>
#include <cstdlib>  // Для функции rand()
#include <ctime>    // Для функции time()

// Рекурсивная функция для поиска индекса минимального элемента
int findMinIndex(const int *arr, int start, int n, int &minIndex) {
    if (start == n - 1) {
        return minIndex; // База рекурсии: массив полностью обработан
    }

    // Если текущий элемент меньше текущего минимального, обновить minIndex
    if (arr[start] < arr[minIndex]) {
        minIndex = start;
    }

    // Рекурсивный вызов с шагом вперёд
    return findMinIndex(arr, start + 1, n, minIndex);
}

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    // Динамическое выделение массива
    int *arr = new int[n];

    // Заполнение массива случайными числами и вывод его на экран
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
    std::cout << "Массив: ";
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 100;  // Ограничиваем числа от 0 до 99 для наглядности
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Начальное значение для minIndex - 0 (индекс первого элемента)
    int minIndex = 0;
    minIndex = findMinIndex(arr, 0, n, minIndex);

    std::cout << "Индекс минимального элемента: " << minIndex << std::endl;

    // Освобождение выделенной памяти
    delete[] arr;

    return 0;
}

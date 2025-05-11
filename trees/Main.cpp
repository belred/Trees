#include <iostream>
#include <clocale>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <ctime>
#include "SplayTree.h"
#include "AVLTree.h"
#include "BTree.h"
#include <chrono>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> param_t = { {10,3}, {100, 10}, {1000, 20}, {10000, 30}, {100000, 50} };

void file() {
    cout << "1. 10 элементов" << endl;
    cout << "2. 100 элементов" << endl;
    cout << "3. 1000 элементов" << endl;
    cout << "4. 10000 элементов" << endl;
    cout << "5. 100000 элементов" << endl;
    cout << endl << "6. Сформировать новый файл" << endl;
    cout << "7. Выбрать свой файл" << endl;
}

void operation() {
    cout << "1. Вставка по ключу" << endl;
    cout << "2. Удаление по ключу" << endl;
    cout << "3. Поиск по ключу" << endl;
    cout << "4. Обход дерева" << endl;
    cout << "0. Выход" << endl;
}

void type_file() {
    cout << "1. Отсортированный по возрастанию" << endl;
    cout << "2. Отстортированный по убыванию" << endl;
    cout << "3. Неотсортированный" << endl;
}

//вывод таблицы результатов в файл
void table(int arr_time[], string fileName, int arr_count[]) {
    ofstream file(fileName, std::ios::app);
    file << setw(7) << "|" << setw(15) << "Avl-дерево |" << setw(15) << "Splay-дерево |" << setw(10) << "B-дерево" << endl;
    file << setw(7) << "time |" << setw(9) << arr_time[0] << " мкс |" << setw(9) << arr_time[2] << " мкс |" << setw(6) << arr_time[1] << " мкс" << endl;
    file << setw(7) << "count |" << setw(13) << arr_count[0] << " |" << setw(13) << arr_count[2] << " |" << setw(10) << arr_count[1] << endl << endl;
}

//формирование деревьев
void init(AVLTree& avl, SplayTree& spl, BTree& b, int size, string fileName, int* arr) {
    ofstream file(fileName, std::ios::app);
    int arr_time[3];
    int arr_count[3];
    int count = 0;
    // работа с avl-деревом
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        if (avl.search(arr[i], count) == 0) {
            avl.insertion(arr[i], count);
        }
    }
    double time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[0] = time;
    arr_count[0] = count;
    count = 0;
    // работа с b-деревом
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        if (b.search(arr[i], count) == 0) {
            b.insertion(arr[i], count);
        }
    }
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[1] = time;
    arr_count[1] = count;
    count = 0;
    // работа со splay-деревом
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        if (spl.search(arr[i], count) == 0) {
            spl.insertion(arr[i], count);
        }
    }
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[2] = time;
    arr_count[2] = count;
    file << "Формирование дерева" << endl;
    table(arr_time, fileName, arr_count);
    file << endl << endl;
    file.close();
}

//обход
void walk(AVLTree avl, SplayTree spl, BTree b, string fileName) {
    ofstream file(fileName, std::ios::app);
    int arr_time[3];
    int arr_count[3];
    int count = 0;
    // работа с avl-деревом
    auto start = chrono::high_resolution_clock::now();
    avl.tree_walk();
    double time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[0] = time;
    arr_count[0] = count;
    count = 0;
    // работа с b-деревом
    start = chrono::high_resolution_clock::now();
    b.tree_walk();
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[1] = time;
    arr_count[1] = count;
    count = 0;
    // работа со splay-деревом
    start = chrono::high_resolution_clock::now();
    spl.tree_walk();
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[2] = time;
    arr_count[2] = count;
    file << "Обход дерева" << endl;
    table(arr_time, fileName, arr_count);
    file.close();
}

//вставка
void insert(AVLTree& avl, SplayTree& spl, BTree& b, string fileName, int el) {
    ofstream file(fileName, std::ios::app);
    int arr_time[3];
    int arr_count[3];
    int count = 0;
    // работа с avl-деревом
    auto start = chrono::high_resolution_clock::now();
    if (avl.search(el, count) == 0)
        avl.insertion(el, count);
    double time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[0] = time;
    arr_count[0] = count;
    count = 0;
    // работа с b-деревом
    start = chrono::high_resolution_clock::now();
    if (b.search(el, count) == 0)
        b.insertion(el, count);
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[1] = time;
    arr_count[1] = count;
    count = 0;
    // работа со splay-деревом
    start = chrono::high_resolution_clock::now();
    if (spl.search(el, count) == 0)
        spl.insertion(el, count);
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[2] = time;
    arr_count[2] = count;
    file << "Вставка элемента " << el << endl;
    table(arr_time, fileName, arr_count);
    file.close();
}

//удаление
void del(AVLTree& avl, SplayTree& spl, BTree& b, string fileName, int el) {
    ofstream file(fileName, std::ios::app);
    int arr_time[3];
    int arr_count[3];
    int count = 0;
    // работа с avl-деревом
    auto start = chrono::high_resolution_clock::now();
    if (avl.search(el, count) == 1)
        avl.deletion(el, count);
    double time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[0] = time;
    arr_count[0] = count;
    count = 0;
    // работа с b-деревом
    start = chrono::high_resolution_clock::now();
    if (b.search(el, count) == 1)
        b.deletion(el, count);
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[1] = time;
    arr_count[1] = count;
    count = 0;
    // работа со splay-деревом
    start = chrono::high_resolution_clock::now();
    if (spl.search(el, count) == 1)
        spl.deletion(el, count);
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[2] = time;
    arr_count[2] = count;
    file << "Удаление элемента " << el << endl;
    table(arr_time, fileName, arr_count);
    file.close();
}

//поиск
void search(AVLTree avl, SplayTree& spl, BTree b, string fileName, int el) {
    ofstream file(fileName, std::ios::app);
    int arr_time[3];
    int arr_count[3];
    int count = 0;
    // работа с avl-деревом
    auto start = chrono::high_resolution_clock::now();
    avl.search(el, count);
    double time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[0] = time;
    arr_count[0] = count;
    count = 0;
    // работа с b-деревом
    start = chrono::high_resolution_clock::now();
    b.search(el, count);
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[1] = time;
    arr_count[1] = count;
    count = 0;
    // работа со splay-деревом
    start = chrono::high_resolution_clock::now();
    spl.search(el, count);
    time = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
    arr_time[2] = time;
    arr_count[2] = count;
    file << "Поиск элемента " << el << endl;
    table(arr_time, fileName, arr_count);
    file.close();
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    srand(time(0));
    system("color F0");

    cout << "Данная программа осуществляет заполнение сбалансированных деревьев (avl-дерево, splay-дерево, b-дерево) данными, операции: вставка, удаление, поиск по ключу, центрированный обход, и записывает время и количество итераций, требуемых для выполнения этих операций в текстовый файл.";
    cout << endl << endl << "Для начала работы нажмите любую клавишу!";
    _getch();
    system("cls");

    // выбор файла
    cout << "Список готовых файлов с тестовыми данными: " << endl;
    file();
    cout << endl << "Выберите готовый файл или сформируйте новый файл: ";
    int choice; cin >> choice;
    while (choice < 1 || choice > 7) {
        cout << endl << endl << "Такой функции нет.\nИзмените свой выбор." << endl << endl;
        cout << "Нажмите на любую клавишу.";
        _getch();
        system("cls");

        cout << "Список готовых файлов с тестовыми данными: " << endl;
        file();
        cout << endl << "Выберите готовый файл или сформируйте новый файл: ";
        cin >> choice;
    }
    system("cls");

    int choice_type;
    //выбор типа файла
    if (choice != 7) {
        cout << "Выберите тип файла:" << endl;
        type_file();
        cout << "Ваш выбор: ";
        cin >> choice_type;
        while (choice_type < 1 || choice_type > 3) {
            cout << endl << endl << "Такого типа файла нет." << endl << endl;
            cout << "Выберите тип файла:" << endl;
            type_file();
            cout << "Ваш выбор: ";
            cin >> choice_type;
        }
    }
    string filename;
    switch (choice) {
    case 1: {
        switch (choice_type) {
        case 1: {
            filename = "10 asc.txt";
            break;
        }
        case 2: {
            filename = "10 desc.txt";
            break;
        }
        case 3: {
            filename = "10 not sorted.txt";
            break;
        }
        }
        break;
    }
    case 2: {
        switch (choice_type) {
        case 1: {
            filename = "100 asc.txt";
            break;
        }
        case 2: {
            filename = "100 desc.txt";
            break;
        }
        case 3: {
            filename = "100 not sorted.txt";
            break;
        }
        }
        break;
    }
    case 3: {
        switch (choice_type) {
        case 1: {
            filename = "1000 asc.txt";
            break;
        }
        case 2: {
            filename = "1000 desc.txt";
            break;
        }
        case 3: {
            filename = "1000 not sorted.txt";
            break;
        }
        }
        break;
    }
    case 4: {
        switch (choice_type) {
        case 1: {
            filename = "10000 asc.txt";
            break;
        }
        case 2: {
            filename = "10000 desc.txt";
            break;
        }
        case 3: {
            filename = "10000 not sorted.txt";
            break;
        }
        }
        break;
    }
    case 5: {
        switch (choice_type) {
        case 1: {
            filename = "100000 asc.txt";
            break;
        }
        case 2: {
            filename = "100000 desc.txt";
            break;
        }
        case 3: {
            filename = "100000 not sorted.txt";
            break;
        }
        }
        break;
    }
    case 6: {
        cout << "Введите количество элементов для формирования файла: ";
        int size; cin >> size;
        cout << endl << "Обратите внимание, что файл должен иметь расширение .txt" << endl;
        cout << endl << "Введите название файла: ";
        cin.ignore();
        getline(cin, filename);

        // формирование файла
        ofstream file;
        file.open(filename);
        file << size << endl;
        int start = -size / 2;
        vector<int> vec;
        int el = start;
        while (vec.size() != size) {
            vec.push_back(el);
            el++;
        }
        switch (choice_type) {
        case 1: {
            sort(vec.begin(), vec.end());
            break;
        }
        case 2: {
            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());
            break;
        }
        case 3: {
            for (int i = 0; i < size; i++) {
                swap(vec[i], vec[rand() % size]);
            }
            break;
        }
        }
        for (int i = 0; i < vec.size(); i++)
            file << vec[i] << endl;
        file.close();
        // конец формирования файла
        system("cls");

        cout << "Файл успешно сформирован!" << endl;
        cout << endl << "Для продолжения нажмите любую клавишу." << endl;
        _getch();
        break;
    }
    case 7: {
        cout << "Обратите внимание, что файл должен иметь расширение .txt" << endl;
        cout << endl << "Введите название файла: ";
        cin.ignore();
        getline(cin, filename);
        break;
    }
    }

    ifstream file;
    file.open(filename);
    int size;   
    system("cls");

    cout << "Введите название файла, в который будут сохранены результаты." << endl;
    cout << "Обратите внимание, что файл должен иметь расширение .txt" << endl;
    cout << "Название файла: ";
    string fileName_now;
    cin.ignore();
    getline(cin, fileName_now);

    // открытие файла для сохранения результатов
    ofstream f(fileName_now);
    f << "Деревья сформированы на основе файла " << filename << endl << endl;
    f.close();
    if (file.is_open()) {
        file >> size;
        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            int el;
            file >> el;
            arr[i] = el;
        }
        file.close();
        //формирование деревьев
        AVLTree root_avl;
        SplayTree root_spl;
        int i = 0;
        while (size < param_t[i].first) i++;
        BTree root_b(param_t[i].second);
        init(root_avl, root_spl, root_b, size, fileName_now, arr);

        system("cls");
        cout << "Деревья успешно сформированы! Данные о времени и количестве итераций записаны в файл \"" << fileName_now << "\"." << endl;
        cout << endl << endl << "Для продолжения работы нажите любую клавишу!";
        _getch();
        system("cls");

        // выбор операции
        cout << "Список операций: " << endl;
        operation();
        cout << endl << "Выберите операцию из списка: ";
        cin >> choice;
        while (choice < 0 || choice>4) {
            cout << endl << endl << "Такой операции нет." << endl << endl;
            cout << "Список операций: " << endl;
            operation();
            cout << endl << "Выберите операцию из списка: ";
            cin >> choice;
        }
        system("cls");

        //выполнение операции
        while (choice != 0) {
            switch (choice) {
            case 1: {//вставка
                cout << "Элемент для вставки должен быть целым числом.";
                cout << endl << "Введите элемент: ";
                int el; cin >> el;
                insert(root_avl, root_spl, root_b, fileName_now, el);
                break;
            }
            case 2: {//удаление
                cout << "Элемент для удаления должен быть целым числом.";
                cout << endl << "Введите элемент: ";
                int el; cin >> el;
                del(root_avl, root_spl, root_b, fileName_now, el);
                break;
            }
            case 3: {//поиск
                cout << "Элемент для поиска должен быть целым числом.";
                cout << endl << "Введите элемент: ";
                int el; cin >> el;
                search(root_avl, root_spl, root_b, fileName_now, el);
                break;
            }
            case 4: {//обход
                walk(root_avl, root_spl, root_b, fileName_now);
                system("cls");
                break;
            }
            }

            cout << "Операция выполнена успешно! Данные о времени и количестве итераций записаны в файл " << fileName_now << endl;
            cout << endl << endl << "Для продолжения работы нажите любую клавишу!";
            _getch();
            system("cls");

            cout << "Список операций: " << endl;
            operation();
            cout << endl << "Выберите операцию из списка: ";
            cin >> choice;

            system("cls");
        }
    }
    cout << "Выход из программы. Нажмите enter!" << endl;
    _getch();
}
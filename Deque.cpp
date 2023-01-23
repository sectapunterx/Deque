#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
//1-Проверка на наличие элементов в структуре данных
//2-Получение количества элементов  в структуре данных
//3-Добавление элемента в указанный конец структуры данных
//4-Удаление элемента из указанного конца структуры данных
//5-Очистка структуры данных
//6-Чтение элемента из указанной вершины (головы) структуры данных

struct Plane
{
    string name;
    string model;
    string year;
    string max_speed;
    string height;
    string max_distance;
    string max_people;
    string max_weight;
    string fuel;
    string fuel_consumption;
};

struct Deque
{
    Plane* data;
    Deque* head;
    Deque* tail;
};

Deque* head = nullptr;
Deque* tail = nullptr;

void create_node(Deque* deque)
{
    deque->data = new Plane;
    cout << "Введите название самолета: ";
    cin >> deque->data->name;
    cout << "Введите модель самолета: ";
    cin >> deque->data->model;
    cout << "Введите год выпуска самолета: ";
    cin >> deque->data->year;
    cout << "Введите максимальную скорость самолета: ";
    cin >> deque->data->max_speed;
    cout << "Введите высоту полета самолета: ";
    cin >> deque->data->height;
    cout << "Введите максимальную дальность полета самолета: ";
    cin >> deque->data->max_distance;
    cout << "Введите максимальное количество пассажиров самолета: ";
    cin >> deque->data->max_people;
    cout << "Введите максимальную грузоподъемность самолета: ";
    cin >> deque->data->max_weight;
    cout << "Введите емкость топлива самолета: ";
    cin >> deque->data->fuel;
    cout << "Введите расход топлива самолета: ";
    cin >> deque->data->fuel_consumption;
}

bool isEmpty()
{
    if(head == nullptr)
    {
        cout << "Дек пуст" << endl;
        return true;
    }
    else cout << "Дек не пуст" << endl;
    return false;
}

int size()
{
    int size = 0;
    Deque* deque = head;
    while(deque != nullptr)
    {
        size++;
        deque = deque->tail;
    }
    cout << "Размер дека: " << size << endl;
    return size;
}

void push_back()
{
    Deque* deque = new Deque;
    create_node(deque);
    deque->tail = nullptr;
    if(head == nullptr)
    {
        deque->head = nullptr;
        head = deque;
        tail = deque;
    }
    else
    {
        deque->head = tail;
        tail->tail = deque;
        tail = deque;
    }
}
void delete_front()
{
    if(isEmpty())
        return;
    else
    {
        Deque* deque = head;
        head = head->tail;
        delete deque;
    }
}

void delete_back()
{
    if(isEmpty()) return;
    Deque* deque = tail;
    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->head;
        tail->tail = nullptr;
    }
    delete deque;
}
void clear_all()
{
    while(!isEmpty())
    {
        delete_back();
    }
}
void read_info_head() {
    if (!isEmpty()) {
        cout << "Название самолета: " << head->data->name << endl;
        cout << "Модель самолета: " << head->data->model << endl;
        cout << "Год выпуска самолета: " << head->data->year << endl;
        cout << "Максимальная скорость самолета: " << head->data->max_speed << endl;
        cout << "Высота полета самолета: " << head->data->height << endl;
        cout << "Максимальная дальность полета самолета: " << head->data->max_distance << endl;
        cout << "Максимальное количество пассажиров самолета: " << head->data->max_people << endl;
        cout << "Максимальная грузоподъемность самолета: " << head->data->max_weight << endl;
        cout << "Емкость топлива самолета: " << head->data->fuel << endl;
        cout << "Расход топлива самолета: " << head->data->fuel_consumption << endl;
        delete_front();
    }
    else return;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    while (true)
    {
        cout << "Выберите операцию:" << endl;
        cout << "1. Добавить элемент в конец списка" << endl;
        cout << "2. Удалить элемент из конца списка" << endl;
        cout << "3. Проверить, является ли список пустым" << endl;
        cout << "4. Получить количество элементов в списке" << endl;
        cout << "5. Очистить список" << endl;
        cout << "6. Прочитать элемент из головы списка" << endl;
        cout << "7. Выйти" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                push_back();
                break;
            case 2:
                delete_back();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                size();
                break;
            case 5:
                clear_all();
                break;
            case 6:
                read_info_head();
                break;
            case 7:
                return 0;
            default:
                cout << "Неверный ввод" << endl;
                break;
        }
    }
    return 0;
}

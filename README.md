# lab-3
Лабораторная №3
1. main.cpp - демонстрация утечки памяти
   - Каждый раз, когда создаётся новый объект Book, вызывается конструктор, который выводит сообщение "Add new book", но при завершении программы деструктор не вызывается, и сообщение "Remove book" не выводится. Это приводит к утечке памяти, так как выделенная память для объектов не возвращается в систему.
2. uniqeu.cpp - использование std::unique_ptr для управления выделенной памятью
   - Создается массив, который будет хранить уникальные указатели на объекты Book. В цикле for создаются 10 объектов Book с помощью std::make_unique<Book>(), и каждый объект добавляется в массив. Когда программа завершает выполнение, массив указателей выходит из области видимости, и все объекты Book автоматически уничтожаются, вызывая их деструкторы. На экран выводится 10 сообщений "Add new book" и 10 - "Remove book". Утечки памяти нет.
3. shared.cpp - разделяемое владение ресурсом с помощью std::shared_ptr
   - Программа создает класс Image, который создает изображения, и класс Window, который отображает эти изображения. С помощью std::shared_ptr реализуется совместное использование объекта Image, что позволяет нескольким объектам Window ссылаться на одно и то же изображение. Умные указатели автоматически управляют временем жизни объекта Image, гарантируя, что память будет освобождена, когда на объект больше не останется ссылок, что предотвращает утечки памяти. В результате, когда программа завершается, деструкторы объектов вызываются автоматически, и память освобождается корректно.
4. weak.ptr - наблюдение за объектом без продления времени жизни с помощью std::weak_ptr
   - Создается кэш, который хранит в себе изображения. Метод displayImages проверяет, существуют ли изображения в кэше. Если изображение было уничтожено, выводится сообщение об этом.После выхода из области видимости (где создавались изображения) происходит уничтожение объектов, и при следующем вызове displayImages отображаются сообщения о том, что изображения были удалены.
5. raii 

# lab-3
Лабораторная №3
1. main.cpp - демонстрация утечки памяти
   - Каждый раз, когда создаётся новый объект Book, вызывается конструктор, который выводит сообщение "Add new book", но при завершении программы деструктор не вызывается, и сообщение "Remove book" не выводится. Это приводит к утечке памяти, так как выделенная память для объектов не возвращается в систему.
2. uniqeu.cpp - использование std::unique_ptr для управления выделенной памятью
   - 

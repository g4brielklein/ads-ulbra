import 'package:flutter/material.dart';
import 'Pages/todo_list.dart';

void main() {
  runApp(AppTodo());
}

class AppTodo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "To-do List - Biblioteca de livros",
      debugShowCheckedModeBanner: false,
      home: TodoList(),
    );
  }
}
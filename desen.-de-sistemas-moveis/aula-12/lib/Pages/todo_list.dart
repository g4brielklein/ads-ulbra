import 'package:flutter/material.dart';
import 'package:sqflite/sqlite_api.dart';
import 'package:todo_list_flutter/Models/todo.dart';
import 'package:todo_list_flutter/Pages/todo_detail.dart';
import 'package:todo_list_flutter/Utils/database_helper.dart';

class TodoList extends StatefulWidget {
  @override
  _TodoListState createState() => _TodoListState();
}

class _TodoListState extends State<TodoList> {
  DatabaseHelper databaseHelper = DatabaseHelper();
  List<Todo> todoList = List<Todo>();

  @override
  void initState() {
    super.initState();
    updateListView();
    debugPrint(todoList.length.toString());
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Biblioteca de Livros'),
      ),
      body: getTodosListView(),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          debugPrint('Click');
          navigateToDetail(
              Todo('', '', '', '', ''), 'Adicionando livro na biblioteca:');
        },
        tooltip: '+ 1 Book',
        child: Icon(Icons.add),
      ),
    );
  }

  Widget getTodosListView() {
    return ListView.builder(
      itemCount: todoList.length,
      itemBuilder: (BuildContext context, int position) {
        Todo todo = todoList[position];
        return Card(
          margin: EdgeInsets.all(7.0),
          color: Colors.white,
          elevation: 4.0,
          child: ListTile(
            leading: CircleAvatar(
              backgroundColor: Colors.blue,
              child: Text(getAvatar(todo.title),
                  style: TextStyle(fontWeight: FontWeight.bold)),
            ),
            title: Text('Título: ' + todo.title,
                style: TextStyle(fontWeight: FontWeight.bold, fontSize: 17)),
            subtitle: Text.rich(TextSpan(
              text: 'Autor: ',
              style: TextStyle(fontWeight: FontWeight.bold, fontSize: 14),
              children: [
                TextSpan(
                    text: todo.author,
                    style: TextStyle(fontWeight: FontWeight.normal)),
                TextSpan(
                    text: '\nEditora: ',
                    style:
                        TextStyle(fontWeight: FontWeight.bold, fontSize: 14)),
                TextSpan(
                    text: todo.publisher,
                    style: TextStyle(fontWeight: FontWeight.normal)),
                TextSpan(
                    text: '\nLivro lido? ',
                    style:
                        TextStyle(fontWeight: FontWeight.bold, fontSize: 14)),
                TextSpan(
                    text: todo.read,
                    style: TextStyle(fontWeight: FontWeight.normal))
              ],
              /*subtitle: Text(
                  'Autor: ' +
                  todo.author +
                  ' \nEditora: ' +
                  todo.publisher +
                  '\nLivro lido? ' +
                  todo.read,*/
              //style: TextStyle(fontWeight: FontWeight.bold),
            )),
            trailing: GestureDetector(
                child: Icon(
                  Icons.delete,
                  color: Colors.blueAccent,
                ),
                onTap: () {
                  _delete(context, todo);
                }),
            onTap: () {
              print("Lista de livros");
              navigateToDetail(todo, todo.title);
            },
          ),
        );
      },
    );
  }

  getAvatar(String title) {
    if (title.length < 2) {
      return '';
    } else {
      return title.substring(0, 2);
    }
  }

  void _showSnackBar(BuildContext context, String message) {
    final snackBar = SnackBar(content: Text(message));
    Scaffold.of(context).showSnackBar(snackBar);
  }

  void navigateToDetail(Todo todo, String title) async {
    Navigator.push(context, MaterialPageRoute(builder: (context) {
      return TodoDetail(todo, title);
      //debugPrint("Chamou a segunda tela");
    })).then((result) {
      if (result ?? true) {
        updateListView();
      }
    });
  }

  void _delete(BuildContext ctx, Todo todo) async {
    int result = await databaseHelper.deleteTodo(todo.id);
    if (result != 0) {
      _showSnackBar(ctx, "Apagando livro da biblioteca...");
      updateListView();
    }
  }

  void updateListView() {
    final Future<Database> dbFuture = databaseHelper.initializeDatabase();
    dbFuture.then((database) {
      Future<List<Todo>> todoListFuture = databaseHelper.getTodoList();
      todoListFuture.then((todoList) {
        setState(() {
          this.todoList = todoList;
        });
      });
    });
  }
}
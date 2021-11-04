import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:todo_list_flutter/Models/todo.dart';
import 'package:todo_list_flutter/Utils/database_helper.dart';


class TodoDetail extends StatefulWidget {
  final String appBarTitle;
  final Todo todo;

  TodoDetail(this.todo, this.appBarTitle);
  @override
  _TodoDetailState createState() {
    return _TodoDetailState(this.todo, this.appBarTitle);
  }
}

class _TodoDetailState extends State<TodoDetail> {
  DatabaseHelper helper = DatabaseHelper();

  String appBarTitle;
  Todo todo;

  TextEditingController titleController = TextEditingController();
  TextEditingController authorController = TextEditingController();
  TextEditingController publisherController = TextEditingController();
  TextEditingController readController = TextEditingController();

  _TodoDetailState(this.todo, this.appBarTitle);

  @override
  Widget build(BuildContext context) {
    TextStyle textStyle = Theme.of(context).textTheme.bodyText1;
    titleController.text = todo.title;
    authorController.text = todo.author;
    publisherController.text = todo.publisher;
    readController.text = todo.read;

    return Scaffold(
      appBar: AppBar(
        title: Text(appBarTitle),
        leading: IconButton(
            icon: Icon(Icons.arrow_back),
            onPressed: () {
              moveToLastScreen();
            }),
      ),
      body: Padding(
        padding: EdgeInsets.only(top: 15.0, left: 10.0, right: 10.0),
        child: ListView(
          children: <Widget>[
            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: titleController,
                style: textStyle,
                onChanged: (value) {
                  debugPrint('PASSOU');
                  updateTitle();
                },
                decoration: InputDecoration(
                    labelText: 'Titulo',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),
            

            // 3 elemento
            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: authorController,
                style: textStyle,
                onChanged: (value) {
                  debugPrint('PASSOU2');
                  updateAuthor();
                },
                decoration: InputDecoration(
                    labelText: 'Autor',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: publisherController,
                style: textStyle,
                onChanged: (value) {
                  debugPrint('PASSOU3');
                  updatePublisher();
                },
                decoration: InputDecoration(
                    labelText: 'Editora',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: readController,
                style: textStyle,
                onChanged: (value) {
                  debugPrint('PASSOU3');
                  updateRead();
                },
                decoration: InputDecoration(
                    labelText: 'Lido',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            // quarto Elemento
            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: Row(
                children: <Widget>[
                  Expanded(
                    child: RaisedButton(
                      color: Theme.of(context).primaryColorDark,
                      textColor: Theme.of(context).primaryColorLight,
                      child: Text(
                        'Salvar',
                        textScaleFactor: 1.5,
                      ),
                      onPressed: () {
                        setState(() {
                          debugPrint("Click salvar");
                          _save();
                        });
                      },
                    ),
                  ),
                  Container(
                    width: 5.0,
                  ),
                  Expanded(
                    child: RaisedButton(
                      color: Theme.of(context).primaryColorDark,
                      textColor: Theme.of(context).primaryColorLight,
                      child: Text(
                        'Apagar',
                        textScaleFactor: 1.5,
                      ),
                      onPressed: () {
                        setState(() {
                          debugPrint("Apagar clicado");
                          _delete();
                        });
                      },
                    ),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }

  void moveToLastScreen() {
    Navigator.pop(context, true);
  }

  void updateTitle() {
    todo.title = titleController.text;
  }

  void updateAuthor() {
    todo.author = authorController.text;
  }

  void updatePublisher() {
    todo.publisher = publisherController.text;
  }

  void updateRead() {
    todo.read = readController.text;
  }

  void _save() async {
    moveToLastScreen();

    todo.date = DateFormat.yMMMd().format(DateTime.now());
    int result;
    if (todo.id != null) {
      // Caso 1: Atualizar
      result = await helper.updateTodo(todo);
    } else {
      // Caso 2: Inserir
      result = await helper.insertTodo(todo);
    }

    if (result != 0) {
      // Succeso
      _showAlertDialog('Status', 'Salvo com sucesso $result');
    } else {
      // deu erro
      _showAlertDialog('Status', 'Erro!');
    }
  }

  void _delete() async {
    moveToLastScreen();

    if (todo.id == null) {
      _showAlertDialog('Status', 'Não há nada a deletar');
      return;
    }
    int result;
      result = await helper.deleteTodo(todo.id);
    if (result != 0) {
      _showAlertDialog('Status', 'Menos uma coisa a fazer!');
    } else {
      _showAlertDialog('Status', 'Deu pau!');
    }
  }

  void _showAlertDialog(String title, String message) {
    AlertDialog alertDialog = AlertDialog(
      title: Text(title),
      content: Text(message),
    );
    showDialog(context: context, builder: (_) => alertDialog);
  }
}
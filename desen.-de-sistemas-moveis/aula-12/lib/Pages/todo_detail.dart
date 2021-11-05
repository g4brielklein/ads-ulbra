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

      // #1 - ELEMENTO TITULO
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
                  //debugPrint('');
                  updateTitle();
                },
                decoration: InputDecoration(
                    labelText: 'Titulo',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            // #2 - ELEMENTO AUTOR
            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: authorController,
                style: textStyle,
                onChanged: (value) {
                  //debugPrint('');
                  updateAuthor();
                },
                decoration: InputDecoration(
                    labelText: 'Autor',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            // #3 - ELEMENTO EDITORA
            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: publisherController,
                style: textStyle,
                onChanged: (value) {
                  //debugPrint('');
                  updatePublisher();
                },
                decoration: InputDecoration(
                    labelText: 'Editora',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            // #4 - ELEMENTO CONFIRMAÇÃO DE LEITURA
            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: TextField(
                controller: readController,
                style: textStyle,
                onChanged: (value) {
                  //debugPrint('');
                  updateRead();
                },
                decoration: InputDecoration(
                    labelText: 'Livro lido? (Sim / Não)',
                    labelStyle: textStyle,
                    border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(5.0))),
              ),
            ),

            Padding(
              padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
              child: Row(
                children: <Widget>[
                  // #4 - BOTÃO PARA APAGAR
                  Expanded(
                    child: RaisedButton(
                      color: Colors.red,
                      //color: Theme.of(context).primaryColorDark,
                      textColor: Theme.of(context).primaryColorLight,
                      child: Text(
                        'Apagar',
                        style: TextStyle(color: Colors.white),
                        textScaleFactor: 1.5,
                      ),
                      onPressed: () {
                        setState(() {
                          debugPrint("Delete executado");
                          _delete();
                        });
                      },
                    ),
                  ),
                  Container(
                    width: 5.0,
                  ),

                  // #4 - BOTÃO PARA SALVAR
                  Expanded(
                    child: RaisedButton(
                      color: Colors.green.shade700,
                      //Style: ButtonStyle(minimumSize: MaterialStateProperty.all(Size(100,100))),
                      //color: Theme.of(context).primaryColorDark,
                      textColor: Theme.of(context).primaryColorLight,

                      child: Text(
                        'Salvar',
                        style: TextStyle(color: Colors.white),
                        textScaleFactor: 1.5,
                      ),
                      onPressed: () {
                        setState(() {
                          debugPrint("Save Executado");
                          _save();
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
      // ATUALIZAÇÃO
      result = await helper.updateTodo(todo);
    } else {
      // INSERÇÃO
      result = await helper.insertTodo(todo);
    }

    if (result != 0) {
      // MENSAGEM DE OK NO SAVE
      _showAlertDialog('Status', 'Livro "$result" salvo na biblioteca');
    } else {
      // MENSAGEM DE ERRO NO SAVE
      _showAlertDialog('Status', 'Erro! Tente novamente!');
    }
  }

  void _delete() async {
    moveToLastScreen();

    if (todo.id == null) {
      _showAlertDialog('Status', 'Não tem livro para apagar!');
      return;
    }
    int result;
    result = await helper.deleteTodo(todo.id);
    if (result != 0) {
      _showAlertDialog('Status', 'Livro excluído da biblioteca!');
    } else {
      _showAlertDialog('Status', 'Erro! Tente novamente!');
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
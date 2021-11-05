import 'dart:io';
import 'package:path_provider/path_provider.dart';
import 'package:sqflite/sqflite.dart';
import 'package:todo_list_flutter/Models/todo.dart';

class DatabaseHelper {
  static DatabaseHelper _databaseHelper; // SINGLETON / PADRAO DE PROJETO
  static Database _database; // SINGLETON DATABASE
  String todoTable = 'todo_table';
  String colId = 'id';
  String colTitle = 'title';
  String colAuthor = 'author';
  String colPublisher = 'publisher';
  String colRead = 'read';
  String colDate = 'date';

  DatabaseHelper._createInstancia(); // CONSTRUTOR NOMEADO

  factory DatabaseHelper() {
    if (_databaseHelper == null) {
      _databaseHelper = DatabaseHelper._createInstancia();
    }
    return _databaseHelper;
  }

  void _createDb(Database db, int newVersion) async {
    await db.execute(
        'CREATE TABLE $todoTable($colId INTEGER PRIMARY KEY AUTOINCREMENT, $colTitle TEXT, $colAuthor TEXT, $colPublisher TEXT, $colRead TEXT, $colDate TEXT)');
  }

  Future<Database> initializeDatabase() async {
    Directory diretorio = await getApplicationDocumentsDirectory();
    String path = diretorio.path + "todonew.db";
    var todoDatabase =
        await openDatabase(path, version: 1, onCreate: _createDb);
    return todoDatabase;
  }

  Future<Database> get database async {
    if (_database == null) {
      _database = await initializeDatabase();
    }
    return _database;
  }

// ADD
  Future<int> insertTodo(Todo todo) async {
    Database db = await this.database;
    var result = db.insert(todoTable, todo.toMap());
    return result;
  }

// UPDATE
  Future<int> updateTodo(Todo todo) async {
    Database db = await this.database;
    //db.query("Update from todotable .............. where id=id")
    var result = db.update(todoTable, todo.toMap(),
        where: '$colId =?', whereArgs: [todo.id]);
    return result;
  }

// SELECTION MAPS
  Future<List<Map<String, dynamic>>> getTodoMapList() async {
    Database db = await this.database;
    //var result = await db.rawQuery('SELECT * FROM $todoTable order by $colTitle ASC');
    var result = await db.query(todoTable, orderBy: '$colTitle');
    return result;
  }

  Future<List<Todo>> getTodoList() async {
    var todoMapList = await getTodoMapList();
    //int count = todoMapList.length;
    int count = todoMapList.length;
    List<Todo> todoList = List<Todo>();
    for (int i = 0; i < count; i++) {
      todoList.add(Todo.fromMapObject(todoMapList[i]));
    }
    return todoList;
  }

// DELETE
  Future<int> deleteTodo(int id) async {
    Database db = await this.database;
    //db.query("Update from todotable .............. where id=id")
    //var result=db.update(todoTable, todo.toMap(),where: '$colId =?',whereArgs: [todo.id] );
    //db.delete(table)
    //id = todo.id
    int result = await db.rawDelete('DELETE FROM $todoTable  WHERE $colId=$id');
    return result;
  }

// SELECIONAR TOTAL DE LINHAS
  Future<int> getCount() async {
    Database db = await this.database;
    List<Map<String, dynamic>> x =
        await db.rawQuery('SELECT COUNT(*) from $todoTable');
    int result = Sqflite.firstIntValue(x);
    return result;
  }

// GETCOUNT2
  Future<List<Todo>> getCount2() async {
    var todoMapList = await getTodoMapList();
    int count = todoMapList.length;
  }
}
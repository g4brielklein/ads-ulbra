class Todo {
  int _id;
  String _title;
  String _author;
  String _publisher;
  String _read;
  String _date;

  Todo(this._title, this._author, this._publisher, this._read,
      this._date); // CONTRUTOR OBJETO
  Todo.comId(this._id, this._title, this._author, this._publisher, this._read,
      this._date); // CONSTRUTOR NOMEADO

  int get id => _id;

  String get title => _title;

  String get author => _author;

  String get publisher => _publisher;

  String get read => _read;

  String get date => _date;

  set title(String newTitle) {
    if (newTitle.length <= 100) {
      this._title = newTitle;
    }
  }

  set author(String newAuthor) {
    this._author = newAuthor;
  }

  set publisher(String newPublisher) {
    this._publisher = newPublisher;
  }

  set read(String newRead) {
    this._read = newRead;
  }

  set date(String newDate) {
    this._date = newDate;
  }

  Map<String, dynamic> toMap() {
    // CONVERTE UM OBJETO PARA UM MAPA
    var map = Map<String, dynamic>();
    if (id != null) {
      map['id'] = _id;
    }
    map['title'] = _title;
    map['author'] = _author;
    map['publisher'] = _publisher;
    map['read'] = _read;
    map['date'] = _date;
    return map;
  }

  Todo.fromMapObject(Map<String, dynamic> map) {
    // PEGA O MAPA E CONVERTE PARA OBJETO
    this._id = map['id'];
    this._title = map['title'];
    this.author = map['author'];
    this.publisher = map['publisher'];
    this.read = map['read'];
    this._date = map['date'];
  }
}
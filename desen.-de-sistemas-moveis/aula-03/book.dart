import 'dart:io';

class Book {
  String? name;
  String? description;
  double? price;
  String? isbn;

  void show() {
    print("-----------");
    print(this.name);
    print(description);
    print(price);
    print("ISBN: ${isbn}");
  }

  void read() {
    print("Type book's name here:");
    this.name = stdin.readLineSync()!;
    print("Type book's description here");
    this.description = stdin.readLineSync()!;
    print("Type book's isbn here");
    this.isbn = stdin.readLineSync()!;
    print("Type book's price here");
    this.price = double.parse(stdin.readLineSync()!);
  }

  void applyDiscount(por) {
    if (por > 0.8) {
      this.price = this.price! * por;
    } else {
      this.price = this.price! * 0.80;
    }
  }

}
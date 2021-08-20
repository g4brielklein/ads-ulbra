import 'book.dart';

main(List<String> args) {
  Book l1 = Book();
  l1.read();
  l1.applyDiscount(0.85);
  l1.show();
}
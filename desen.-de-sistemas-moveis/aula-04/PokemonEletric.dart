import 'Pokemon.dart';

class PokemonEletric extends Pokemon {
  PokemonEletric(String name, double weight) : super(name, "Eletric", weight);

  void atack() {
    print('${this.name} Eletric Pokemon Atack! ${this.weight}');
  }

  void SpecialAtack() {
    print('${this.name} Special Atack! ${this.weight}');
  }

  void NaturalEvolution(String name) {
    this.name = name;
  }

  void RocksEvolution(String name, String rock) {
    this.name = name;
    print('Using ${rock} rock');
  }

}
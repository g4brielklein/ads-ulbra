abstract class Pokemon {
  String? _name;
  String? _family;
  double? _weight;

  void atack() {
    print('${this.name} Atack! ${this.weight}');
  }

  String get name => _name!.toUpperCase();
  String get family => _family!.toUpperCase();
  double get weight => _weight!;

  set weight(double w) {
    if (w > 0 && w < 100) {
      _weight = w;
    } else {
      _weight = 1;
    }
  }

  set name(String n) {
    if (n.isNotEmpty) {
      _name = n;
    } else {
      _name = "Unamed";
    }
  }

  set family(String f) {
    if (f.isNotEmpty) {
      _family = f;
    } else {
      _name = "Unamed";
    }
  }

  Pokemon (String name, String family, double weight) {
    this.name = name;
    this.family = family;
    this.weight = weight;
  }

  Pokemon.Evolve (String name, String family) {
    this.name = name;
    this.family = family;
    this.weight = 60;
  }

}
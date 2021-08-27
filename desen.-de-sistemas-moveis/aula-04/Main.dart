import 'Pokemon.dart';
import 'PokemonEletric.dart';

main(List<String> args) {

  PokemonEletric pk = PokemonEletric("Picachu", 80);
  pk.atack();
  pk.RocksEvolution("Raichu Gigamax", "Gold");
  pk.SpecialAtack();

  // PokemonNormal pk2 = PokemonNormal("Snorlax", 20);
  // pk2.atack();

  Pokemon pk3 = PokemonEletric("Raichu", 30);
  pk3.atack();

}
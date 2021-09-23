import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Aula | ULBRA',
      home: Scaffold(
        backgroundColor: Colors.black,
        appBar: AppBar(
          iconTheme: IconThemeData(),
          backgroundColor: Colors.grey[800],
          title: Text(
            'Aula | ULBRA',
            style: TextStyle(color: Colors.white),
          ),
        ),
        
        drawer: Drawer(),
        
        body: Padding(
          padding: EdgeInsets.all(16.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [Header(), BadgeCard(), BadgeCard()],
          ),
        ),
      ),
    );
  }
}

class Header extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text('Salas Virtuais',
              style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold, fontSize: 22.0)),
        ],
      ),
    );
  }
}

class CaixaCards extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: EdgeInsets.only(top: 16.0, bottom: 16.0),
      child: Column(
        children: [
          CardMateria(),
          CardMateriaBaixo(),
        ],
      ),
    );
  }
}

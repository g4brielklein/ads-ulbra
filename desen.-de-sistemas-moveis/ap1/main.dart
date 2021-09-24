import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
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
          padding: EdgeInsets.all(20.0),
          child: Column(
            children: [
                Header()
              , Class()
              , Class()
            ],
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
              style: TextStyle(color: Colors.white
                              , fontWeight: FontWeight.bold
                              , fontSize: 22.0)
                              ),
        ],
      ),
    );
  }
}

class ContainerCards extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: EdgeInsets.only(top: 16.0, bottom: 16.0),
      child: Column(
        children: [
          CardClass(),
          CardInfo(),
        ],
      ),
    );
  }
}

class CardClass extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 140.0,
      width: double.infinity,
      child: Card(
          margin: EdgeInsets.all(0.0),
          shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.only(
                  topLeft: Radius.circular(4.0),
                  topRight: Radius.circular(4.0))),
          color: Colors.green[900],
          child: Padding(
            padding: EdgeInsets.only(
                top: 32.0, left: 16.0, right: 16.0, bottom: 24.0),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              mainAxisAlignment: MainAxisAlignment.end,
              children:
               [
                Text(
                  'Desenvolvimento de Sistemas Móveis',
                  style: TextStyle(fontWeight: FontWeight.w500,color: Colors.white,fontSize: 20
                      ),
                ),
                SizedBox(height: 8.0),
                Text(
                  'Turma: 0658-A - 51N - Graduação',
                  style: TextStyle(
                      color: Colors.white,
                      fontWeight: FontWeight.w300,
                      fontSize: 12)
                ),
              ],
            ),
          )),
    );
  }
}

class Class extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(top: 8.0, bottom: 8.0),
      child: Column(
        children: [
          Stack(children: [
            ContainerCards(),
            SizedBox(
              height: 20,
              width: 80,
              child: Card(
                margin: EdgeInsets.all(0.0),
                shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.only(
                        topLeft: Radius.circular(15.0),
                        topRight: Radius.circular(15.0),
                        bottomRight: Radius.circular(15.0))),
                color: Colors.white,
                child: Container(
                  alignment: Alignment.center,
                  child: Text(
                    '152103',
                    style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                  ),
                ),
              ),
            ),
          ])
        ],
      ),
    );
  }
}


class CardInfo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 120.0,
      width: double.infinity,
      child: Card(
        margin: EdgeInsets.all(0.0),
        child: Column(
          children: [
            Notifications()
            ],
        ),
      ),
    );
  }
}

class ButtonEnterRoom extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SizedBox(
      child: Column(
        children: [
          Padding(
            padding: EdgeInsets.only(top: 16.0, bottom: 16.0),
            child: SizedBox(
              height: 40.0,
              width: double.infinity,
              child: Padding(
                padding: EdgeInsets.only(left: 16.0, right: 16.0),
                // ignore: deprecated_member_use
                child: RaisedButton(
                  onPressed: () {},
                  color: Colors.green[700],
                  child: Text(
                    'Entrar na sala',
                    style: TextStyle(color: Colors.white, fontSize: 14),
                  ),
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}


class Notifications extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SizedBox(
      child: Column(
        children: [
          Padding(
            padding: EdgeInsets.only(top: 16.0),
            child: SizedBox(
              width: 160.0,
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Icon(
                    Icons.star,
                    size: 30,
                    color: Colors.grey,
                  ),
                  Icon(
                    Icons.chat_bubble_outlined,
                    size: 30,
                    color: Colors.grey,
                  ),
                  Icon(
                    Icons.info_rounded,
                    size: 30,
                    color: Colors.grey,
                  ),
                ],
              ),
            ),
          ), ButtonEnterRoom()
        ],
      ),
    );
  }
}
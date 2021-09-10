import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primaryColor: Color(0xFFF3F7FA),
        primaryTextTheme: TextTheme(
          headline6: TextStyle(
            color: Colors.orange,
            fontSize: 30,
          ),
        ),
      ),
      home: MyHomePage(
        title: 'inter',
      ),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key? key, required this.title}) : super(key: key);

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: PreferredSize(
        preferredSize: Size.fromHeight(70.0), // here the desired height
        child: AppBar(
          title: Text(widget.title),
          // titleTextStyle: ,
          actions: <Widget>[
            IconButton(
              onPressed: () {},
              icon: Padding(
                padding: EdgeInsets.all(5.0),
                child: Icon(
                  Icons.search,
                  color: Color(0xFFFF7B00),
                ),
              ),
            ),
            IconButton(
              onPressed: () {},
              icon: Padding(
                padding: EdgeInsets.all(5.0),
                child: Icon(
                  Icons.menu,
                  color: Color(0xFFFF7B00),
                ),
              ),
            ),
          ],
        ),
      ),
      body: Center(
          child: Padding(
        padding: EdgeInsets.all(15.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          children: <Widget>[
            Row(
              children: [
                Column(
                  children: [
                    Text(
                      "R\$ 1.000.000.000,00",
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        color: Colors.black,
                        fontSize: 25,
                      ),
                    ),
                  ],
                ),
                Column(
                  children: [
                    Padding(
                      padding: EdgeInsets.only(left: 5.0),
                      child: Icon(
                        Icons.remove_red_eye_outlined,
                        color: Color(0xFFFF7B00),
                      ),
                    )
                  ],
                )
              ],
            ),
            Row(
              children: [
                Padding(
                  padding: EdgeInsets.only(top: 15.0, bottom: 15.0),
                  child: Text(
                    "Ver extrato",
                    style: TextStyle(
                      fontWeight: FontWeight.bold,
                      color: Colors.orange,
                      fontSize: 14,
                    ),
                  ),
                )
              ],
            ),
            Row(
              children: [
                Wrap(
                  runSpacing: 15.0,
                  spacing: 15.0,
                  children: [
                    OptionCard(icon: Icons.credit_card, name: 'Cartões'),
                    OptionCard(icon: Icons.paid_rounded, name: 'Empréstimos'),
                    OptionCard(icon: Icons.bar_chart, name: 'Investimentos'),
                  ],
                ),
              ],
            ),
          ],
        ),
      )),
    );
  }

  // ignore: non_constant_identifier_names
  Widget OptionCard({IconData? icon, String? name}) {
    return Container(
      width: 110.0,
      height: 110.0,
      decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(6.0),
          boxShadow: [BoxShadow(blurRadius: 6.0, color: Colors.black12)]),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Container(
              width: 50.0,
              height: 50.0,
              margin: EdgeInsets.only(top: 15.0),
              decoration: BoxDecoration(
                color: Color(0xFFF5F6FA),
                borderRadius: BorderRadius.circular(30.0),
              ),
              child: Icon(icon, color: Color(0xFFEA4F00))),
          Padding(
            padding: const EdgeInsets.only(bottom: 12.0),
            child: Text(name.toString(),
                style: TextStyle(fontSize: 13.0, color: Color(0xFF787A84))),
          ),
        ],
      ),
    );
  }
}

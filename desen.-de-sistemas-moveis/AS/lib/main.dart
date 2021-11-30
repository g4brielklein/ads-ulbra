import 'dart:async';
import 'dart:convert';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

const request = 'https://api.binance.com/api/v3/ticker/price?';

void main() async {
  runApp(MaterialApp(
    debugShowCheckedModeBanner: false,
    home: Home(),
    theme: ThemeData(
    hintColor: Colors.amber,
    primaryColor: Colors.amber,
    inputDecorationTheme: InputDecorationTheme(
      enabledBorder:
        OutlineInputBorder(borderSide: BorderSide(color: Colors.white)),
      focusedBorder:
        OutlineInputBorder(borderSide: BorderSide(color: Colors.amber)),
      hintStyle: TextStyle(color: Colors.amber),
    )),
  ));
}

Future<Map> getData() async {
  var response = await http.get(request);
  return json.decode(response.body);
}

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final realController = TextEditingController();
  final bitcoinController = TextEditingController();

  double real;
  double bitcoin;

  void _clearAll() {
    realController.text = '';
    bitcoinController.text = '';
  }

  void _realChanged(String text) {
    if (text.isEmpty) {
      _clearAll();
      return;
    }

    var real = double.parse(text);
    realController.text = (real / real).toStringAsFixed(2);
    bitcoinController.text = (real / bitcoin).toStringAsFixed(2);
  }

  void _bitcoinChanged(String text) {
    if (text.isEmpty) {
      _clearAll();
      return;
    }

    var bitcoin = double.parse(text);
    realController.text = (bitcoin * this.bitcoin).toStringAsFixed(2);
    realController.text = (bitcoin * this.bitcoin / real).toStringAsFixed(2);
  }

  static const _goldenColor = Color(0xFFFFD700);
  static const _lightColor = Color(0xFFFfcfaf1);

  final kLabelStyle = TextStyle(
    color: _goldenColor, fontWeight: FontWeight.bold, fontSize: 22);

  Widget buildTextField(String label, String prefix,
      TextEditingController changeMoney, Function changed) {
    return TextField(
      controller: changeMoney,
      decoration: InputDecoration(
        border: InputBorder.none,
        labelText: label,
        labelStyle: kLabelStyle,
        prefixText: prefix),
      style: kLabelStyle,
      onChanged: changed,
      keyboardType: TextInputType.numberWithOptions(decimal: true),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: _lightColor,
      appBar: AppBar(
        title: Text('Conversor de criptomoeda',
          style: TextStyle(color: _lightColor, fontSize: 24)),
        backgroundColor: _goldenColor,
        centerTitle: true,
        actions: <Widget>[
          IconButton(
            icon: Icon(Icons.refresh, color: _lightColor, size: 24),
            onPressed: _clearAll,
          ),
        ],
      ),
      body: FutureBuilder<Map>(
        future: getData(),
        builder: (context, snapshot) {
          switch (snapshot.connectionState) {
            case ConnectionState.none:
            case ConnectionState.waiting:
              return Center(
                child: Text('Carregando dados da API...', style: kLabelStyle));
              default:
                if (snapshot.hasError) {
                  return Center(
                    child: Text('Erro ao carregador dados da API...', style: kLabelStyle));
                } else {
                  real = double.parse(snapshot.data[1].price);
                  // bitcoin = double.parse(snapshot.data['ticker']['buy']);
                    return SingleChildScrollView(
                      child: Padding(
                      padding:
                        EdgeInsets.symmetric(horizontal: 30, vertical: 8),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.stretch,
                          children: <Widget>[
                            Icon(Icons.monetization_on,
                              size: 120.0, color: _goldenColor),
                            Divider(
                              color: _goldenColor,
                              thickness: 2.5,
                              indent: 60,
                              endIndent: 60),
                            Divider(),
                            buildTextField(
                              'Real', 'R\$ ', realController, _realChanged),
                            Divider(),
                            buildTextField(
                              'Bitcoin', '₿ ', bitcoinController,
                                _bitcoinChanged),
                          ],
                        ),
                      )
                    );
                }
          }
        }
      )
    );
  }
}
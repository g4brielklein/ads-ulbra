import 'package:flutter/material.dart';

import 'package:flutter/widgets.dart';

class my_text extends StatelessWidget {
  final String text;
  const my_text(this.text);

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: EdgeInsets.all(12),
      child: DecoratedBox(
        decoration: BoxDecoration(color: Colors.blue),
        child: Text(text, style: TextStyle(fontSize: 40, backgroundColor: Colors.amber),),
      )
    );
  }
}
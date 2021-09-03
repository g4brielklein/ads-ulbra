import 'package:flutter/material.dart';
// import 'package:flutter_code/screens/login_screen.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Login - Aula 05',
      debugShowCheckedModeBanner: false,
      // home: LoginScreen(),
    );
  }
}

// class MyApp extends StatelessWidget {
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       title: 'My App',
//       debugShowCheckedModeBanner: false,
//       home: Scaffold (
//         appBar: AppBar(
//           title: Text("My first app"),
//         ), body: Padding (
//           padding: const EdgeInsets.all(8.0),
//           child: Center (
//             child: Row(
//               children: [
//                 Padding(
//                   padding: EdgeInsets.all(30.0)),
//                 Text("Text 01",
//                  overflow: TextOverflow.ellipsis,),
//                 Expanded(
//                   child:
//                   my_text("Ola")
//                   ),
//                   Container (alignment: Alignment.center, color: Colors.red, child: Text("Text 03"))
//               ],
//             )
//           )
//         )
//       )
//     );
//   }
// }